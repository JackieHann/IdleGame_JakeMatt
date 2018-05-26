
#include <iostream>
#include <iomanip>
#include <string>

#include "ConsoleUtils_JH.h"

#include "Game.h"

using namespace std;

int main()
{
	//Initialise rng for all randoms
	srand(time(NULL));

	Game theGame;
	theGame.start();

	system("PAUSE");
	return 0;
}