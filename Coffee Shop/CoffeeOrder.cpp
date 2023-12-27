#include <iostream>
#include <fstream>
#include <vector>
#include "coffeeOrder.h"
#include <string>


using namespace N;
using namespace std;


void orderCoffe::coffeeOrder()
{

	//Variables

	ofstream totalOrder;
	fstream coffeeFile, foodFile;
	string coffeeMenu{};
	string foodList;
	vector<string> orderCoffee{};
	vector<double> coffeePrice{ 3, 2.5, 3, 5, 3, 0.50 };
	vector<double> foodPrice{ 1.2, 3.2, 5.3, 2.35, 3, 2.80 };
	double totalPrice;
	int order = 0;
	int countFood = 0;
	int countCoffee{ 0 };
	int foodChoice;
	char foodYn;
	char commentYn = {};
	vector<string> foodMenu{};
	string commentBarista;
	

	//Pointers
	const double* dpr;
	dpr =  &deliveryCost;


	//menu Push back to vector
	coffeeFile.open("coffeeMenu.txt");
	if (coffeeFile.is_open()) {
		while (getline(coffeeFile, coffeeMenu)) {

			orderCoffee.push_back(coffeeMenu);
		}


	}
	foodFile.open("foodList.txt");
	if (foodFile.is_open()) {
		while (getline(foodFile, foodList)) {
			foodMenu.push_back(foodList);
		}
	}


	//COFFEE MENU

	for (auto val : orderCoffee)
	{
		countCoffee++;
		cout << "[" << countCoffee << "]" << val << " " << coffeePrice.at(countCoffee - 1)<< "$" << endl;
	}

	cin >> order; // Taking order
	cout << "Your coffee Order is : " << orderCoffee.at(order - 1) << " costs : " << coffeePrice.at(order - 1) << "$" << endl;

	cout << "Would you like to order something to eat ? Y/N " << endl; 
	cin >> foodYn;
	switch (foodYn)
	{
	case 'y': // printing food menu
		for (auto val : foodMenu) {
			countFood++;
			cout << "[" << countFood << "]" << val << " " << foodPrice.at(countFood -1)<< "$" << endl;
		}
		cout << "Pick your food" << endl;
		cin >> foodChoice;
		totalPrice = coffeePrice.at(order - 1) + foodPrice.at(foodChoice - 1) + *dpr;
		totalOrder.open("totalOrder.txt");
		totalOrder << "Coffee : " << orderCoffee.at(order - 1) << endl;
		totalOrder << "Food : " << foodMenu.at(foodChoice - 1) << endl; // printing totalOrder
		totalOrder << "Price :" << totalPrice << "$" << endl;
		break;
	case 'n':
		cout << "No snack" << endl;
		foodChoice = 0;
		totalOrder.open("totalOrder.txt");
		totalOrder << "Coffee : " << orderCoffee.at(order - 1) << endl;
		totalOrder << "Price :" << coffeePrice.at(order - 1) + *dpr << "$" << endl;
		break;
	}
	do
	{ // comment section
		cout << "Would you like to enter a comment for the barista ? Y/N" << endl;
		cin >> commentYn;

	} while (commentYn != 'y' && commentYn != 'Y' && commentYn != 'n' && commentYn != 'N');
		switch (commentYn) {
		case 'y':
		case 'Y':
			cout << "Enter your comment: " << endl;
			cin.ignore();
			getline(cin, commentBarista);
			break;
		case 'n':
		case 'N':
			cout << "No comment added.." << endl;
			break;
		default:
			cout << "Invalid Key" << endl;
			break;
		}

		cout << "Delivery Cost: " << *dpr << "$" << endl;
		double totalPricex;
		//orderCoffee.at(order - 1).erase(0, 3); // Erasing [1] Menu
	
		if (foodChoice == 0) {
			cout << "TOTAL ORDER: " << (orderCoffee.at(order - 1)) << " Food :" << "No Food" << endl;
			cout << "TOTAL PRICE: " << totalPrice << "$" << endl;
		} else 
		{
			totalPricex = coffeePrice.at(order - 1) + foodPrice.at(foodChoice - 1) + *dpr;
			cout << "TOTAL ORDER: " << (orderCoffee.at(order - 1)) << " Food :" << foodMenu.at(foodChoice - 1) << endl;
			cout << "TOTAL PRICE: " << totalPricex << "$" << endl;
		}

		totalOrder << "Comment: " << ((commentBarista.size() == 0 ) ? "No Comment Added." :commentBarista) << endl;
		coffeeFile.close();
		totalOrder.close(); 
		foodFile.close();

}