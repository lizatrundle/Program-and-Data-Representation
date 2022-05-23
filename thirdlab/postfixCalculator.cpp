// Liza Trundle
// February 8, 2022
// postlab 3
//postfixCalculator.cpp
//the implementation of the postfix calculator

#include <iostream>
#include <string>
#include "postfixCalculator.h"
#include "newStack.h"

using namespace std;


postfixCalculator:: postfixCalculator(){
  theStack= newStack();
}


void postfixCalculator:: addition(){

  if (!theStack.empty()){
    int a,b,c;
    
    a= theStack.top();
    theStack.pop();
    b= theStack.top();
    theStack.pop();
    c = a+b;
    theStack.push(c);
    
  }}
 

  
void postfixCalculator:: subtraction(){

 if (!theStack.empty()){
    int a,b,c;
    
    a= theStack.top();
    theStack.pop();
    b= theStack.top();
    theStack.pop();
    c = b-a;
    theStack.push(c);
 }}


void postfixCalculator:: multiplication(){

  if (!theStack.empty()){
    int a,b,c;

    a= theStack.top();
    theStack.pop();
    b= theStack.top();
    theStack.pop();
    c = b*a;
    theStack.push(c);

    
  }}


void postfixCalculator:: division(){
  if (!theStack.empty()){
    int a,b,c;

     a= theStack.top();
    theStack.pop();
    b= theStack.top();
    theStack.pop();
    c = b/a;
    theStack.push(c);
  
  }}
  

void postfixCalculator:: negation(){
if (!theStack.empty()){
  int top, answer;
 top = theStack.top();
 theStack.pop();
 answer = top * (-1);
 theStack.push(answer);
 
 }}
  

int postfixCalculator:: top(){
if (!theStack.empty()){
 return theStack.top();
}
 else exit(-1);
 }


void postfixCalculator::push(int x){
 return theStack.push(x);}

void  postfixCalculator::pop(){
 if (!theStack.empty()){
  return theStack.pop();}
  else exit(-1);
}


bool postfixCalculator::empty(){
    return theStack.empty();}


// do we use negation (the ~ operator) for the prelab for anything? 
    

  

  
 
