// Program #1 – Hurricane Program
// Programmer:  Zachary Goodman 1001
// Class:  CS 2020, SP 2022
// Due Date: Feb 7, 2022
// Purpose of program: Intake information from an outside file, sort the file by name, and output the information organized. It then also outputs which cities have iolent winds or major floods, as well as the city with the highest winds. 

//all the libraries needed for this program to function
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <iomanip>
using namespace std;

//this function reads the data from an outside file and returns the number of cities in this outside file
int ReadData(vector<string>& city,vector<int>& wind,vector<double>& rain) {
  ifstream inFS;
  string tempstr;
  int i;
  int numCities = 0;

  inFS.open("hurricanes.txt");

  while (!(inFS.eof())) {
    getline(inFS, city.at(numCities));
    inFS >> wind.at(numCities);
    inFS >> rain.at(numCities);
    getline(inFS, tempstr);

    ++numCities;
  }

  inFS.close();
  return numCities;
}

//prints out the values in the vectors in an organized column pattern
void PrintVectors(vector<string> city,vector<int> wind,vector<double> rain, int numCities){
  int i;
  cout << "City              ";
  cout << "Wind       ";
  cout << "Rain       " << endl;
  for (i = 0; i < 35; ++i) {
    cout << "-";
  }
  cout << endl;
  for (i = 0; i < numCities; ++i) {
    cout << setw(17) << left;
    cout << city.at(i) << " ";
    cout << setw(3);
    cout << wind.at(i) << setw(3) << " mph" << "    ";
    cout << rain.at(i) << " in" << endl;
  }
  cout << endl;
}

//performs a seleciton sort that organizes the names of the cities alphabetically. It also sorts the correponding wind and rain values in the other arrays
void SelSort(vector<string>& city,vector<int>& wind,vector<double>& rain, int numCities) {
  int i;
  int j;
  string tempCity;
  int tempWind;
  double tempRain;
  for (i = 1; i < numCities; ++i) {
    j = i;
    while (j > 0 && city.at(j) < city.at(j-1)) {
      tempCity = city.at(j);
      city.at(j) = city.at(j-1);
      city.at(j-1) = tempCity;

      tempWind = wind.at(j);
      wind.at(j) = wind.at(j-1);
      wind.at(j-1) = tempWind;

      tempRain = rain.at(j);
      rain.at(j) = rain.at(j-1);
      rain.at(j-1) = tempRain;

      --j;
    }
  }
}

//sorts through the wind vector and prints all the cities with wind speeds equal to or greater than 120 mph. 
void ViolentWinds (vector<string> city,vector<int> wind,vector<double> rain, int numCities) {
  int i;
    cout << "Cities with violent winds:" << endl;
    for (i = 0; i < numCities; ++i) {
      if (wind.at(i) >= 120) {
        cout << setw(17) << left;
        cout << city.at(i) << " ";
        cout << setw(3);
        cout << wind.at(i) << setw(3) << " mph" << "    ";
        cout << rain.at(i) << " in" << endl;
    }
  }
  cout << endl;
}

//sorts through the rain vector and prints all the cities with rain equal to or greater than 3.5 inches.
void MajorFlood (vector<string> city,vector<int> wind,vector<double> rain, int numCities) {
  int i;
  cout << "Cities with major floods:" << endl;
  for (i = 0; i < numCities; ++i) {   
     if (rain.at(i) >= 3.5) {
      cout << setw(17) << left;
      cout << city.at(i) << " ";
      cout << setw(3);
      cout << wind.at(i) << setw(3) << " mph" << "    ";
      cout << rain.at(i) << " in" << endl;
    }
  }
  cout << endl;
}

//returns the index of the city with the highest wind speed
int WindiestCity (vector<int> wind, int numCities) {
  int i;
  int maxWind = wind.at(0);
  int maxWindIndex;
  for (i = 0; i < numCities; ++i) {
    if (maxWind < wind.at(i)) {
      maxWind = wind.at(i);
      maxWindIndex = i;
    }
  } 
  return maxWindIndex;
}

//returns the average wind speed of all the cities in the outside file
double AverWind (vector<int> wind, int numCities) {
  int i;
  double sum = 0;
  double avgWind;
  for (i = 0; i < numCities; ++i) {
    sum = sum + wind.at(i);
  }

  avgWind = sum / numCities;

  return avgWind;
}

//retusnt te average rainfall of all the cities in the outside file
double AverRain (vector<double> rain, int numCities) {
  int i;
  double sum = 0;
  double avgRain;
  for (i = 0; i < numCities; ++i) {
    sum = sum + rain.at(i);
  }

  avgRain = sum / numCities;

  return avgRain;
}

int main() {
  //neccessary to input data from an outside file
  ifstream inFS;

  //the vectors used to store the data from the outside file. 50 was the maximum number of cities and as such that is the starting size of the vectors
  int MAX_CITIES = 50;
  vector<string> city(MAX_CITIES);
  vector<int> wind(MAX_CITIES);
  vector<double> rain(MAX_CITIES);

  //initialization of other variables used throughout the program 
  int numCities;
  int maxWindIndex;
  double avgWind;
  double avgRain;

  //code below is simply calling the various functions from above
  numCities = ReadData(city, wind, rain); 

  SelSort(city, wind, rain, numCities);

  cout << "The data file consists of:" << endl;
  PrintVectors(city, wind, rain, numCities);

  ViolentWinds(city, wind, rain, numCities);

  MajorFlood(city, wind, rain, numCities);

  maxWindIndex = WindiestCity(wind, numCities);
  
  //uses the index from maxWindIndex and outputs the information in a digestible way
  cout << city.at(maxWindIndex) << " is the windiest city at " << wind.at(maxWindIndex) << "mph." << endl << endl;

  avgWind = AverWind(wind, numCities);
  avgRain = AverRain(rain, numCities);

  //uses the averages from the aver functions and output them in an understadable format
  cout << "The average wind is " << avgWind << " mph" << endl;

  cout << "The average rain is " << avgRain << " inches" << endl;

}