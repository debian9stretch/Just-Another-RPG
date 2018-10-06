#pragma once

class Item;

class Inventory {
public:

	//constructor
	Inventory();

	//every day inventory accessing methods
	//these of which are setters
	
	void addItem(Item& item, int quantity);
	void removeItem(Item& item);

	//these of which are getters
	void displayItems();
	Item* getItem();
};