#pragma once
#include <iostream>
#include "listarrayiterator.h"
using namespace std;

template <class T>
class TListArray
{
protected:
  T* data; 
  int* links;
  int size;
  int root;
  int count; 

public:
  TListArray(int _size = 1);
  TListArray(TListArray<T>& _v);
  ~TListArray();

  TListArray<T>& operator =(TListArray<T>& _v);

  void InsFirst(T d);
  void InsLast(T d);
  bool IsEmpty(void) const;
  bool IsFull(void) const;

  TListArrayIterator<T>* begin();
  TListArrayIterator<T>* end();

  void DellFirst();
  void DellLast();
  T GetFirst();
  T GetLast();

  template<class T1>
  friend ostream& operator<< (ostream& ostr, const TListArray<T1>& A);
  template<class T1>
  friend istream& operator>> (istream& istr, TListArray<T1>& A);

  template <class T>
  friend class TListArrayIterator;

  int GetCount();
};

template<class T1>
inline ostream& operator<<(ostream& ostr, const TListArray<T1>& A)
{
  int i = A.root;
  while (A.links[i] != -1)
  {
    ostr << A.data[i];
    i = A.links[i];
  }

  return ostr;
}

template<class T1>
inline istream& operator>>(istream& istr, TListArray<T1>& A)
{
  int Count = 0;
  istr >> Count;
  for (int i = 0; i < count; i++)
  {
    T1 d;
    istr >> d;
    A.InsLast(d);
  }
  return istr;
}

template<class T>
inline TListArray<T>::TListArray(int _size)
{
  if (_size <= 0)
    throw "logic_error";
  size = _size;
  
  data = new T[size];
  links = new int[size];
  count = 0;

  for (int i = 0; i < _size; i++)
  {
    links[i] = -1;
  }
  root = -1;
}

template<class T>
inline TListArray<T>::TListArray(TListArray& _v)
{
  count = _v.count;
  size = _v.size;
  root = _v.root;

  data = new T[size];
  links = new int[size];

  for (int i = 0; i < size; i++)
  {
    links[i] = _v.links[i];
    data[i] = _v.data[i];  
  }
}

template<class T>
inline TListArray<T>::~TListArray()
{
  if (data != 0)
  {
    delete[] data;
    delete[] links;
    data = 0;
    links = 0;
    count = 0;
    size = 0;
    root = -1;
  }
}

template<class T>
inline TListArray<T>& TListArray<T>::operator=(TListArray<T>& _v)
{
  if (this == _v)
    return *this;

  if (size != _v.size)
  {
    delete[] data;
    delete[] links;
    
    size = _v.size;
    data = new T[size];
    links = new int[size];
    count = _v.size;

    for (int i = 0; i < size; i++)
    {
      links[i] = _v.links[i];
      data[i] = _v.data[i];
    }

    return this;
  }
  else
  {
    count = _v.count;
    for (int i = 0; i < size; i++)
    {
      links[i] = _v.links[i];
      data[i] = _v.data[i];
    }
  }
}

template<class T>
inline void TListArray<T>::InsFirst(T d)
{
  if (this->IsFull())
    throw "List is Full";
  int i;
  for (i = 0; i < size; i++)
  {
    if (links[i] == -1)
      break;
  }
  data[i] = d;
  links[i] = root;
  root = i;
  count++;
}

template<class T>
inline void TListArray<T>::InsLast(T d)
{
  if(this->IsFull())
    throw "List is Full";
  if (this->IsEmpty())
  {
    root = 0;
    data[0] = d;
    links[0] = -1;
  }
  else
  {
    for (i = 0; i < size; i++)
    {
      if (links[i] == -1)
        break;
    }

    int end = root;
    while (links[end] != -1)
      end = links[end];

    data[i] = d;
    links[i] = -1;
    links[end] = i;
  }
  count++;
}

template<class T>
inline bool TListArray<T>::IsEmpty(void) const
{
  return count == 0;
}

template<class T>
inline bool TListArray<T>::IsFull(void) const
{
  return count == size;
}

template<class T>
inline TListArrayIterator<T>* TListArray<T>::begin()
{
  return TListArrayIterator<T>(*this, root);
}

template<class T>
inline TListArrayIterator<T>* TListArray<T>::end()
{
  return TListArrayIterator<T>(*this, -1);
}

template<class T>
inline void TListArray<T>::DellFirst()
{
  if (this->IsEmpty())
    throw "List is Empty";
  
  int i = root;
  root = links[root];
  links[i] = -1;

  count--;
}

template<class T>
inline void TListArray<T>::DellLast()
{
  if (this->IsEmpty())
    throw "List is Empty";

  if (links[root] == -1)
    root = -1;
  else
  {
    int pEnd = root; // (end - 1) element
    int end = links[root];

    while (links[end] != -1)
    {
      pEnd = end;
      end = links[end];
    }
    links[pEnd] = -1;
    linls[end] = -1;
  }
  count--;
}

template<class T>
inline T TListArray<T>::GetFirst()
{
  if (this->IsEmpty())
    throw "List is Empty";
  
  return data[root];
}

template<class T>
inline T TListArray<T>::GetLast()
{
  if (this->IsEmpty())
    throw "List is Empty";

  int end = root;
  while (links[end] != -1)
    end = links[end];
  return data[end];
}

template<class T>
inline int TListArray<T>::GetCount()
{
  return count;
}
