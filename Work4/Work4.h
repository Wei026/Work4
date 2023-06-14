#pragma once
#include <iostream>
#include <vector>
#include <iomanip>
#include <fstream>
#include <sstream>
#include "Drinkitem.h"
#include "OrderItem.h"

void AddNewDrink(std::vector<Drinkitem>&);
void DisplayDrinkMenu(vector<Drinkitem>&);
void OrderDrink(vector<OrderItem>&, vector<Drinkitem>&);
void CalculateSalePrice(vector<OrderItem>&, vector<Drinkitem>& drinks);
void PrintOrder(vector<OrderItem>&, vector<Drinkitem> drinks, string, string, int, int);
string ReadFile(const string&);
vector<string> Split(const string&, char);