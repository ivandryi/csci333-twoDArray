#include "STwoDArray.h"
#include <iostream>
#include <assert.h>

Node::Node(int r, int c, int val) {
  row = r;
  column = c;
  value = val;
  rowNext = 0;
  columnNext = 0;
}

int Node::getValue() {
  return value;
}

int Node::getRow(){
  return row;
}

int Node::getColumn(){
  return column;
}

Node* Node::getRowNext() {
  return rowNext;
}

Node* Node::getColumnNext() {
  return columnNext;
}

void Node::setRowNext(Node* n) {
  rowNext = n;
}

void Node::setColumnNext(Node* n) {
  columnNext = n;
}

STwoDArray::STwoDArray(int r, int c, int def) {
  assert (r > 0 && c > 0);
  numRow = r;
  numColumn = c;
  defaultValue = def;
  rows = new Node* [numRow];
  columns = new Node* [numColumn];
  for (int i = 0; i < numRow; i++)
    rows[i] = 0;
  for (int j = 0; j < numColumn; j++)
    columns[j] = 0;
}

STwoDArray::~STwoDArray() {
  for (int i = 0; i < numColumn; i++) {
    Node* curr = columns[i];
    while (curr != 0) {
      Node* temp = curr->getRowNext();
      delete curr;
      curr = temp;
    }
  }
  delete[] rows;
  delete[] columns;
}

void STwoDArray::insert(int r, int c, int val) {
  assert (r > 0 && c > 0 && r <= numRow && c <= numColumn);
  Node* newNode = new Node(r - 1, c - 1, val);
  if (rows[r - 1] == 0) {
    rows[r - 1] = newNode;
  } else {
    Node* currRow = rows[r - 1];
    Node* prevRow = rows[r - 1];
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
    Node* currCol = columns[c - 1];
    Node* prevCol = columns[c - 1];
    if (currCol->getRow() > (r - 1)) {
      newNode->setRowNext(currCol);
      columns[c - 1] = newNode;
    } else if (currCol->getRow() == (r - 1)) {
      Node* temp = currCol;
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
	Node* temp = currCol;
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

int STwoDArray::access(int r, int c) {
  assert (r > 0 && c > 0 && r <= numRow && c <= numColumn);
  Node* currRow = rows[r - 1];
  while (currRow != 0 && currRow->getColumn() < (c - 1)) {
    currRow = currRow->getColumnNext();
  }
  return (currRow == 0 || currRow->getColumn() > (c - 1)) ? defaultValue : (currRow->getValue());
}

void STwoDArray::remove(int r, int c) {
  assert (r > 0 && c > 0 && r <= numRow && c <= numColumn);
  assert (rows[r - 1] != 0 || columns[c - 1] != 0);
  Node* currRow = rows[r - 1];
  Node* currColumn = columns[c - 1];
  if (currRow->getColumn() == (c - 1)) {
    rows[r - 1] = currRow->getColumnNext();
  } else {
    while (currRow->getColumnNext() != 0 && currRow->getColumnNext()->getColumn() < (c - 1)) {
      currRow = currRow->getColumnNext();
    }
    currRow->setColumnNext(currRow->getColumnNext()->getColumnNext());
  }
  if (currColumn->getRow() == (r - 1)) {
    Node* temp = currColumn;
    columns[c - 1] = currColumn->getRowNext();
    delete temp;
  } else {
    while (currColumn->getRowNext() != 0 && currColumn->getRowNext()->getRow() < (r - 1)) {
      currColumn = currColumn->getRowNext();
    }
    Node* temp = currColumn->getRowNext();
    currColumn->setRowNext(temp->getRowNext());
    delete temp;
  }
}

void STwoDArray::print() {
  for (int i = 0; i < numRow; i++ ){
    Node* currRow = rows[i];
    for (int j = 0; j < numColumn; j++) {
      while (currRow != 0) {
	std::cout << currRow->getValue() << " [" << currRow->getRow() + 1 << "," << "] , ";
	currRow = currRow->getColumnNext();
      }
      std::cout << std::endl;
    }
  }
}

int STwoDArray::getNumRows() {
  return numRow;
}

int STwoDArray::getNumCols() {
  return numColumn;
}
