// Program #4 – BG Insurance
// Programmer:  Zachary Goodman 1001
// Class:  CS 2020, SP 2022
// Due Date: Apr 3, 2022
// Purpose of program: Intake information from an outside file, and manipulate it using a linked list to change the member elements or display selective portions of the list

//the node class definition
#ifndef memberNode_H
#define memberNode_H

//the neccessary librarys
#include <iostream>
#include <cstdlib>
#include <iomanip>
#include <fstream>
#include <string>
using namespace std;

class memberNode {
public:

  //the base constructor for membernode
	memberNode(int dataInit = 0, string nameInit = "null", string policyInit = "null", int yearInit = 0, int premiumInit = 0, memberNode * nextLoc = nullptr);

	~memberNode();	//Destructor 

  //getter function declarations
	int Getid();
  string GetName();
  string GetPolicy();
  int GetYear();
  int GetPremium();

	memberNode* GetNext();
	void SetNext(memberNode* nextNodeLoc);		//Allows the client to change where the node points

  //function declarations for functions that print out individuals nodes data and help organize it
	void PrintData();
  void PrintFormat();

private:

  //all the relavent values within the node
	int id;
  string name;
  string policy;
  int year;
  int premium;
	memberNode* nextNodePtr;  // pointer to the next node
};
#endif

