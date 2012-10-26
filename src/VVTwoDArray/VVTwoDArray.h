#ifndef __VVTWODARRAY_H
#define __VVTWODARRAY_H

#include <vector>

class VVTwoDArray {
 private:
  std::vector<std::vector<int> > theArray;
  int row;
  int column;
  int defaultValue;
 public:
  VVTwoDArray(int r, int c, int def);
  ~VVTwoDArray();
  void insert(int r, int c, int val);
  int access(int r, int c);
  void remove(int r, int c);
  void print();
  int getNumRows();
  int getNumCols();
};

#endif
