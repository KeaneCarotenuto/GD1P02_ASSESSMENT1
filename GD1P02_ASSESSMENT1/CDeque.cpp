#include "CDeque.h"

CDeque::CDeque() :
	firstNode(nullptr),
	LastNode(nullptr)
{
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
		cout << "Stack is Empty" << endl;
		data = 0;
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
		cout << "Stack is Empty" << endl;
		data = 0;
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
		cout << "Stack is Empty" << endl;
		data = 0;
		return false;
	}

	data = firstNode->getData();;
	return true;
}

int CDeque::PeekBack(int& data)
{
	if (IsEmpty()) {
		cout << "Stack is Empty" << endl;
		data = 0;
		return false;
	}

	data = LastNode->getData();;
	return true;
}

bool CDeque::IsEmpty()
{
	return (firstNode == nullptr);
}
