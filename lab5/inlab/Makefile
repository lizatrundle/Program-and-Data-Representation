# Liza Trundle emt8kdn
#Makefile
# inlab 5


CXX=clang++ $(CXXFLAGS)
CXXFLAGS = -Wall # Enable all warnings
DEBUG=-g

OBJECTS = BinaryNode.cpp BinarySearchTree.cpp BSTPathTest.cpp

a.out : $(OBJECTS)
	$(CXX) $(DEBUG) $(OBJECTS) -o a.out
	@echo "Compilation complete!"

BSTPathTest.o: BSTPathTest.cpp BinarySearchTree.h BinaryNode.h

BinaryNode.o: BinaryNode.cpp BinaryNode.h

BinarySearchTree.o: BinarySearchTree.cpp BinaryNode.h BinarySearchTree.h

.PHONY: clean
clean:
	-rm -f *.o *~ a.out
