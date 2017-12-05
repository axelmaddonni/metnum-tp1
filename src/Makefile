CXX= g++
CXXFLAGS= -std=c++11 -g
DEPS= TP.h
SOURCES = $(wildcard *.cpp)
OBJECTS = $(SOURCES:.cpp=.o)

horno: $(OBJECTS) TP.h
	$(CXX) -o horno $(OBJECTS) TP.h $(CXXFLAGS)

clean:
	rm -f *.o horno
