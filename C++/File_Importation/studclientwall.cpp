// Program #4 – Hurricane Program
// Programmer:  Zachary Goodman 1001
// Class:  CS 2020, SP 2022
// Due Date: Mar 06, 2022
// Purpose: Run a simluated competition between two climbers and determine the winner
//Input: Most of the program is random and not based on user input. In fact, even the names are predetermines in the program so there is no outside input while the program is currently running
//Process: Using a class to store information, use random numbers to track how the position of the two climbers change over time, and then determine the winner.
//Output: Outputs the position and name of the climbers after each climb/drop, and then has a particular message congratulating the winner. 

//the neccessary libraries used in the program
#include <iostream>
#include <iomanip>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;

//includes the file with the class definitions used throughout the program
#include "wall.h"

int main() {
  //creates the two climbers who will be used in the race, using the wall class
  wall climber1("Coal");
  wall climber2("Jasper");

  //variable used later for the drop and climb functions
  int chance;

  //randomizes the number generation
  srand(time(0));

  //continues the program until at least one of the climbers has reached the top of the wall
  while (!((climber1.GetPosition() == 20) || (climber2.GetPosition() == 20))) {

    //variable chance becomes either 0 or 1, if it is 1 then it calls climb function, if 0 then calls the drop fucntion for climber 1. Afterwords, print the name and position of climber 1
    chance = (rand() % 2);
    if (chance == 1) {
      climber1.Climb();
    }
    else {
      climber1.Drop();
    }
    climber1.Print();

    //same code as above, except used for climber2
    chance = (rand() % 2);
    if (chance == 1) {
      climber2.Climb();     
    }
    else {
      climber2.Drop();
    }
    climber2.Print();

    //used to help formatting
    cout << endl;
  }

  //based on position, finds out if the winner is climber1 and if so, uses an accessor function to output their name 
  if ((climber1.GetPosition() == 20) && (climber2.GetPosition() != 20)) {
    cout << "Congratulations " << climber1.GetName() <<  "! You are the winner! " << climber2.GetName() << " got second and is eliminated.";
  }

    //same as above, except in the case of climber2
  else if ((climber2.GetPosition() == 20) && (climber1.GetPosition() != 20)) {
    cout << "Congratulations " << climber2.GetName() <<  "! You are the winner! " << climber1.GetName() << " got second and is eliminated.";
  }

    //if there is a tie, then player 1 wins and a special messgae is output if that is the cse
  else {
    cout << "Huh, looks like " << climber1.GetName() << " and " << climber2.GetName() << " tied. Well, based on an arbitary decision, " << climber1.GetName() << " is the winner. Sorry " << climber2.GetName() << ", the world isnt fair.";
  }
  
}