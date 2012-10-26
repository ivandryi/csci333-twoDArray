BUILD = ../build
TEST = ../test
LIB = ../lib
SRCA = ../src/AQueue
SRCLL = ../src/LLQueue
// SRCSL = ../src/SLQueue
GTEST = $(LIB)/gtest-1.6.0
GTEST_MAINA = $(GTEST)/make/gtest_main.a

GTEST_INCLUDES = -I$(GTEST) -I$(GTEST)/include

CPP = g++
CPPFLAGS = -Wall -Wextra

#queue: Queue.cpp $(SRCA)/AQueue.o $(SRCLL)/LLQueue.o $(GTEST_MAINA)
#	$(CPP) $(CFLAGS) $(GTEST_INCLUDES) -pthread -o queue_test $^

queue_test: Queue.cpp $(SRCA)/AQueue.o $(SRCLL)/LLQueue.o $(GTEST_MAINA)
	$(CPP) $(CFLAGS) $(GTEST_INCLUDES) -pthread -o queue_test Queue.cpp $(SRCA)/AQueue.o $(SRCLL)/LLQueue.o $(GTEST_MAINA)

$(GTEST_MAINA): $(GTEST)/src/*.cc $(GTEST)/src/*.h
	cd $(GTEST)/make; make

clean:
	rm -f queue_test
	rm -f $(GTEST_MAINA)
	cd $(GTEST)/make; $(MAKE) clean


