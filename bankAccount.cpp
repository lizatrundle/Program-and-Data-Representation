//Liza Trundle
//emt8kdn
//january 25 2021
//bankAccount.cpp


#include <iostream>
#include <string>
#include <iostream>
#include <string>
#include <stdlib.h>
#include <cmath>
#include <iomanip>

#include "bankAccount.h"


using namespace std;


// default constructor
bankAccount:: bankAccount(){
  balance = 0; }

  

     // destructor
bankAccount:: ~bankAccount(){}

    //A constructor that will be called when a program creates a bankAccount object with an initial balance.


bankAccount::bankAccount(double amount){
    balance = amount;
}



  
  
  

    // A method that withdraws the specified amount of money from your bank account.

double bankAccount::withdraw(double amount){
  if (amount > balance){
    
    return balance;}
  
  if (amount < balance){
    balance = balance - amount;
    return balance;
  }
  
  else balance = 0.0; return balance; 
  }


    //A method that deposits the specified amount of money from your bank account.
double bankAccount:: deposit(double amount){

  balance = balance + amount;
  return balance;
}

    
    // A method that will return the balance currently in the bank account.
double bankAccount:: getBalance() const{
  return balance;
}

