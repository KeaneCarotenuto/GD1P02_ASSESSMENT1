#include <iostream>
#include <windows.h>
#include <cmath>

#include"CDeque.h"

using namespace std;

void QuickSort(int _arr[], int lowest, int highest);
int Split(int _arr[], int lowest, int highest);
void swap(int* a, int* b);
void DisplayArray(int _arr[], int);

int main() {

	return 0;
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