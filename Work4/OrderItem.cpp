#include "OrderItem.h"

OrderItem::OrderItem(int index, int qty)
{
	itemIndex = index;
	quantity = qty;
}

void OrderItem::displayOrderItem(vector<Drinkitem>& drinks)
{
	Drinkitem drinkitem = drinks[itemIndex - 1];
	cout << "�z���I�����Ƭ�: " << drinkitem.getName() << "" << drinkitem.getSize() << "" << quantity << "�M�A�C�M" << drinkitem.getPrice() << "���A�p�p" << drinkitem.getPrice() * quantity << "��" << endl;
}

int OrderItem::getIndex()
{
	return itemIndex;
}

int OrderItem::getQuantity()
{
	return quantity;
}


void OrderItem::printOrderItem(ofstream& output_file, vector<Drinkitem>& drinks)
{
	Drinkitem drinkitem = drinks[itemIndex - 1];
	output_file << "�z���I�����Ƭ�: " << drinkitem.getName() << "" << drinkitem.getSize() << "" << quantity << "�M�A�C�M" << drinkitem.getPrice() << "���A�p�p" << drinkitem.getPrice() * quantity << "��" << endl;
}


