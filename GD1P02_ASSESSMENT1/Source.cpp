#include <iostream>
#define NOMINMAX
#include <windows.h>
#include <cmath>
#include <io.h>
#include <fcntl.h>
#include <time.h>
#include <limits>

#include"CPosition.h"
#include"CDeque.h"

using namespace std;

void SetupProgram();

void MainLoop();

void QuickSort(int _arr[], int lowest, int highest);
int Split(int _arr[], int lowest, int highest);
void swap(int* a, int* b);
void DisplayArray(int _arr[], int);

int IntInput(int, int);
void Print(CPosition pos, wstring str, int effect = 15);
void SlowPrint(CPosition _pos, wstring _message, int effect = 15, int _wait = 20);
void GotoXY(CPosition pos);

int main() {
	SetupProgram();
	Sleep(1000);
	SlowPrint({ 0,0 }, L"Booting", 0);
	SlowPrint({ 0,0 }, L"Deque and Quicksort Program    By Keane Carotenuto", 10);

	MainLoop();

	return 0;
}

//Changes The console size etc
void SetupProgram()
{
	//Enable the use of Unicode
	(void)_setmode(_fileno(stdout), _O_U16TEXT);
	SlowPrint({ 0,0 }, L"Booting", 12);
	

	//Maximise the screen
	ShowWindow(GetConsoleWindow(), SW_MAXIMIZE);

	//Set the buffer size to the size of the screen
	HANDLE hstdout = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	GetConsoleScreenBufferInfo(hstdout, &csbi);
	csbi.dwSize.X = csbi.dwMaximumWindowSize.X;
	csbi.dwSize.Y = csbi.dwMaximumWindowSize.Y;
	SetConsoleScreenBufferSize(hstdout, csbi.dwSize);

	//makes Cursor Invisible
	CONSOLE_CURSOR_INFO info;
	info.dwSize = 100;
	info.bVisible = FALSE;
	SetConsoleCursorInfo(hstdout, &info);

	//Seed for Random
	srand(static_cast <unsigned> (time(0)));
}

void MainLoop() {
	int state = 0;


	while (state != -1) {
		switch (state)
		{
		case 0:
			system("CLS");
			Print({ 0,0 }, L"Deque and Quicksort Program    By Keane Carotenuto", 10);
			Print({1,3}, L"Which Program Would you Like to Use?");
			Print({2,4}, L"(1) Deque Program", 8);
			Print({2,5}, L"(2) Quicksort Program", 8);
			Print({2,7}, L"Choice: ", 7);

			state = IntInput(0,2);

			break;

		case 1:
			wcout << "Deque" << endl;;
			state = IntInput(0, 2);
			break;

		case 2:
			wcout << "Quicksort" << endl;
			state = IntInput(0, 2);
			break;

		case 3:

			break;

		case 4:

			break;

		case 5:

			break;


		default:
			break;
		}
	}

	return;
}

void QuickSort(int _arr[], int lowest, int highest) {
	//Only happens if the two numbers have not met in the middle.
	if (lowest < highest) {
		//Splits the array around one number
		int splitIndex = Split(_arr, lowest, highest);

		cout << "\nLower\n";
		DisplayArray(_arr, 10);
		//Sorts lower half of current split
		QuickSort(_arr, lowest, splitIndex - 1);
		cout << "\nUpper\n";
		DisplayArray(_arr, 10);
		//sorts upper half of current split 
		QuickSort(_arr, splitIndex + 1, highest);
	}
}

//Splits given portion of array (range defined by lowest and highest)
int Split(int _arr[], int lowest, int highest) {
	//makes last number pivot.
	int pivotVal = _arr[highest];
	int lowIndex = (lowest - 1);

	//Places elements on the correct side of the pivot
	for (int i = lowest; i <= highest - 1; i++) {
		//If smaller than pivot, swap to lowest avaliable position
		if (_arr[i] < pivotVal) {
			lowIndex++;
			swap(&_arr[lowIndex], &_arr[i]);
		}
	}

	//Swaps low and high for next round of sorting
	swap(&_arr[lowIndex + 1], &_arr[highest]);
	return (lowIndex + 1);
}

//Swaps items in array
void swap(int* a, int* b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}

//Draws array on screen
void DisplayArray(int _arr[], int _arrSize) {
	cout << _arrSize << " ";
	cout << "Array: ";
	for (int i = 0; i < _arrSize; i++) {
		cout << _arr[i] << ", ";
	}
	cout << " END." << endl;
}

int IntInput(int min = numeric_limits<int>::min(), int max = numeric_limits<int>::max()) {
	int tempInt;
	cin >> tempInt;
	while (cin.fail() || tempInt < min || tempInt > max) {
		cin.clear();
		cin.ignore(INT_MAX, '\n');
		wcout << L"Please input an integer between, " << min << L" and " << max << L": ";
		cin >> tempInt;
	}
	return tempInt;
}

//Used to print out text at the specified coordinate, with the specified effect.
void Print(CPosition pos, wstring str, int effect) {
	GotoXY(pos);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), effect);
	wcout << str;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
};

//Prints text at coord with colour one letter at a time
void SlowPrint(CPosition _pos, wstring _message, int effect, int _wait) {
	GotoXY(_pos);
	for (wchar_t _char : _message) {																						// TF: Iteration Structure
		Sleep(_wait);
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), effect);
		wcout << _char;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
	}
}

//Used to move the Console Cursor to a point on the screen for more accurate text management.
void GotoXY(CPosition pos) {
	COORD point;
	point.X = pos.x;
	point.Y = pos.y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), point);
};