#include "Work4.h"

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
}

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
}