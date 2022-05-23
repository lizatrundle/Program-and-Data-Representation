//Liza Trundle
//emt8kdn
//This program is the skeleton code for the lab 10 in-lab.
// It uses C++ streams for the file input,
// and just prints out the data when read in from the file.

#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdlib>
#include "heap_node.h"
#include <string>
#include <vector>
using namespace std;


heap_node* tree_root = NULL;
void decodingTree(heap_node*& root, char letter, string prefix);
string decodeMessage(string prefix);



int main (int argc, char** argv) {
    // verify the correct number of parameters
    if (argc != 2) {
        cout << "Must supply the input file name as the only parameter" << endl;
        exit(1);
    }

    // attempt to open the supplied file
    // must be opened in binary mode as otherwise trailing whitespace is discarded
    ifstream file(argv[1], ifstream::binary);
    // report any problems opening the file and then exit
    if (!file.is_open()) {
        cout << "Unable to open file '" << argv[1] << "'." << endl;
        exit(2);
    }

    // read in the first section of the file: the prefix codes
    while (true) {
        string character, prefix;
        // read in the first token on the line
	// the first token is the character: aka a,b,c,d,
        file >> character;

        // did we hit the separator?
        if (character[0] == '-' && character.length() > 1) {
            break;
        }

        // check for space
        if (character == "space") {
            character = " ";
        }

        // read in the prefix code
        file >> prefix;
        // do something with the prefix code
	//here you would add the prefix code to the tree


	decodingTree(tree_root, character[0], prefix);
	
	// cout << "character '" << character << "' has prefix code '" << prefix << "'" << endl;
    }

    // read in the second section of the file: the encoded message
    stringstream sstm;
    while (true) {
        string bits;
        // read in the next set of 1's and 0's
        file >> bits;
        // check for the separator
        if (bits[0] == '-') {
            break;
        }
        // add it to the stringstream
        sstm << bits;
    }

    string allbits = sstm.str();
    // at this point, all the bits are in the 'allbits' string
    // cout << "All the bits: " << allbits << endl;
    // this gives the decoded message, so now you take this message and go through the tree to decode it

    cout<< decodeMessage(allbits)<<endl;
   
    // close the file before exiting
    file.close();

    return 0;


}


void decodingTree(heap_node*& root, char letter, string prefix){

   if (root == NULL){
     root = new heap_node();
  }

   if (prefix.length()==0){
    root->character = letter;
  }
  
   if (prefix[0]=='0'){
    if (root->left == NULL){
      root->left= new heap_node();
    }

    decodingTree(root->left, letter, prefix.substr(1, prefix.length()-1));
  }
    
   if (prefix[0] == '1'){
      if (root->right == NULL){
	root->right= new heap_node();}

      decodingTree(root->right, letter, prefix.substr(1, prefix.length()-1));
   }}
	
	
  
	
 
string decodeMessage(string prefix){

    string message ="";
    
    heap_node* current_node = tree_root;
   
    for(int i=0; i<prefix.length(); i++){
  
  if (prefix[i] =='0'){
    current_node = current_node->left; 
      }

  if (prefix[i] == '1'){
   current_node = current_node->right; 
	}

	if (current_node->left==NULL && current_node->right == NULL){
	  message+= current_node->character;
	  current_node= tree_root;
	}
	
}

return message;

}  
