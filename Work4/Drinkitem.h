#pragma once
#include <iostream>
#include <string>
using namespace std;
class Drinkitem
{
	string drinkName;
	string dringSize;
	int drinkPrice;
public:
	Drinkitem(const string&, const string&, int);
	void displayItem();
};

