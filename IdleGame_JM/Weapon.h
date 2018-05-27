#ifndef WEAPON_H
#define WEAPON_H

#include <string>
#include <vector>
#include "Header.h"
using namespace std;

class Weapon {
public:
	Weapon();
	Weapon(int level);

	virtual string getItemType() { return "Weapon"; };
	string getWeaponType() { return name; };

	int getMinDamage()	{ return minDmg; };
	int getMaxDamage()	{ return maxDmg; };
	int getRarity()		{ return rarity; };

	string getFullWeaponName();
	string getFullWeaponRange();

	//Public stuff
	vector<NameValue> Weapons
	{
		//Name followed by attack speed!
		{ "Dagger",		2.0f },
		{ "Shortsword",	1.5f },
		{ "Greatsword",	0.6f },
		{ "Sword",		1.0f },
		{ "Glaive",		1.1f },
		{ "Wand",		1.2f },
		{ "Staff",		0.8f }
	};

	vector<NameValue> Prefixes
	{
		//Name followed by min damage boost
		{ "Bad",		0.0f },
		{ "Normal",		0.5f },
		{ "Good",		1.0f },
		{ "Great",		1.5f },
		{ "Insane",		2.0f }

	};

	vector<NameValue> Suffixes
	{
		//Name followed by max damage boost
		{ "Bad",		0.0f },
		{ "Normal",		0.5f },
		{ "Good",		1.0f },
		{ "Great",		1.5f },
		{ "Insane",		2.0f }
	};

	int numOfWeapons = Weapons.size();
	int numOfPrefixes = Prefixes.size();
	int numOfSuffixes = Suffixes.size();

private:
	string name;
	int rarity;
	int sellPrice;

	int minDmg;
	int maxDmg;
	
	string prefix;
	int prefixDamage;

	string suffix;
	int suffixDamage;

	float attackSpeed;
};






#endif
