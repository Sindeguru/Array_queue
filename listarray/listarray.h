#pragma once
#include <iostream>
#include "listelem.h"

using namespace std;


template <class T>
class TList
{
protected:
  TListElem* root;
  TListElem* end;
  int count; 

public:
  TList();
  TList(TList<T>& _v);
  ~TList();

  TList<T>& operator =(TList<T>& _v);

  void InsFirst(T d);
  void InsLast(T d);
  void Ins(TListElem<T>* e, T d);

  bool IsEmpty(void) const;

  TListElem<T>* GetFirst();
  TListElem<T>* GetLast();

  void DellFirst();
  void DellLast();
  void Dell(TListElem<T>* e);

  template<class T1>
  friend ostream& operator<< (ostream& ostr, const TList<T1>& A);
  template<class T1>
  friend istream& operator>> (istream& istr, TList<T1>& A);

  int GetCount();
};

template<class T1>
inline ostream& operator<<(ostream& ostr, const TList<T1>& A)
{
  TListElem<T>* i = A.root;
  while (i != 0)
  {
    ostr << *i << endl;
    i = i->GetNext;
  }
  return ostr;
}

template<class T1>
inline istream& operator>>(istream& istr, TList<T1>& A)
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
inline TList<T>::TList()
{
  root = 0;
  end = 0;
  count = 0;
}

template<class T>
inline TList<T>::TList(TList& _v)
{
  count = _v.count;
  TListElem<T>* i = _v.root;
  TListElem<T>* j = this->root;
  TListElem<T>* p = 0;

  while (i != 0)
  {
    j = new TListElem<T>(*i);
    j->SetNext(0);
    if (p != 0)
    {
      p->SetNext(j);
      j->SetPrev(p);
    }
    else
      p = j;

    if (root == 0)
      root = j;

    end = j;

    i = i->GetNext();
  }
}

template<class T>
inline TList<T>::~TList()
{
  if (this->root != 0)
  {
    TListElem<T>* i = this->root;
    TListElem<T>* p = 0;

    while (i != 0)
    {
      p = i;
      i = i->GetNext();
      delete p;
    }
    this->root = 0;
    this->end = 0;
    count = 0;
  }
}

template<class T>
inline TList<T>& TList<T>::operator=(TList<T>& _v)
{
  if (this == _v)
    return *this;

  if (this->root != 0)
  {
    TListElem<T>* i = this->root;
    TListElem<T>* p = 0;

    while (i != 0)
    {
      p = i;
      i = i->GetNext();
      delete p;
    }
    this->root = 0;
    this->end = 0;
    count = 0;
  }

  count = _v.count;
  TListElem<T>* i = _v.root;
  TListElem<T>* j = this->root;
  TListElem<T>* p = 0;

  while (i != 0)
  {
    j = new TListElem<T>(*i);
    j->SetNext(0);
    if (p != 0)
    {
      p->SetNext(j);
      j->SetPrev(p);
    }
    else
      p = j;

    if (root == 0)
      root = j;

    end = j;

    i = i->GetNext();
  }
}

template<class T>
inline void TList<T>::InsFirst(T d)
{
  TLisElem<T> tmp = new TListElem<T>(d);
  tmp->SetNext(root);
  root = tmp;
  count++;
}

template<class T>
inline void TList<T>::InsLast(T d)
{
  TLisElem<T> tmp = new TListElem<T>(d);
  tmp->SetPrev(end);
  end = tmp;
  count++;
}

template<class T>
inline void TList<T>::Ins(TListElem<T>* e, T d)
{
  TLisElem<T> tmp = new TListElem<T>(d);
  tmp->SetNext(e->GetNext());
  tmp->SetPrev(e);
  e->GetNext()->SetPrev(tmp);
  e->SetNext(tmp);
  count++;
}

template<class T>
inline bool TList<T>::IsEmpty(void) const
{
  return count == 0;
}

template<class T>
inline TListElem<T>* TList<T>::GetFirst()
{
  return root;
}

template<class T>
inline TListElem<T>* TList<T>::GetLast()
{
  return end;
}

template<class T>
inline void TList<T>::DellFirst()
{
  TListElem<T>* i = root;
  root = root->GetNext();
  delete i;
  count--;
}

template<class T>
inline void TList<T>::DellLast()
{
  TListElem<T>* i = end;
  end = end->GetPrev();
  delete i;
  count--;
}

template<class T>
inline void TList<T>::Dell(TListElem<T>* e)
{
  e->GetPrev()->SetNext(e->GetNext());
  e->GetNext()->SetPrev(e->GetPrev());

  count--;
  delete e;
}

template<class T>
inline int TList<T>::GetCount()
{
  return count;
}
