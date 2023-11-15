// ННГУ, ИИТММ, Курс "Алгоритмы и структуры данных"
//
// Copyright (c) Сысоев А.В.
//
//

#ifndef __TDynamicMatrix_H__
#define __TDynamicMatrix_H__

#include <iostream>

using namespace std;

const int MAX_VECTOR_SIZE = 100000000;
const int MAX_MATRIX_SIZE = 10000;

// Динамический вектор - 
// шаблонный вектор на динамической памяти
template<typename T>
class TDynamicVector
{
protected:
  size_t sz;//размер
  T* pMem; //память
public:
  TDynamicVector(size_t size = 1) : sz(size) // конструктор с параметром
  {
    if (sz == 0)
      throw out_of_range("Vector size should be greater than zero"); //вышел за пределы допустимого диапазона значений объекта
    if (sz > MAX_VECTOR_SIZE)
        throw out_of_range("Больше максимального размера");
    pMem = new T[sz]{};// У типа T д.б. констуктор по умолчанию
  }
  TDynamicVector(T* arr, size_t s) : sz(s) // конструктор с массивом
  {
      if (sz == 0)
          throw out_of_range("Vector size should be greater than zero"); //вышел за пределы допустимого диапазона значений объекта
      if (sz > MAX_VECTOR_SIZE)
          throw out_of_range("Больше максимального размера");
      assert(arr != nullptr && "TDynamicVector ctor requires non-nullptr arg"); //ошибку выводит с abort и с конкретным местом где она находится
      pMem = new T[sz];
      std::copy(arr, arr + sz, pMem);
  }
  TDynamicVector(const TDynamicVector& v) //конструктор копирования
  {
      sz = v.sz;
      if (v.pMem == nullptr) {
          pMem = nullptr;
      }
      else {
          pMem = new T[sz];
          for (int i = 0; i < sz; i++) {
              pMem[i] = v.pMem[i];
          }
      }
  }
  TDynamicVector(TDynamicVector&& v) noexcept //конструктор перемещения (вместо копирования данных они просто перемещаются из одной копии объекта в другую)
  {
      sz = v.sz;
      pMem = v.pMem;

      v.sz = 0;
      v.pMem = nullptr;
  }
  ~TDynamicVector()
  {
      if (pMem != nullptr) {
          sz = 0;
          delete[]pMem;
      }
  }
  TDynamicVector& operator=(const TDynamicVector& v)
  {
      if (this == &v) { // если равен сам себе (что может глупенький сделать, то мы его же и возвращаем)
          return *this;
      }
      if (pMem != nullptr) { // если в квартире грязно, то ее надо почистить
          delete[]pMem;
      }
      if (v.pMem == nullptr) {
          sz = 0;
          pMem = nullptr;
      }
      else {
          sz = v.sz;
          pMem = new T[sz];
          for (int i = 0; i < sz; i++) {
              pMem[i] = v.pMem[i];
          }
      }
      return *this;
  }
  TDynamicVector& operator=(TDynamicVector&& v) noexcept
  {
      if (this == &v) { // если равен сам себе (что может глупенький сделать, то мы его же и возвращаем)
          return *this;
      }
      if (pMem != nullptr) { // если в квартире грязно, то ее надо почистить
          delete[]pMem;
      }
      if (v.pMem == nullptr) {
          sz = 0;
          pMem = nullptr;
      }
      else {
          sz = v.sz;
          pMem = v.pMem;

          v.sz = 0;
          v.pMem = nullptr;
      }
      return *this;
  }

  size_t size() const noexcept { return sz; }

  // индексация
  T& operator[](size_t ind) //можно потом изменить
  {
      return pMem[ind];
  }
  const T& operator[](size_t ind) const //нельзя потом изменить
  {
      return pMem[ind];
  }
  // индексация с контролем
  T& at(size_t ind)
  {
      if ((ind < 0) || (ind >= sz)) {
          throw "Error";
      }
      if (pMem == nullptr) {
          throw "Error";
      }
      return pMem[ind];
  }
  const T& at(size_t ind) const
  {
      if ((ind < 0) || (ind >= sz)) {
          throw "Error";
      }
      if (pMem == nullptr) {
          throw "Error";
      }
      return pMem[ind];
  }

  // сравнение
  bool operator==(const TDynamicVector& v) const noexcept
  {
      if (sz != v.sz) {
          return 0;
      }
      for (int i = 0; i < sz; i++) {
          if (pMem[i] != v.pMem[i]) {
              return 0;
          }
      }
      return 1;
  }
  bool operator!=(const TDynamicVector& v) const noexcept
  {
      if (sz != v.sz) {
          return 1;
      }
      for (int i = 0; i < sz; i++) {
          if (pMem[i] != v.pMem[i]) {
              return 1;
          }
      }
      return 0;
  }

  // скалярные операции
  TDynamicVector operator+(T val)
  {
      TDynamicVector temp(*this);
      for (int i = 0; i < sz; i++) {
          temp[i] = pMem[i] + val;
      }
      return temp;
  }
  TDynamicVector operator-(T val)
  {
      TDynamicVector temp(*this);
      for (int i = 0; i < sz; i++) {
          temp[i] = pMem[i] - val;
      }
      return temp;
  }
  TDynamicVector operator*(T val)
  {
      TDynamicVector<T> temp(*this);
      for (int i = 0; i < sz; i++) {
          temp[i] = pMem[i]*val;
      }
      return temp;
  }

  // векторные операции
  TDynamicVector operator+(const TDynamicVector& v)
  {
      if (this->sz != v.sz)
          throw exception("Error");
      TDynamicVector temp(v);
      for (int i = 0; i < sz; i++) {
          temp[i] = pMem[i] + v.pMem[i];
      }
      return temp;
  }
  TDynamicVector operator-(const TDynamicVector& v)
  {
      if (this->sz != v.sz)
          throw exception("Error");
      TDynamicVector temp(v);
      for (int i = 0; i < sz; i++) {
          temp[i] = pMem[i] - v.pMem[i];
      }
      return temp;
  }
  T operator*(const TDynamicVector& v) //noexcept(noexcept(T()))
  {
      if (sz != v.sz) {
          throw "Error";
      }
      T temp{};
      for (int i = 0; i < sz; i++) {
          temp = temp +( pMem[i] * v.pMem[i]);
      }
      return temp;
  }

  friend void swap(TDynamicVector& lhs, TDynamicVector& rhs) noexcept
  {
    std::swap(lhs.sz, rhs.sz);
    std::swap(lhs.pMem, rhs.pMem);
  }

  // ввод/вывод
  friend istream& operator>>(istream& istr, TDynamicVector& v)
  {
    for (size_t i = 0; i < v.sz; i++)
      istr >> v.pMem[i]; // требуется оператор>> для типа T
    return istr;
  }
  friend ostream& operator<<(ostream& ostr, const TDynamicVector& v)
  {
    for (size_t i = 0; i < v.sz; i++)
      ostr << v.pMem[i] << ' '; // требуется оператор<< для типа T
    return ostr;
  }
};


// Динамическая матрица - 
// шаблонная матрица на динамической памяти
template<typename T>
class TDynamicMatrix : private TDynamicVector<TDynamicVector<T>>
{
  using TDynamicVector<TDynamicVector<T>>::pMem;
  using TDynamicVector<TDynamicVector<T>>::sz;
public:
  TDynamicMatrix(size_t s = 1) : TDynamicVector<TDynamicVector<T>>(s)
  {
    if (sz == 0 || sz > MAX_MATRIX_SIZE)
      throw out_of_range("Размер матрицы больше нуля или больше MAX_MATRIX_SIZE");
    for (size_t i = 0; i < sz; i++)
      pMem[i] = TDynamicVector<T>(sz);
  }

  using TDynamicVector<TDynamicVector<T>>::operator[];

  // сравнение
  bool operator==(const TDynamicMatrix& m) const noexcept
  {
      if (this->sz != m.sz)
          return 0;
      for (size_t i = 0; i < sz; i++)
          if (pMem[i] != m.pMem[i])
              return 0;
      return 1;
  }
  //неравенство
  bool operator!=(const TDynamicMatrix& m) const noexcept
  {
      if (this->sz != m.sz)
          return 1;
      for (size_t i = 0; i < sz; i++)
          if (pMem[i] != m.pMem[i])
              return 1;
      return 0;
  }
  // матрично-скалярные операции
  TDynamicMatrix operator*(const T& val)
  {
      TDynamicMatrix res(*this);
      for (size_t i = 0; i < sz; i++)
          res.pMem[i] = res.pMem[i] * val;
      return res;
  }

  // матрично-векторные операции
  TDynamicVector<T> operator*(const TDynamicVector<T>& v)
  {
      if (sz != v.sz)
          throw exception("Error");
      TDynamicVector<T> res(sz);
      for (size_t i = 0; i < sz; i++)
          res[i] = pMem[i] * v;
      return res;
  }

  // матрично-матричные операции
  TDynamicMatrix operator+(const TDynamicMatrix& m)
  {
      if (sz != m.sz)
          throw "Разный размер матриц!";
      TDynamicMatrix res(*this);
      for (size_t i = 0; i < sz; i++)
          res.pMem[i] = pMem[i] + m.pMem[i];
      return res;
  }
  TDynamicMatrix operator-(const TDynamicMatrix& m)
  {
      if (sz != m.sz)
          throw "Разный размер матриц!";
      TDynamicMatrix res(*this);
      for (size_t i = 0; i < sz; i++)
          res.pMem[i] = pMem[i] - m.pMem[i];
      return res;
  }
  TDynamicMatrix operator*(const TDynamicMatrix& m)
  {
      if (sz != m.sz)
          throw "Разный размер матриц!";
      TDynamicMatrix res(*this);
      for (size_t i = 0; i < sz; i++)
          for (size_t j = 0; j < sz; j++)
              for (size_t k = 0; k < sz; k++)
                  res.pMem[i][j] += pMem[i][k] * m.pMem[k][j];
      return res;
  }

  // ввод/вывод
  friend istream& operator>>(istream& istr, TDynamicMatrix& v)
  {
      for (size_t i = 0; i < v.sz; i++)
          for (size_t j = 0; j < v.sz; j++)
              istr >> v[i][j];
      return istr;
  }
  friend ostream& operator<<(ostream& ostr, const TDynamicMatrix& v)
  {
      for (size_t i = 0; i < v.sz; i++)
      {
          for (size_t j = 0; j < v.sz; j++)
          {
              ostr << v[i][j] << " ";
          }
          ostr << endl;
      }
      return ostr;
  }

  size_t size() 
  { 
      return sz; 
  }
  T& at(int a, int b) 
  {
      if (((a < 0) || (b < 0))||((a>sz)||(b>sz)))
          throw "Error";
      return pMem[a][b];
  }

};
#endif
