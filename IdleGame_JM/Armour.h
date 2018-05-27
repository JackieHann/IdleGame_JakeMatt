
#ifndef ARMOUR_H
#define ARMOUR_H

#include <string>
#include <vector>
#include "Header.h"
using namespace std;

class Armour {
public:
	Armour();
	Armour(string, int, string);
	Armour(int level);

	virtual string getItemType() { return "Armour"; };
	string getWeaponType() { return name; };

	int getArmourBonus() { return armourRating; };
	int getRarity() { return rarity; };

	string getFullArmourName();
	string getFullArmourValue();


	//Public stuff
	vector<NameValue> Armours
	{
		//Name followed by how much weight they have on your defence!
		{ "Helmet",		1.2f },
		{ "Platebody",	1.5f },
		{ "Legs",		1.2f },
		{ "Boots",		1.0f },
		{ "Gloves",		1.0f },
		{ "Belt",		0.8f }
	};

	vector<NameValue> Prefixes
	{
		//Name followed by min damage mitigated
		{ "Bad",		0.0f },
		{ "Normal",		0.5f },
		{ "Good",		1.0f },
		{ "Great",		1.5f },
		{ "Insane",		2.0f }

	};

	vector<NameValue> Suffixes
	{
		//Name followed by max damage mitigated
		{ "Bad",		0.0f },
		{ "Normal",		0.5f },
		{ "Good",		1.0f },
		{ "Great",		1.5f },
		{ "Insane",		2.0f }
	};

	int numOfArmours = Armours.size();
	int numOfPrefixes = Prefixes.size();
	int numOfSuffixes = Suffixes.size();

private:
	string name;
	int rarity;
	int sellPrice;

	int armourRating;

	string prefix;
	string suffix;
};






#endif
