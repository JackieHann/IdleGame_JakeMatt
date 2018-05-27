#ifndef PLAYER_H
#define PLAYER_H

//---------------------------------------------------------------------------
//Player: class declaration
//---------------------------------------------------------------------------
#include <string>
#include <vector>
#include "Weapon.h"
#include "Armour.h"

using namespace std;

struct Enemy 
{
	string eName;
	int eLevel;
	float eMaxHP;
	float eCurrHP;

	float eDamageMin;
	float eDamageMax;

	float eAccuracy;
	float eDropRate;
	
	vector<string> battleLog;
};

class Player {
public:

	Player();
	Player(const string&);
	~Player();

	void incExp(const float);
	void setCurrAction(const string& str) { currentAction_ = str; };
	void addToLog(const string&);
	void addToBattleLog(const string&);
	void addToWeaponBag(const Weapon&);
	void addToArmourBag(const Armour&);
	void update();

	void setupEnemy();
	void attackEnemy();
	void attackPlayer();

	void resetStats();

	string	getName()			{ return name_; };
	int		getLevel()			{ return level_; };
	float	getPercentExp()		{ return ((float)(int)(currentExp_ / nextLevelExp_ * 100.0f)); };
	string	getCurrAction()		{ return currentAction_; };
	string	getCurrLocation()	{ return currentLocation_; };

	vector<string> getLog()		{ return log_; };
	vector<Weapon> getWeapons() { return weaponBag; };
	vector<Armour> getArmours() { return armourBag; };
	string getWeaponSpace();
	string getArmourSpace();

	vector<Weapon> getEquippedWeapon();
	vector<Armour> getEquippedArmour();

	Enemy	getEnemy()			{ return enemy; };

	float getMaxHP()			{ return pMaxHP; };
	float getCurrHP()			{ return pCurrHP; };
	float getMinimumDmg()		{ return pDamageMin; };
	float getMaximumDmg()		{ return pDamageMax; };

	Enemy enemy;

private:

	void levelUp();

	string	name_;
	int		level_;
	float	currentExp_;
	string	currentAction_;
	string	currentLocation_;
	float nextLevelExp_;

	bool playersTurn;
	vector<string> log_;

	//at some point
	vector<Weapon> weaponBag;
	vector<Armour> armourBag;
	int maxWeaponBagLimit = 5;
	int maxArmourBagLimit = 10;
	

	//Battle Stats (HP ETC)
	float pMaxHP;
	float pCurrHP;

	float pDamageMin;
	float pDamageMax;

	float pAccuracy;

	int	pCoins;
	int tickCounter;

	Weapon *weapon;

	Armour *head;
	Armour *body;
	Armour *legs;
	Armour *feet;
	Armour *hands;
	Armour *waist;
};


#endif