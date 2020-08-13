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

int Menu();
int Deque();

void QuickSort(int _arr[], int lowest, int highest);
int Split(int _arr[], int lowest, int highest);
void swap(int* a, int* b);
void DisplayArray(int _arr[], int);

int IntInput(int min = numeric_limits<int>::min(), int max = numeric_limits<int>::max());
void Print(CPosition pos, wstring str, int effect = 15);
void SlowPrint(CPosition _pos, wstring _message, int effect = 15, int _wait = 20);

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
			state = Menu();

			break;

		case 1:
			state = Deque();

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

int Menu() {
	system("CLS");
	Print({ 0,0 }, L"Deque and Quicksort Program    By Keane Carotenuto", 10);
	Print({ 1,3 }, L"Which Program Would you Like to Use?");
	Print({ 2,5 }, L"(1) Deque Program", 8);
	Print({ 2,6 }, L"(2) Quicksort Program", 8);
	Print({ 2,8 }, L"Choice: ", 7);

	return IntInput(0, 2);
}

int Deque() {
	CDeque* myDeque = new CDeque;

	while (true) {
		system("CLS");
		Print({ 0,0 }, L"Deque Program    By Keane Carotenuto", 10);
		Print({ 1,3 }, L"Which Opperatoin Would you Like to Test?");
		Print({ 2,5 }, L"(0) Return To Menu (Will Lose List)", 8);
		Print({ 2,7 }, L"(1) Enqueue at Front", 8);
		Print({ 2,8 }, L"(2) Enqueue at Back", 8);
		Print({ 2,10 }, L"(3) Dequeue at Front", 8);
		Print({ 2,11 }, L"(4) Dequeue at Back", 8);
		Print({ 2,13 }, L"(5) Peek at Front", 8);
		Print({ 2,14 }, L"(6) Peek at Back", 8);
		Print({ 2,16 }, L"(7) Check Empty", 8);
		Print({ 2,18 }, L"(8) Reset Deque", 8);

		myDeque->DisplayArray({50,3},true);

		Print({ 2,20 }, L"Choice: ", 7);
		int dequeState = IntInput(0, 8);

		int theData = 0;

		switch (dequeState)
		{
		case 1:
			system("CLS");
			Print({ 0,0 }, L"Deque Program    By Keane Carotenuto", 10);
			Print({ 1,3 }, L"Please Enter a Number to Enque at Front: ");
			Print({ 2,5 }, L"Choice: ", 7);

			myDeque->Enqueue_Front(IntInput());

			break;

		case 2:
			system("CLS");
			Print({ 0,0 }, L"Deque Program    By Keane Carotenuto", 10);
			Print({ 1,3 }, L"Please Enter a Number to Enque at Back: ");
			Print({ 2,5 }, L"Choice: ", 7);

			myDeque->Enqueue_Back(IntInput());

			break;

		case 3:
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
			return 1;
			break;

		default:
			return 0;

			break;
		}
	}
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

int IntInput(int min, int max) {
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