#include <iostream>
#include "coffeeMenu.h"
#include "coffeeOrder.h"
#include "foodMenu.h"


using namespace N;
using namespace std;
int main()
{

	coffeTypes().administratorPage();
	coffeTypes().coffeeMenu();
	foodList().foodMenu();
	orderCoffe().coffeeOrder();


}