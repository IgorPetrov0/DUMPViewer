#include "parserdae.h"

parserDAE::parserDAE()
{
    xmlDocument=NULL;
    vOffset=0;
    nOffset=0;
    texCoordOffset=0;
}
/////////////////////////////////////////////////////////////
parserDAE::~parserDAE(){
    if(xmlDocument!=NULL){
        delete xmlDocument;
    }
}
////////////////////////////////////////////////////////////
bool parserDAE::readFile(QString fileName){
    QFile file(fileName);
    if(!file.open(QFile::ReadOnly|QFile::Text)){
        error=tr("File ")+fileName+tr(" not open.");
        return false;
    }
    xmlDocument = new QDomDocument;
    QString errorStr;
    int errorLine;
    int errorColumn;
    if(!xmlDocument->setContent(&file,false,&errorStr,&errorLine,&errorColumn)){
        error=tr("XML parse error at line \n")+errorLine+
                tr("column: ")+QString::number(errorLine)+"\n"+
                tr("error column: ")+QString::number(errorColumn)+" .";
        return false;
    }
    QDomElement root=xmlDocument->documentElement();
    if(root.tagName()!="COLLADA"){
        error=tr("XML file is not Collada compability.");
        return false;
    }
    parsDAE(&root);
    return true;
}
/////////////////////////////////////////////////////////////
void parserDAE::parsDAE(QDomElement *root){

//    QDomNode child=root->firstChild();

//    while(!child.toElement().isNull()){
//        child=root->firstChild();
//        if(element.tagName()=="library_geometries"){
//            parsGeometry(&element);
//        }
//        child=root->nextSibling();
//    }
}
/////////////////////////////////////////////////////////////
void parserDAE::parsGeometry(QDomNode *geometry){

}
