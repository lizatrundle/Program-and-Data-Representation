# Liza Trundle emt8kdn
#Makefile
# prelab 5


CXX=clang++ $(CXXFLAGS)
CXXFLAGS = -Wall # Enable all warnings
DEBUG=-g

OBJECTS = TreeCalc.cpp TreeNode.cpp TreeCalcTest.cpp

a.out : $(OBJECTS)
	$(CXX) $(DEBUG) $(OBJECTS) -o a.out
	@echo "Compilation complete!"

TreeCalc.o: TreeCalc.cpp TreeCalc.h TreeNode.h

TreeCalcTest.o: TreeCalcTest.cpp TreeCalc.h TreeNode.h

TreeNode.o: TreeNode.cpp TreeNode.h

.PHONY: clean

clean:
	-rm -f *.o *~ a.out
