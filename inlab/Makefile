# Liza Trundle emt8kdn
#Makefile
# inlab 11 

CXX=clang++ $(CXXFLAGS)
CXXFLAGS =-Wall -O2 -g -std=c++11

OBJECTS = traveling.cpp middleearth.cpp
.SUFFIXES: .o .cpp

a.out : $(OBJECTS)
	$(CXX) $(OBJECTS)
	doxygen
	@echo "Compilation complete!"

.PHONY: clean
clean:
	-rm -f *.o *~ a.out