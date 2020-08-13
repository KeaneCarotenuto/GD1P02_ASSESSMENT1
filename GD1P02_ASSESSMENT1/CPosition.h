#pragma once
#include <windows.h>

class CPosition
{
public:
	int x;
	int y;

	static void GotoXY(CPosition pos);
};

