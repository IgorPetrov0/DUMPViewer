#include "parserobj.h"

parserOBJ::parserOBJ()
{
    object=NULL;
}
///////////////////////////////////////////////////
parserOBJ::~parserOBJ()
{
    deleteObject();
}
///////////////////////////////////////////////////
bool parserOBJ::readFile(QString fileName){
    QFile file(fileName);
    QFileInfo fi(file);
    path=fi.absolutePath();

    bool rez=false;//результат парсинга

    if(file.open(QIODevice::ReadOnly|QIODevice::Text)){
        if(parsObj(&file)){//если прочиталось
            rez=true;
        }
        file.close();//закрываем файл, если он открывался
    }     
    else{
        error=tr("Can't open file ")+fileName;
    }
    return rez;
}
//////////////////////////////////////////////////////////
bool parserOBJ::parsObj(QFile *file){

    QVector<float>vertexArray;
    QVector<float>normalsArray;
    QVector<float>texturesArray;
    QVector<float>tmpVertexesArray;//временный массив вершин. формат: поверхн/текстура/нормаль

    deleteObject();
    object=new sceneObject;

    //читаем имя библиотеки материалов
    QString tmp=file->readLine();
    while(!file->atEnd()){
        if(tmp.left(6)=="mtllib"){
            tmp=tmp.mid(7);
            tmp.remove(tmp.size()-1,2);//удаляем символы окончания строки. не думаю, что будут отличные от "\n"
            mtLib=path+"/"+tmp;
            break;
        }
        tmp=file->readLine();
    }
    if(file->atEnd()){
        error=tr("Materials library file name not found.");
        return false;
    }

    tmp=file->readLine();
    while(!file->atEnd()){//читаем до конца файла
        //if(tmp.left(1)=="o"){
            //tmp=file->readLine();
            while(tmp.left(2)=="v "){//читаем пока не кончатся вершины
                if(!readNumbers(&tmp,&vertexArray)){//читаем вершины
                    return false;
                }
                tmp=file->readLine();//читаем следующую строку
            }
            while(tmp.left(2)=="vt"){//читаем пока не кончатся вершины
                if(!readNumbers(&tmp,&texturesArray)){//читаем вершины
                    return false;
                }
                tmp=file->readLine();//читаем следующую строку
            }
            while(tmp.left(2)=="vn"){//читаем нормали
                if(!readNumbers(&tmp,&normalsArray)){
                    return false;
                }
                tmp=file->readLine();//читаем следующую строку
            }
        //}
        if(tmp.left(6)=="usemtl"){//читаем материал
           //ищем материал с таким-же именем
           int mCount=object->getMaterialsSize();
           int n;
           QString name=tmp.mid(7,-2);
           material *tmpMaterial;

           for(n=0;n!=mCount;n++){
               tmpMaterial=object->getMaterial(n);
               if(tmpMaterial->getName()==name){//если нашли имя,
                   break;//то пишем в этот-же материал
               }
           }
           if(n==mCount){//если не нашли
               tmpMaterial=new material;//то создаем новый
               tmpMaterial->setName(name);
               if(!readMaterial(tmpMaterial)){//читаем свойства материала
                   return false;
               }
           }

           tmp=file->readLine();
           if(tmp.left(1)=="s"){//пропускаем строку S
                tmp=file->readLine();
           }
           while(tmp.left(1)=="f"){//читаем поверхности
               if(!readNumbers(&tmp,&tmpVertexesArray)){
                   return false;
               }
               tmp=file->readLine();
           }
           int size=tmpVertexesArray.size()/3;
           int *tmpVIndices;
           int *tmpTIndices;
           int *tmpNIndices;
           //создаем массивы индексов
           int vertexes=tmpMaterial->getVertexesCount();
           tmpVIndices=new int[size+vertexes];//вершины
           tmpTIndices=new int[size+vertexes];//текстурные координаты
           tmpNIndices=new int[size+vertexes];//нормали
           //заполняем массивы
           if(n==mCount){//если это новый материал
               for(int n=0;n!=size;n++){
                   tmpVIndices[n]=tmpVertexesArray.at(n*3);
                   tmpTIndices[n]=tmpVertexesArray.at(n*3+1);
                   tmpNIndices[n]=tmpVertexesArray.at(n*3+2);
               }
               //передаем указатели материалу
               tmpMaterial->setVertexesCount(size+vertexes);
               tmpMaterial->setNormalsIndicesArray(tmpNIndices);
               tmpMaterial->setTextureIndicesArray(tmpTIndices);
               tmpMaterial->setVertexIndicesArray(tmpVIndices);
               object->addMaterial(tmpMaterial);
           }
           else{//если материал существующий
               //здесь tmpMaterial указывает на object->material
               int nn;
               for(nn=0;nn!=vertexes;nn++){//сначала переносим существующие данные в новые массивы
                   tmpVIndices[nn]=tmpMaterial->getVertexIndicesArrayPointer()[nn];
                   tmpTIndices[nn]=tmpMaterial->getTextureIndicesArrayPointer()[nn];
                   tmpNIndices[nn]=tmpMaterial->getNormalsIndicesArrayPointer()[nn];
               }
               for(int n=0;n!=size;n++){//затем добавляем новые данные
                   tmpVIndices[nn+n]=tmpVertexesArray.at(n*3)-1;
                   tmpTIndices[nn+n]=tmpVertexesArray.at(n*3+1)-1;
                   tmpNIndices[nn+n]=tmpVertexesArray.at(n*3+2)-1;
               }
               //передаем указатели материалу
               tmpMaterial->setVertexesCount(size+vertexes);
               tmpMaterial->setNormalsIndicesArray(tmpNIndices);
               tmpMaterial->setTextureIndicesArray(tmpTIndices);
               tmpMaterial->setVertexIndicesArray(tmpVIndices);
           }
           tmpVertexesArray.clear();//очищаем массив поверхностей т.к. у одного объекта их может быть много
        }
        else{
            tmp=file->readLine();
        }
    }
    //создаем массивы вершин,текстур и нормалей
    int size=vertexArray.size();//вершины
    float *v=new float[size];
    for(int n=0;n!=size;n++){
        v[n]=vertexArray.at(n);
    }
    object->setVertexArray(v,size);

    size=texturesArray.size();//текстурные координаты
    float *t=new float[size];
    for(int n=0;n!=size;n++){
        t[n]=texturesArray.at(n);
    }
    object->setTexturesArray(t,size);

    size=normalsArray.size();//нормали
    float *norm=new float[size];
    for(int n=0;n!=size;n++){
        norm[n]=normalsArray.at(n);
    }
    object->setNormalsArray(norm,size);

    return true;
}
///////////////////////////////////////////////////////////////////////////////////
bool parserOBJ::readNumbers(QString *string, QVector<float> *outVector){

    QString tmp;
    int end=0;
    int beg=0;
    float num=0;
    bool ok=true;
    bool endString=false;

    beg=string->indexOf(" ");//находим первый пробел-это будет начало числа
    while(!endString){//выполняем, пока не кончатся пробелы
        end=string->indexOf(" ",beg+1);//ищем следующий пробел - это будет конец числа
        if(end==-1){//если пробелов больше нет, то ищем конец строки
            end=string->indexOf("\n",beg+1);
            if(end==-1){//если и конца строки не найдено то ошибка
                error=tr("Can't find end string terminator in string")+*string;
                return false;
            }
            endString=true;//и создаем условие выхода из цикла
        }
        tmp=string->mid(beg,end-beg);//получаем кусок строки между пробелами

        if(string->contains("/")){//если в строке имеются слеши
            int b=0,e=0;
            tmp.append("/");//добавляем в конец слеш, что-бы не морочиться
            tmp.remove(0,1);//удаляем первый пробел
            e=tmp.indexOf("/",b);
            while(e!=-1){
                QString t=tmp.mid(b,e-b);
                if(t.isEmpty()){
                    num=-1;//то в массив заносим -1
                    outVector->append(num);
                }
                else{
                    num=t.toInt(&ok);
                    if(!ok){//если не оцифровывается
                        error=tr("Symbols ")+t+tr(" in string ")+*string+tr(" in not number.");
                        return false;//то ошибка
                    }
                    else{
                        outVector->append(num-1);//иначе пихаем в массив/ вычитаем 1 т.к. в .obj индексы начинаются с 1
                    }
                }
                b=e+1;
                e=tmp.indexOf("/",e+1);//ищем следующий слеш
            }
        }
        else{
            num=tmp.toFloat(&ok);//пробуем преобразовать в число
            if(!ok){
                error=tr("Symbols ")+tmp+tr(" in string ")+*string+tr(" in not number.");
                return false;//если не выходит - то ошибка
            }
            else{
                outVector->append(num);//иначе пихаем в массив
            }
        }
        beg=end;
    }
    return true;
}
///////////////////////////////////////////////////////////////////////////////////
//bool parserOBJ::readNumSring(QString *string, unsigned char n,QVector<QString> *outVector){
//    /*
//  Читаем из строки string числа в буфер outVector
//  n-максимальное ожидаемое количество чисел
//  */
//    QString str;
//    int spacePos=0,spacePos1=0;

//    outVector->clear();

//    if(string->contains("/")){//если в строке имеются слеши

//    }

//    int nums=string->count(" ")+string->count("/")+1;//получаем количество чисел в строек. числа могут разделяться пробелами и слешами


//    if(nums>n){//если количество чисел больше ожидаемого то строка некошерная
//        return false;//выходим с ошибкой
//    }

//    for(int t=0;t!=nums;t++){
//         int sl=0,sp=0;// кол-ва знаков до следующего пробела и слеша
//            sp=string->indexOf(" ",spacePos+1);//считаем кол-во знаков до пробела

//            sl=string->indexOf("/",spacePos+1);//считаем кол-во знаков до слеша

//            //spacePos=string->indexOf(" ",spacePos+1);//считаем кол-во знаков до пробела
//            if((sp==-1) & (sl==-1)){//если пробел и слеш не найдены
//                //проверяем номер прохода
//                if(t==nums-1){//если последний то
//                    spacePos=string->indexOf("\n",spacePos+1);//считаем кол-во знаков до конца строки
//                }
//                else{//если не последний то строка некошерная
//                    return 1;//и выходим с ошибкой
//                }
//            }
//            else{
//                if((sp==-1)|(sl==-1)){//есля хоть одно значение <0
//                    if(sp>sl)spacePos=sp;//выбираем наибольшее кол-во знаков
//                    else spacePos=sl;
//                }
//                else{//иначе
//                    if(sp<sl)spacePos=sp;//выбираем наименьшее кол-во знаков
//                    else spacePos=sl;
//                }
//            }

//            str=string->mid(spacePos1,spacePos-spacePos1);
//            if(str!="/"){//если прочитанный символ не слеш
//                spacePos1=spacePos;//то двигаемся дальше
//                 outVector->append(str);//и записываем число
//            }
//            else{
//               // t=t-1;//иначе данный проход не считается и позиция не меняется
//                spacePos1=spacePos+1;
//                outVector->append("void");//и записываем пустоту
//            }
//    }
//    return 0;
//}
/////////////////////////////////////////////////////////////////////////////////////////////
void parserOBJ::getAllMaterials(QVector<material *> *matArray){
//    for(int n=0;n!=objectsArray.size();n++){
//        for(int m=0;m!=objectsArray.at(n)->getMaterialsSize();m++){
//            matArray->append(objectsArray.at(n)->getMaterial(m));
//        }
//    }
}
/////////////////////////////////////////////////////////////////////////////////////////////
void parserOBJ::deleteObject(){
    //пока указатель на объект не запрошен за него отвечает парсер
    if(object!=NULL){
        delete object;
    }
}
///////////////////////////////////////////////////////////////////////////////////////////////
bool parserOBJ::readMaterial(material *mat){
    QString tmpLine;
    float tmp;
    QVector3D tmpVector3D;
    QString tmpString;
    bool Ns=false, Ka=false, Kd=false, Ks=false, Ni=false, d=false, illum=false, mat_Kd=false;

    //материал знать ничего не должен, из какого он файла, потому читаем файл в парсере
    QFile mtlLib(mtLib);

    if(mtlLib.open(QIODevice::ReadOnly|QIODevice::Text)){
        //ищем в файле материал по имени
        while(!mtlLib.atEnd()){
            tmpLine=mtlLib.readLine();
            if(tmpLine.left(7)=="newmtl "){
                QString g=tmpLine.mid(7);
                if(mat->getName()==tmpLine.mid(7)){
                     break;
                }
            }
        }
        if(mtlLib.atEnd()){//если материал не нашли то выходим
            error=tr("Material ")+mat->getName()+tr(" not found in file ")+mtLib;
            return false;
        }
        else{//иначе читаем свойства
                //исходим из того, что параметры могут быть расположены в любом порядке.
                //отсутствие каких-либо параметров, а так-же наличие неучтенных здесь параметром допускается
                //для оптимизации раз прочитанный параметр помечаем и больше он не участвует в поиске. таким образом дважды прописанный
                //параметр запишется только один раз(первый встреченый) и двойная запись в файле не считается ошибкой
                //на данном этапе считаю, что оптимизация имеет смысл при чтении сложных моделей с большим количеством материалов
                //при этом исключаются лишние сравнения строк
            do{
                tmpLine=mtlLib.readLine();
                if(!Ns){
                    if(tmpLine.left(3)=="Ns "){
                        if(!readFloat(&tmpLine,&tmp)){
                            return false;
                        }
                        mat->setNs(tmp);
                        Ns=true;
                        continue;
                    } 
                }
                if(!Ka){
                    if(tmpLine.left(3)=="Ka "){
                        if(!readVector3(&tmpLine,&tmpVector3D)){
                            return false;
                        }
                        mat->setKaRGB(tmpVector3D);
                        Ka=true;
                        continue;
                    }     
                }
                if(!Kd){
                    if(tmpLine.left(3)=="Kd "){
                        if(!readVector3(&tmpLine,&tmpVector3D)){
                            return false;
                        }
                        mat->setKdRGB(tmpVector3D);
                        Kd=true;
                        continue;
                    }        
                }
                if(!Ks){
                    if(tmpLine.left(3)=="Ks "){
                        if(!readVector3(&tmpLine,&tmpVector3D)){
                            return false;
                        }
                        mat->setKsRGB(tmpVector3D);
                        Ks=true;
                        continue;
                    }    
                }
                if(!Ni){
                    if(tmpLine.left(3)=="Ni "){
                        if(!readFloat(&tmpLine,&tmp)){
                            return false;
                        }
                        mat->setNi(tmp);
                        Ni=true;
                        continue;
                    }  
                }
                if(!d){
                    if(tmpLine.left(2)=="d "){
                        if(!readFloat(&tmpLine,&tmp)){
                            return false;
                        }
                        mat->setD(tmp);
                        d=true;
                        continue;
                    }
                }
                if(!illum){
                    if(tmpLine.left(6)=="illum "){
                        if(!readFloat(&tmpLine,&tmp)){
                            return false;
                        }
                        mat->setD(tmp);
                        illum=true;
                        continue;
                    } 
                }
                if(!mat_Kd){
                    if(tmpLine.left(7)=="map_Kd "){
                        if(!readString(&tmpLine,&tmpString)){
                            return false;
                        }
                        tmpString.remove(tmpString.size()-1,2);//обрезаем символ конца строки
                        QFileInfo fi(tmpString);
                        tmpString=fi.fileName();//выделяем только имя файла
                        //смысл в том, что в материале будет хранится только имя файла.
                        //путь до места его хранения определяет программа, которая этот материал использует
                        //в .obj файле может быть какой угодно путь, записанный редактором, тогда, как материал
                        //может использоваться например на другой машине и/или в другой программе
                        mat->setMapKd(tmpString);
                        mat_Kd=true;
                        continue;
                    }                 
                }
            }while((tmpLine.left(7)!="newmtl ")&(!mtlLib.atEnd()));//читаем пока не наткнемся на следующий материал или на конец файла
        }
        mtlLib.close();//закрываем файл, если он открывался
    }
    else{
        error=tr("Can't open materials library file ")+mtLib;
        return false;
    }
    return true;
}
/////////////////////////////////////////////////////////////////////////////////////////////
bool parserOBJ::readVector3(QString *string, QVector3D *target){
    QString tmp;
    int end=0;
    int beg=0;
    int iterator=0;
    float num=0;
    bool ok=true;
    bool endString=false;

    beg=string->indexOf(" ");//находим первый пробел-это будет начало числа
    while(!endString){//выполняем, пока не кончатся пробелы
        end=string->indexOf(" ",beg+1);//ищем следующий пробел - это будет конец числа
        if(end==-1){//если пробелов больше нет, то ищем конец строки
            end=string->indexOf("\n",beg+1);
            if(end==-1){//если и конца строки не найдено то ошибка
                error=tr("Can't find end string terminator in string")+*string;
                return false;
            }
            endString=true;//и создаем условие выхода из цикла
        }
        tmp=string->mid(beg,end-beg);//получаем кусок строки между пробелами
            num=tmp.toFloat(&ok);//пробуем преобразовать в число
            if(!ok){
                error=tr("Symbols ")+tmp+tr(" in string ")+*string+tr(" in not number.");
                return false;//если не выходит - то ошибка
            }
            else{
                switch(iterator){
                    case(0):{
                        target->setX(num);
                        break;
                    }
                    case(1):{
                        target->setY(num);
                        break;
                    }
                    case(2):{
                        target->setZ(num);
                        break;
                    }
                }
                iterator++;
            }
        beg=end;
    }
    return true;
}
/////////////////////////////////////////////////////////////////////////////////////////////
bool parserOBJ::readFloat(QString *string, float *target){
    QString tmp;
    int end=0;
    int beg=0;
    float num=0;
    bool ok=true;

    beg=string->indexOf(" ");//находим первый пробел-это будет начало числа
    end=string->indexOf(" ",beg+1);//ищем следующий пробел - это будет конец числа
    if(end==-1){//если пробелов больше нет, то ищем конец строки
        end=string->indexOf("\n",beg+1);
        if(end==-1){//если и конца не нашли
            error=tr("Can't find end string terminator in string ")+*string;
            return false;
        }
    }
    tmp=string->mid(beg,end-beg);//получаем кусок строки между пробелами
    num=tmp.toFloat(&ok);//пробуем преобразовать в число
    if(!ok){
        error=tr("Symbols ")+tmp+tr(" in string ")+*string+tr(" in not number.");
        return false;//если не выходит - то ошибка
    }
    else{
        *target=num;
    }
    return true;
}
/////////////////////////////////////////////////////////////////////////////////////////////
bool parserOBJ::readString(QString *string, QString *target){
    *target=string->mid(7);
    if(target->isEmpty()){
        error=tr("Texture file ")+*target+tr(" not defined.");
        return false;
    }
    return true;
}
/////////////////////////////////////////////////////////////////////////////////////////////











