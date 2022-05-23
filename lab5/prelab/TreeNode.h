// Liza trundle
//Emt8kdn
//TreeNode.h: TreeNode class definition
// CS 2150: Lab 5, prelab 


#ifndef TREENODE_H
#define TREENODE_H

#include <string>
using namespace std;

class TreeNode {
public:
    TreeNode();                  // Default Constructor
    TreeNode(const string& val); // Constructor

private:
    string value;
  // important that the value of the node is a string because it must be able to represent both numbers and operators
  // for this expression tree, the stack doesnt need actual numbers because we arent doing actual mathematical conversions 
  
  TreeNode* left;// the left child of the node , each node has a value and a left and right field 
  TreeNode* right; // the right child of the node
    friend class TreeCalc;       // gives TreeCalc access to private data
};

#endif
