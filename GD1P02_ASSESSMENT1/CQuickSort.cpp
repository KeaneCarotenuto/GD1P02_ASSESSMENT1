#include "CQuickSort.h"

void CQuickSort::QuickSort(int _arr[], int lowest, int highest) {
	//Only happens if the two numbers have not met in the middle.
	if (lowest < highest) {
		//Splits the array around one number
		int splitIndex = Split(_arr, lowest, highest);

		//Sorts lower half of current split
		QuickSort(_arr, lowest, splitIndex - 1);

		//sorts upper half of current split 
		QuickSort(_arr, splitIndex + 1, highest);
	}
}

//Splits given portion of array (range defined by lowest and highest)
int CQuickSort::Split(int _arr[], int lowest, int highest) {
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
void CQuickSort::swap(int* a, int* b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}

//Draws array on screen
void CQuickSort::DisplayArray(int _arr[], int _arrSize) {
	wcout << L"Array: ";
	for (int i = 0; i < _arrSize; i++) {
		wcout << _arr[i] << L", ";
	}
	wcout << L" END." << endl;
}
