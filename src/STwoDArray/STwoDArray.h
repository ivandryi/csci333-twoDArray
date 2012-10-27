#ifndef __STWODARRAY_H__
#define __STWODARRAY_H__

template <typename T>
class Node {
 private:
  int column;
  int row;
  T value;
  Node<T>* rowNext;
  Node<T>* columnNext;
 public:
  Node<T>(int r, int c, T val);
  T getValue();
  int getRow();
  int getColumn();
  Node<T>* getRowNext();
  Node<T>* getColumnNext();
  void setRowNext(Node<T>* n);
  void setColumnNext(Node<T>* n);
};

template <typename T>
class STwoDArray {
 private:
  Node<T>** rows;
  Node<T>** columns;
  int numColumn;
  int numRow;
  T defaultValue;
 public:
  STwoDArray<T>(int r, int c, T def);
  ~STwoDArray<T>();
  void insert(int r, int c, T val);
  T access(int r, int c);
  void remove(int r, int c);
  void print();
  int getNumRows();
  int getNumCols();
};

#endif
