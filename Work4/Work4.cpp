﻿#include "Work4.h"

int main()
{
	vector<Drinkitem> drinks;
	vector<OrderItem> order;

	//新增飲料品項
	AddNewDrink(drinks);

	//顯示飲料菜單
	DisplayDrinkMenu(drinks);

	//點餐
	OrderDrink(order, drinks);

	//計算金額與售價
	CalculateSalePrice(order, drinks);
	return 0;
}

void AddNewDrink(vector<Drinkitem>& drinks)
{
	//DrinkItem drink1("紅茶", "大杯", 60);
	//drinks.push_back(drink1);
	//drinks.push_back(DrinkItem("紅茶", "大杯", 60));
	//drinks.push_back(DrinkItem("紅茶", "小杯", 40));
	//drinks.push_back(DrinkItem("綠茶", "大杯", 60));
	//drinks.push_back(DrinkItem("綠茶", "小杯", 40));
	//drinks.push_back(DrinkItem("咖啡", "大杯", 70));
	//drinks.push_back(DrinkItem("咖啡", "小杯", 50));
	//drinks.push_back(DrinkItem("可樂", "大杯", 40));
	//drinks.push_back(DrinkItem("可樂", "小杯", 20));

	string filename("drinks.csv");
	string file_content = ReadFile(filename);

	vector<string> lines = Split(file_content, '\n');
	for (string line : lines) {
		vector<string> fields = Split(line, ',');
		if (fields.size() == 3) {
			string name = fields[0];
			string size = fields[1];
			int price = stoi(fields[2]);
			drinks.push_back(Drinkitem(name, size, price));
		}
	}
}

string ReadFile(const string& filename) {
	auto string_content = ostringstream();
	ifstream input_file(filename);
	if (!input_file.is_open()) {
		cout << "無法讀取檔案: " << filename << endl;
		return "";
	}

	string_content << input_file.rdbuf();
	input_file.close();
	return string_content.str();
}

vector<string> Split(const string& string_content, char delimiter)
{
	vector<string> tokens;
	string token;
	istringstream tokenStream(string_content);
	while (getline(tokenStream, token, delimiter)) {
		tokens.push_back(token);
	}
	return tokens;
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

void OrderDrink(vector<OrderItem>& order, vector<Drinkitem>& drinks)
{
	int index;
	int qty;
	char ans = 'Y';

	do 
	{
		cout << "請輸入要訂購的飲料編號: ";
		cin >> index;
		cout << "清輸入要訂購的飲料數量: ";
		cin >> qty;
		if (index < 1 || index>drinks.size())
		{
			cout << "輸入飲料編號錯誤，請重新輸入" << endl;
		}
		else if (qty<1)
		{
			cout << "輸入飲料編號錯誤，請重新輸入" << endl;
		}
		else
		{
			OrderItem orderitem(index, qty);
			order.push_back(orderitem);
			orderitem.displayOrderItem(drinks);
			cout << "是否繼續點餐>(Y或y 繼續訂餐)";
			cin >> ans;
		}
	} 
	while (ans == 'y' || ans == 'Y');

}

void CalculateSalePrice(vector<OrderItem>& order, vector<Drinkitem>& drinks)
{
	int tackIn = 1;
	cout << "請問是內用還是外帶?(1:內用 2:外帶)";
	cin >> tackIn;
	string messageTackIn = (tackIn == 1) ? "內用" : "外帶";
	int totalPrice = 0;
	int salePrice = 0;
	string messagePrice = "";
	cout << "----------------------------------------------------------" << endl;
	cout << "您所點的飲料如下:" << endl;
	cout << "----------------------------------------------------------" << endl;
	for (OrderItem orderitem : order) {
		orderitem.displayOrderItem(drinks);
		Drinkitem drinkitem = drinks[orderitem.getIndex() - 1];
		totalPrice += drinkitem.getPrice() * orderitem.getQuantity();
	}

	if (totalPrice >= 500) 
	{
		salePrice = totalPrice * 0.8;
		messagePrice = "訂購500元以上者8折";
	}
	else if (totalPrice >= 300)
	{
		salePrice = totalPrice * 0.9;
		messagePrice = "訂購500元以上者9折";
	}
	else if (totalPrice >= 200)
	{
		salePrice = totalPrice * 0.95;
		messagePrice = "訂購500元以上者95折";
	}
	else 
	{
		salePrice = totalPrice;
		messagePrice = "不打折";
	}
	cout << "----------------------------------------------------------" << endl;
	cout << "訂購方式: " << messageTackIn << endl;
	cout << "總金額: " << totalPrice << endl;
	cout << messagePrice << endl;
	cout << "售價: " << salePrice << endl;
	cout << "----------------------------------------------------------" << endl;

	PrintOrder(order, drinks, messageTackIn, messagePrice, totalPrice, salePrice);
}

void PrintOrder(vector<OrderItem>& order, vector<Drinkitem> drinks, string messageTackIn, string messagePrice, int totalPrice, int salePrice)
{
	string filename{ "order.txt" };
	ofstream output_file;
	output_file.open(filename, ios::app);
	if (!output_file.is_open()) {
		cout << "無法寫入檔案" << filename << endl;
		return;
	}
	output_file << "----------------------------------------------------------" << endl;
	output_file << "您所點的飲料如下:" << endl;
	output_file << "----------------------------------------------------------" << endl;
	for (OrderItem orderitem : order) {
		orderitem.printOrderItem(output_file, drinks);
	}
	output_file << "----------------------------------------------------------" << endl;
	output_file << "訂購方式: " << messageTackIn << endl;
	output_file << "總金額: " << totalPrice << endl;
	output_file << messagePrice << endl;
	output_file << "售價: " << salePrice << endl;
	output_file << "----------------------------------------------------------" << endl;

	output_file.close();
}
