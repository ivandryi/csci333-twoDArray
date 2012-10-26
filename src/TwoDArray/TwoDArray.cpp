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
      theArray[i,j] = defaultValue;
  }
}

TwoDArray::~TwoDArray() {

}

void TwoDArray::insert(int r , int c, int val) {

}

int TwoDArray::access(int r, int c) {

}

void TwoDArray::remove(int r, int c) {

}

void TwoDArray::print() {

}

int TwoDArray::getNumRows() {

}

int TwoDArray::getNumCols() {

}
