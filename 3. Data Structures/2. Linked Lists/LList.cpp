// LList.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "LinkedList.h"

int main()
{
	LinkedList list;

	for (int i = 0; i < 10; i++)
	{
		list.Insert(rand() % 252);
	}

	list.PrintList();

}

