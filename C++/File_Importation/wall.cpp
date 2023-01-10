//this file includes all the class function definitions

//the neccessary libraries for this file
#include <iostream>
#include <ctime>
#include <string>

using namespace std;

//since these are the function definitions for the class, we need to bring in the class definition as wel
#include "wall.h"

//constructor for the wall class that takes a name in through a parameter but has a default position value of 0 since all climbers start on the floor
wall::wall(string climberName){
  name = climberName;
  position = 0;
}

//accessors used to recieve the name or position fo the climbers
string wall::GetName() {
  return name;
}

int wall::GetPosition() {
  return position;
}

//A print function that wasn't required but made the code easier to read 
void wall::Print() {
  cout << name << " is at " << position << " feet" << endl;
}

//the climb function that gets a random value from 1 to 3 and adds it to the climbers position. Also has a check for if a climber goes past 20 feet an sets their position to 20 if that is the case
void wall::Climb() {
  int result = 0;
  result = ((rand() % 3) + 1);
  position = position + result;
  if (position > 20) {
    position = 20;
  }
}

//the drop function that gets a random value from 1 to 3 and subtracts it to the climbers position. Also has a check for if a climber goes under 0 feet an sets their position to 0 if that is the case
void wall::Drop() {
  int result = 0;
  result = ((rand() % 3) + 1);
  position = position - result;
  if (position < 0) {
    position = 0;
  }
}

//setting functions, not required either but were used  to test particlar values for the program independent of the random chance
void wall::SetName(string climberName) {
   name = climberName;
}

void wall::SetPosition(int climberPosition) {
   position = climberPosition;
}