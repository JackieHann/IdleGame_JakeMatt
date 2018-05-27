#include "Weapon.h"
#include <math.h>

Weapon::Weapon()
{
	rarity = 0;
	name = "Sword";
	prefix = "Shoddy";
	suffix = "Shitness";

	attackSpeed = 1.0f;

	minDmg = 1;
	maxDmg = 3;
}
Weapon::Weapon(int level)
{

	//Set rarity of the new item
	int iRarity = rand() % 100 + 1;
	if (iRarity >= 95)		//5% chance
		rarity = 4;
	else if (iRarity >= 85) //10% chance
		rarity = 3;
	else if (iRarity >= 70) //15% chance
		rarity = 2;
	else if (iRarity >= 50)	//20% chance
		rarity = 1;
	else					//50% chance
		rarity = 0;
	
	//Select a random weapon type
	int iName = rand() % Weapons.size();
	name = Weapons.at(iName).name;
	
	//Select a random weapon prefix
	int iPrefix = rand() % Prefixes.size();
	prefix = Prefixes.at(iPrefix).name;
	
	//Select a random weapon suffix
	int iSuffix = rand() % Suffixes.size();
	suffix = Suffixes.at(iSuffix).name;
	
	//Default range
	float tempMin = 1;
	float tempMax = 2;
	
	//Take into account the prefix (ie base damage);
	tempMin += Prefixes.at(iPrefix).value;
	tempMax += Prefixes.at(iPrefix).value;
	prefixDamage = Prefixes.at(iPrefix).value;
	
	//Take into account suffix (ie difference between min and max);
	tempMax += Suffixes.at(iSuffix).value;
	suffixDamage = Suffixes.at(iSuffix).value;
	
	//Take into account attack speed
	tempMin *= Weapons.at(iName).value;
	tempMax *= Weapons.at(iName).value;
	attackSpeed = Weapons.at(iName).value;
	
	//Take into account rarity
	tempMin *= (1.0f + (rarity / 10.0f));
	tempMax *= (1.0f + (rarity / 10.0f));
	
	//Scale down to level ye whatever
	tempMin *= (level / 2.0f);
	tempMax *= (level / 2.0f);
	
	minDmg = (int)floor(tempMin);
	maxDmg = (int)floor(tempMax);
}

string Weapon::getFullWeaponName()
{
	return (prefix + " " + name + " of " + suffix);
}

string Weapon::getFullWeaponRange()
{
	return (to_string(getMinDamage()) + " ~ " + to_string(getMaxDamage()));
}
