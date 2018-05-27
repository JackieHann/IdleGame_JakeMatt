#include "Armour.h"

Armour::Armour()
{
	rarity = 0;
	name = "Helmet";
	prefix = "Starter";
	suffix = "Newbs";
	armourRating = 0;
}

Armour::Armour(string prfx, int nm, string sffx)
{
	rarity = 0;

	if (nm <= Armours.size())
		name = Armours.at(nm).name;
	else
		name = "ERROR";

	prefix = prfx;
	suffix = sffx;
	armourRating = 0;
}

Armour::Armour(int level)
{
	//Set rarity of the new item
	int iRarity = rand() % 100 + 1;
	if (iRarity >= 99)		//1% chance
		rarity = 4;
	else if (iRarity >= 94) //5% chance
		rarity = 3;
	else if (iRarity >= 80) //14% chance
		rarity = 2;
	else if (iRarity >= 55)	//25% chance
		rarity = 1;
	else					//55% chance
		rarity = 0;

	//Select a random armour type
	int iName = rand() % Armours.size();
	name = Armours.at(iName).name;

	int iPrefix = rand() % Prefixes.size();
	prefix = Prefixes.at(iPrefix).name;

	int iSuffix = rand() % Suffixes.size();
	suffix = Suffixes.at(iSuffix).name;

	float tempMin = 1;
	float tempMax = 1;

	tempMin += Prefixes.at(iPrefix).value;
	tempMax += Prefixes.at(iPrefix).value;

	tempMax += Suffixes.at(iSuffix).value;
	
	tempMin *= Armours.at(iName).value;
	tempMax *= Armours.at(iName).value;

	float rarityMultiplier = sqrt(rarity);
	if (rarityMultiplier == 0.0f)
		rarityMultiplier = 1.0f;

	tempMin *= rarityMultiplier;
	tempMax *= rarityMultiplier;

	tempMin *= (level / 2.0f);
	tempMax *= (level / 2.0f);

	armourRating = (int)((tempMin + tempMax) / 2.0f);

}

string Armour::getFullArmourName()
{
	return (prefix + " " + name + " of " + suffix);
}

string Armour::getFullArmourValue()
{

	//return random damage mitigated from armour rating
	return ("+ " + to_string(armourRating) + " Def");
}

