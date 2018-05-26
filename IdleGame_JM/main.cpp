
#include <iostream>
#include <iomanip>
#include <string>

#include "ConsoleUtils_JH.h";

using namespace std;

int main()
{

	//UI Test Stuff

	//Move to coordinate on screen
	Gotoxy(3, 6);

	//Set colours
	SelectBackColour(clWhite);
	SelectTextColour(clRed);

	//Write something
	cout << "POGGERS" << endl;

	//Set colours baack
	SelectBackColour(clBlack);
	SelectTextColour(clWhite);

	//Make game hang on last action
	system("PAUSE");
	return 0;
}