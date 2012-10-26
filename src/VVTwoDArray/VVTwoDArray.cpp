#include "VVTwoDArray.h"
#include <iostream>
#include <assert.h>

VVTwoDArray::VVTwoDArray(int r, int c, int def) {
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

VVTwoDArray::~VVTwoDArray() {
  std::cout << "Destructor call" << std::endl;
}

void VVTwoDArray::insert(int r, int c, int val) {
  assert (r > 0 && c > 0 && r <= row && c <= column);
  theArray[r - 1][c - 1] = val;
}

int  VVTwoDArray::access(int r, int c) {
  assert(r > 0 && c > 0 && r <= row && c <= column);
  return theArray[r - 1][c - 1];
}

void VVTwoDArray::remove(int r, int c) {
  assert (r > 0 && c > 0 && r <=row && c <= column);
  theArray[r - 1][c - 1] = defaultValue;
}

void VVTwoDArray::print() {
  for (int i = 0; i < row; i++) {
    std::cout << "\n" << std::endl;
    for (int j = 0; j < column; j++)
      std::cout << theArray[i][j];
  }
}

int VVTwoDArray::getNumRows() {
  return row;
}

int VVTwoDArray::getNumCols() {
  return column;
}
