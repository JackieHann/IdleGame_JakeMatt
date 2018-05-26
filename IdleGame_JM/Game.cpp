#include "Game.h"

Game::Game()
	: theUI_()
{
	targetTime = Time::currentTime() + (long)1;
	tick = true;
}

Game::~Game()
{
}

void Game::start()
{
	bool keyPressed(false);
	//Make a new player
	string name = theUI_.showNameInputAndGet();
	thePlayer_ = new Player(name);

	//Reset next time
	targetTime = Time::currentTime() + (long)1;

	int command(1);
	//Show Stats Of Player On Screen
	updateUI();

	//Game loop
	while (command != 0)
	{
		
		//if S is pressed
		if (GetKeyState('S') & 0x8000)
		{
			if (!keyPressed)
			{
				keyPressed = true;
				//exit loop condition
				Clrscr();
				//enter shop loop
				updateUI();

				cout << "Went to shop" << endl;
			}
		}
		else if(GetKeyState('L') & 0x8000)
		{
			if (!keyPressed)
			{
				keyPressed = true;
				//Testing gaining exp
				thePlayer_->incExp(2.75f);
				updateUI();
			}
		}
		else
		{
			keyPressed = false;
			//If game tick should be executed
			if (Time::currentTime() == targetTime) //target time is currently 1 second after
			{
				//Update the game or whatever
				update();
				setNextTargetTick();
			}
			else if(targetTime < Time::currentTime())
			{
				//If game tick needs resetting (tabbed out, held keys etc)
					targetTime = Time::currentTime() + (long)1;
			}

		}
	}
	cout << "exited loop" << endl;
}

void Game::update()
{
	//Get random number from 0 -> 2
	int event = rand() % 2;

	//If you get a 1 (do something)
	if (event == 1)
	{
		thePlayer_->update();
		updateUI();
	}
	else
	{
		thePlayer_->addToLog("...");
		updateUI();
	}
	//Else do nothing, have to wait.
}

void Game::updateUI()
{
	theUI_.showTitle();
	theUI_.showPlayerStatus(thePlayer_->getName(), thePlayer_->getLevel(), thePlayer_->getPercentExp(), thePlayer_->getCurrAction(), thePlayer_->getCurrLocation());
	theUI_.showPlayerLog(thePlayer_->getLog());

	//If battle dialogue should be shown
	if (thePlayer_->getCurrAction() == "Battling")
	{
		theUI_.showBattle(thePlayer_->getEnemy());
	}
		
}


void Game::setNextTargetTick()
{
	//Make next tick be current plus 1 (for now) 
	targetTime = targetTime + (long)1;
}
