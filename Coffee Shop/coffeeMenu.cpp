#include <iostream>
#include "coffeeMenu.h"
#include <fstream>

using namespace std;
using namespace N;

void coffeTypes::coffeeMenu()
{
	ofstream coffeeFile;
	int countCoffee{0};
	vector<string> coffees = {
		"Freddo Espresso",
		"Capuccino",
		"Latte",
		"Freddo Capuccino",
		"Espresso",
		"Water"
	};
	coffeeFile.open("coffeeMenu.txt");
	cout << "==>>> Coffee Menu <<<==" << endl;
	for (auto val : coffees)
	{
	
	coffeeFile << " " << val << endl;
	}
	coffeeFile.close();
	cout << endl;

}