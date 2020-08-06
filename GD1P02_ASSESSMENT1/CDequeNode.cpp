#include "CDequeNode.h"

CDequeNode::CDequeNode() :
	data(-INFINITY),
	nextNode(nullptr)
{
}

void CDequeNode::setData(int iData)
{
	data = iData;
}

int CDequeNode::getData() const
{
	return data;
}

void CDequeNode::setNextNode(CDequeNode* _nextNode)
{
	nextNode = _nextNode;
}

CDequeNode* CDequeNode::getNextNode() const
{
	return nextNode;
}