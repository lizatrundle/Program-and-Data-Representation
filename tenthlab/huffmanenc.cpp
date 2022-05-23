//Liza trundle emt8kdn
//prelab 10
//huffmanenc.cpp
//used fileio.cpp file from the lab description page

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
#include <iostream>
#include <vector>
#include <stdlib.h>
#include <unordered_map>
#include "heap.h"
#include "heap_node.h"

using namespace std;

void prefixOutput(heap_node* root, string s);
//void huffmanTree(binary_heap a_heap);

unordered_map<char , string > prefix; 

int main(int argc,char* argv[]){
 
  
//correct parameter check
   if (argc != 2) {
        cout << "The input file name should be the only parameter" << endl;
        exit(1);
    }

//correct file check
ifstream file(argv[1]);
    // if the file wasn't found, output an error message and exit
    if (!file.is_open()) {
        cout << "Unable to open '" << argv[1] << "' for reading" << endl;
        exit(2);
    }

unordered_map<char, int> char_freq;
   
heap my_heap;

char g;
int symbols = 0;
int unique = 0;
 
while (file.get(g)) {
  
      if (g>= 0x20 && g <= 0x7e){

	// character not in map
       if (char_freq.find(g)== char_freq.end()){
	char_freq[g]= 1;
	unique+=1;
       }

      //character in map 
      else {
	char_freq[g]++;
      }
        symbols+=1;
      }
     

 }

file.clear(); 
file.seekg(0);

 // putting elements of map into the heap 
 for (unordered_map<char, int>::iterator it = char_freq.begin(); it!= char_freq.end(); it++)
   
   {
   
     my_heap.insert(new heap_node(it->first, it->second));
   }
 
  
//now you have the minheap, now you have to go through and make it into the huffman tree

my_heap.huffmanTree();
 
prefixOutput(my_heap.findMin(), "");

//my_heap.print();


file.clear(); // Clears the _state_ of the file, not its contents!
  

cout << "----------------------------------------"<< endl;

 string output= "";
 int prefix_count= 0; 

 while (file.get(g)) {
 
 
 output+=prefix[g] + " ";
 prefix_count += prefix[g].length();
 }
 cout << output <<endl;

 file.close();
      


cout << "----------------------------------------"<< endl;


int bits = symbols*8;
double compression_rate= (double)((double)bits/(double)prefix_count);
 double sum_cost= 0; 
 


for (unordered_map<char, string>::iterator it = prefix.begin(); it!= prefix.end(); it++)
   
  {

    double prob = (double)char_freq[it->first]/(double)symbols;

    sum_cost += prob * it->second.length();

  }
 
cout << "There are a total of "<< symbols << " symbols that are encoded."<< endl;
cout << "There are " << unique << " distinct symbols used."<< endl;
cout << "There were " << bits << " bits in the original file."<< endl;
cout << "There were " << prefix_count << " bits in the compressed file."<< endl;
cout << "This gives a compression ratio of  " << compression_rate << " ."<< endl;
cout << "The cost of the Huffman tree is " << sum_cost   << " bits per character."<<endl;



 
    return 0;

}

void prefixOutput(heap_node* root, string s){

  if (root==NULL){
    return;
  }

   if (root->left==NULL && root->right == NULL){
     if (root->character == ' '){
       cout<< "space " << s <<"\n";
     }
     else{
       cout<< root->character << " " << s << endl;
     }   
       prefix[root->character] = s;
   }
    
 
   if (root->left!= NULL)
     {
       prefixOutput(root->left, s + "0");
     }

   if (root->right!= NULL){
     
  prefixOutput(root->right, s + "1");
   }
 
  
}
