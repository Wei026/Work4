#pragma once
#include <iostream>
#include <string>
#include <iomanip>
using namespace std;
class Drinkitem
{
	string drinkName;
	string drinkSize;
	int drinkPrice;
public:
	Drinkitem(const string&, const string&, int);
	string getName();
	string getSize();
	int getPrice();
	void displayItem();
};

