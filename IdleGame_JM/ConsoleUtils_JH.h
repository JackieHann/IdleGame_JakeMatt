/* Jake Hanne - b6027599
** A simple library of console functions ~
---------------------------------------
** Clrscr() - clear the screen, and reset cursor to (0, 0)
** Gotoxy(x, y) - move the text cursor to position (x, y)
** SelectBackColour(colour) - select a background colour from the colour constants list
** SelectTextColour(colour) - select a text colour from the colour constants list
*/

#ifndef ConsoleUtilsH
#define ConsoleUtilsH

#include <windows.h>
#include <string>
#include <iostream>
#include <iomanip>

using namespace std;


//colour constants for translation
const WORD clBlack = 0;
const WORD clDarkRed = 1;
const WORD clDarkGreen = 2;
const WORD clDarkBlue = 3;
const WORD clDarkCyan = 4;
const WORD clDarkMagenta = 5;
const WORD clDarkYellow = 6;
const WORD clDarkGrey = 7;
const WORD clGrey = 8;
const WORD clRed = 9;
const WORD clGreen = 10;
const WORD clBlue = 11;
const WORD clCyan = 12;
const WORD clMagenta = 13;
const WORD clYellow = 14;
const WORD clWhite = 15;

//-------------
//clear the screen, and reset cursor to (0, 0)
void Clrscr();

//move the text cursor to position (x, y)
void Gotoxy(int x, int y);

//select a background colour from the colour constants list
void SelectBackColour(int colour);

//select a text colour from the colour constants list
void SelectTextColour(int colour);

void ShowMessage(const WORD backColour, const WORD textColour, int x, int y, const string message);

//select the text attributes
void SelectAttributes();

//get the heigth of the screen (console window)
int screenHeight();

//get the width of the screen (console window)
int screenWidth();

#endif