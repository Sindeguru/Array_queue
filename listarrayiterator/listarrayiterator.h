#pragma once
#include <iostream>
#include "listarray.h"
using namespace std;

template <class T>
class TListArrayIterator
{
protected:
  int index;
  TListArray<T>& list;

public:
  TListArrayIterator(TListArray<T>& _list, int _index = -1);
  TListArrayIterator(TListArrayIterator<T>& _v);
  ~TListArrayIterator();

  //first variant
  bool IsGoNext();
  void GoNext();

  //second variant
  bool operator== (TListArrayIterator<T>& _v);
  bool operator!= (TListArrayIterator<T>& _v);

  T& operator* (int);
  T& operator* ();

  TListArrayIterator<T>& operator++();
  TListArrayIterator<T>& operator=(const TListArrayIterator& _v);

  T GetData();
};

template<class T>
TListArrayIterator<T>::TListArrayIterator(TListArray<T>& _list, int _index):list(_list)
{
  this->index = _index;
}

template<class T>
inline TListArrayIterator<T>::TListArrayIterator(TListArrayIterator<T>& _v):list(_v.list), index(_v.index)
{
} 

template<class T>
inline TListArrayIterator<T>::~TListArrayIterator()
{
  index = -1;
}

template<class T>
inline bool TListArrayIterator<T>::IsGoNext()
{
  return (index >= 0);
}

template<class T>
inline void TListArrayIterator<T>::GoNext()
{
  if (IsGoNext())
    index = list.links[index];
  else
    throw "can't go next";
}

template<class T>
inline bool TListArrayIterator<T>::operator==(TListArrayIterator<T>& _v)
{
  return ((index==_v.index)&&(*list ==*_v.list));
}

template<class T>
inline bool TListArrayIterator<T>::operator!=(TListArrayIterator<T>& _v)
{
  return !this->operator==(_v);
}

template<class T>
inline T& TListArrayIterator<T>::operator*(int)
{
  return list.data[index];
}

template<class T>
inline T& TListArrayIterator<T>::operator*()
{
  return list.data[index];
}

template<class T>
inline TListArrayIterator<T>& TListArrayIterator<T>::operator++()
{
  GoNext();
  return *this;
}

template<class T>
inline TListArrayIterator<T>& TListArrayIterator<T>::operator=(const TListArrayIterator& _v)
{
  list = _v.list;
  index = _v.index;
}

template<class T>
inline T TListArrayIterator<T>::GetData()
{
  if (index < 0)
    throw "list is empty";
  return list.data[index];
}
