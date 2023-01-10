//the file with the class definition
//more detailed comments on the functions are included in the wall.cpp file

#ifndef WALL_H
#define WALL_H

using namespace std;

class wall {
  public:
    //constructor
    wall(string climberName);

    //outputting function for name and position 
    void Print();

    //getter functions
    string GetName();
    int GetPosition();

    //two main functions that affect climber position
    void Climb();
    void Drop();

    //setter functions used in testing
    void SetName(string climberName);
    void SetPosition(int climberPosition);

  private:
    //private part of the class that stores the name and position of the climbers
    string name;
    int position;
};

#endif