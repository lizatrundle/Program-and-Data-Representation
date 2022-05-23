# Liza Trundle emt8kdn
#Makefile
# postlab 5


CXX=clang++ $(CXXFLAGS)
CXXFLAGS = -Wall # Enable all warnings
DEBUG=-g

OBJECTS = AVLNode.cpp AVLTree.cpp AVLPathTest.cpp

a.out : $(OBJECTS)
	$(CXX) $(DEBUG) $(OBJECTS) -o a.out
	@echo "Compilation complete!"

AVLNode.o: AVLNode.cpp AVLNode.h

AVLPathTest.o: AVLPathTest.cpp AVLTree.h AVLNode.h

AVLTree.o: AVLTree.cpp AVLNode.h AVLTree.h

.PHONY: clean
clean:
	-rm -f *.o *~ a.out
