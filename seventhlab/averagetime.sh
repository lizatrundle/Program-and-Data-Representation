#!/bin/bash

#liza trundle, lab 7 inlab, march 21 2022
#take in the number of iterations as a single input value
# prompting the user to input the dictionary and grid files

#Your script should then print the average time taken for each execution.
#You MUST call your executable program a.out in your shell script.

NUMTIMES=6
LOOPTIMES=1
SUM=0
echo "enter the exponent for counter.cpp:"
read input
if [[ $input == quit ]] ; then
    exit
fi

while [ $LOOPTIMES -lt $NUMTIMES ]; do
    RUNNING_TIME=`./a.out $input  | tail -1`
    echo "Running iteration $LOOPTIMES ..."
    echo "time taken:  $RUNNING_TIME ms"
    SUM=$(($SUM+$RUNNING_TIME))
    let LOOPTIMES=$LOOPTIMES+1
done

AVERAGE=$(($SUM/5))

echo "5 iterations took $SUM ms"
echo "Average time was $AVERAGE ms"

