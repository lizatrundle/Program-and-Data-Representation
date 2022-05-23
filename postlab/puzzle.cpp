//Liza Trundle
//emt8kdn
//postlab 11


#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
#include <vector>
#include <queue>
#include <unordered_map> 

using namespace std;

//call first or return if impossible
bool solvability(string example [3][3]);

vector<string> makeVec(string arr[3][3]);

vector<string> neighbors;

vector<string> getNeighbors(string my_vec);

string makeString(string example[3][3]);

queue<string> sortqueue;

int breadthFirst(string arr[3][3]);


unordered_map<string, int> node_dist;

string puzzle_string;

string end_state[3][3] = {{"1","2","3"},{"4","5","6"},{"7","8","0"}};



/*! \class main
 *  \brief holds a program to compute shortest path to end state of sliding 8 puzzle 
 *   
 *  
 */
int main() {


    /**
 * variables used in program
 * \public
 */
  string start_grid[3][3];
 
  string input;
  // string answer= "";
  
 
  cout<<"Enter puzzle" <<endl;
  
   
    for (int row =0; row<3; row++){
      for (int column=0; column< 3; column++){
	cin>>input;
	puzzle_string+=input; 

	//int x = std::stoi(input);
	start_grid[row][column]=input;
       	
      }}

             /**
 * \if
 */

    
    if (!solvability(start_grid)){
     cout<<"IMPOSSIBLE"<<endl;}

     /**
 * \else
 */ 
    else if (solvability(start_grid)){
	cout<< "true"<<endl;
      }
    
   
    cout<<breadthFirst(start_grid)<<endl;
    //cout<<puzzle_string<<endl;

    // cout<< findZero(start_grid)<<endl;
   
   return 0;
   }


/*! @brief A method to check if puzzle is solvable  
      @parame example a 2d array of strings representing the puzzle 
 
    */
bool solvability(string example [3][3]){
 
 int num_inversions=0;
 vector<string> my_vector = makeVec(example);


 // Credit for formula to: http://www.cs.bham.ac.uk/~mdr/teaching/modules04/java2/TilesSolvability.html
 for (int index =0; index<9; index++){
      for (int match=index+1; match<9; match++){
	if(my_vector[match]>my_vector[index]  && my_vector[match]!="0" && my_vector[index]!="0"){
	  num_inversions++;
	}}}

	//check if inversions is even, and then the puzzle is solvable
	if (num_inversions%2==0){
	  return true;
	}
	else return false;

}

/*! @brief A method to convert the 2D array into a vector 
      @param arr a 2d array of strings representing the puzzle 
 
    */
vector<string> makeVec(string arr[3][3]){
  vector<string> ret_vec;
  
   for (int row =0; row<3; row++){
      for (int column=0; column< 3; column++){
	ret_vec.push_back(arr[row][column]);
      }}
   return ret_vec;
}

/*! @brief A method to perform a breadthfirst shortest path algorithm to solve the shortest path to the end state
      @param arr a 2d array of strings representing the puzzle 
 
    */
int breadthFirst(string arr[3][3]){
  //vector<int> my_vector = makeVec(puzz);
  string my_string = makeString(arr);
  if (my_string=="123456780"){
    return 0;
  }
  node_dist[my_string]=0;
  sortqueue.push(my_string);
  

 while (!sortqueue.empty()){
   string vertex = sortqueue.front();
   sortqueue.pop();
   vector<string> neg= getNeighbors(vertex);
   // sort through vector of strings
   //if you dont find it in the vector then you have to add it to it

   for (int i=0;i<neg.size();i++)
     {
       if (node_dist.find(neg[i])==node_dist.end()){
	 node_dist[neg[i]]=node_dist[vertex]+1;
         sortqueue.push(neg[i]);
       }
   if (neg[i]=="123456780"){
     return node_dist[neg[i]];
   }}}

 return -1;

}
 
  
  
/*! @brief A method to convert 2D array into a vector and then into a string 
      @parame example a 2d array of strings representing the puzzle 
 
    */
string makeString(string example[3][3]){
  vector<string> vec = makeVec(example);
  
  string my_string ="";
  
  for (int i=0; i<9;i++){
    //string s =to_string(vec[i]);
    my_string+=vec[i];
  }
  return my_string;
}


/*! @brief A method to generate neighbor nodes of the puzzle 
      @parame my_vect a string representing the puzzle as a string 
 
    */
vector<string> getNeighbors(string my_vec){
  
  // string my_vec = makeString(arr);
  vector<string> neighbors;
  //vector<vector<string>> neighbors;
  
  if (my_vec[0]=='0'){
    char temp1 = my_vec[1];
    char temp2 = my_vec[3];
    my_vec[0]=temp1;
    my_vec[1]='0';
    neighbors.push_back(my_vec);
    my_vec[0]=temp2;
    my_vec[1]=temp1;
    my_vec[3]='0';
    neighbors.push_back(my_vec);
  }
 


  else if (my_vec[1]=='0'){
    char temp1 = my_vec[0];
    char temp2 = my_vec[2];
    char temp3 = my_vec[4];
    my_vec[1]=temp1;
    my_vec[0]='0';
    neighbors.push_back(my_vec);
    my_vec[1]=temp2;
    my_vec[0]=temp1;
    my_vec[2]='0';
    neighbors.push_back(my_vec);
    my_vec[1]=temp3;
    my_vec[2]=temp2;
    my_vec[4]='0';
    neighbors.push_back(my_vec);
  }

  else if (my_vec[2]=='0'){
   char temp1 = my_vec[1];
    char temp2 = my_vec[5];
    my_vec[2]=temp1;
    my_vec[1]='0';
    neighbors.push_back(my_vec);
    my_vec[2]=temp2;
    my_vec[1]=temp1;
    my_vec[5]='0';
    neighbors.push_back(my_vec);
   }


  else if (my_vec[3]=='0'){
     char temp1= my_vec[0];
      char temp2= my_vec[4];
     char temp3= my_vec[6];
     my_vec[3]=temp1;
     my_vec[0]='0';
     neighbors.push_back(my_vec);
     my_vec[3]=temp2;
     my_vec[0]=temp1;
     my_vec[4]='0';
     neighbors.push_back(my_vec);
     my_vec[3]=temp3;
     my_vec[4]=temp2;
     my_vec[6]='0';
   }

  else if (my_vec[4]=='0'){
  char temp1= my_vec[1];
  char temp2= my_vec[3];
  char temp3= my_vec[5];
  char temp4 = my_vec[7];
  my_vec[4]=temp1;
  my_vec[1]='0';
  neighbors.push_back(my_vec);
  my_vec[4]=temp2;
  my_vec[1]=temp1;
  my_vec[3]='0';
  neighbors.push_back(my_vec);
  my_vec[4]=temp3;
  my_vec[3]=temp2;
  my_vec[5]='0';
  neighbors.push_back(my_vec);
  my_vec[4]=temp4;
  my_vec[5]=temp3;
  my_vec[7]='0';
  neighbors.push_back(my_vec);
 }
  else if (my_vec[5]=='0'){
     char temp1= my_vec[2];
     char temp2= my_vec[4];
     char temp3= my_vec[8];
     my_vec[5]=temp1;
     my_vec[2]='0';
     neighbors.push_back(my_vec);
     my_vec[5]=temp2;
     my_vec[2]=temp1;
     my_vec[4]='0';
     neighbors.push_back(my_vec);
     my_vec[5]=temp3;
     my_vec[4]=temp2;
     my_vec[8]='0';
     neighbors.push_back(my_vec);
  }
  else if(my_vec[6]=='0'){
    char temp1 = my_vec[3];
    char temp2 = my_vec[7];
    my_vec[6]=temp1;
    my_vec[3]='0';
    neighbors.push_back(my_vec);
    my_vec[6]=temp2;
    my_vec[3]=temp1;
    my_vec[7]='0';
    neighbors.push_back(my_vec);
  }

  else if(my_vec[7]=='0'){
    
    char temp1 = my_vec[4];
    char temp2 = my_vec[6];
    char temp3 = my_vec[8];
    my_vec[7]=temp1;
    my_vec[4]='0';
    neighbors.push_back(my_vec);
    my_vec[7]=temp2;
    my_vec[4]=temp1;
    my_vec[6]='0';
    neighbors.push_back(my_vec);
    my_vec[7]=temp3;
    my_vec[6]=temp2;
    my_vec[8]='0';
    neighbors.push_back(my_vec);
  }

  else if(my_vec[8]=='0'){
    char temp1 = my_vec[5];
    char temp2 = my_vec[7];
    my_vec[8]=temp1;
    my_vec[5]='0';
    neighbors.push_back(my_vec);
    my_vec[8]=temp2;
    my_vec[5]=temp1;
    my_vec[7]='0';
    neighbors.push_back(my_vec);
   }
  return neighbors;
} 
  
  

  
