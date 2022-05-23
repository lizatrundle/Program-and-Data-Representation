#ifndef MIDDLEEARTH_H
#define MIDDLEEARTH_H

#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <random>

using namespace std;

// see the comments in the lab11 write-up, or in middleearth.cpp

class MiddleEarth {
public:

  /**
   *constuctor for Middleearth 
     
     */
    /*! @brief A constructor to create MiddleEarth
      @param xsize middleearth size from x
      @param ysize middleearth size from y 
      @param num_cities the number of cities in middleearth
      @param seed random seed
    */

  
    MiddleEarth(int xsize, int ysize, int num_cities, int seed);

     /*!
     print method to print out middle earth
     */
    void print();
     /*!
     print distances
     */
    
    void printTable();

    /*! @brief method to return distance
      @param city1  city1 name
      @param city2  city2 name
     */
    float getDistance(const string& city1, const string& city2);
    
/*! @brief method to get itinerary; returns vector of strings 
      @param length length of roadmap 
     */
    
    vector<string> getItinerary(unsigned int length);

private:

    /**
     Private variables that hold locations
     */
    
    /*!
     The number of cities and the size of the location
     */

    
    int num_city_names, xsize, ysize;
    /*! unordered map of positions of the cities
    
    */
    
    unordered_map<string, float> xpos, ypos;
     /*! vector of city names 
    
    */
    vector<string> cities;
     /*! unordered map of cities distances 
    
    */
    unordered_map<string, unordered_map<string, float>> distances;

    
 /*! random number engine  
    
    */
    mt19937 gen; 
};

#endif
