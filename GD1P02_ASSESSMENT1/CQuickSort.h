#pragma once
#include <iostream>
#include <string>
#include"CPosition.h"

using namespace std;

class CQuickSort
{
public:
	static void QuickSort(int _arr[], int lowest, int highest);
	static int Split(int _arr[], int lowest, int highest);
	static void swap(int* a, int* b);
	static void DisplayArray(int _arr[], int _arrSize);
};

