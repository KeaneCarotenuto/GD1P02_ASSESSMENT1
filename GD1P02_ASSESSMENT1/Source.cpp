#include <iostream>
#define NOMINMAX //Used for max and min int (in IntInput), two libraries seem to conflict about this
#include <windows.h>
#include <cmath>
#include <io.h>
#include <fcntl.h>
#include <time.h>
#include <limits>

#include"CPosition.h"
#include"CDeque.h"
#include"CQuickSort.h"

using namespace std;

void SetupProgram();

void MainLoop();

int Menu();
int Deque();
int Sort();


int IntInput(int min = numeric_limits<int>::min(), int max = numeric_limits<int>::max());
void Print(CPosition pos, wstring str, int effect = 15);
void SlowPrint(CPosition _pos, wstring _message, int effect = 15, int _wait = 20);

//The main function, used to call the inital programs, and then the main loop.
int main() {
	SetupProgram();
	Sleep(1000);
	SlowPrint({ 0,0 }, L"Booting", 0);
	SlowPrint({ 0,0 }, L"Deque and Quicksort Program    By Keane Carotenuto", 10);

	MainLoop();

	return 0;
}

//Changes The console size, buffer size, text format, cursor format, and sets random seed
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

//The Main Loop that manages Which program is currently running
void MainLoop() {
	int state = 0;


	while (state != -1) {
		switch (state)
		{
		case 0:
			state = Menu();

			break;

		case 1:
			state = Deque();

			break;

		case 2:
			state = Sort();
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

//This is used to Manage which Program the user would like to use.
int Menu() {
	system("CLS");
	Print({ 0,0 }, L"Deque and Quicksort Program    By Keane Carotenuto", 10);
	Print({ 1,3 }, L"Which Program Would you Like to Use?");
	Print({ 2,5 }, L"(1) Deque Program", 7);
	Print({ 2,6 }, L"(2) Quicksort Program", 7);
	Print({ 2,8 }, L"Choice: ", 8);

	return IntInput(0, 2);
}


//This is the main portion of the Deque Program. Each Case is one of the options that can be taken to interact with the Deque.
//This system is managed by a switch case, for ease of reading. Each case is one option, and does one thing.
int Deque() {
	CDeque* myDeque = new CDeque;

	while (true) {
		system("CLS");
		Print({ 0,0 }, L"Deque Program    By Keane Carotenuto", 10);
		Print({ 1,3 }, L"Which Opperatoin Would you Like to Test?");
		Print({ 2,5 }, L"(0) Return To Menu (Will Lose List)", 7);
		Print({ 2,7 }, L"(1) Enqueue at Front", 7);
		Print({ 2,8 }, L"(2) Enqueue at Back", 7);
		Print({ 2,10 }, L"(3) Dequeue at Front", 7);
		Print({ 2,11 }, L"(4) Dequeue at Back", 7);
		Print({ 2,13 }, L"(5) Peek at Front", 7);
		Print({ 2,14 }, L"(6) Peek at Back", 7);
		Print({ 2,16 }, L"(7) Check Empty", 7);
		Print({ 2,18 }, L"(8) Reset Deque", 7);

		myDeque->DisplayArray({50,3});

		Print({ 2,20 }, L"Choice: ", 8);
		int dequeState = IntInput(0, 8);

		int theData = 0;

		switch (dequeState)
		{
		case 1:
			//Enqueue at front 

			system("CLS");
			Print({ 0,0 }, L"Deque Program    By Keane Carotenuto", 10);
			Print({ 1,3 }, L"Please Enter a Number to Enqueue at Front: ");
			Print({ 2,5 }, L"Choice: ", 8);

			myDeque->Enqueue_Front(IntInput());

			break;

		case 2:
			//Enqueue at back

			system("CLS");
			Print({ 0,0 }, L"Deque Program    By Keane Carotenuto", 10);
			Print({ 1,3 }, L"Please Enter a Number to Enqueue at Back: ");
			Print({ 2,5 }, L"Choice: ", 8);

			myDeque->Enqueue_Back(IntInput());

			break;

		case 3:
			//Dequeue at front

			system("CLS");
			Print({ 0,0 }, L"Deque Program    By Keane Carotenuto", 10);
			SlowPrint({ 1,3 }, L"Dequeuing from Front...", 15, 10);

			if (myDeque->Dequeue_Front(theData)) {
				SlowPrint({ 1,4 }, L"Dequeued Data: " + to_wstring(theData) + L"\n\n", 10, 10);
			}
			else {
				SlowPrint({1,4}, L"The Deque is Empty... \n\n", 12, 10);
			}

			system("pause");

			break;

		case 4:
			//Dequeue at back

			system("CLS");
			Print({ 0,0 }, L"Deque Program    By Keane Carotenuto", 10);
			SlowPrint({ 1,3 }, L"Dequeuing from Back...", 15, 10);

			if (myDeque->Dequeue_Back(theData)) {
				SlowPrint({ 1,4 }, L"Dequeued Data: " + to_wstring(theData) + L"\n\n", 10, 10);
			}
			else {
				SlowPrint({ 1,4 }, L"The Deque is Empty... \n\n", 12, 10);
			}

			system("pause");

			break;

		case 5:
			//Peek Front

			system("CLS");
			Print({ 0,0 }, L"Deque Program    By Keane Carotenuto", 10);
			SlowPrint({ 1,3 }, L"Peeking at Front...", 15, 10);

			if (myDeque->PeekFront(theData)) {
				SlowPrint({ 1,4 }, L"Data: " + to_wstring(theData) + L"\n\n", 10, 10);
			}
			else {
				SlowPrint({ 1,4 }, L"The Deque is Empty... \n\n", 12, 10);
			}

			system("pause");

			break;

		case 6:
			//Peek Back

			system("CLS");
			Print({ 0,0 }, L"Deque Program    By Keane Carotenuto", 10);
			SlowPrint({ 1,3 }, L"Peeking at Back...", 15, 10);

			if (myDeque->PeekBack(theData)) {
				SlowPrint({ 1,4 }, L"Data: " + to_wstring(theData) + L"\n\n", 10, 10);
			}
			else {
				SlowPrint({ 1,4 }, L"The Deque is Empty... \n\n", 12, 10);
			}

			system("pause");

			break;

		case 7:
			//IsEmpty

			system("CLS");
			Print({ 0,0 }, L"Deque Program    By Keane Carotenuto", 10);
			SlowPrint({ 1,3 }, L"Checking Emptyness...", 15, 10);

			if (myDeque->IsEmpty()) {
				SlowPrint({ 1,4 }, L"The Deque is Empty. \n\n", 12, 10);
				
			}
			else {
				SlowPrint({ 1,4 }, L"The Deque is Not Empty. \n\n", 10, 10);
			}

			system("pause");

			break;

		case 8:
			//Reset

			return 1;

			break;

		default:
			//Return to Menu

			return 0;

			break;
		}
	}
}

int Sort() {
	system("CLS");
	Print({ 0,0 }, L"Deque and Quicksort Program    By Keane Carotenuto", 10);
	Print({ 1,3 }, L"Please Enter how long of an Array you want to sort");
	Print({ 2,5 }, L"Number of Elements: ", 8);

	int arrayLength = IntInput(1,100);

	int* myArray = new int[arrayLength];

	Print({ 2,7 }, L"Please Enter all " + to_wstring(arrayLength) + L" Elements now, seperated by spaces", 8);
	Print({ 2,8 }, L"Or Enter one at a time followed by <ENTER>", 8);

	for (int i = 0; i < arrayLength; i++) {
		Print({ 0,10 + i }, L"------------------------------------------------------------------", 0);
		Print({3,10+i}, L"Element " + to_wstring(i + 1) + L": ", 8);
		myArray[i] = IntInput();
		Print({ 3,10 + i }, L"------------------------------------------------------------------", 0);
		Print({ 3,10 + i }, L"Element " + to_wstring(i + 1) + L": " + to_wstring(myArray[i]), 8);

	}
	cin.clear();
	cin.ignore(INT_MAX, '\n');

	wcout << "\n\n";
	CQuickSort::DisplayArray(myArray, arrayLength);
	wcout << "\n";
	CQuickSort::QuickSort(myArray, 0, arrayLength-1);
	wcout << "\n";
	CQuickSort::DisplayArray(myArray, arrayLength);

	wcout << "\n";

	system("pause");

	return 0;
}

//used to manage integer inputs from the user. Filters out bad inputs and asks again. Can be configured to be between a range.
int IntInput(int min, int max) {
	int tempInt;
	cin >> tempInt;

	//If input is bad, ask again.
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
	CPosition::GotoXY(pos);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), effect);
	wcout << str;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
};

//Prints text at coord with colour one letter at a time
void SlowPrint(CPosition _pos, wstring _message, int effect, int _wait) {
	CPosition::GotoXY(_pos);
	for (wchar_t _char : _message) {
		Sleep(_wait);
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), effect);
		wcout << _char;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
	}
}