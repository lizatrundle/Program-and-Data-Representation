//Liza Trundle
//postlab 3
//testPostfixCalculator.cpp
//february 8, 2022

#include <iostream>
#include <string>


#include "postfixCalculator.h"
#include "newStack.h"


using namespace std;

//accepts user-input (see below) and evaluates that expression.
//

int main(){
  
string input;
postfixCalculator post;


while (cin >> input) {

  if (input == "+"){
     post.addition();
     
  }
  else if (input == "-" && input.length()==1) {

   
     post.subtraction();
     
  }

  else if (input == "*"){
    post.multiplication();
  }

  else if (input == "/"){
    post.division();
  }
  
  else if (input == "~"){
    post.negation();

  }
 
  
  
  else{
    int x = std::stoi(input);
    post.theStack.push(x);
    
  }


 }
 
 int final = post.theStack.top();
 cout << final << endl;

  
 return 0;
}


 
  
   
