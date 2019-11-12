#pragma once
#include <vector>
#include <memory>

class Item;

class Inventory {
public:

	//constructor
	Inventory();

	//every day inventory accessing methods
	//these of which are setters

	void addItem(std::unique_ptr<Item> Inventory, Item& item, int quantity);
	void removeItem(Item& item, int quantity);

	//these of which are getters
	void displayItems();
	Item* getItem();

private:
	
};