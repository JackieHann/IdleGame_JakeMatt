#ifndef PLAYER_H
#define PLAYER_H

//---------------------------------------------------------------------------
//Player: class declaration
//---------------------------------------------------------------------------
#include <string>
#include <vector>
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
};

class Player {
public:

	Player();
	Player(const string&);

	void incExp(const float);
	void setCurrAction(const string& str) { currentAction_ = str; };
	void addToLog(const string&);
	void update();
	void setupEnemy();
	void attackEnemy();



	string	getName()	{ return name_; };
	int		getLevel()	{ return level_; };
	float	getPercentExp() { return ((float)(int)(currentExp_ / nextLevelExp_ * 100.0f)); };
	string	getCurrAction(){ return currentAction_; };
	string	getCurrLocation() { return currentLocation_; };
	vector<string> getLog() { return log_; };
	Enemy	getEnemy() { return enemy; };

	Enemy enemy;

private:

	void levelUp();

	string	name_;
	int		level_;
	float	currentExp_;
	string	currentAction_;
	string	currentLocation_;
	float nextLevelExp_;

	vector<string> log_;

	//at some point
	int		backpack[5][5];

};


#endif