#include "abstractparser.h"

abstractParser::abstractParser()
{
    error=tr("No errors.");
}
////////////////////////////////////////////////
bool abstractParser::readFile(QString fileName){
    return false;
}
////////////////////////////////////////////////
sceneObject* abstractParser::getSceneObject(){
    //указатель на объект можно запросить только раз
    //кто запросил объект, тот и отвечает за его удаление
    sceneObject *tmp=object;
    object=NULL;//если указатель запрошен, то парсер его забывает
    return tmp;
}
////////////////////////////////////////////////
QString abstractParser::getLastError(){
    QString g=tr("Parsrer .obj error:   ")+error;
    error=tr("No error.");
    return g;
}
///////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////
