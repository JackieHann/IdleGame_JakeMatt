#ifndef UserInterfaceH 
#define UserInterfaceH

#include "ConsoleUtils_JH.h"
#include <iomanip>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include "Player.h"

using namespace std;


//---------------------------------------------------------------------------
//UserInterface: class declaration
//---------------------------------------------------------------------------

class UserInterface {

public:
	int		showMainMenuAndGetCommand() const;
	string	showNameInputAndGet() const;
	void	showPlayerStatus(string, int, float, string, string) const;
	void	showPlayerLog(vector<string>) const;
	void	showTitle() const;
	void	showBattle(Enemy) const;

private:
	int		readInCommand() const;
	void	outputLine(const string&) const;
};

#endif