#pragma once
#include <iostream>

struct Node
{
	int value = 0;
	Node* nextNode=nullptr;
};

class LinkedList
{
private:
	Node* head = nullptr;

public:
	LinkedList();
	~LinkedList();
	void Insert(int val);
	void Insert(Node* currentNode, int val);
	void PrintList() const;
};

