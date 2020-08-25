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

	//If empty then simply set first and last to new node. Else insert and direct propperly.
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

	//Same as above.
	if (IsEmpty()) {
		firstNode = newNode;
		LastNode = newNode;
	}
	else {
		//Order matters here.
		LastNode->setNextNode(newNode);
		LastNode = newNode;
	}
}

//Keeps track of first node, sets next node to first, then deletes original first node and returns data.
bool CDeque::Dequeue_Front(int& data)
{
	if (IsEmpty()) {
		return false;
	}

	data = firstNode->getData();

	//Checks if there is only one node, if so, clean up the while list.
	if (firstNode == LastNode) {
		delete firstNode;
		firstNode = nullptr;
		LastNode = nullptr;
	}
	else {
		CDequeNode* tempNode = firstNode;
		firstNode = firstNode->getNextNode();
		delete tempNode;
	}
	

	return true;
}

//This function could be the same as the above function, but reversed if I added a previous node pointer to each node, 
//but I guess this just demonstrates multiple ways of doing it, where every node is still only able to see the node ahead of it, and not behind it.
bool CDeque::Dequeue_Back(int& data)
{
	if (IsEmpty()) {
		return false;
	}

	//Checks if there is only one node, if so, clean up the while list.
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

//Returns data at front
int CDeque::PeekFront(int& data)
{
	if (IsEmpty()) {
		return false;
	}

	data = firstNode->getData();;
	return true;
}

//Returns data at back
int CDeque::PeekBack(int& data)
{
	if (IsEmpty()) {
		return false;
	}

	data = LastNode->getData();;
	return true;
}

//returns bool of if the deque is empty or not
bool CDeque::IsEmpty()
{
	return (firstNode == nullptr);
}

//Displays the list at a given coordinate in a grid style
void CDeque::DisplayArray(CPosition pos)
{

	CDequeNode* tempNode = firstNode;

	size_t row = 4;
	size_t col = 0;

	CPosition::GotoXY({ pos.x, pos.y});
	wcout << L"Your Deque:";

	CPosition::GotoXY({ pos.x, pos.y + 2 });
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), ((firstNode == nullptr) ? 0 : 10));
	wcout << L"↓ First Node";

	while (tempNode != nullptr) {
		CPosition::GotoXY({ pos.x + static_cast<int>(col), pos.y + static_cast<int>(row) });

		//Prints out the current node's data followed by an arrow
		if (tempNode != firstNode) SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		wcout << tempNode->getData() <<  ((tempNode->getNextNode() != nullptr) ? L" →" : L"");
		col += to_string(tempNode->getData()).size() + 3;

		tempNode = tempNode->getNextNode();

		//Manages grid position
		if (col >= 40) {
			row+= 2;
			col = 0;
		}
	}

}
