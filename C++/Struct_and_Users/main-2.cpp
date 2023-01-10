// Program #2 – Hurricane Program
// Programmer:  Zachary Goodman 1001
// Class:  CS 2020, SP 2022
// Due Date: Feb 20, 2022
// Purpose of program: Based off of user input, the program stores information pertaining to products and their corresponding quantities and prices. There are then other funcitons allowing for displaying of the information and other more particular pieces of sorting of the data. 

//all the libraries needed for this program to function
#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
using namespace std;

//creates a struct that can store a name, quantity, and price
struct Product {
  string name;
  int qtny;
  double price;
};

//The menu function that displays the possible other functions the user can call and returns the user's choice. 
int menu() {

  int choice;

  cout << "1. Add new product" << endl;
  cout << "2. Average Price" << endl;
  cout << "3. Highest Price" << endl;
  cout << "4. Display out of stock" << endl;
  cout << "5. Display all products in inventory" << endl;
  cout << "6. Exit the program" << endl;

  cout << "Enter your choice: " << endl;

  cin >> choice;
  //input validation
  while (!(choice >= 1 && choice <= 6)) {
    cout << "Invalid input. Input should be between 1-6" << endl;
    cin >> choice;
  }

  return choice;
}

//function that asks for the name, quantity, and price of a profuct and adds them to our struct vector
void addprod(vector<Product> &bginventory) {
  Product tempInventory;
  cout << "Enter the name of the product: " << endl; 
  cin >> tempInventory.name;
  cout << "Enter the quantity of the product: " << endl;
  cin >> tempInventory.qtny;
  cout << "Enter the price of the product: " << endl;
  cin >> tempInventory.price;
  bginventory.push_back(tempInventory);
}

//function that interates through all the prices of the products and prints out the average
void showavgprice(vector<Product> bginventory) {
  double sum = 0;
  int i; 

  for (i = 0; i < bginventory.size(); ++i) {
    sum = sum + bginventory.at(i).price;
  }
  sum = sum / (bginventory.size() - 1);
  cout << fixed << setprecision(2);
  cout << "Average Price: $" << sum << endl;
}

//function that iterates through the vector and prints out the product with the highest price; both its name and price
void showhiprice(vector<Product> bginventory) {
  double temp = bginventory.at(0).price;
  int index = 0;
  int i;

  for (i = 0; i < bginventory.size(); ++i) {
    if (bginventory.at(i).price > temp) {
      temp = bginventory.at(i).price;
      index = i;
    }
  }

  cout << "Most Expensice Product: " << bginventory.at(index).name << endl;
  cout << fixed << setprecision(2);
  cout << "Highest Price: $" << bginventory.at(index).price << endl;
}

//function that iterates through the vector and outputs the product information for all the products which have a quantity of 0
void showoutofstock(vector<Product> bginventory) {
  int i;

  cout << "The products out of stock are: " << endl;
  for (i = 0; i < bginventory.size(); ++i) {
    if (bginventory.at(i).qtny == 0) {
      cout << bginventory.at(i).name << endl;
    }
  }
}

//function that outputs the information pertaining to all the products stored in the vector
void showinventory (vector<Product> bginventory) {
  int i;

  cout << "Name              | Quantity | Price   " << endl;
  for (i = 0; i < 39; ++i) {
    cout << "-";
  }
  cout << endl;
  for (i = 1; i < bginventory.size(); ++i) {
    cout << setw(18) << left << bginventory.at(i).name << "| ";

    cout << setw(9) << bginventory.at(i).qtny << "| ";

    cout << fixed << setprecision(2);
    cout << "$" << bginventory.at(i).price << endl;
  }
}

int main() {
  //creates the vector of structs of our products 
  vector<Product> bginventory(1);

  //the variables we will use later in the program
  int choice; 
  int i;

  //stores the user's inputed choice into the proper variable
  choice = menu();

  //a while loop that iterates through unless the user inputs a 6. Each number corresponds to one of the other functions
  while (choice != 6) {
    switch (choice) {
      case 1:
      addprod(bginventory);
      break;

      case 2: 
      showavgprice(bginventory);
      break;

      case 3:
      showhiprice(bginventory);
      break;

      case 4:
      showoutofstock(bginventory);
      break;
    
      case 5:
      showinventory(bginventory);
      break;
    }
  
    //calls the menu function to show the possible functions and regain the user's input
    choice = menu();
  }

  
}