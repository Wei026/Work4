#include <iostream>
#include <vector>
#include <iomanip>
#include "Drinkitem.h"
#include "OrderItem.h"
#include "Work4.h"

void AddNewDrink(std::vector<Drinkitem>& drinks)
{
	//Drinkitem drink1("紅茶", "大杯", 30);
	//drinks.push_back(drink1);
	drinks.push_back(Drinkitem("紅茶", "大杯", 30));
	drinks.push_back(Drinkitem("紅茶", "小杯", 20));
	drinks.push_back(Drinkitem("綠茶", "大杯", 30));
	drinks.push_back(Drinkitem("綠茶", "小杯", 20));
	drinks.push_back(Drinkitem("咖啡", "大杯", 50));
	drinks.push_back(Drinkitem("咖啡", "小杯", 40));
	drinks.push_back(Drinkitem("可樂", "大杯", 50));
	drinks.push_back(Drinkitem("可樂", "小杯", 40));
}

void DisplayDrinkMenu(vector<Drinkitem>& drinks) 
{
	cout << setw(4) << "編號" << setw(10) << "飲料名稱" << setw(10) << "大小" << setw(10) << "售價" << endl;
	cout << "------------------------------------------" << endl;

	//方法一
	int i = 1;
	for (Drinkitem item : drinks) 
	{
		cout << setw(4) << i;
		item.displayItem();
		i++;
	}

	//方法二
	//int i = 1;
	//vector<Drinkitem>::iterator v = drinks.begin();
	//while (v != drinks.end())
	//{
	//	cout << setw(4) << i;
	//	v->displayItem();
	//	v++;
	//	i++;
	//}

	cout << "------------------------------------------" << endl;
}

void OrderDrink(vector<OrderItem>& order) 
{

}

int main()
{
	vector<Drinkitem> drinks;
	vector<OrderItem> order;

	//新增飲料品項
	AddNewDrink(drinks);

	//顯示飲料菜單
	DisplayDrinkMenu(drinks);

	//點餐
	OrderDrink(order);

	//計算金額與售價
}



