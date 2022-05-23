// mathfun.cpp
//prelab 8: assembly
//Liza Trundle emt8kdn

#include <iostream>
#include <cstdlib>

using namespace std;

extern "C" long product (long, long);
extern "C" long power (long, long);

int  main () {

    // delcare the local variables
    long  x, y;

    // get x and y from the user 
    cout << "Enter integer 1:  ";
    cin >> x;

    cout << "Enter integer 2:  ";
    cin >> y;

    
    cout << "Product:  " << product(x,y) << endl;
    cout << "Power:  " << power(x,y) << endl; 
   
    return 0;
}
