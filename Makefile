CXXFLAGS := -std=c++17 -Wall -pedantic
CXX := g++
BIN := bin
OBJ := obj 
SRC := src

.PHONY: all clean

all: $(BIN)/test	

$(BIN)/test: $(SRC)/test.cpp $(SRC)/heap.hpp
	$(CXX) $(CXXFLAGS) -o $(BIN)/test $(SRC)/test.cpp 

clean:
	rm -f $(OBJ)/* $(BIN)/*