// Program #4 – BG Insurance
// Programmer:  Zachary Goodman 1001
// Class:  CS 2020, SP 2022
// Due Date: Apr 3, 2022
// Purpose of program: Intake information from an outside file, and manipulate it using a linked list to change the member elements or display selective portions of the list

//neccessary outside libraries
#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
using namespace std;

//be sure to bring in the funciton declarations
#include "memberNode.h"
#include "memberList.h"

//neccessary to use an outside file
ifstream infile;

int main() {

  //allows us to access the outside file
  infile.open("memberData.txt");

  //all the variables we will use
	memberList MyListOfInt;
  memberList NewList;
  int DelID;
  int tempID;
  string tempName;
  string tempPolicy;
  int tempYear;
  int tempPremium;
  int choice;
	memberNode* HiNode;

  //an initial choice to see what the file wants to do
  infile >> choice;

  //until the program reads a seven, will keep asking for number which correspond to different actions pertaining to the outside file
  while (choice != 7) {

    //choice one intakes a series of data and adds another node to the linked list
    if (choice == 1) {
      infile >> tempID;
      infile.ignore();
      getline(infile, tempName);
      getline(infile, tempPolicy);
      infile >> tempYear;
      infile >> tempPremium;
      MyListOfInt.AddOneMember(new memberNode(tempID, tempName, tempPolicy, tempYear, tempPremium));
    }

    //choice 2 intake an ID then attempts to delete it from the linked list
    else if (choice == 2) {
      infile >> DelID;
      MyListOfInt.DeleteNode(DelID);
    }

    //choice 3 prints out all the members data in a tabular format
    else if (choice == 3) {
      MyListOfInt.PrintList();		
    }

    //choice 4 reads in a value for policy then calls the PrintPolicy funciton with said value
    else if (choice == 4) {
      infile.ignore();
      getline(infile, tempPolicy);
      MyListOfInt.PrintPolicy(tempPolicy);
    }

    //choice 5 reads in a value corresponding to a year, then calls the PrintYear function with said value
    else if (choice == 5) {
      infile >> tempYear;
      MyListOfInt.PrintYear(tempYear);
    }

    //only calls the PrintLowPremium function
    else if (choice == 6) {
      MyListOfInt.PrintLowPremium();
    }
    //if the value of choice is 7, then the while loop just exits
  infile >> choice;
  }

  //close the file so it can be used elsewhere
  infile.close();
	return 0;
}