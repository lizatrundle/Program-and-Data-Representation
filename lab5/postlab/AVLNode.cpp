//Liza Trundle  emt8kdn
//Postlab 5
// March 1, 2022
//AVLNode.cpp 

#include "AVLNode.h"
#include <string>
using namespace std;

AVLNode::AVLNode() {
    value = "?";
    left = NULL;
    right = NULL;
    height = 0;
}

AVLNode::~AVLNode() {
    delete left;
    delete right;
    left = NULL;
    right = NULL;
    // dont have to delete the height because its just a counter int 
}
