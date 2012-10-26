#ifndef __TWODARRAY_H__
#define __TWODARRAY_H__


class TwoDArray {
 private:
  int** theArray;
  int row;
  int column;
  int defaultValue;
  
 public:
  TwoDArray(int r, int c, int def);
  ~TwoDArray();
  void insert(int r, int c, int val);
  int access(int r, int c);
  void remove(int r, int c);
  void print();
  int getNumRows();
  int getNumCols();
};

#endif
