#ifndef GAME_H
#define GAME_H

//---------------------------------------------------------------------------
//Game: class declaration
//---------------------------------------------------------------------------

#include <iostream>
#include <fstream>
#include <string>
#include <cassert>
#include "UserInterface.h"
#include "Time.h"

#include "Player.h"
#include <stdlib.h> 

using namespace std;

class Game {
public:
	Game();
	~Game();
	void start();
	void update();
	void updateUI();
private:
	const UserInterface theUI_;
	Player *thePlayer_;

	//Tick manipulation
	Time targetTime;

	void setNextTargetTick();

	bool tick;
};


#endif