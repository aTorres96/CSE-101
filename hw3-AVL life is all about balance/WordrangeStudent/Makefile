CXX = g++
CXXFLAGS = -Wall -std=c++11

OBJECTS = bst.o wordrange.o

wordrange: $(OBJECTS)
		$(CXX) -g $(CXXFLAGS) -o wordrange bst.o wordrange.o

bst.o: bst.cpp bst.h
		$(CXX) -g $(CXXFLAGS) -c bst.cpp

wordrange.o: bst.cpp bst.h wordrange.cpp
		$(CXX) -g $(CXXFLAGS) -c wordrange.cpp

clean:
	rm -f *.object
	rm wordrange