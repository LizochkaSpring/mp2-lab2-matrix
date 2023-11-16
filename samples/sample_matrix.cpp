// ННГУ, ИИТММ, Курс "Алгоритмы и структуры данных"
//
// Copyright (c) Сысоев А.В.
//
// Тестирование матриц

#include <iostream>
#include "tmatrix.h"
//---------------------------------------------------------------------------
//посчитать по времени и сравнить их операции при разном размере.

TDynamicVector<int> rand_vector(TDynamicVector<int> a, int n) {
    for (int i = 0; i < n; i++) {
        a[i] = 0 + rand() % 11;
    }
    return a;
}
TDynamicMatrix<int> rand_matrix(TDynamicMatrix<int> b, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
        {
            b[i][j] = 0 + rand() % 12;
        }
    }
    return b;
}


void main()
{
  /*TDynamicMatrix<int> a(5), b(5), c(5);
  int i, j;

  setlocale(LC_ALL, "Russian");
  srand(time(NULL));

  cout << "Тестирование класс работы с матрицами"
    << endl;
  for (i = 0; i < 5; i++)
    for (j = i; j < 5; j++ )
    {
      a[i][j] =  i * 10 + j;
      b[i][j] = (i * 10 + j) * 100;
    }
  c = a + b;
  cout << "Matrix a = " << endl << a << endl;
  cout << "Matrix b = " << endl << b << endl;
  cout << "Matrix c = a + b" << endl << c << endl;*/

    setlocale(LC_ALL, "Russian");
    int n;
    time_t start, end;
    cout << "Тестирование класс работы с матрицами"<< endl;
    cout << "Введите размер матрицы: ";
    cin >> n;

    double x = 0;
    TDynamicMatrix<int> a(n), b(n), c(n);
    a = rand_matrix(a, n);
    b = rand_matrix(b, n);
    time(&start);
    c = a + b;
    time(&end);
    x = (x + (double)(end - start) / CLOCKS_PER_SEC) * 1000;
    cout << "O(n^2) - " << x << endl;
    

    x = 0;
    TDynamicMatrix<int> aa(n), bb(n), cc(n);
    aa = rand_matrix(a, n);
    bb = rand_matrix(b, n);
    time(&start);
    cc = aa * bb;
    time(&end);
    x = (x + (double)(end - start) / CLOCKS_PER_SEC) * 1000;
    cout << "O(n^3) - " << x << endl;
    cout << "\n";

    int k;
    cout << "Тестирование класс работы с векторами" << endl;
    cout << "Введите размер вектора: ";
    cin >> k;

    double g = 0;
    TDynamicVector<int> arr1(k), arr2(k), arr3(k);
    arr1 = rand_vector(arr1, k);
    arr2 = rand_vector(arr2, k);
    time(&start);
    arr3 = arr1 + arr2;
    time(&end);
    g = (g + (double)(end - start) / CLOCKS_PER_SEC) * 1000;
    cout << "O(n^2) - " << g << endl;


    g = 0;
    TDynamicVector<int> arr11(k), arr22(k), arr33(k);
    arr11 = rand_vector(arr1, k);
    arr22 = rand_vector(arr2, k);
    time(&start);
    arr33 = arr11 * arr22;
    time(&end);
    g = (g + (double)(end - start) / CLOCKS_PER_SEC) * 1000;
    cout << "O(n^3) - " << g << endl;
}
//---------------------------------------------------------------------------
