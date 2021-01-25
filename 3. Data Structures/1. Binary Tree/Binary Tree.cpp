// Binary Tree.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include "BinaryTreeSearch.h"
#include <iostream>

int main()
{
	BinaryTreeSearch tree;
	BinaryTreeNode* test;

	tree.Insert(20);
	tree.Insert(9);
	tree.Insert(25);
	tree.Insert(5);
	tree.Insert(12);
	tree.Insert(11);
	tree.Insert(14);

	tree.Display();

	std::cout << "\n";
	std::cout << tree.nextHighest(9) << "\n";
	tree.CheckIfInTree(25);
	test = tree.getNode(12);
	test = tree.nextHighestNode(test);
	std::cout << test->data << "\n";

	//tree.InvertBinaryTree();
	//tree.Display();

}