#include "Drinkitem.h"
#include <iomanip>
Drinkitem::Drinkitem(const string& name, const string& size, int price)
{
	drinkName = name;
	dringSize = size;
	drinkPrice = price;
}

void Drinkitem::displayItem()
{
	cout << setw(10) << drinkName << setw(10) << dringSize << setw(10) << drinkPrice << endl;
}
