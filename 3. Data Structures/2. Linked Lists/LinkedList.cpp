#include "LinkedList.h"

LinkedList::LinkedList()
{

}

LinkedList::~LinkedList()
{

}

void LinkedList::Insert(int val)
{
	if (head == nullptr)
	{
		head = new Node();
		head->value = val;
	}
	else
	{
		Insert(head, val);
	}
}

void LinkedList::Insert(Node* currentNode, int val)
{
	while (currentNode->nextNode != nullptr)
	{
		currentNode = currentNode->nextNode;
	}

	currentNode-> nextNode = new Node();
	currentNode-> nextNode -> value = val;
}

void LinkedList::PrintList() const
{
	Node* currentNode = head;

	while (currentNode != nullptr)
	{
		std::cout << currentNode->value << "--";
		currentNode = currentNode->nextNode;
	}
}