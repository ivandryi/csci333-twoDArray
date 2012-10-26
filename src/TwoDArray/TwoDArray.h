#ifndef __TWODARRAY_H__
#define __TWODARRAY_H__

template <typename T>
class TwoDArray {
 private:
  T** theArray;
  int row;
  int column;
  T defaultValue;
  
 public:
  TwoDArray<T>(int r, int c, T def);
  ~TwoDArray<T>();
  void insert(int r, int c, T val);
  T access(int r, int c);
  void remove(int r, int c);
  void print();
  int getNumRows();
  int getNumCols();
};

#endif
