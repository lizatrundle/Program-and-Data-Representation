//Liza trundle emt8kdn
//lab 5 prelab
// february 24, 2022 

// TreeCalc.cpp:  CS 2150 Tree Calculator method implementations

#include "TreeCalc.h"
#include "TreeNode.h"
#include <iostream>
#include <stack>
#include <cstdlib>
#include <stdlib.h>

using namespace std;

// Constructor
TreeCalc::TreeCalc() {
  stack<TreeNode*> expressionStack;
}

// Destructor - frees memory
TreeCalc::~TreeCalc() {
   while(!expressionStack.empty()){
    cleanTree(expressionStack.top());
    expressionStack.pop();
  }
}


// Deletes tree/frees memory
void TreeCalc::cleanTree(TreeNode* tree) {
  if (tree == NULL){
    return;}
  cleanTree(tree->left);
  cleanTree(tree->right);
  delete tree;
  tree= NULL;
}

// Gets data from user
// DO NOT MODIFY
void TreeCalc::readInput() {
    string response;
    cout << "Enter elements one by one in postfix notation" << endl
         << "Any non-numeric or non-operator character,"
         << " e.g. #, will terminate input" << endl;
    cout << "Enter first element: ";
    cin >> response;
    //while input is legal
    while (isdigit(response[0]) || response[0] == '/' || response[0] == '*'
            || response[0] == '-' || response[0] == '+') {
        insert(response);
        cout << "Enter next element: ";
        cin >> response;
    }
}

// Puts value in tree stack

//If operand push into the stack
//If operator pop two values from stack make them its child and push the current node again.
//In end, the only element of the stack will be the root of  expression tree.
void TreeCalc::insert(const string& val) {

   if (val == "*" || val =="+" || val == "-" || val == "/"){
    TreeNode* a = expressionStack.top();
      expressionStack.pop();
      TreeNode* b= expressionStack.top();
      expressionStack.pop();
      TreeNode* op = new TreeNode(val);
      op->left = b;
      op->right =a;
      expressionStack.push(op);
   }

   else {
    TreeNode* value = new TreeNode(val);
    expressionStack.push(value);
   }
 
   
    // insert a value into the tree
}

// Prints data in prefix form
// PREFIX = root, left, right 
void TreeCalc::printPrefix(TreeNode* tree) const {
    // print the tree in prefix format
  if (tree== NULL){
    return;
  }

  //if (tree->left == NULL || tree-> right ==NULL){

  cout<< tree->value << " ";
 
    printPrefix(tree->left);
 
    printPrefix(tree-> right);
    
   
}

// Prints data in infix form
// INFIX = left, root, right
void TreeCalc::printInfix(TreeNode* tree) const {


  // base case
    if (tree== NULL){
    return;
  }

    // if the node you are currently on is an operator, check for the parenthesis adding 
    if( tree->value == "*" ||tree->value == "+" ||tree->value == "-" ||tree->value == "/"){
      cout<< "(";}
    
    printInfix(tree->left);
   
   if( tree->value == "*" ||tree->value == "+" ||tree->value == "-" ||tree->value == "/"){
     cout<< " "<< tree->value << " " ;
   }
   
   else {cout<< tree->value;}
    
    printInfix(tree-> right);
    
 if( tree->value == "*" ||tree->value == "+" ||tree->value == "-" ||tree->value == "/"){
      cout<< ")";} 


  
    // print tree in infix format with appropriate parentheses
}

//Prints data in postfix form
//POSTFIX = left, right, root 
void TreeCalc::printPostfix(TreeNode* tree) const {


   if (tree== NULL){
    return;
  }
    printPostfix(tree->left);
 
    printPostfix(tree-> right);

    cout<< tree->value << " ";
    
    // print the tree in postfix form
}

// Prints tree in all 3 (post, in, pre) forms
// DO NOT MODIFY
void TreeCalc::printOutput() const {
    if (expressionStack.size() != 0 && expressionStack.top() != NULL) {
        TreeNode* tree = expressionStack.top();
        cout << "Expression tree in postfix expression: ";
        printPostfix(tree);
        cout << endl;

        cout << "Expression tree in infix expression: ";
        printInfix(tree);
        cout << endl;

        cout << "Expression tree in prefix expression: ";
        printPrefix(tree);
        cout << endl;
    } else {

      cout << "Size is 0." << endl;
    }
}

// Evaluates tree, returns value
// private calculate() method
int TreeCalc::calculate(TreeNode* tree) const {

  int answer;
  if (tree==NULL){
    return 0;}
  
  //if it is a leaf node, or if it is a number, then convert the number from a string to an integer
  // once you hit a leaf you are done
  if (tree->left == NULL && tree-> right == NULL){
    answer = std::stoi(tree->value);
    return answer;
  }

  int left = calculate(tree->left);
  int right = calculate (tree->right);

  if (tree->value == "-"){
    answer = left - right;
  }
  if (tree->value == "+"){
    answer = left+right; }
  if (tree->value == "*"){
    answer = left*right;}
  if (tree->value =="/"){
    answer = left/right;
  }


  
  return answer; 
}

  

// public is wrapper function, allows other functions to call while hiding data
// calculat function is public bc dont want outside classes to accesss the tree
// using this one to get tree and pass it through to helper function

//Calls calculate, sets the stack back to a blank stack
// public calculate() method. Hides private data from user
int TreeCalc::calculate() {

  TreeNode* tree = expressionStack.top();

  int answer = calculate(tree);

  while(!expressionStack.empty()){
  cleanTree(expressionStack.top());
  expressionStack.pop();}
 
  

 

  return answer;
  
}
