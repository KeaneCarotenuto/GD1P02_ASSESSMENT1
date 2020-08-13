#include "CPosition.h"

//Used to move the Console Cursor to a point on the screen for more accurate text management.
void CPosition::GotoXY(CPosition pos) {
	COORD point;
	point.X = pos.x;
	point.Y = pos.y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), point);
};