#ifndef __STWODARRAY_H__
#define __STWODARRAY_H__

class Node {
 private:
  int column;
  int row;
  int value;
  Node* rowNext;
  Node* columnNext;
 public:
  Node(int r, int c, int val);
  int getValue();
  int getRow();
  int getColumn();
  Node* getRowNext();
  Node* getColumnNext();
  void setRowNext(Node* n);
  void setColumnNext(Node* n);
};

class STwoDArray {
 private:
  Node** rows;
  Node** columns;
  int numColumn;
  int numRow;
  int defaultValue;
 public:
  STwoDArray(int r, int c, int def);
  ~STwoDArray();
  void insert(int r, int c, int val);
  int access(int r, int c);
  void remove(int r, int c);
  void print();
  int getNumRows();
  int getNumCols();
};

#endif
