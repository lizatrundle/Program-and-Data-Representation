# Makefile for CS 2150 pre-lab 9, Liza Trundle emt8dkn
# inspo from PDR: lab 8 instructions , vecsum makefile


# Defines the C++ compiler we'll be using
CC = clang 

# Defines the flags we'll be passing to the C++ compiler
CCFLAGS = -Wall -g


# All of the .o files for our program
OBJECTS = linkedlist.o 

# Compile our files into a.out
a.out: $(OBJECTS)
	$(CC) $(CCFLAGS) $(OBJECTS)

linkedlist.o: linkedlist.c


# This will clean up (remove) all our object files.  The -f option
# tells rm to forcily remove the files (i.e. don't ask if they should
# be removed or not).  This removes object files (*.o) and Emacs
# backup files (*~)
clean:
	-rm -f *.o *~