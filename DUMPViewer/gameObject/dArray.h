#ifndef ARRAY_H
#define ARRAY_H

#include <iostream>
#include <vector>
#include "defines.h"

//шаблон класса массива. нужен для удобства использования массивов с указанием их размеров

using namespace std;
template<class pointerType> class dArray
{
public:
    dArray();
    dArray(arraySize pSize);
    dArray(dArray<pointerType> *arr);//конструктор копирования
    dArray(pointerType* dArray, arraySize size);
    ~dArray();
    void setArray(arraySize pSize);
    pointerType &operator [](arraySize t);
    pointerType &operator =(pointerType& arr);
    bool operator ==(dArray<pointerType> &arr);
    bool operator !=(dArray<pointerType> &arr);
    void fillArray(vector<pointerType> *arr);//заполнение массива из вектора
    void deletePointers();//последовательно удаляет все объекты, если элементы массива являются указателями
    void addElement(arraySize index, pointerType element);//добавляет элемент в массив на указанную позицию
    pointerType const *getArrayPointer();//возвращает указатель на массив
    arraySize getSize();//возвращает размер массива
    void clear();

protected:
    pointerType *arrayPointer;
    arraySize size;



};
///////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////
/// описание и реализация ДОЛЖНЫ БЫТЬ В ОДНОМ ФАЙЛЕ!!!!!!!!!!!!!!!!!!!!!!!!!!

template <class pointerType>
dArray<pointerType>::dArray(arraySize pSize)
{
    setArray(pSize);
}
////////////////////////////////////////////////////////////
template<class pointerType>
dArray<pointerType>::dArray(){
    arrayPointer=NULL;
    size=0;
}
///////////////////////////////////////////////////////////
template<class pointerType>
dArray<pointerType>::dArray(dArray<pointerType> *arr){
    setArray(arr->getSize());
    for(unsigned int n=0;n!=size;n++){
        arrayPointer[n]=(*arr)[n];
    }
}
//////////////////////////////////////////////////////////
template<class pointerType>
dArray<pointerType>::dArray(pointerType *arr, arraySize size){
    arrayPointer=arr;
    this->size=size;
}
//////////////////////////////////////////////////////////
template<typename pointerType>
dArray<pointerType>::~dArray(){
   delete []arrayPointer;
}
///////////////////////////////////////////////////////////
template <class pointerType>
void dArray<pointerType>::setArray(arraySize pSize){
    arrayPointer=new pointerType[pSize];
    size=pSize;
}
///////////////////////////////////////////////////////////
template<typename pointerType>
pointerType &dArray<pointerType>::operator [](arraySize t){
    return arrayPointer[t];
}
//////////////////////////////////////////////////////////////
template<class pointerType>
void dArray<pointerType>::fillArray(vector<pointerType> *arr){
    for(unsigned int n=0;n!=size;n++){//заполняем только выделенные элементы массива
        arrayPointer[n]=arr->at(n);
    }
}
/////////////////////////////////////////////////////////////////////////////////////
template<class pointerType>
void dArray<pointerType>::deletePointers(){
    for(unsigned int n=0;n!=size;n++){
        delete arrayPointer[n];
    }
}
/////////////////////////////////////////////////////////////////////////////////////////
template<class pointerType>
void dArray<pointerType>::addElement(arraySize index, pointerType element){
    arrayPointer[index]=element;
}
/////////////////////////////////////////////////////////////////////////////////////////
template<class pointerType>
pointerType const *dArray<pointerType>::getArrayPointer(){
    return arrayPointer;
}
////////////////////////////////////////////////////////////////////////////////////////
template<class pointerType>
arraySize dArray<pointerType>::getSize(){
    return size;
}
/////////////////////////////////////////////////////////////////////////////////////////
template<class pointerType>
void dArray<pointerType>::clear(){
    delete []arrayPointer;
    arrayPointer=NULL;
    size=0;
}
/////////////////////////////////////////////////////////////////////////////////////////
template<class pointerType>
pointerType& dArray<pointerType>::operator =(pointerType &arr){
    clear();
    size=arr.getSize();
    arrayPointer=new pointerType[size];
    for(unsigned int n=0;n!=size;n++){
        arrayPointer[n]=arr[n];
    }
    return *this;
}
//////////////////////////////////////////////////////////////////////////////////////////
template<class pointerType>
bool dArray<pointerType>::operator ==(dArray<pointerType> &arr){
    if(arr.getSize()!=size){
        return false;
    }
    for(unsigned int n=0;n!=size;n++){
        if(this->operator [](n)!=arr[n]){
            return false;
        }
    }
    return true;
}
///////////////////////////////////////////////////////////////////////////////////////////
template<class pointerType>
bool dArray<pointerType>::operator !=(dArray<pointerType> &arr){
    return !operator ==(arr);
}
///////////////////////////////////////////////////////////////////////////////////////////




#endif // ARRAY_H
