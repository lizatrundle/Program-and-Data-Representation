//Liza Trundle
//postlab 3
// postfixCalculator.h
//feb 8, 2022
//which is the class declaration of the postfix calculator


#ifndef POSTFIXCALCULATOR_H
#define POSTFIXCALCULATOR_H


#include <iostream>
#include <string>
#include "newStack.h" 
// use a stack of int values 

using namespace std;

class postfixCalculator{
  

public:


newStack theStack;

postfixCalculator();

void addition();

void subtraction();

  void multiplication();

void division();

void negation();


  void push(int x);

  int top();

  void pop();

  bool empty();
  

  



//If pop() or top() are called on an empty stack, terminate the program with the function call exit(-1), which is from the <cstdlib> library.



};

#endif



//you will need to check if the stack is empty before every top and pop call, it may be worth it to add helper methods to your postfix calculator that, when called, will perform the necessary checks before top/pop.

