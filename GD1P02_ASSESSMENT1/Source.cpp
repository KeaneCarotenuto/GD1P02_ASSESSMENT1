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
	SlowPrint({ 0,0 }, L"Deque and Quicksort Program    By Keane Carotenuto", 10, 10);

	MainLoop();

	return 0;
}

//Changes The console size, buffer size, text format, cursor format, and sets random seed
void SetupProgram()
{
	//Enable the use of Unicode
	(void)_setmode(_fileno(stdout), _O_U16TEXT);
	SlowPrint({ 0,0 }, L"Booting", 12, 10);
	

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

	//Manages program state
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
			return;
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
	Print({ 2,7 }, L"(3) Quit", 4);
	Print({ 2,9 }, L"Choice: ", 8);

	return IntInput(0, 3);
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

			//Checks if valid frist
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

			//Checks if valid first
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

			//Checks if valid first
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

//The main portion of code used to interact with the user in reguards to the quicksort algorithm.
//This portion of the code is a bit wonky, I could be condensed a lot more, but it runs well enough to keep it the way it is.
int Sort() {
	//I delcare my variables here as values that are impossible to achieve through user input, so that I can use them to check the state of the code.
	int arrayLength = -1;
	int* myArray = nullptr;
	int isAscending = -1;
	int lastGoodNum = 0; // Keeps track of the index of the last number in the array that the user entered

//I use a label here to come back here and re-print the screen after the user has entered some data to clean it up.
reprint:
	system("CLS");
	Print({ 0,0 }, L"Deque and Quicksort Program    By Keane Carotenuto", 10);
	Print({ 1,3 }, L"Please Enter how long of an Array you want to sort");
	Print({ 2,5 }, L"Number of Elements: " + ((arrayLength != -1) ? to_wstring(arrayLength) : L""), 8); //Checks what to print depenidng on state 

	//Only asks user for length if they havent already
	if (arrayLength == -1) {
		arrayLength = IntInput(1, 100);
		myArray = new int[arrayLength];

		goto reprint;
	}

	Print({ 1,7 }, L"Would you like to sort is (0)Ascending, or (1)Descending Order?");
	Print({ 2,9 }, L"(0) or (1): " + ((isAscending != -1) ? to_wstring(!isAscending) : L"" ), 8);

	//Only asks if user hasnt already chosen
	if (isAscending == -1) {
		isAscending = true;
		(IntInput(0, 1) ? isAscending = false : isAscending = true);

		goto reprint;
	}

	Print({ 2,11 }, L"Please Enter all " + to_wstring(arrayLength) + L" Elements now, seperated by spaces");
	Print({ 2,12 }, L"Or Enter one at a time followed by <ENTER>");

	int row = 0;
	size_t col = 3; //Is a size_t to supress error about data loss when converting to int (even thought it could not happen in this situation)

	//Prints out each of the elements in a vertical list for the user, making sure to stop at the msot recent un-decided element;
	for (int j = 0; j < lastGoodNum; j++) {
		if (j % 4 == 0) {
			row++;
			col = 3;
		}
		Print({ 3 + static_cast<int>(col), 14 + row }, L"Element " + to_wstring(j + 1) + L": " + to_wstring(myArray[j]), 8);
		col += 22;
		
		//col += 12 + to_string(j + 1).size() + to_string(myArray[j]).size();
	}
	if (lastGoodNum < arrayLength) {
		if (lastGoodNum % 4 == 0) {
			row++;
			col = 3;
		}

		//Highlights current elemnt and asks user to input
		Print({ 3 + static_cast<int>(col), 14 + row }, L"Element " + to_wstring(lastGoodNum + 1) + L": ", 10);
		myArray[lastGoodNum] = IntInput();

		col += 12 + to_string(lastGoodNum + 1).size() + to_string(myArray[lastGoodNum]).size();
		lastGoodNum++;
		goto reprint;
	}

	//Clears cin so any extra inputs arent counted as input
	cin.clear();
	cin.ignore(INT_MAX, '\n');


	//Displays the current array, sorts it, and displays the sorted array;
	wcout << "\n\n";
	wcout << "Initial ";
	CQuickSort::DisplayArray(myArray, arrayLength);

	CQuickSort::QuickSort(myArray, 0, arrayLength-1, isAscending);
	wcout << "\n\nSorted ";
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