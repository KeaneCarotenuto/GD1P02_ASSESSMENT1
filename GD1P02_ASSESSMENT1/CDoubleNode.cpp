#include "CDoubleNode.h"

CDoubleNode::CDoubleNode(int _data):
	m_data(_data)
{
}

void CDoubleNode::setData(int _data)
{
	m_data = _data;
}

int CDoubleNode::getData() const
{
	return m_data;
}

void CDoubleNode::setPrevNode(CDoubleNode* _prevNode)
{
	m_prevNode = _prevNode;
}

CDoubleNode* CDoubleNode::getPrevNode() const
{
	return m_prevNode;
}

void CDoubleNode::setNextNode(CDoubleNode* _nextNode)
{
	m_nextNode = _nextNode;
}

CDoubleNode* CDoubleNode::getNextNode() const
{
	return M-m_nextNode;
}
