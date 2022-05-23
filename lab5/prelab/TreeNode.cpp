//Liza Trundle
// Emt8kdn
// feb 24, 2022

// TreeNode.cpp:  Tree Node method implementations
// CS 2150: Lab 5 prelab 

#include "TreeNode.h"

// Default Constructor - left and right are NULL, value '?'
TreeNode::TreeNode() {
    value = "?";
    left = NULL;
    right = NULL;
    // default is that the node has no children 
}

// Constructor - sets value to val
TreeNode::TreeNode(const string& val) {
    value = val;
    left = NULL;
    right = NULL;
}
