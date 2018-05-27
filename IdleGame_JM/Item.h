#ifndef ITEM_H
#define ITEM_H

#include <string>
using namespace std;

class Item{

public:
	
	Item(int level);

	void setName(string newName) { name = newName; };

	string getName() { return name; };
	int getSellPrice() { return sellPrice; };

private:
	string name;
	int sellPrice;
};



#endif
