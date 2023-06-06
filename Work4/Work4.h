#pragma once
#include <iostream>
#include <vector>
#include <iomanip>
#include "Drinkitem.h"
#include "OrderItem.h"

void AddNewDrink(std::vector<Drinkitem>&);
void DisplayDrinkMenu(vector<Drinkitem>&);
void OrderDrink(vector<OrderItem>&, vector<Drinkitem>&);
void CalculateSalePrice(vector<OrderItem>&, vector<Drinkitem>& drinks);