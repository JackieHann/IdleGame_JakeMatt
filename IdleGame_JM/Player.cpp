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
	nextLevelExp_(10.0f)

{
	log_.clear();
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

void Player::update()
{
	//Should be in player update.
	//If player is currently idling in town
	if (getCurrAction() == "Idling")
	{
		setCurrAction("Searching");
		addToLog("Searching for Enemy");
	}
		

	else if (getCurrAction() == "Searching")
	{
		setCurrAction("Battling");
		addToLog("Battling Enemy");
		//setup enemy, reset stuff etc
		setupEnemy();
	}
		

	else if (getCurrAction() == "Battling")
	{
		attackEnemy();
		if (enemy.eCurrHP <= 0.0f)
		{
			incExp(3);
			setCurrAction("Looting");
			addToLog("Looting Enemy");
		}
	}	

	else if (getCurrAction() == "Looting")
	{
		setCurrAction("Returning");
		addToLog("Returning to Town");
	}
		

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

	enemy.eMaxHP = enemy.eLevel * 10;
	enemy.eCurrHP = enemy.eMaxHP;

	//Some random ranges, idk if they good
	enemy.eDamageMin = rand() % (enemy.eLevel * 5);
	enemy.eDamageMax = 1 + enemy.eDamageMin + (rand() % (enemy.eLevel * 5));

	//50% accuracy test
	enemy.eAccuracy = 50;

	//50% drop rate test
	enemy.eDropRate = 50;

}

void Player::attackEnemy()
{
}

void Player::levelUp()
{
	//Need to get overflow exp into next bar
	float overflow = currentExp_ - nextLevelExp_;
	currentExp_ = overflow;
	level_++;
	nextLevelExp_ = level_ * 10.0f;

}



