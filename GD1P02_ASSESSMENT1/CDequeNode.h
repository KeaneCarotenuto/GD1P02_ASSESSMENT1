#pragma once
#include <cmath>

class CDequeNode
{
private:
	int data;
	CDequeNode* nextNode;

public:
	CDequeNode();
	void setData(int iData);
	int getData() const;
	void setNextNode(CDequeNode* nextNode);
	CDequeNode* getNextNode() const;
};

