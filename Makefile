BUILD = ./build
TEST = ./test
LIB = ./lib
SRCTD = ./src/TwoDArray
SRCVV = ./src/VVTwoDArray
SRCSD = ./src/STwoDArray

CPP = g++
CPPFLAGS = -Wall -Wextra

all:  $(TEST)/array_test

$(TEST)/array_test: $(TEST)/Test.cpp $(SRCTD)/TwoDArray.o $(SRCVV)/VVTwoDArray.o $(SRCSD)/STwoDArray.o
	cd $(TEST); $(MAKE)

clean:
	cd $(SRCTD); $(MAKE) clean
	cd $(SRCVV); $(MAKE) clean
	cd $(SRCSD); $(MAKE) clean
	cd $(TEST); $(MAKE) clean

