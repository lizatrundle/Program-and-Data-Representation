
//Liza Trundle
// Emt8kdn
// January 24, 2021
// xToN.cpp


#include <iostream>
using namespace std;

int xton (int a, int b) {
  if (b==0){
    return 1;
  }
  return a * xton(a, b - 1); // recursive function that uses exponentiation without using the math power function by multiplying by a decreasing number each time , similar to factorial 
}

int main () {
  int x, y, z; 
    cin >> x;
    cin >> y;
    z = xton (x, y);
    cout << z << endl;
    
    return 0;
}
