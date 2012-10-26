BUILD = ../build
TEST = ../test
LIB = ../lib
SRCTD = ../src/TwoDArray
SRCVV = ../src/VVTwoDArray
SRCST = ../src/STwoDArray
GTEST = $(LIB)/gtest-1.6.0
GTEST_MAINA = $(GTEST)/make/gtest_main.a

GTEST_INCLUDES = -I$(GTEST) -I$(GTEST)/include

CPP = g++
CPPFLAGS = -Wall -Wextra

array_test: Test.cpp $(SRCTD)/TwoDArray.o $(SRCVV)/VVTwoDArray.o $(SRCST)/STwoDArray.o $(GTEST_MAINA)
	$(CPP) $(CFLAGS) $(GTEST_INCLUDES) -pthread -o array_test Test.cpp $(SRCTD)/TwoDArray.o $(SRCVV)/VVTwoDArray.o $(SRCST)/STwoDArray.o $(GTEST_MAINA)

$(GTEST_MAINA): $(GTEST)/src/*.cc $(GTEST)/src/*.h
	cd $(GTEST)/make; make

clean:
	rm -f queue_test
	rm -f $(GTEST_MAINA)
	cd $(GTEST)/make; $(MAKE) clean


