//#include "array.h"
template <class pointerType>
array<pointerType>::array(pointerType *pArray, unsigned int pSize)
{
    setArray(pArray,pSize);
}
//////////////////////////////////////////////////////////
template<class pointerType>
array<pointerType>::array(){
    arrayPointer=NULL;
    size=0;
}
//////////////////////////////////////////////////////////
template<typename pointerType>
array<pointerType>::~array(){
    if(arrayPointer!=NULL){
        delete arrayPointer;
    }
}
///////////////////////////////////////////////////////////
template <typename pointerType>
void array<pointerType>::setArray(pointerType *pArray, unsigned int pSize){
    arrayPointer=pArray;
    size=pSize;
}
///////////////////////////////////////////////////////////
template<typename pointerType>
pointerType array<pointerType>::operator [](unsigned int t){
    return arrayPointer[t];
}
/////////////////////////////////////////////////////////////
template<typename pointerType>
pointerType array<pointerType>::deletePointers(){
    for(unsigned int n;n!=size;n++){
        delete arrayPointer[n];
    }
}
///////////////////////////////////////////////////////////////
