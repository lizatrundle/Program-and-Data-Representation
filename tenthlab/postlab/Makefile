# Liza Trundle emt8kdn
#Makefile
#inlab 10 

CXX=clang++ $(CXXFLAGS)
CXXFLAGS = -Wall # Enable all warnings
DEBUG=-g

OBJECTS = huffmandec.cpp heap_node.cpp 

a.out : $(OBJECTS)
	$(CXX) $(DEBUG) $(OBJECTS) -o a.out
	@echo "Compilation complete!"

heap_node.o: heap_node.cpp heap_node.h

huffmandec.o: huffmandec.cpp heap_node.h

.PHONY: clean
clean:
	-rm -f *.o *~ a.out