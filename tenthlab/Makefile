# Liza Trundle emt8kdn
#Makefile
# prelab 10 


CXX=clang++ $(CXXFLAGS)
CXXFLAGS = -Wall # Enable all warnings
DEBUG=-g

OBJECTS = heap.cpp heap_node.cpp huffmanenc.cpp

a.out : $(OBJECTS)
	$(CXX) $(DEBUG) $(OBJECTS) -o a.out
	@echo "Compilation complete!"

heap.o: heap.cpp heap.h heap_node.h

heap_node.o: heap_node.cpp heap_node.h

huffmanenc.o: huffmanenc.cpp heap.h heap_node.h

.PHONY: clean
clean:
	-rm -f *.o *~ a.out

