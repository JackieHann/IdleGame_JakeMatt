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
	ShowMessage(clBlack, clYellow, 2, 7, "-<STATS>-------------------------------------");
	ShowMessage(clBlack, clYellow, 2, 8, "|                                           |");
	ShowMessage(clBlack, clYellow, 2, 9,"|                                           |");
	ShowMessage(clBlack, clYellow, 2, 10,"|                                           |");
	ShowMessage(clBlack, clYellow, 2, 11,"---------------------------------------------");

	SelectTextColour(clWhite);
	//Write player stuff to screen
	Gotoxy(5, 8);
	cout << "Name:" << pName << "  |  Lv:" << pLevel << "  |  Exp: " << pExp << "%";
	
	Gotoxy(5, 9);
	cout << "Health: [" << pCurrHP << " / " << pMaxHP << "]  Dmg: " << pDamageMin << " ~ " << pDamageMax;

	Gotoxy(5, 10);
	cout << "Currently: " << pAct << " in " << pLoc;



}

void UserInterface::showPlayerLog(vector<string> pLog) const
{
	//Setup UI
	ShowMessage(clBlack, clYellow, 50, 2, "-<LOG>----------------");
	ShowMessage(clBlack, clYellow, 50, 3, "|                    |");
	ShowMessage(clBlack, clYellow, 50, 4, "|                    |");
	ShowMessage(clBlack, clYellow, 50, 5, "|                    |");
	ShowMessage(clBlack, clYellow, 50, 6, "|                    |");
	ShowMessage(clBlack, clYellow, 50, 7, "|                    |");
	ShowMessage(clBlack, clYellow, 50, 8, "|                    |");
	ShowMessage(clBlack, clYellow, 50, 9, "|                    |");
	ShowMessage(clBlack, clYellow, 50, 10,"|                    |");
	ShowMessage(clBlack, clYellow, 50, 11,"----------------------");

	SelectTextColour(clDarkGrey);
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
	ShowMessage(clBlack, clYellow, 2, 2, "    _______________________________   ");
	ShowMessage(clBlack, clYellow, 2, 3, "   /                               \\  ");
	ShowMessage(clBlack, clYellow, 2, 4, "  |     IDLE GAME - JAKE H :)       | ");
	ShowMessage(clBlack, clYellow, 2, 5, "   \\_______________________________/  ");
	ShowMessage(clBlack, clYellow, 2, 6, "                                      ");

}

void UserInterface::showBattle(Enemy enemy) const
{
	//Setup UI
	ShowMessage(clBlack, clYellow, 74, 2, "-<Most Recent Enemy>-------------------------");
	ShowMessage(clBlack, clYellow, 74, 3, "| ________                                  |");
	ShowMessage(clBlack, clYellow, 74, 4, "| |      |                                  |");
	ShowMessage(clBlack, clYellow, 74, 5, "| | PIC~ |                                  |");
	ShowMessage(clBlack, clYellow, 74, 6, "| |______|                                  |");
	ShowMessage(clBlack, clYellow, 74, 7, "|                                           |");
	ShowMessage(clBlack, clYellow, 74, 8, "|                                           |");
	ShowMessage(clBlack, clYellow, 74, 9, "|                                           |");
	ShowMessage(clBlack, clYellow, 74, 10,"|                                           |");
	ShowMessage(clBlack, clYellow, 74, 11,"---------------------------------------------");

	SelectTextColour(clWhite);

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
	int y = 13;
	int x = 74;
	//Setup Battle Log
	ShowMessage(clBlack, clYellow, x, y,		"-<Battle Log>--------------------------------");
	ShowMessage(clBlack, clYellow, x, y + 1,	"|                                           |");
	ShowMessage(clBlack, clYellow, x, y + 2,	"|                                           |");
	ShowMessage(clBlack, clYellow, x, y + 3,	"|                                           |");
	ShowMessage(clBlack, clYellow, x, y + 4,	"|                                           |");
	ShowMessage(clBlack, clYellow, x, y + 5,	"|                                           |");
	ShowMessage(clBlack, clYellow, x, y + 6,	"|                                           |");
	ShowMessage(clBlack, clYellow, x, y + 7,	"---------------------------------------------");

	SelectTextColour(clWhite);
	if (enemy.battleLog.size() != 0)
	{
		for (int i = 0; i < enemy.battleLog.size(); i++)
		{
			Gotoxy(76, i + 14);
			cout << enemy.battleLog.at(i);
		}
	}
}

void UserInterface::showWeaponBag(vector<Weapon> weapons, string backpackSpace) const
{
	int y = 24;
	int x = 2;

	//Top border
	ShowMessage(clBlack, clYellow, x, y,									"-<Weapon Bag>-----------------------<Damage>-");
	for (int i = 0; i < weapons.size(); i++)
	{
		ShowMessage(clBlack, clYellow, x, y + i + 1, "|                                           |");
		Gotoxy(x + 2, y + i + 1);
		//Output weapon number in bag
		SelectTextColour(clWhite);
		cout << to_string(i + 1) << "] ";

		//Colour weapon text based on rarity
		switch (weapons.at(i).getRarity())
		{
		case 0:
			SelectTextColour(clDarkGrey);
			break;
		case 1:
			SelectTextColour(clGreen);
			break;
		case 2:
			SelectTextColour(clCyan);
			break;
		case 3:
			SelectTextColour(clDarkMagenta);
			break;
		case 4:
			SelectTextColour(clYellow);
			break;
		}
		cout << weapons.at(i).getFullWeaponName();

		//Show weapons range
		SelectTextColour(clWhite);
		Gotoxy(x + 34, y + i + 1);
		cout << "| " << weapons.at(i).getFullWeaponRange();
	}
	//Bottom Border
	ShowMessage(clBlack, clYellow, x, y + weapons.size() + 1,				backpackSpace + "-------------------------------------");
}

void UserInterface::showArmourBag(vector<Armour> armours, string backpackSpace) const
{
	int y = 24;
	int x = 50;

	//Top border
	ShowMessage(clBlack, clYellow, x, y, "-<Armour Bag>------------------------<Bonus>-");
	for (int i = 0; i < armours.size(); i++)
	{
		ShowMessage(clBlack, clYellow, x, y + i + 1, "|                                           |");
		Gotoxy(x + 2, y + i + 1);
		//Output weapon number in bag
		SelectTextColour(clWhite);
		cout << to_string(i + 1) << "] ";

		//Colour weapon text based on rarity
		switch (armours.at(i).getRarity())
		{
		case 0:
			SelectTextColour(clDarkGrey);
			break;
		case 1:
			SelectTextColour(clGreen);
			break;
		case 2:
			SelectTextColour(clCyan);
			break;
		case 3:
			SelectTextColour(clDarkMagenta);
			break;
		case 4:
			SelectTextColour(clYellow);
			break;
		}
		cout << armours.at(i).getFullArmourName();

		//Show weapons range
		SelectTextColour(clWhite);
		Gotoxy(x + 34, y + i + 1);
		cout << "| " << armours.at(i).getFullArmourValue();
	}
	//Bottom Border
	ShowMessage(clBlack, clYellow, x, y + armours.size() + 1, backpackSpace + "-------------------------------------");
}

void UserInterface::showEquippedItems(vector<Weapon> weapons, vector<Armour> armours) const
{
	int y = 13;
	int x = 2;

	//Top border
	ShowMessage(clBlack, clYellow, x, y,		"-<Equipped Items>-----------------------------<Bonus>----<Sell Price>-");
	ShowMessage(clBlack, clYellow, x, y+ 1,		"| Weapon  ->                                                         |");
	ShowMessage(clBlack, clYellow, x, y+ 2,		"| Offhand ->                                                         |");
	ShowMessage(clBlack, clYellow, x, y + 3,	"| Head    ->                                                         |");
	ShowMessage(clBlack, clYellow, x, y + 4,	"| Body    ->                                                         |");
	ShowMessage(clBlack, clYellow, x, y + 5,	"| Legs    ->                                                         |");;
	ShowMessage(clBlack, clYellow, x, y + 6,	"| Feet    ->                                                         |");
	ShowMessage(clBlack, clYellow, x, y + 7,	"| Hands   ->                                                         |");
	ShowMessage(clBlack, clYellow, x, y + 8,	"| Waist   ->                                                         |");
	ShowMessage(clBlack, clYellow, x, y + 9,	"----------------------------------------------------------------------");

	//Show weapons;
	for (int i = 0; i < weapons.size(); i++)
	{
		Gotoxy(x + 14, y + i + 1);
		//Output weapon number in bag
		SelectTextColour(clWhite);
	
		//Colour weapon text based on rarity
		switch (weapons.at(i).getRarity())
		{
		case 0:
			SelectTextColour(clDarkGrey);
			break;
		case 1:
			SelectTextColour(clGreen);
			break;
		case 2:
			SelectTextColour(clCyan);
			break;
		case 3:
			SelectTextColour(clDarkMagenta);
			break;
		case 4:
			SelectTextColour(clYellow);
			break;
		}
		cout << weapons.at(i).getFullWeaponName();
	
		//Show weapons range
		SelectTextColour(clWhite);
		Gotoxy(x + 45, y + i + 1);
		cout << "| + " << weapons.at(i).getFullWeaponRange() +" Dmg";
	}

	//Show armour
	for (int i = 0; i < armours.size(); i++)
	{
		Gotoxy(x + 14, y + i + 3);
		//Output weapon number in bag
		SelectTextColour(clWhite);

		//Colour weapon text based on rarity
		switch (armours.at(i).getRarity())
		{
		case 0:
			SelectTextColour(clDarkGrey);
			break;
		case 1:
			SelectTextColour(clGreen);
			break;
		case 2:
			SelectTextColour(clCyan);
			break;
		case 3:
			SelectTextColour(clDarkMagenta);
			break;
		case 4:
			SelectTextColour(clYellow);
			break;
		}
		cout << armours.at(i).getFullArmourName();
	
		//Show weapons range
		SelectTextColour(clWhite);
		Gotoxy(x + 45, y + i + 3);
		cout << "| " << armours.at(i).getFullArmourValue();
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
