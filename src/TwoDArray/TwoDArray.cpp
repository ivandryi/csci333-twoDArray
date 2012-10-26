#include "TwoDArray.h"
#include <iostream>
#include <assert.h>

TwoDArray::TwoDArray(int r, int c, int def){
  assert (r > 0 && c > 0);
  defaultValue = def;
  row = r;
  column = c;
  theArray = new int* [row];
  for (int i = 0; i < row; i++) {
    theArray[i] = new int[column];
  }
  for (int i = 0; i < row; i++) {
    for (int j = 0; j < column; j++)
      theArray[i][j] = defaultValue;
  }
}

TwoDArray::~TwoDArray() {
  for (int i = 0; i < row; i++) {
    delete [] theArray[i];
  }
  delete [] theArray;
}

void TwoDArray::insert(int r , int c, int val) {
  assert (r > 0 && c > 0 && r <= row && c <= column);
  theArray[r - 1][c - 1] = val;
}

int TwoDArray::access(int r, int c) {
  assert (r > 0 && c > 0 && r <= row && c <= column);
  return theArray[r - 1][c - 1];
}

void TwoDArray::remove(int r, int c) {
  assert(r > 0 && c > 0 && r <=row && c <=column);
  theArray[r - 1][c - 1] = defaultValue;
}

void TwoDArray::print() {
  for (int i = 0; i < row; i++) {
    std::cout << "\n" << std::endl;
    for (int j = 0; j < column; j++)
      std::cout << theArray[i][j] << " ";
  }
}

int TwoDArray::getNumRows() {
  return row;
}

int TwoDArray::getNumCols() {
  return column;
}
