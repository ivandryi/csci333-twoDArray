BUILD = ./build
TEST = ./test
LIB = ./lib
SRCA = ./src/AQueue
SRCLL = ./src/LLQueue
SRCSL = ./src/SLQueue
SRCT = ./src/TimingTests

CPP = g++
CPPFLAGS = -Wall -Wextra

all: $(BUILD)/mainA $(BUILD)/mainll $(BUILD)/mainsl $(BUILD)/timing_test $(TEST)/queue_test

$(BUILD)/mainA: $(SRCA)/AQueue.cpp $(SRCA)/AQueue.o
	cd $(SRCA); $(MAKE)

$(BUILD)/mainll: $(SRCLL)/LLQueue.cpp $(SRCLL)/LLQueue.o
	cd $(SRCLL); $(MAKE)

$(BUILD)/mainsl: $(SRCSL)/SLQueue.cpp $(SRCSL)/SLQueue.o
	cd $(SRCSL); $(MAKE)

$(BUILD)/timing_test: $(SRCT)/timing_test.cpp $(SRCA)/AQueue.o $(SRCLL)/LLQueue.o $(SRCSL)/SLQueue.o
	cd $(SRCT); $(MAKE)

$(TEST)/queue_test: $(TEST)/Queue.cpp $(SRCA)/AQueue.o $(SRCLL)/LLQueue.o $(SRCSL)/SLQueue.o
	cd $(TEST); $(MAKE)

clean:
	cd $(SRCA); $(MAKE) clean
	cd $(SRCLL); $(MAKE) clean
	cd $(SRCSL); $(MAKE) clean
	cd $(SRCT); $(MAKE) clean
	cd $(TEST); $(MAKE) clean

