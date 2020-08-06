#pragma once
class CDoubleNode
{
private:
	int m_data;
	CDoubleNode* m_prevNode;
	CDoubleNode* m_nextNode;
public:
	CDoubleNode(int _data);
	void setData(int _data);
	int getData() const;
	void setPrevNode(CDoubleNode* _prevNode);
	CDoubleNode* getPrevNode() const;
	void setNextNode(CDoubleNode* _nextNode);
	CDoubleNode* getNextNode() const;
};

