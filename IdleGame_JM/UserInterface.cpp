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

void UserInterface::showPlayerStatus(string pName, int pLevel, float pExp, string pAct, string pLoc, float pMaxHP, float pCurrHP, float pDamageMax, float pDamageMin) const
{
	//Setup UI
	ShowMessage(clBlack, clCyan, 2, 8, "-<STATS>-------------------------------------");
	ShowMessage(clBlack, clCyan, 2, 9, "|                                           |");
	ShowMessage(clBlack, clCyan, 2, 10,"|                                           |");
	ShowMessage(clBlack, clCyan, 2, 11, "|                                           |");
	ShowMessage(clBlack, clCyan, 2, 12,"---------------------------------------------");

	SelectTextColour(clRed);
	//Write player stuff to screen
	Gotoxy(5, 9);
	cout << "Name:" << pName << "  |  Lv:" << pLevel << "  |  Exp: " << pExp << "%";
	
	Gotoxy(5, 10);
	cout << "Health: [" << pCurrHP << " / " << pMaxHP << "]  Dmg: " << pDamageMin << " ~ " << pDamageMax;

	Gotoxy(5, 11);
	cout << "Currently: " << pAct << " in " << pLoc;



}

void UserInterface::showPlayerLog(vector<string> pLog) const
{
	//Setup UI
	ShowMessage(clBlack, clCyan, 50, 2, "-<LOG>----------------");
	ShowMessage(clBlack, clCyan, 50, 3, "|                    |");
	ShowMessage(clBlack, clCyan, 50, 4, "|                    |");
	ShowMessage(clBlack, clCyan, 50, 5, "|                    |");
	ShowMessage(clBlack, clCyan, 50, 6, "|                    |");
	ShowMessage(clBlack, clCyan, 50, 7, "|                    |");
	ShowMessage(clBlack, clCyan, 50, 8, "|                    |");
	ShowMessage(clBlack, clCyan, 50, 9, "|                    |");
	ShowMessage(clBlack, clCyan, 50, 10,"|                    |");
	ShowMessage(clBlack, clCyan, 50, 11,"----------------------");

	SelectTextColour(clRed);
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
	ShowMessage(clBlack, clCyan, 2, 2, "                                       ");
	ShowMessage(clBlack, clCyan, 2, 3, "                                       ");
	ShowMessage(clBlack, clCyan, 2, 4, "          Title Goes Here              ");
	ShowMessage(clBlack, clCyan, 2, 5, "                                       ");
	ShowMessage(clBlack, clCyan, 2, 6, "                                       ");

}

void UserInterface::showBattle(Enemy enemy) const
{
	//Setup UI
	ShowMessage(clBlack, clCyan, 74, 2, "-<Most Recent Enemy>-------------------------");
	ShowMessage(clBlack, clCyan, 74, 3, "| ________                                  |");
	ShowMessage(clBlack, clCyan, 74, 4, "| |      |                                  |");
	ShowMessage(clBlack, clCyan, 74, 5, "| | PIC~ |                                  |");
	ShowMessage(clBlack, clCyan, 74, 6, "| |______|                                  |");
	ShowMessage(clBlack, clCyan, 74, 7, "|                                           |");
	ShowMessage(clBlack, clCyan, 74, 8, "|                                           |");
	ShowMessage(clBlack, clCyan, 74, 9, "|                                           |");
	ShowMessage(clBlack, clCyan, 74, 10,"|                                           |");
	ShowMessage(clBlack, clCyan, 74, 11,"---------------------------------------------");

	SelectTextColour(clRed);

	Gotoxy(84, 4);
	cout << "  Name:  " << enemy.eName;
	Gotoxy(84, 5);
	cout << "  Level: " << enemy.eLevel;

	Gotoxy(84, 6);
	cout << "  Health: [" << enemy.eCurrHP << " / " << enemy.eMaxHP << "]";
	
	Gotoxy(84, 7);
	cout << "  Damage: " << enemy.eDamageMin << " ~ " << enemy.eDamageMax;

	Gotoxy(84, 8);
	cout << "  Accuracy: " << enemy.eAccuracy << "%";

	Gotoxy(84, 9);
	cout << "  Drop Rate: " << enemy.eDropRate << "%";
}

void UserInterface::showBattleLog(Enemy enemy) const
{

	//Setup Battle Log
	ShowMessage(clBlack, clCyan, 74, 13, "-<Battle Log>--------------------------------");
	ShowMessage(clBlack, clCyan, 74, 14, "|                                           |");
	ShowMessage(clBlack, clCyan, 74, 15, "|                                           |");
	ShowMessage(clBlack, clCyan, 74, 16, "|                                           |");
	ShowMessage(clBlack, clCyan, 74, 17, "|                                           |");
	ShowMessage(clBlack, clCyan, 74, 18, "|                                           |");
	ShowMessage(clBlack, clCyan, 74, 19, "|                                           |");
	ShowMessage(clBlack, clCyan, 74, 20, "---------------------------------------------");

	SelectTextColour(clRed);
	if (enemy.battleLog.size() != 0)
	{
		for (int i = 0; i < enemy.battleLog.size(); i++)
		{
			Gotoxy(76, i + 14);
			cout << enemy.battleLog.at(i);
		}
	}
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
