#include <iostream>
#include "coffeeMenu.h"
#include <fstream>
#include <vector>
#include <string>

using namespace std;
using namespace N;
vector<string> coffees =
{
"Freddo Espresso",
"Capuccino",
"Latte",
"Freddo Capuccino",
"Espresso",
"Water"
};

// Creating coffee menu
void coffeTypes::coffeeMenu()
{
	ofstream coffeeFile;
	int countCoffee{0};
	
	coffeeFile.open("coffeeMenu.txt");
	cout << "==>>> Coffee Menu <<<==" << endl;
	for (auto val : coffees)
	{
	
	coffeeFile << " " << val << endl;
	}
	coffeeFile.close();
	cout << endl;

}

// ADMIN PAGE PANEL
void coffeTypes::administratorPage()
{	
	ofstream coffeeFile, coffeePrice;
	int action;
	int coffeesCount = 0;
	int removeCoffee;
	int action1;
	string userName = "admin";
	string password = "adminPass";
	string userInput;
	string passwordInput;
	int givePrice;
	string addProduct{};

	do {
	
			cout << "[1]Admin Page [2]CustomerPage [3]Show Coffee Shop Details [4]to Quit" << endl;
		cin >> action;

		switch (action)
		{
		case 1:
		
			do {
				cout << "User name : " << endl;
				cin.ignore();
				getline(cin, userInput);
				cout << "Password : " << endl;
				cin.ignore();
				getline(cin, passwordInput);
				if (userInput != userName && passwordInput != password) {
					cout << "wrong user name or password please try again.." << endl;
				}
		} while (userInput != userName && passwordInput != password);

			cout << "[1]Add Coffee [2] Add Food" << endl;
			cin >> action1;
			switch (action1) {
			case 1:
				 // push back Product
				cout << " Enter the product you want to add " << endl;
				coffeeFile.open("coffeeMenu.txt");
				cin.ignore();
				getline(cin, addProduct);
				coffees.push_back(addProduct);
				for (auto val : coffees) {
					coffeeFile << " " << val << endl;
				}
				// give price
				coffeeFile.close();
				cout << "Add a price $: " << endl;
				cin >> givePrice;
				coffeePrice.open("price.txt");
				coffeePrice << givePrice;
				coffeePrice.close();
				break;
			case 2:
				cout << " Enter the product you want to add" << endl;
				break;
			} break;
			
		case 2:
			cout << "Entering customer's page..." << endl;
			cout << "============================" << endl;
			cout << endl;
			action = 4;
			break;
		case 3:
			cout << "Broady Coffee Shop" << endl;
			cout << "Broadway avenue str 90" << endl;
			cout << "Phone : +4130513022" << endl;
			break;
		case 4:
			cout << "Quiting panel " << endl;
			break;
		};
	} while (action != 4);
	

}