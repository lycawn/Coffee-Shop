#include "foodMenu.h"
#include <iostream>
#include <vector>
#include <fstream>

using namespace N;
using namespace std;

void foodList::foodMenu()
{
	ofstream foodList;
	vector<string> foodMenu =
	{
		"Ham sandwich",
		"Cheese Pie",
		"Cheese cake",
		"Brownies",
		"Vanilla Donut",
		"Bueno Donut"
	};
	foodList.open("foodList.txt");
	for (auto val : foodMenu)
	{

		foodList << " " <<  val << endl;

	}
	foodList.close();
}