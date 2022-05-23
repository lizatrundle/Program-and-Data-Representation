// Liza Trundle
//emt8kdn
//inlab 11 


#include <iostream>
#include <string>
#include <cstdlib>
#include <vector>
#include <algorithm>

using namespace std;

#include "middleearth.h"

float computeDistance(MiddleEarth &me, const string& start, vector<string> dests);
void printRoute(const string& start, const vector<string>& dests);



/*! \class main
 *  \brief holds a program computes traveling salesman problem to return
shortest path 
 *   
 *  
 */
  
int main(int argc, char** argv) {
  
    /**
 * reading  with command line parameters
 */
    if (argc != 6) {
        cout << "Usage: " << argv[0] << " <world_height> <world_width> "
             << "<num_cities> <random_seed> <cities_to_visit>" << endl;
        exit(0);
    }
    
    
    /**
 * variables used from the command line parameters 
 * \public
 */
    int width = stoi(argv[1]);
    int height = stoi(argv[2]);
    int num_cities = stoi(argv[3]);
    int rand_seed = stoi(argv[4]);
    int cities_to_visit = stoi(argv[5]);
    

    
    /** create the world, and select your itinerary
     * this builds a grid of the world and makes size width by height
     * randomly pick 10 cities
     * each city is a name tied to points on a grid
     */
    
    MiddleEarth me(width, height, num_cities, rand_seed);
    
    
    vector<string> dests = me.getItinerary(cities_to_visit);
    
   
    //dests.erase(dests.begin());

    /** 
     * in order to use next_permutation you must sort the vector first
     *sorting the vector minus the start city since we already have this
     */ 
    
    sort(dests.begin()+1, dests.end());
    
    string start_city = dests[0];

    
    vector <string> min_path = dests;

    
    float smallest = computeDistance(me, start_city, dests);

    
    do {
      
      float smallest_temp = computeDistance(me, start_city, dests);

           /**
 * \if
 */ 
      if (smallest_temp<smallest){
	
	min_path = dests;
	
	smallest = smallest_temp;
    /**
 * \endif
 */ 
      
      }
    } while (next_permutation(dests.begin()+1, dests.end()));

	     
    string final_start = min_path[0];
    float dist =  computeDistance(me, final_start, min_path);
    
    cout<< "Minimum path has distance " << dist  << " :";
    
    printRoute(final_start,min_path);
    

    return 0;
	   
	   }


 /*! @brief A method to compute full ditance of cycle that staerts at start parameter, goes to each cities in dests, and returns to start 
      @param me  middleearth world
      @param start starting city as string 
      @param dests vector of all visiting cities 
 
    */

float computeDistance(MiddleEarth& me, const string& start, vector<string> dests) {
    // TODO: YOUR CODE HERE
  string start_string = start;
  string end_string = dests.back();
  float distance= 0.0;


  // getting the cycle distance that starts at start city and goes to each one
  for(int i=0; i<dests.size(); i++){
    
    distance += me.getDistance(start_string, dests.at(i));
    start_string = dests[i];
}
// accounting for the final distance back to the start

distance+= me.getDistance(dests[0], dests.back());
return distance; 

}



 /*! @brief This method will print the entire route, starting and ending at the 'start' parameter.
      @param start starting city as string 
      @param dests vector of all visiting cities 
 
    */
void printRoute(const string& start, const vector<string>& dests) {
  // save the shortest distance vector and then loop through it and print it out

  for (int i =0; i<dests.size(); i++){
    cout<< dests[i] << " -> ";
    
  }
  
  cout<<start<<endl;

}
