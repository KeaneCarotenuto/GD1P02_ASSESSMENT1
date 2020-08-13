#pragma once
#include <iostream>
#include <string>
#include"CDequeNode.h"
#include"CPosition.h"

using namespace std;

class CDeque
{
private:
	CDequeNode* firstNode;
	CDequeNode* LastNode;

public:
	CDeque();

	CDequeNode* GetFirstNode();
	CDequeNode* GetLastNode();

	void Enqueue_Front(int _data);
	void Enqueue_Back(int _data);
	bool Dequeue_Front(int& data);
	bool Dequeue_Back(int& data);
	int PeekFront(int& data);
	int PeekBack(int& data);
	bool IsEmpty();

	void DisplayArray(CPosition pos);
};

