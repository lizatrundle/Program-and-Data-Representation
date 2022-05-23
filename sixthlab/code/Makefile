# Liza Trundle emt8kdn
#Makefile
# prelab6


CXX=clang++ $(CXXFLAGS)
CXXFLAGS = -O2 -Wall # Enable all warnings
DEBUG=-g


OBJECTS = hashTable.cpp wordPuzzle.cpp timer.cpp

a.out : $(OBJECTS)
	$(CXX) $(DEBUG) $(OBJECTS) -o a.out
	@echo "Compilation complete!"

wordPuzzle.o: wordPuzzle.cpp

hashTable.o: hashTable.h hashTable.cpp

timer.o: timer.h timer.cpp


.PHONY: clean
clean:
	-rm -f *.o *~ a.out
