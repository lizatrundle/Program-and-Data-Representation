//Liza Trundle Emt8kdn
//prelab 10
// this code is taken from the slides 
//Code written by Aaron Bloomfield, 2014
// Released under a CC BY-SA license
// This code is part of the https://github.com/aaronbloomfield/pdr repository

#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
#include <stdlib.h>
#include "heap.h"
#include "heap_node.h"
using namespace std;

// default constructor
heap::heap() {
  heap_node* new_node= new heap_node();
    the_heap.push_back(new_node);
    heap_size = 0;
}

// the destructor doesn't need to do much
heap::~heap() {
}

void heap::insert(heap_node* node) {
    // a vector push_back will resize as necessary
    the_heap.push_back(node);
    // move it up into the right position
    percolateUp(++heap_size);
}

void heap::percolateUp(int hole) {
  int x = the_heap[hole]->frequency;
  heap_node* insert_node = the_heap[hole];
    for ( ; (hole > 1) && (x < the_heap[hole/2]->frequency); hole /= 2) {
        the_heap[hole] = the_heap[hole/2];
    }
    the_heap[hole]=insert_node;
    
}
heap_node* heap::deleteMin() {
    // make sure the heap is not empty
    if (heap_size == 0) {
        throw "deleteMin() called on empty heap";
    }
    // save the value to be returned
    heap_node* ret = the_heap[1];
    // move the last inserted position into the root
    the_heap[1] = the_heap[heap_size--];
    // make sure the vector knows that there is one less element
    the_heap.pop_back();
    // percolate the root down to the proper position
    if (!isEmpty()) {
        percolateDown(1);
    }
    // return the old root node
    return ret;
}

void heap::percolateDown(int hole) {
    int x = the_heap[hole]->frequency;
    heap_node* insert_node = the_heap[hole];
    // while there is a left child...
    while (hole*2 <= heap_size) {
        int child = hole*2; // the left child
        // is there a right child?  if so, is it lesser?
        if ((child+1 <= heap_size) && (the_heap[child+1]->frequency < the_heap[child]->frequency)) {
            child++;
        }
        // if the child is greater than the node...
        if (x > the_heap[child]->frequency) {
            the_heap[hole] = the_heap[child]; // move child up
            hole = child;             // move hole down
        } else {
            break;
        }
    }
    // correct position found!  insert at that spot
    the_heap[hole] = insert_node;
}

heap_node* heap::findMin() {
    if (heap_size == 0) {
        throw "findMin() called on empty heap";
    }
    return the_heap[1];
}

unsigned int heap::size() {
    return heap_size;
}

void heap::makeEmpty() {
    heap_size = 0;
    the_heap.resize(1);
}

bool heap::isEmpty() {
    return heap_size == 0;
}

void heap::huffmanTree(){
  while(heap_size!=1){
   
    heap_node* left = deleteMin();
    heap_node* right = deleteMin();

    int sum = left->frequency + right->frequency;
    heap_node*  huff_node = new heap_node('\n', sum);
    huff_node->left = left;
    huff_node ->right = right; 
    //title it as a nonprintable char 
   
    insert(huff_node);
    
  }}
