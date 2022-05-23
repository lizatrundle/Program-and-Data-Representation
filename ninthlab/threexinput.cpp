// liza trundle emt8kdn
// prelab 9 assembly part 2
// april 6

#include <iostream>
#include <cstdlib>
#include "timer.h"

using namespace std;


extern "C" int threexplusone (int);

int  main () {

    // delcare the local variables
    int x, n;

    // get x: a positive number to enter into the subroutine 
    cout << "Enter a number:  ";
    cin >> x;

    
    // get n: number of times to call the subroutine 
    cout << "Enter iterations of subroutine:  ";
    cin >> n;

    //run the subroutine once and store the result 
    int answer = threexplusone(x);
    // timer time;
    // time.start();
    


    // calling the subroutine n more times to get the amount of time it took
    for (int i =0; i<n; i++){
      threexplusone(x);
    }
    // time.stop();


    // double time_took =time.getTime()/1000000;
   // double avg_time= time_took / n;
   
    

    // printing out the number of iterations it took for the integer to converge to 1 (which is the return value of the function) 
    cout << "steps:  " << answer << endl;
    //cout<< avg_time<<endl;
   
   
    return 0;
}
