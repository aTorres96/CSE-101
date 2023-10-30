CXX= g++
CXXFLAGS = -Wall -std=c++11

OBJECTS = billfunctions.o bard.o

bard: $(OBJECTS)
	$(CXX) -g $(CXXFLAGS) -o bard billfunctions.o bard.o

billfunctions.o: billfunctions.cpp billheader.h
	$(CXX) -g $(CXXFLAGS) -c billfunctions.cpp

bard.o: billfunctions.cpp billheader.h bard.cpp
	$(CXX) -g $(CXXFLAGS) -c bard.cpp

clean:
	rm -f *.o
	rm bard