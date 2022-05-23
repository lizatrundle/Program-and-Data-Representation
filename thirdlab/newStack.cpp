//Liza Trundle
//postlab 3
//newStack.cpp 
//feb 8, 2022



#include <iostream>
#include <string>

#include "newStack.h"
#include "ListNode.h"
#include "List.h"
#include "ListItr.h"

using namespace std;

newStack::newStack(){
  stacklist= List();
}

void newStack:: push(int x){
  stacklist.insertAtTail(x);
}

int newStack:: top(){
  ListItr iterator = stacklist.last();
  return iterator.retrieve();

  // if not create a new method 
    }

void newStack:: pop(){
  stacklist.removeAtTail();
}

bool newStack:: empty(){
  return stacklist.isEmpty();
}


  
  
  
  
  



  

  

  

  
