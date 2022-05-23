// liza trundle
// prelab 6 hashes
// march 12 2022
//wordPuzzle.cpp

#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <cctype>

#include "hashTable.h"
#include "timer.h"

using namespace std;

#define MAXROWS 500
#define MAXCOLS 500
char grid[MAXROWS][MAXCOLS];

// taken from lab 6 prelab reources, written by aaron bloomfield

void readInDictionary(string filename, hashTable &my_table );

bool readInGrid(string filename, int& rows, int& cols);

string getWordInGrid(int startRow, int startCol, int dir, int len,
                     int numRows, int numCols);


bool readInGrid(string filename, int& rows, int& cols) {
  // try to open the file
  ifstream file(filename);
    // upon an error, return false
    if (!file.is_open()) {
        return false;
    }
    // first comes the number of rows
    file >> rows;
    //cout << "There are " << rows << " rows." << endl;

    // then the columns
    file >> cols;
    // cout << "There are " << cols << " cols." << endl;

    // and finally the grid itself
    string data;
    file >> data;

    // close the file
    file.close();

    // convert the string read in to the 2-D grid format into the
    // grid[][] array.
    // In the process, we'll print the grid to the screen as well.
    int pos = 0; // the current position in the input data
    for (int r = 0; r < rows; r++) {
        for (int c = 0; c < cols; c++) {
            grid[r][c] = data[pos++];
        }
    }
    return true;
}
string getWordInGrid (int startRow, int startCol, int dir, int len,
                      int numRows, int numCols) {
  
    static string output;
    output.clear(); // Since it's static we need to clear it
    output.reserve(256); // Can't set capacity in the constructor so do it the first time here

    // the position in the output array, the current row, and the
    // current column
    int r = startRow, c = startCol;
    // iterate once for each character in the output
    for (int i = 0; i < len; i++) {
        // if the current row or column is out of bounds, then break
        if (c >= numCols || r >= numRows || r < 0 || c < 0) {
            break;
        }

        // set the next character in the output array to the next letter
        // in the grid
        output += grid[r][c];

        // move in the direction specified by the parameter
        switch (dir) { // assumes grid[0][0] is in the upper-left
            case 0:
                r--;
                break; // north
            case 1:
                r--;
                c++;
                break; // north-east
            case 2:
                c++;
                break; // east
            case 3:
                r++;
                c++;
                break; // south-east
            case 4:
                r++;
                break; // south
            case 5:
                r++;
                c--;
                break; // south-west
            case 6:
                c--;
                break; // west
            case 7:
                r--;
                c--;
                break; // north-west
        }
    }

    return output;
}

int main (int argc, char *argv[]){
  hashTable my_table;
  int rows, columns;
  int number_words = 0;
  timer time;
   
  if (argc!=3)
  {
    cout<< "invalid inputs"<< endl;
    
    return 1;
  }

  string my_string;
  unsigned int table_size=0;
    // try to open the file

  ifstream file(argv[1]);
    // upon an error, return false
    if (!file.is_open()) {
        return 2;
    }
    while (getline(file,my_string)){
      table_size++;
	}
    file.close();

    
    my_table = hashTable(table_size);

    
  ifstream file2(argv[1]);
    // upon an error, return false
    if (!file2.is_open()) {
        return 2;
    }
    while (getline(file2,my_string)){
	  my_table.insert(my_string);
	}
    file2.close();
	

  bool grid_check = readInGrid(argv[2], rows, columns);

  //check to make sure grid is valid 
  if(!grid_check){
    cout<< "invalid file"<< endl;
    return 3 ;  }
  
  //create a string array of directions to easily access 
  string directions [8] = {"N","NE", "E","SE", "S","SW", "W", "NW"};

  time.start();
  
  for (int r =0; r < rows; r++){
    for (int c =0; c<columns; c++){
      for (int d =0; d<8; d++){
	for (int l=3; l<22; l++){
	  string output_word = getWordInGrid(r,c,d,l,rows,columns);
	  if(output_word.length() == l && my_table.contains(output_word)){
	    number_words++;

	    if(directions[d].length()==1){
	cout<< directions[d]<< " ("<< r << ", " <<  c<< "):             " << output_word<< endl;
	    }
	    else if (directions[d].length()>1){
       cout<< directions[d]<< "("<< r << ", " <<  c<< "):             " << output_word<< endl;
	     
	    }
	  }
	
	}
      }
    }
  }

  time.stop();

cout<< number_words << " words found" << endl;

//double int_time = time.getTime()*100000;
//int answer = (int)(int_time);
//cout<< time.getTime() <<endl;
 return 0;
}
