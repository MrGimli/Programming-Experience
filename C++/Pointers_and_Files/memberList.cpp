// Program #4 – BG Insurance
// Programmer:  Zachary Goodman 1001
// Class:  CS 2020, SP 2022
// Due Date: Apr 3, 2022
// Purpose of program: Intake information from an outside file, and manipulate it using a linked list to change the member elements or display selective portions of the list

//linked list definitions

//bring in all the other declarations
#include "memberNode.h"
#include "memberList.h"

//neccessary libraries
#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
using namespace std;

//linked list destroyer
memberList::~memberList()
{
	if (head) {
		delete head;
		head = nullptr;
		tail = nullptr;
	}
}

//overloading = operator for dynamic memoroy allotion 
memberList& memberList::operator=(memberList& rhs){
	memberNode* currObj = rhs.head;      // Copy List
	cout << "Overloaded assignment operator called" << endl;
	if (head != rhs.head)
	{
		if (head){
			delete head;
			head = nullptr;
			tail = nullptr;
		}
		while (currObj != nullptr) {
			PushBack(new memberNode(currObj->Getid(),currObj->GetName(),currObj->GetPolicy(),currObj->GetYear(),currObj->GetPremium()));
			currObj = currObj->GetNext();					//Traversal Statement
		}													
	}
	return *this;
}

//copy constructor 
memberList::memberList(memberList& rhs){
	memberNode* currObj = rhs.head;     // Copy List
	cout << "Copy Constructor called\n";

	while (currObj != nullptr) {
		PushBack(new memberNode(currObj->Getid(),currObj->GetName(),currObj->GetPolicy(),currObj->GetYear(),currObj->GetPremium()));
		currObj = currObj->GetNext();					//Traversal Statement
	}													
}

//adds node into the end of a linked list
void memberList::PushBack(memberNode* nuNode){
	if (!head){
		head = tail = nuNode;
	}
	else{
		tail->SetNext(nuNode);
		tail = nuNode;
	}
}

//adds node to the front of a linked list
void memberList::AddOneMember(memberNode* nuNode){
	if (!head){
		head = tail = nuNode;
	}
	else{
		nuNode->SetNext(head);
		head = nuNode;
	}
	cout << nuNode->Getid() << " member added." << endl;
}

// searches for a node by id and if finding it then deletes it
void memberList::DeleteNode(int dval){
	memberNode* currNode = nullptr;       // To traverse the list
	memberNode* prevNode = nullptr;  // To point to the previous node

	 //Scenario #1 Empty List
	// If the list is empty, do nothing.
	if (!head){
		cout << "The list is empty." << endl;
		cout << "As such, " << dval << " is not a member." << endl;
		return;
	}
	//Scenario #2 delete the head
	// Determine if the first node is the one.
	if (head->Getid() == dval){
		currNode = head;
		if (head == tail)
			tail = nullptr;
		head = head->GetNext();
		currNode->SetNext(nullptr);
		delete currNode;
	}
	else{
		//Scenario #3 Node is on the list elsewhere
		// Scenario #4  Node is not on the list
		// Initialize currNode to head of list
		currNode = head;

		// Skip all nodes whose value member is 
		// not equal to target until you reach the end
		while (currNode && currNode->Getid() != dval){
			prevNode = currNode;
			currNode = currNode->GetNext();				//Traversal Statement
		}												//Important to point to the next node
		// If currNode is not at the end of the list, 
		// link the previous node to the node after
		// currNode, then delete currNode.
		if (currNode){
			prevNode->SetNext(currNode->GetNext());
			currNode->SetNext(nullptr);
			if (currNode == tail)
				tail = prevNode;
			delete currNode;
		}
		else
			cout << dval << " is not a member." << endl;
	}
}

//returns the lowest value of premium of all the members
void memberList::PrintLowPremium(){
	memberNode* currObj = head;  
	memberNode* lowObj = head;
	while (currObj != nullptr) {
		if (currObj->GetPremium() < lowObj->GetPremium())
			lowObj = currObj;
		currObj = currObj->GetNext();//Traversal Statement
	}											
  cout << lowObj->GetName() << " has the lowest premium at " << lowObj->GetPremium() << " dollar(s)." << endl;
}

//prints all the members that have the desired policy as well as computes the average of their premiums
void memberList::PrintPolicy(string policyWanted){
	memberNode* currObj = head;  
  double sum = 0.0;
  int count = 0;
	cout << "Members with the " << policyWanted << " policy include:" << endl;
	currObj->PrintFormat();

	while (currObj != nullptr) {
		if (currObj->GetPolicy() == policyWanted){
			currObj->PrintData();
      sum = sum + currObj->GetPremium();
      count++;
      }
		  currObj = currObj->GetNext();		
      //Traversal Statement
	}												

  //if there is at least one member with the policy, then computes the average, but if there are none then print as much
  if (count > 0) {
    cout << "The average premium of " << policyWanted <<" members is $" << (sum/count) << endl;  
    }
  else {
    cout << "Sorry, no " << policyWanted << " members." << endl;
  }
}

//finds the members who have greater than or equal to the number of years according to the input value, and prints them and their data
void memberList::PrintYear(int yearWanted){
	memberNode* currObj = head;  
  int count = 0;
	cout << "Members with at least " << yearWanted << " years" << endl;
	currObj->PrintFormat();

	while (currObj != nullptr) {
		if (currObj->GetYear() >= yearWanted) {
			currObj->PrintData();
      count++;
    }
		currObj = currObj->GetNext();				//Traversal Statement
	}
  // if statement to mention if no members meet the criteria
  if (count == 0) {
    cout << "Sorry, no members with " << yearWanted << " or more years";
    }
  cout << endl;
}

//prints all the id in the list
void memberList::PrintList(){
	memberNode* currObj = head;

	currObj->PrintFormat();
	while (currObj != nullptr) {
		currObj->PrintData();
		currObj = currObj->GetNext();			//Traversal Statement
	}											
  cout << endl;
}