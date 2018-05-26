#include "UserInterface.h"

int UserInterface::showMainMenuAndGetCommand() const
{
	Clrscr();
	return (readInCommand());

}

string UserInterface::showNameInputAndGet() const
{
	string name;
	//Box in middle with information             
	ShowMessage(clGrey, clDarkRed, 10, 7, "        IDLE GAME TESTING       ");
	ShowMessage(clGrey, clDarkRed, 10, 8, "            JAKE - MATT         ");
	ShowMessage(clGrey, clDarkRed, 10, 9, "                 :)             ");

	ShowMessage(clBlack, clWhite, 10, 11, "Player Name:____________________");
	ShowMessage(clBlack, clRed, 23, 11, "");
	cin >> name;

	//Resize name if its too long
	if (name.length() > 10)
		name.resize(10);

	Clrscr();
	return name;

}

void UserInterface::showPlayerStatus(string pName, int pLevel, float pExp, string pAct, string pLoc) const
{
	//Setup UI
	ShowMessage(clGrey, clDarkRed, 2, 8, "-<STATS>-------------------------------------");
	ShowMessage(clGrey, clDarkRed, 2, 9, "|                                           |");
	ShowMessage(clGrey, clDarkRed, 2, 10,"|                                           |");
	ShowMessage(clGrey, clDarkRed, 2, 11,"---------------------------------------------");

	//Write player stuff to screen
	Gotoxy(5, 9);
	cout << "Name:" << pName << "  |  Lv:" << pLevel << "  |  Exp: " << pExp << "%";
	Gotoxy(5, 10);
	cout << "Currently: " << pAct << " in " << pLoc;



}

void UserInterface::showPlayerLog(vector<string> pLog) const
{
	//Setup UI
	ShowMessage(clGrey, clDarkRed, 50, 2, "-<LOG>----------------");
	ShowMessage(clGrey, clDarkRed, 50, 3, "|                    |");
	ShowMessage(clGrey, clDarkRed, 50, 4, "|                    |");
	ShowMessage(clGrey, clDarkRed, 50, 5, "|                    |");
	ShowMessage(clGrey, clDarkRed, 50, 6, "|                    |");
	ShowMessage(clGrey, clDarkRed, 50, 7, "|                    |");
	ShowMessage(clGrey, clDarkRed, 50, 8, "|                    |");
	ShowMessage(clGrey, clDarkRed, 50, 9, "|                    |");
	ShowMessage(clGrey, clDarkRed, 50, 10,"|                    |");
	ShowMessage(clGrey, clDarkRed, 50, 11,"----------------------");

	if (pLog.size() != 0)
	{
		for (int i = 0; i < pLog.size(); i++)
		{
			Gotoxy(52, i + 3);
			cout << pLog.at(i);
		}
	}
}

void UserInterface::showTitle() const
{
	ShowMessage(clGrey, clDarkRed, 2, 2, "                                       ");
	ShowMessage(clGrey, clDarkRed, 2, 3, "                                       ");
	ShowMessage(clGrey, clDarkRed, 2, 4, "          Title Goes Here              ");
	ShowMessage(clGrey, clDarkRed, 2, 5, "                                       ");
	ShowMessage(clGrey, clDarkRed, 2, 6, "                                       ");

}

void UserInterface::showBattle(Enemy enemy) const
{
	//Setup UI
	ShowMessage(clGrey, clDarkRed, 74, 2, "-<Current Enemy>-----------------------------");
	ShowMessage(clGrey, clDarkRed, 74, 3, "| ________                                  |");
	ShowMessage(clGrey, clDarkRed, 74, 4, "| |      |                                  |");
	ShowMessage(clGrey, clDarkRed, 74, 5, "| | PIC~ |                                  |");
	ShowMessage(clGrey, clDarkRed, 74, 6, "| |______|                                  |");
	ShowMessage(clGrey, clDarkRed, 74, 7, "|                                           |");
	ShowMessage(clGrey, clDarkRed, 74, 8, "|                                           |");
	ShowMessage(clGrey, clDarkRed, 74, 9, "|                                           |");
	ShowMessage(clGrey, clDarkRed, 74, 10,"---------------------------------------------");

	Gotoxy(84, 4);
	cout << "  Name:  " << enemy.eName;
	Gotoxy(99, 4);
	cout << " | Level: " << enemy.eLevel;

	Gotoxy(84, 5);
	cout << "  Health: [" << enemy.eCurrHP << " / " << enemy.eMaxHP << "]";
	
	Gotoxy(84, 6);
	cout << "  Damage: " << enemy.eDamageMin << " ~ " << enemy.eDamageMax;

	Gotoxy(84, 7);
	cout << "  Accuracy: " << enemy.eAccuracy << "%";

	Gotoxy(99, 7);
	cout << " | Drop Rate: " << enemy.eDropRate << "%";
}

int UserInterface::readInCommand() const
{
	cout << "\n";
	outputLine("ENTER YOUR COMMAND: ");
	int com;
	cin >> com;
	return com;
}

void UserInterface::outputLine(const string& text) const
{
	cout << "\n      " << text;
}
