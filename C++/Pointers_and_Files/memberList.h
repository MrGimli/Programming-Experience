// Program #4 – BG Insurance
// Programmer:  Zachary Goodman 1001
// Class:  CS 2020, SP 2022
// Due Date: Apr 3, 2022
// Purpose of program: Intake information from an outside file, and manipulate it using a linked list to change the member elements or display selective portions of the list

//memberlist declarations
#ifndef memberList_H
#define memberList_H

//neccessary libraries
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <fstream>
#include <string>

//should also include the memberNode declarations
#include "memberNode.h"
using namespace std;

class memberList {
public:

//Default Constructor, No paramters for this class
	memberList() {} 

//copy constructor
  memberList(memberList& rhs);		

//Destructor, dealocates all of the memory use in the lists
  ~memberList();				

//Overloaded Assignment Operator
	memberList& operator=(memberList& rhs);	

// adds a node to the end of the list
	void PushBack(memberNode* nuNode); 

// adds a node to the head of the list
	void AddOneMember(memberNode* nuNode); 

//search the list and deletes the node with the given ID
	void DeleteNode(int dval);		

//find and prints the name and premium of the member with the lowest premium
	void PrintLowPremium();			

//prints all the members with the relevent policy with their corresponding data, as well as print the average premiums of said members
	void PrintPolicy(string policyWanted);	

//finds the members who have greater than or equal to the number of years according to the input value, and prints them and their data
  void PrintYear(int yearWanted);

//prints all the members in a tabular format
	void PrintList();				

private:
	memberNode* head = nullptr;	    //Pointer to the first node in the list
	memberNode* tail = nullptr;		//Pointer to the last node in the list

};
#endif

