#include "gtest/gtest.h"
#include "../src/TwoDArray/TwoDArray.h"
#include "../src/VVTwoDArray/VVTwoDArray.h"
#include "../src/STwoDArray/STwoDArray.h"

TEST(TwoDArray, CreateDestroy) {
  TwoDArray<int>* array1 = new TwoDArray<int>(5, 3, 0);
  TwoDArray<double>* array2 = new TwoDArray<double>(5, 3, 0.0);
  TwoDArray<std::string>* array3 = new TwoDArray<std::string>(5, 3, "null");
  //TwoDArray<int>* array4 = new TwoDArray<int>(-5, 4, 78); // inserting out of the range aborts the program
  delete array1;
  delete array2;
  delete array3;
}

TEST(VVTwoDArray, CreateDestroy) {
  VVTwoDArray<int> array = VVTwoDArray<int>(5, 3, 0);
  VVTwoDArray<double> array2 = VVTwoDArray<double>(5, 3, 0.0);
  VVTwoDArray<std::string> array3 = VVTwoDArray<std::string>(5, 3, "null");
}

TEST (STwoDArray, CreateDestroy) {
  STwoDArray<int>* array = new STwoDArray<int>(3, 3, 0);
  STwoDArray<double>* array2 = new STwoDArray<double>(5, 3, 0.0);
  STwoDArray<std::string>* array3 = new STwoDArray<std::string>(5, 3, "null");
  delete array;
  delete array2;
  delete array3;
}

TEST(TwoDArray, InsertAccess) {
  TwoDArray<int>* array1 = new TwoDArray<int>(5, 3, 0);
  TwoDArray<double>* array2 = new TwoDArray<double>(5, 3, 0.0);
  TwoDArray<std::string>* array3 = new TwoDArray<std::string>(5, 3, "null");
  array2->insert(5, 3, 45.5);
  EXPECT_EQ(45.5, array2->access(5, 3));
  EXPECT_EQ(0.0,  array2->access(1, 1));
  array3->insert(5, 3, "hello");
  EXPECT_EQ("hello", array3->access(5, 3));
  EXPECT_EQ("null", array3->access(1, 1));
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
  delete array2;
  delete array3;
}

TEST(VVTwoDArray, InsertAccess) {
  VVTwoDArray<int> array = VVTwoDArray<int>(5, 3, 0);
  VVTwoDArray<double> array2 = VVTwoDArray<double>(5, 3, 0.0);
  VVTwoDArray<std::string> array3 = VVTwoDArray<std::string>(5, 3, "null");
  array2.insert(5, 3, 45.5);
  EXPECT_EQ(45.5,  array2.access(5, 3));
  EXPECT_EQ(0.0, array2.access(1, 1));
  array3.insert(5, 3, "hello");
  EXPECT_EQ("hello", array3.access(5, 3));
  EXPECT_EQ("null", array3.access(1, 1));
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
  STwoDArray<double>* array2 = new STwoDArray<double>(3, 3, 0.0);
  STwoDArray<std::string>* array3 = new STwoDArray<std::string>(3, 3, "null");
  array2->insert(3, 3, 45.5);
  EXPECT_EQ(45.5,  array2->access(3, 3));
  EXPECT_EQ(0.0, array2->access(1, 1));
  array3->insert(3, 3, "hello");
  EXPECT_EQ("hello", array3->access(3, 3));
  EXPECT_EQ("null", array3->access(1, 1));
  array->insert(3, 3, 1);
  EXPECT_EQ(1, array->access(3, 3));
  array->insert(2, 3, 2);
  EXPECT_EQ(2, array->access(2, 3));
  EXPECT_EQ(0, array->access(1, 1));
  array->insert(3, 3, 11);
  EXPECT_EQ(11, array->access(3, 3));
  delete array, array2, array3;
}

TEST(TwoDArray, Delete) {
  TwoDArray<int>* array = new TwoDArray<int>(3, 3, 0);
  TwoDArray<double>* array2 = new TwoDArray<double>(3, 3, 0.0);
  TwoDArray<std::string>* array3 = new TwoDArray<std::string>(3, 3, "null");
  array2->insert(1, 1, 3.5);
  array2->remove(1, 1);
  EXPECT_EQ(0.0, array2->access(1, 1));
  array3->insert(1, 1, "hello");
  array3->remove(1, 1);
  EXPECT_EQ("null", array3->access(1, 1));
  array->insert(1, 1, 4);
  array->insert(1, 3, 5);
  array->remove(1, 1);
  array->remove(1, 3);
  EXPECT_EQ(0, array->access(1, 1));
  EXPECT_EQ(0, array->access(1, 3));
  array->remove(1, 1); //deleting non-existing element
  delete array, array2, array3;
}

TEST(VVTwoDArray, Delete) {
  VVTwoDArray<int> array = VVTwoDArray<int>(3, 3, 0);
  VVTwoDArray<double> array2 = VVTwoDArray<double>(3, 3, 0.0);
  VVTwoDArray<std::string> array3 = VVTwoDArray<std::string>(3, 3, "null");
  array2.insert(1, 1, 45.5);
  array2.remove(1, 1);
  EXPECT_EQ(0.0, array2.access(1, 1));
  array3.insert(1, 1, "hello");
  array3.remove(1, 1);
  EXPECT_EQ("null", array3.access(1, 1));
  array.insert(1, 1, 4);
  array.insert(1, 3, 5);
  array.remove(1, 1);
  array.remove(1, 3);
  EXPECT_EQ(0, array.access(1, 1));
  EXPECT_EQ(0, array.access(1, 3));
  array.remove(1, 1); //deleting non existing element
}

TEST(STwoDArray, Delete) {
  STwoDArray<int>* array = new STwoDArray<int>(3, 3, 0);
  STwoDArray<double>* array2 = new STwoDArray<double>(3, 3, 0.0);
  STwoDArray<std::string>* array3 = new STwoDArray<std::string>(3, 3, "null");
  array2->insert(1, 1, 4.5);
  array2->remove(1, 1);
  EXPECT_EQ(0.0, array2->access(1, 1));
  array3->insert(1, 1, "hello");
  array3->remove(1, 1);
  EXPECT_EQ("null", array3->access(1, 1));
  array->insert(1, 1, 4);
  array->insert(1, 3, 5);
  array->remove(1, 1);
  array->remove(1, 3);
  array->remove(1, 1); //deleting non-existing element
  EXPECT_EQ(0, array->access(1, 1));
  EXPECT_EQ(0, array->access(1, 3));
  delete array, array2, array3;
}

TEST(TwoDArray, ColRows) {
  TwoDArray<int>* array = new TwoDArray<int>(3, 4, 0);
  TwoDArray<double>* array2 = new TwoDArray<double>(3, 4, 0.0);
  TwoDArray<std::string>* array3 = new TwoDArray<std::string>(3, 4, "null");
  EXPECT_EQ(3, array2->getNumRows());
  EXPECT_EQ(4, array2->getNumCols());
  EXPECT_EQ(3, array3->getNumRows());
  EXPECT_EQ(4, array3->getNumCols());
  EXPECT_EQ(3, array->getNumRows());
  EXPECT_EQ(4, array->getNumCols());
  delete array, array2, array3;
 }

TEST(STwoDArray, ColRows) {
  STwoDArray<int>* array = new STwoDArray<int>(3, 4, 0);
  TwoDArray<double>* array2 = new TwoDArray<double>(3, 4, 0.0);
  TwoDArray<std::string>* array3 = new TwoDArray<std::string>(3, 4, "null");
  EXPECT_EQ(3, array2->getNumRows());
  EXPECT_EQ(4, array2->getNumCols());
  EXPECT_EQ(3, array3->getNumRows());
  EXPECT_EQ(4, array3->getNumCols());
  EXPECT_EQ(3, array->getNumRows());
  EXPECT_EQ(4, array->getNumCols());
  delete array, array2, array3;
 }

TEST(VVTwoDArray, ColRows) {
  VVTwoDArray<int> array = VVTwoDArray<int>(3, 4, 0);
  TwoDArray<double> array2 = TwoDArray<double>(3, 4, 0.0);
  TwoDArray<std::string> array3 = TwoDArray<std::string>(3, 4, "null");
  EXPECT_EQ(3, array2.getNumRows());
  EXPECT_EQ(4, array2.getNumCols());
  EXPECT_EQ(3, array3.getNumRows());
  EXPECT_EQ(4, array3.getNumCols());
  EXPECT_EQ(3, array.getNumRows());
  EXPECT_EQ(4, array.getNumCols());
 }
