#include "VVTwoDArray.h"
#include <iostream>
#include <assert.h>

template <typename T>
VVTwoDArray<T>::VVTwoDArray(int r, int c, T def) {
  assert (r > 0 && c > 0);
  defaultValue = def;
  row = r;
  column = c;
  theArray.resize(row);
  for (int i = 0; i < row; i++) {
    theArray[i].resize(column);
  }
  for (int i = 0; i < row; i++)
    for (int j = 0; j < column; j++)
      theArray[i][j] = defaultValue;
}

template <typename T>
VVTwoDArray<T>::~VVTwoDArray() {
  std::cout << "Destructor call" << std::endl;
}

template <typename T>
void VVTwoDArray<T>::insert(int r, int c, T val) {
  assert (r > 0 && c > 0 && r <= row && c <= column);
  theArray[r - 1][c - 1] = val;
}

template <typename T>
T  VVTwoDArray<T>::access(int r, int c) {
  assert(r > 0 && c > 0 && r <= row && c <= column);
  return theArray[r - 1][c - 1];
}

template <typename T>
void VVTwoDArray<T>::remove(int r, int c) {
  assert (r > 0 && c > 0 && r <=row && c <= column);
  theArray[r - 1][c - 1] = defaultValue;
}

template <typename T>
void VVTwoDArray<T>::print() {
  for (int i = 0; i < row; i++) {
    std::cout << "\n" << std::endl;
    for (int j = 0; j < column; j++)
      std::cout << theArray[i][j];
  }
}

template <typename T>
int VVTwoDArray<T>::getNumRows() {
  return row;
}

template <typename T>
int VVTwoDArray<T>::getNumCols() {
  return column;
}

template class VVTwoDArray<int>;
template class VVTwoDArray<double>;
