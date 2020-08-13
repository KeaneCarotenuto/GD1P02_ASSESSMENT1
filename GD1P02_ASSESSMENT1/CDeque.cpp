#include "CDeque.h"

CDeque::CDeque() :
	firstNode(nullptr),
	LastNode(nullptr)
{
}

CDequeNode* CDeque::GetFirstNode()
{
	return firstNode;
}

CDequeNode* CDeque::GetLastNode()
{
	return LastNode;
}

void CDeque::Enqueue_Front(int _data)
{
	CDequeNode* newNode = new CDequeNode;
	newNode->setData(_data);

	if (IsEmpty()) {
		firstNode = newNode;
		LastNode = newNode;
	}
	else {
		newNode->setNextNode(firstNode);
		firstNode = newNode;
	}
}

void CDeque::Enqueue_Back(int _data)
{
	CDequeNode* newNode = new CDequeNode;
	newNode->setData(_data);

	if (IsEmpty()) {
		firstNode = newNode;
		LastNode = newNode;
	}
	else {
		LastNode->setNextNode(newNode);
		LastNode = newNode;
	}
}

bool CDeque::Dequeue_Front(int& data)
{
	if (IsEmpty()) {
		return false;
	}

	data = firstNode->getData();

	CDequeNode* tempNode = firstNode;
	firstNode = firstNode->getNextNode();
	delete tempNode;

	return true;
}

bool CDeque::Dequeue_Back(int& data)
{
	if (IsEmpty()) {
		return false;
	}

	if (firstNode == LastNode) {
		data = firstNode->getData();
		delete firstNode;
		firstNode = nullptr;
		LastNode = nullptr;
		return true;
	}

	CDequeNode* tempNode = firstNode;
	while (tempNode->getNextNode() != LastNode) {
		tempNode = tempNode->getNextNode();
	}

	data = LastNode->getData();

	tempNode->setNextNode(nullptr);

	delete LastNode;

	LastNode = tempNode;

	return true;
}

int CDeque::PeekFront(int& data)
{
	if (IsEmpty()) {
		return false;
	}

	data = firstNode->getData();;
	return true;
}

int CDeque::PeekBack(int& data)
{
	if (IsEmpty()) {
		return false;
	}

	data = LastNode->getData();;
	return true;
}

bool CDeque::IsEmpty()
{
	return (firstNode == nullptr);
}

void CDeque::DisplayArray(CPosition pos)
{

	CDequeNode* tempNode = firstNode;

	int row = 2;
	int col = 13;

	CPosition::GotoXY({ pos.x, pos.y});
	wcout << L"↓ Your Deque ↓";

	CPosition::GotoXY({ pos.x, pos.y + 2 });
	wcout << L"First Node →";

	while (tempNode != nullptr) {
		CPosition::GotoXY({ pos.x + col, pos.y + row});
		wcout << tempNode->getData() <<  ((tempNode->getNextNode() != nullptr) ? L" →" : L"");
		col += to_string(tempNode->getData()).size() + 3;

		tempNode = tempNode->getNextNode();

		if (col >= 40) {
			row+= 2;
			col = 0;
		}
	}

}
