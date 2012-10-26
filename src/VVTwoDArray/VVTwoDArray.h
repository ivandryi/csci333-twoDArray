#ifndef __VVTWODARRAY_H
#define __VVTWODARRAY_H

#include <vector>

template <typename T>
class VVTwoDArray {
 private:
  std::vector<std::vector<T> > theArray;
  int row;
  int column;
  T defaultValue;
 public:
  VVTwoDArray<T>(int r, int c, T def);
  ~VVTwoDArray<T>();
  void insert(int r, int c, T val);
  T access(int r, int c);
  void remove(int r, int c);
  void print();
  int getNumRows();
  int getNumCols();
};

#endif
