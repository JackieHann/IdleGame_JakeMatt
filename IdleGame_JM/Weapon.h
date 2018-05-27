#ifndef WEAPON_H
#define WEAPON_H

#include <string>
#include <vector>
//#include "WeaponNames.h"
using namespace std;

struct NameValue
{
	string name;
	float value;
};

class Weapon {
public:
	Weapon();
	Weapon(int level);

	virtual string getItemType() { return "Weapon"; };
	string getWeaponType() { return name; };

	int getMinDamage() { return minDmg; };
	int getMaxDamage() { return maxDmg; };

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
		{ "Demonic",		1 },
		{ "Infernal",	2 },
		{ "Glacial",		3 },
		{ "Ominous",		4 },
		{ "Sharp",		5 },
		{ "Blunt",		6 },
		{ "Zealous",		7 }
	};

	vector<NameValue> Suffixes
	{
		//Name followed by max damage boost
		{ "Hell",		1 },
		{ "Heaven",		2 },
		{ "God",			3 },
		{ "Memes",		4 },
		{ "Tortellini",	5 },
		{ "Phlava",		6 }
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
