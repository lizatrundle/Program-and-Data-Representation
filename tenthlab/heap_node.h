//Liza trundle
//Emt8kdn
//prekab 10
//heap_node.h

#ifndef HEAP_NODE_H
#define HEAP_NODE_H

// heap_node class
//heap node should store character, frequency, and a left and right pointers
// the heapnodes are what are being inserted into the huffman tree

class heap_node{

 public:
  heap_node();
  heap_node(char ch, int fr);
  // heap_node(char ch, int fr, heap_node* l, heap_node* r);
  char character;
  int frequency;
  heap_node* left;
  heap_node* right;
  friend class binary_heap;

};


#endif
