//Liza trundle
//emt8kdn
//prelab 10 huffman coding
//heap_node.cpp

#include "heap_node.h"
#include <iostream>
using namespace std;

heap_node::heap_node(){
  character = '\n';
  frequency = 0;
  left = NULL;
  right = NULL;
}

heap_node::heap_node(char ch, int fr){
  character= ch;
  frequency= fr;
  left = NULL;
  right = NULL;
  
}


