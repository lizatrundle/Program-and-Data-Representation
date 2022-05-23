# Liza Trundle emt8kdn
#Makefile
# postlab 11 

CXX=clang++ $(CXXFLAGS)
CXXFLAGS =-Wall -O2 -g -std=c++11

OBJECTS = puzzle.cpp 
.SUFFIXES: .o .cpp

a.out : $(OBJECTS)
	$(CXX) $(OBJECTS)
	doxygen
	@echo "Compilation complete!"

.PHONY: clean
clean:
	-rm -f *.o *~ a.out