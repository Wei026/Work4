#pragma once
#include <vector>
#include <fstream>
#include "Drinkitem.h"

class OrderItem
{
	//飲料品項的第幾個
	int itemIndex;

	//訂了幾杯
	int quantity;


public:
	OrderItem(int, int);
	int getIndex();
	int getQuantity();
	void displayOrderItem(vector<Drinkitem>&);
	void printOrderItem(ofstream& output_file, vector<Drinkitem>& );
};

