#include "Player.h"

Player::Player()
{
}

Player::Player(const string& pName)
	:name_(pName),
	level_(1),
	currentExp_(0.0f),
	currentAction_("Idling"),
	currentLocation_("Starter Town"),
	nextLevelExp_(10.0f),
	playersTurn(true)
{
	enemy.battleLog.clear();
	weaponBag.clear();
	log_.clear();
	pMaxHP = 20;
	pCurrHP = pMaxHP;
	pDamageMin = 5;
	pDamageMax = 20;

	weapon = new Weapon();
	head = new Armour("Damaged", 0, "Training");
	body = new Armour("Damaged", 1, "Training");
	legs = new Armour("Damaged", 2, "Training");
	feet = new Armour("Damaged", 3, "Training");
	hands = new Armour("Damaged", 4, "Training");
	waist = new Armour("Damaged", 5, "Training");

	//addToWeaponBag(*weapon);
	//addToArmourBag(*head);
	//addToArmourBag(*body);
	//addToArmourBag(*legs);
	//addToArmourBag(*feet);
	//addToArmourBag(*hands);
	//addToArmourBag(*waist);

}

Player::
~Player()
{
	delete weapon;
	delete head;
	delete body;
	delete legs;
	delete feet;
	delete hands;
	delete waist;
}

void Player::incExp(const float inc)
{
	//Give player some exp
	currentExp_ += inc;

	//If player should level up now
	if (currentExp_ >= nextLevelExp_)
	{
		//level player
		levelUp();
	}
}

void Player::addToLog(const string& toAdd)
{
	if (log_.size() > 7)
	{
		for (int i = 0; i < 7; i++)
			log_.at(i) = log_.at(i + 1);

		log_.pop_back();
	}

	log_.push_back(toAdd);

}

void Player::addToBattleLog(const string & toAdd)
{
	if (enemy.battleLog.size() > 5)
	{
		for (int i = 0; i < 5; i++)
			enemy.battleLog.at(i) = enemy.battleLog.at(i + 1);

		enemy.battleLog.pop_back();
	}

	enemy.battleLog.push_back(toAdd);
}

void Player::addToWeaponBag(const Weapon& weap)
{
	if (weaponBag.size() < maxWeaponBagLimit)
		weaponBag.push_back(weap);
	else
		addToBattleLog("But the bag was full!!");
}

void Player::addToArmourBag(const Armour& arm)
{
	if (armourBag.size() < maxArmourBagLimit)
		armourBag.push_back(arm);
	else
		addToBattleLog("But the bag was full!!");
}

void Player::update()
{
	//If player is currently idling in town
	if (getCurrAction() == "Idling")
	{
		setCurrAction("Searching");
		addToLog("Searching for Enemy");
	}
	//If player is currently searching for a battle
	else if (getCurrAction() == "Searching")
	{
		setCurrAction("Battling");
		addToLog("Battling Enemy");
		//setup enemy, reset stuff etc
		setupEnemy();
		resetStats();
	}
	//If player is currently battling
	else if (getCurrAction() == "Battling")
	{
		if (enemy.eCurrHP == 0.0f)
		{
			int expGain = enemy.eMaxHP * 0.25f;
			incExp(expGain);
			addToBattleLog("You Gained [+" + to_string(expGain) + "] Experience");
			addToBattleLog("You Search the remains for gold...");
			tickCounter = 0;
			setCurrAction("Looting");
			addToLog("Looting " + enemy.eName);
		}
		else if (pCurrHP == 0.0f)
		{
			addToBattleLog("You Return Empty Handed...");
			setCurrAction("Returning");
			addToLog("Returning to Town");
		}
		else if (playersTurn)
		{
			attackEnemy();
			playersTurn = false;
		}
		else
		{
			attackPlayer();
			playersTurn = true;
		}

		
	}	
	//If player is looting
	else if (getCurrAction() == "Looting")
	{
		tickCounter += 1;

		if (tickCounter == 1 || tickCounter == 2 || tickCounter == 5 || tickCounter == 7)
		{
			addToBattleLog("...");
		}
		if (tickCounter == 3)
		{
			int goldGained = (enemy.eLevel * 10) + ((enemy.eDamageMax - enemy.eDamageMin) * 5) + enemy.eMaxHP * 0.5f;
			pCoins += goldGained;
			addToLog("Looted Gold");
			addToBattleLog("You Found [+" + to_string(goldGained) + "] Gold in the Remains!");
		}
		else if (tickCounter == 4)
		{
			addToLog("Looting Items");
			addToBattleLog("You Search the remains for Items...");
		}
		else if (tickCounter == 6)
		{
			int rng = rand() % 100 + 1;
			if (enemy.eDropRate >= rng)
			{
				addToLog("Looted Items");

				int rnd = rand() % 2;
				if (rnd == 1)
				{
					Weapon weap(getLevel());
					addToWeaponBag(weap);
					addToBattleLog("You Found [" + weap.getFullWeaponName() + "] !");
					addToBattleLog("It Has Stats Range: [" + weap.getFullWeaponRange() + "] !");
				}
				else
				{
					Armour arm(getLevel());
					addToArmourBag(arm);
					addToBattleLog("You Found [" + arm.getFullArmourName() + "] !");
					addToBattleLog("It Has Stats: [" + arm.getFullArmourValue() + "] !");
				}		
			}
			else
			{
				addToLog("No Items Found");
				addToBattleLog("You Found No Items in the Remains!");

			}
		}
		else if (tickCounter == 8)
		{
			addToLog("Packing Up");
			addToBattleLog("You start preparing to head back");
		}
		else if (tickCounter == 9)
		{
			addToBattleLog("---<End Battle>---");
			addToBattleLog("");

			setCurrAction("Returning");
			addToLog("Returning to Town");
		}

	}
	//If player is returning to home
	else if (getCurrAction() == "Returning")
	{
		setCurrAction("Idling");
		addToLog("Idling in Town");
	}
}

void Player::setupEnemy()
{
	//Will be random
	enemy.eName = "Goblin";
	
	//Will be around your level
	int enemyLevelInc = rand() % 2;
		enemy.eLevel = level_ + enemyLevelInc;

	enemy.eMaxHP = enemy.eLevel * 8;
	enemy.eCurrHP = enemy.eMaxHP;

	//Some random ranges, idk if they good
	enemy.eDamageMin = rand() % (enemy.eLevel * 3);
	enemy.eDamageMax = 1 + enemy.eDamageMin + (rand() % (enemy.eLevel * 3));

	//50% accuracy test
	enemy.eAccuracy = 50;

	//50% drop rate test
	enemy.eDropRate = 100;

	//Remove previous logs
	addToBattleLog("---<New Battle>--- [ VS ] ---<" + enemy.eName + ">---");

	playersTurn = true;
}

void Player::attackEnemy()
{
	int damageDealt = (rand() % (int)(pDamageMax - pDamageMin + 1)) + pDamageMin;

	enemy.eCurrHP -= damageDealt;
	if (enemy.eCurrHP <= 0)
	{
		enemy.eCurrHP = 0;
		addToLog("Defeated " + enemy.eName);
		addToBattleLog("Congratulations! You defeated " + enemy.eName);

	}
	else
	{
		addToLog("Damaged " + enemy.eName);
		addToBattleLog("Dealt (-" + to_string(damageDealt) + ") to " + enemy.eName);

	}
		
}

void Player::attackPlayer()
{
	int damageDealt = (rand() % (int)(enemy.eDamageMax - enemy.eDamageMin + 1)) + enemy.eDamageMin;
	pCurrHP -= damageDealt;

	if (pCurrHP <= 0)
	{
		pCurrHP = 0;
		addToLog(enemy.eName + " defeated " + name_);
		addToBattleLog(name_ + " failed the quest to kill " + enemy.eName);
	}
	else
	{
		addToLog("Attacked by " + enemy.eName);
		addToBattleLog(enemy.eName + " dealt (-" + to_string(damageDealt) + ") to " + name_);
	}
}

void Player::resetStats()
{
	pMaxHP = 20;
	pCurrHP = pMaxHP;

	//Do something to calculate these stats later stats based on items
	pDamageMin = weapon->getMinDamage();
	pDamageMax = weapon->getMaxDamage();

}

void Player::levelUp()
{
	//Need to get overflow exp into next bar
	float overflow = currentExp_ - nextLevelExp_;
	currentExp_ = overflow;
	level_++;
	nextLevelExp_ = level_ * 10.0f;

}

string Player::getWeaponSpace()
{
	int maxAmt = maxWeaponBagLimit;
	int currentAmt = weaponBag.size();
	
	string str = "-<";
	if (currentAmt < 10)
		str += "0";

	str += to_string(currentAmt);
	str += "/";

	if (maxAmt < 10)
		str += "0";
	str += to_string(maxAmt);
	str += ">";

	return str;
}

string Player::getArmourSpace()
{
	int maxAmt = maxArmourBagLimit;
	int currentAmt = armourBag.size();

	string str = "-<";
	if (currentAmt < 10)
		str += "0";

	str += to_string(currentAmt);
	str += "/";

	if (maxAmt < 10)
		str += "0";
	str += to_string(maxAmt);
	str += ">";

	return str;
}

vector<Weapon> Player::getEquippedWeapon()
{
	vector<Weapon> temp;

	temp.push_back(*weapon);

	return temp;
}

vector<Armour> Player::getEquippedArmour()
{
	vector<Armour> temp;

	temp.push_back(*head);
	temp.push_back(*body);
	temp.push_back(*legs);
	temp.push_back(*feet);
	temp.push_back(*hands);
	temp.push_back(*waist);

	return temp;
}



