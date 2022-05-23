//Liza Trundle
//emt8kdn
//january 25 2021
//bankAccount.h

#ifndef BANKACCOUNT_H
#define BANKACCOUNT_H

#include <iostream>
#include <string>
#include <iostream>
#include <string>
#include <stdlib.h>
#include <cmath>
#include <iomanip>


using namespace std;

class bankAccount{

public:
    // default constructor
    bankAccount();

     // destructor
    ~bankAccount();

    //A constructor that will be called when a program creates a bankAccount object with an initial balance.
    bankAccount(double amount);

    // A method that withdraws the specified amount of money from your bank account.
    double withdraw(double amount);

    //A method that deposits the specified amount of money from your bank account.
    double deposit(double amount);
    
    // A method that will return the balance currently in the bank account.
    double getBalance() const;


 private:
    // hold the amount of money in the bank account.
    double balance;
    
    
  
};

#endif
