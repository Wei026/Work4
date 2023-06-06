#include "Drinkitem.h"

Drinkitem::Drinkitem(const string& name, const string& size, int price)
{
	drinkName = name;
	drinkSize = size;
	drinkPrice = price;
}

void Drinkitem::displayItem()
{
	cout << setw(10) << drinkName << setw(10) << drinkSize << setw(10) << drinkPrice << endl;
}

string Drinkitem::getName()
{
	return drinkName;
}

string Drinkitem::getSize()
{
	return drinkSize;
}

int Drinkitem::getPrice()
{
	return drinkPrice;
}
