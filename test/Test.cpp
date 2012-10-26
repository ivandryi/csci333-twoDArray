#include "gtest/gtest.h"
#include "../src/TwoDArray/TwoDArray.h"
//#include "../src/VVTwoDArray/VVTwoDArray.h"
//#include "../src/STwoDArray/STwoDArray.h"

TEST(TwoDArray, CreateDestroy) {
  TwoDArray* array = new TwoDArray (5, 3, 0);
  delete array;
}

