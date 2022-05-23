#!/bin/bash

#liza trundle, lab 6 prelab, march 15 2022

# prompting the user to input the dictionary and grid files
# read similar to cin statement
echo 'enter the dictionary file:'
dictionary=$1

echo 'enter the grid file:'
grid=$2

RUNNING_TIME1=`./a.out $dictionary $grid  | tail -1`
RUNNING_TIME2=`./a.out $dictionary $grid  | tail -1`
RUNNING_TIME3=`./a.out $dictionary $grid  | tail -1`
RUNNING_TIME4=`./a.out $dictionary $grid  | tail -1`
RUNNING_TIME5=`./a.out $dictionary $grid  | tail -1`

# finding the average time for all of the running times 
total=$((RUNNING_TIME1+ RUNNING_TIME2 + RUNNING_TIME3 + RUNNING_TIME4 + RUNNING_TIME5))
average=$((total/5))

echo $average




