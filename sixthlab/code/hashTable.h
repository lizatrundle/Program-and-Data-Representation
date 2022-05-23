// liza trundle
// prelab 6 hashes
// march 12 2022
//hashTable.h


#ifndef HASHTABLE_H
#define HASHTABLE_H

#include <iostream>
#include <string>
#include <list>
#include <fstream>
#include <vector> 

using namespace std;

class hashTable{
 public:
 hashTable(unsigned int num);
 hashTable();
 ~hashTable();
 bool contains(string word );
 void insert(string word);
 int exponentiation(int a, int b);
 bool checkprime(unsigned int prime);
 int getNextPrime (unsigned int next);
 int capacity;
 vector<list<string> > vector_table;
 unsigned int hashFunction(string word);


};

#endif
