// liza trundle
// prelab 6 hashes
// march 12 2022
//hashTable.cpp
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <list>

#include "hashTable.h"
using namespace std;

hashTable:: hashTable(){
  capacity = getNextPrime(2*25143);
  vector_table = vector<list <string> >(capacity,list<string>());
}

hashTable:: hashTable(unsigned int num){
   capacity = getNextPrime(2*num);
   vector_table = vector<list <string> >(capacity, list<string>());
}

hashTable:: ~hashTable(){
}

bool hashTable:: contains(string word){
  unsigned int index = hashFunction(word);
  
  unsigned int real_index = index%capacity;

   if (vector_table[real_index].size()==0){
     return false;  
    }
   
  list<string> my_list= vector_table[real_index];
  
  for (list<string>::iterator s = my_list.begin(); s!= my_list.end(); ++s ){
  
    if(*s == word){
      return true;}
  }
  return false;
}

void hashTable:: insert(string word){
  if (!isupper(word[0])){
  unsigned int index_position= hashFunction(word);
  unsigned int real_index = index_position% capacity;
  vector_table[real_index].push_back(word);

  }}

int hashTable:: exponentiation (int a, int b) {
  if (b==0){
    return 1;
  }
  return a * exponentiation(a, b - 1);
}

unsigned int hashTable:: hashFunction(string word){
  int sum = 0;
  int power= 0;
  //int [] powers= {37, 1369, 50653,  };
  // up to 22 
  for (int i = 0; i < word.length(); i++){
    power = exponentiation (37,i);
      //powers[i];
    int answer = word[i] * power;
    sum+= answer;
  }
  unsigned int index = sum % capacity;
  return index;
  
}

bool hashTable::checkprime(unsigned int p) {
  if ( p <= 1 ) // 0 and 1 are not primes; the are both special cases
        return false;
    if ( p == 2 ) // 2 is prime
        return true;
    if ( p % 2 == 0 ) // even numbers other than 2 are not prime
        return false;
    for ( int i = 3; i*i <= p; i += 2 ) // only go up to the sqrt of p
        if ( p % i == 0 )
            return false;
    return true;
}

int hashTable::getNextPrime (unsigned int n) {
    while ( !checkprime(++n) );
    return n; // all your primes are belong to us
}
