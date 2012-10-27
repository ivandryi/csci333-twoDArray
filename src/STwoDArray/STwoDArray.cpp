#include "STwoDArray.h"
#include <iostream>
#include <assert.h>

template <typename T>
Node<T>::Node(int r, int c, T val) {
  row = r;
  column = c;
  value = val;
  rowNext = 0;
  columnNext = 0;
}

template <typename T>
T Node<T>::getValue() {
  return value;
}

template <typename T>
int Node<T>::getRow(){
  return row;
}

template <typename T>
int Node<T>::getColumn(){
  return column;
}

template <typename T>
Node<T>* Node<T>::getRowNext() {
  return rowNext;
}

template <typename T>
Node<T>* Node<T>::getColumnNext() {
  return columnNext;
}

template <typename T>
void Node<T>::setRowNext(Node<T>* n) {
  rowNext = n;
}

template <typename T>
void Node<T>::setColumnNext(Node<T>* n) {
  columnNext = n;
}

template <typename T>
STwoDArray<T>::STwoDArray(int r, int c, T def) {
  assert (r > 0 && c > 0);
  numRow = r;
  numColumn = c;
  defaultValue = def;
  rows = new Node<T>* [numRow];
  columns = new Node<T>* [numColumn];
  for (int i = 0; i < numRow; i++)
    rows[i] = 0;
  for (int j = 0; j < numColumn; j++)
    columns[j] = 0;
}

template <typename T>
STwoDArray<T>::~STwoDArray() {
  for (int i = 0; i < numColumn; i++) {
    Node<T>* curr = columns[i];
    while (curr != 0) {
      Node<T>* temp = curr->getRowNext();
      delete curr;
      curr = temp;
    }
  }
  delete[] rows;
  delete[] columns;
}

template <typename T>
void STwoDArray<T>::insert(int r, int c, T val) {
  assert (r > 0 && c > 0 && r <= numRow && c <= numColumn);
  Node<T>* newNode = new Node<T>(r - 1, c - 1, val);
  if (rows[r - 1] == 0) {
    rows[r - 1] = newNode;
  } else {
    Node<T>* currRow = rows[r - 1];
    Node<T>* prevRow = rows[r - 1];
    if (currRow->getColumn() > (c - 1)) {
      newNode->setColumnNext(currRow);
      rows[r - 1] = newNode;
    } else if (currRow->getColumn() == (c - 1)) {
      newNode->setColumnNext(currRow->getColumnNext());
      rows[r - 1] = newNode;
    } else {
      while(currRow->getColumnNext() != 0 && currRow->getColumnNext()->getColumn() < (c - 1)){
	prevRow = currRow;
	currRow = currRow->getColumnNext();
      }
      if (currRow->getColumnNext() != 0 && currRow->getColumnNext()->getColumn() == (c - 1)) {
	currRow = currRow->getColumnNext();
	newNode->setColumnNext(currRow->getColumnNext());
	prevRow->setColumnNext(newNode);
      } else {
	newNode->setColumnNext(currRow->getColumnNext());
	currRow->setColumnNext(newNode);
      }
    }
  }
  if (columns[c - 1] == 0){
    columns[c - 1] = newNode;
  } else {
    Node<T>* currCol = columns[c - 1];
    Node<T>* prevCol = columns[c - 1];
    if (currCol->getRow() > (r - 1)) {
      newNode->setRowNext(currCol);
      columns[c - 1] = newNode;
    } else if (currCol->getRow() == (r - 1)) {
      Node<T>* temp = currCol;
      newNode->setRowNext(currCol->getRowNext());
      columns[c - 1] = newNode;
      delete temp;
    } else {
      while (currCol->getRowNext() != 0 && currCol->getRowNext()->getRow() < (r - 1)) {
	prevCol = currCol;
	currCol = currCol->getRowNext();
      }
      if (currCol->getRowNext() != 0 && currCol->getRowNext()->getRow() == (r - 1)) {
	currCol = currCol->getRowNext();
	Node<T>* temp = currCol;
	newNode->setRowNext(currCol->getRowNext());
	prevCol->setRowNext(newNode);
	delete temp;
      } else {
	newNode->setRowNext(currCol->getRowNext());
	currCol->setRowNext(newNode);
      }
    }
  }
}

template <typename T>
T STwoDArray<T>::access(int r, int c) {
  assert (r > 0 && c > 0 && r <= numRow && c <= numColumn);
  Node<T>* currRow = rows[r - 1];
  while (currRow != 0 && currRow->getColumn() < (c - 1)) {
    currRow = currRow->getColumnNext();
  }
  return (currRow == 0 || currRow->getColumn() > (c - 1)) ? defaultValue : (currRow->getValue());
}

template <typename T>
void STwoDArray<T>::remove(int r, int c) {
  assert (r > 0 && c > 0 && r <= numRow && c <= numColumn);
  assert (rows[r - 1] != 0 || columns[c - 1] != 0);
  Node<T>* currRow = rows[r - 1];
  Node<T>* currColumn = columns[c - 1];
  if (currRow->getColumn() == (c - 1)) {
    rows[r - 1] = currRow->getColumnNext();
  } else {
    while (currRow->getColumnNext() != 0 && currRow->getColumnNext()->getColumn() < (c - 1)) {
      currRow = currRow->getColumnNext();
    }
    currRow->setColumnNext(currRow->getColumnNext()->getColumnNext());
  }
  if (currColumn->getRow() == (r - 1)) {
    Node<T>* temp = currColumn;
    columns[c - 1] = currColumn->getRowNext();
    delete temp;
  } else {
    while (currColumn->getRowNext() != 0 && currColumn->getRowNext()->getRow() < (r - 1)) {
      currColumn = currColumn->getRowNext();
    }
    Node<T>* temp = currColumn->getRowNext();
    currColumn->setRowNext(temp->getRowNext());
    delete temp;
  }
}

template <typename T>
void STwoDArray<T>::print() {
  for (int i = 0; i < numRow; i++ ){
    Node<T>* currRow = rows[i];
    for (int j = 0; j < numColumn; j++) {
      while (currRow != 0) {
	std::cout << currRow->getValue() << " [" << currRow->getRow() + 1 << "," << "] , ";
	currRow = currRow->getColumnNext();
      }
      std::cout << std::endl;
    }
  }
}

template <typename T>
int STwoDArray<T>::getNumRows() {
  return numRow;
}

template <typename T>
int STwoDArray<T>::getNumCols() {
  return numColumn;
}

template class STwoDArray<int>;
template class STwoDArray<double>;
