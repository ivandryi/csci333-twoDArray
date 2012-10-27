#include "gtest/gtest.h"
#include "../src/TwoDArray/TwoDArray.h"
#include "../src/VVTwoDArray/VVTwoDArray.h"
#include "../src/STwoDArray/STwoDArray.h"

TEST(TwoDArray, CreateDestroy) {
  TwoDArray<int>* array1 = new TwoDArray<int>(5, 3, 0);
  //TwoDArray<int>* array2 = new TwoDArray<int>(-5, 4, 78); // inserting out of the range aborts the program
  delete array1;
  //delete array2;
}

TEST(VVTwoDArray, CreateDestroy) {
  VVTwoDArray<int> array = VVTwoDArray<int>(5, 3, 0);
}

TEST (STwoDArray, CreateDestroy) {
  STwoDArray<int>* array = new STwoDArray<int>(3, 3, 0);
  delete array;
}

TEST(TwoDArray, InsertAccess) {
  TwoDArray<int>* array1 = new TwoDArray<int>(5, 3, 0);
  array1->insert(5, 3, 45);
  //array1->insert(6, 1, 67); //inserting out of the range aborts the program
  // array1->insert(-7, 4, 90);
  array1->insert(1, 1, 4);
  EXPECT_EQ(4, array1->access(1, 1));
  EXPECT_EQ(45, array1->access(5, 3));
  EXPECT_EQ(0, array1->access(1, 2));
  array1->insert(1, 1, 6);
  EXPECT_EQ(6, array1->access(1, 1));
  delete array1;
}

TEST(VVTwoDArray, InsertAccess) {
  VVTwoDArray<int> array = VVTwoDArray<int>(5, 3, 0);
  array.insert(5, 3, 45);
  //array.insert(6, 1, 67); //inserting out of the range aborts the program
  //array.insert(-6, 5, 56);
  EXPECT_EQ(45, array.access(5, 3));
  array.insert(5, 1, 67);
  EXPECT_EQ(67, array.access(5, 1));
  array.insert(5, 2, 23);
  EXPECT_EQ(23, array.access(5, 2));
  array.insert(5, 2, 4);
  EXPECT_EQ(4, array.access(5, 2));
  EXPECT_EQ(0, array.access(2, 3));
}

TEST(STwoDArray, InserAccess) {
  STwoDArray<int>* array = new STwoDArray<int>(3, 3, 0);
  array->insert(3, 3, 1);
  EXPECT_EQ(1, array->access(3, 3));
  array->insert(2, 3, 2);
  EXPECT_EQ(2, array->access(2, 3));
  EXPECT_EQ(0, array->access(1, 1));
  array->insert(3, 3, 11);
  EXPECT_EQ(11, array->access(3, 3));
}

TEST(TwoDArray, Delete) {
  TwoDArray<int>* array = new TwoDArray<int>(3, 3, 0);
  array->insert(1, 1, 4);
  array->insert(1, 3, 5);
  array->remove(1, 1);
  array->remove(1, 3);
  EXPECT_EQ(0, array->access(1, 1));
  EXPECT_EQ(0, array->access(1, 3));
}

TEST(VVTwoDArray, Delete) {
  VVTwoDArray<int> array = VVTwoDArray<int>(3, 3, 0);
  array.insert(1, 1, 4);
  array.insert(1, 3, 5);
  array.remove(1, 1);
  array.remove(1, 3);
  EXPECT_EQ(0, array.access(1, 1));
  EXPECT_EQ(0, array.access(1, 3));
}

TEST(STwoDArray, Delete) {
  STwoDArray<int>* array = new STwoDArray<int>(3, 3, 0);
  array->insert(1, 1, 4);
  array->insert(1, 3, 5);
  array->remove(1, 1);
  array->remove(1, 3);
  EXPECT_EQ(0, array->access(1, 1));
  EXPECT_EQ(0, array->access(1, 3));
}

TEST(TwoDArray, ColRows) {
  TwoDArray<int>* array = new TwoDArray<int>(3, 4, 0);
  EXPECT_EQ(3, array->getNumRows());
  EXPECT_EQ(4, array->getNumCols());
 }

TEST(STwoDArray, ColRows) {
  STwoDArray<int>* array = new STwoDArray<int>(3, 4, 0);
  EXPECT_EQ(3, array->getNumRows());
  EXPECT_EQ(4, array->getNumCols());
 }

TEST(VVTwoDArray, ColRows) {
  VVTwoDArray<int> array = VVTwoDArray<int>(3, 4, 0);
  EXPECT_EQ(3, array.getNumRows());
  EXPECT_EQ(4, array.getNumCols());
 }
