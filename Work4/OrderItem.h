#pragma once
#include <vector>
#include <fstream>
#include "Drinkitem.h"

class OrderItem
{
	//���ƫ~�����ĴX��
	int itemIndex;

	//�q�F�X�M
	int quantity;


public:
	OrderItem(int, int);
	void displayOrderItem(vector<Drinkitem>&);
	int getIndex();
	int getQuantity();
	void printOrderItem(ofstream& output_file, vector<Drinkitem>& );
};

