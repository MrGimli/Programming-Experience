// Program #4 – BG Insurance
// Programmer:  Zachary Goodman 1001
// Class:  CS 2020, SP 2022
// Due Date: Apr 3, 2022
// Purpose of program: Intake information from an outside file, and manipulate it using a linked list to change the member elements or display selective portions of the list

//the memberNode function definitions

//neccessary libraries
#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>

using namespace std;

//inclusion of the memberNode declarations
#include "memberNode.h"

//constructor
memberNode::memberNode(int dataInit, string nameInit, string policyInit, int yearInit, int premiumInit, memberNode* nextLoc) {
	this->id = dataInit;
  this->name = nameInit;
  this->policy = policyInit;
  this->year = yearInit;
  this->premium = premiumInit;
	this->nextNodePtr = nextLoc;
}

// destructor
memberNode::~memberNode() {
	cout << id << " member removed" << endl;
	if (nextNodePtr != nullptr) {
		delete nextNodePtr;
		nextNodePtr = nullptr;
	}
}

//print data in node
void memberNode::PrintData() {
	cout << setw(5) << left << this->id;
  cout << setw(20) << this->name;
  cout << setw(16) << this->policy;
  cout << setw(10) << this->premium;
  cout << this->year << endl;
}

//print the tabular framework to organize the data output in the PrintData function
void memberNode::PrintFormat() {
  cout << setw(5) << left << "ID";
  cout << setw(20) << "Name";
  cout << setw(16) << "Policy";
  cout << setw(10) << "Premium";
  cout << "Year" << endl;

  cout << "--   ----                ------          -------   ----" << endl;
}

// function that returns the pointer to the next node, relavent for going through the entire list
memberNode* memberNode::GetNext() {
	return this->nextNodePtr;
}

//function that changes where a node points to as the next value
void memberNode::SetNext(memberNode* nextNodeLoc){
	nextNodePtr = nextNodeLoc;
}

//returns a node's data value, basically just all my getter functions
int memberNode::Getid() {
	return this->id;
}

string memberNode::GetName() {
  return this->name;
}

string memberNode::GetPolicy() {
  return this->policy;
}

int memberNode::GetYear() {
  return this->year;
}

int memberNode::GetPremium() {
  return this->premium;
}