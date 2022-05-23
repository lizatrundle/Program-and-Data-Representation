// Liza trundle
//bitCounter.cpp
//postlab 4
//february 15, 2022

#include <iostream>
#include <stdio.h>
#include <string>
#include <climits>
#include <cmath>
// include math class for the pow function used in base conversion 

using namespace std;


int bitCount(int n);
string converter(string num, int ogbase, int finalbase);

int main (int argc, char *argv[]){

  string a = argv[1];
  int n = std::stoi(a);
  string b = argv[3];
  string c = argv[4];
  int originalbase = std:: stoi(b);
  int finalbase = std:: stoi(c);
  

  if (argc !=5 )
  {
     exit(-1);
     
      }

  int bits = bitCount(n);
  string converted =  converter(argv[2], originalbase, finalbase);

   cout << n << " has " << bits << " bit(s)" << endl;
   cout << argv[2]<< " (base " << originalbase << ") = " << converted << " (base " << finalbase<< ")"<< endl;

  return 0;
}

int bitCount(int n){


  if (n==0){
    return 0;
  }

  else if (n==1){
    return 1;
  }
  
  else if (n%2!=0){
      return 1 + bitCount(n/2);
    }
  else return bitCount(n/2);
  
}

  
  string converter(string num, int ogbase, int finalbase){

    //  convert from starting base to base ten and then base ten to final base
    
    
    int sum=0;
    int length = num.size();
    int power = num.size()-1;
    unsigned int remainder;
    string answer = "";
    int currentdigit;
    char currentchar;



    // converting from original base to base 10
    for (int i =0; i<length; i++){


      //https://www.geeksforgeeks.org/isdigit-function-in-c-c-with-examples/#:~:text=The%20isdigit(c)%20is%20a,9'%20and%20zero%20for%20others. (is digit function) 
      if (isdigit(num[i])){
	currentdigit = num[i] - '0';
      }
      else {
	currentdigit = num[i] - '7';
      }
      sum += currentdigit* pow(ogbase, power);
      power--;
    }
    
    // converting from base ten to other base
    while (sum>0){
      
       remainder= sum % finalbase;
       if (remainder<=9){
	 
	    currentchar = remainder + '0';
       }
       
       else{
	 currentchar = remainder + 55;
       } 
	 
       answer = currentchar + answer;
       
       sum/= finalbase;
       
    }

    
    return answer;
   
  }
  
