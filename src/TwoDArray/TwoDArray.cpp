#include "TwoDArray.h"
#include <iostream>
#include <assert.h>

template <typename T>
TwoDArray<T>::TwoDArray(int r, int c, T def){
  assert (r > 0 && c > 0);
  defaultValue = def;
  row = r;
  column = c;
  theArray = new T* [row];
  for (int i = 0; i < row; i++) {
    theArray[i] = new T[column];
  }
  for (int i = 0; i < row; i++) {
    for (int j = 0; j < column; j++)
      theArray[i][j] = defaultValue;
  }
}

template <typename T>
TwoDArray<T>::~TwoDArray() {
  for (int i = 0; i < row; i++) {
    delete [] theArray[i];
  }
  delete [] theArray;
}

template <typename T>
void TwoDArray<T>::insert(int r , int c, T val) {
  assert (r > 0 && c > 0 && r <= row && c <= column);
  theArray[r - 1][c - 1] = val;
}

template <typename T>
T TwoDArray<T>::access(int r, int c) {
  assert (r > 0 && c > 0 && r <= row && c <= column);
  return theArray[r - 1][c - 1];
}

template <typename T>
void TwoDArray<T>::remove(int r, int c) {
  assert(r > 0 && c > 0 && r <=row && c <=column);
  theArray[r - 1][c - 1] = defaultValue;
}

template <typename T>
void TwoDArray<T>::print() {
  for (int i = 0; i < row; i++) {
    std::cout << "\n" << std::endl;
    for (int j = 0; j < column; j++)
      std::cout << theArray[i][j] << " ";
  }
}

template <typename T>
int TwoDArray<T>::getNumRows() {
  return row;
}

template <typename T>
int TwoDArray<T>::getNumCols() {
  return column;
}

template class TwoDArray<int>;
template class TwoDArray<double>;
template class TwoDArray<std::string>;
