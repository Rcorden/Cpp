#pragma once
#include <iostream>
#include <algorithm>
#include <string>

struct BinaryTreeNode
{
	int data = NULL;
	BinaryTreeNode* parent = nullptr;
	BinaryTreeNode* left = nullptr;
	BinaryTreeNode* right = nullptr;
};

class BinaryTreeSearch
{
private:
	BinaryTreeNode* root;

public:
	BinaryTreeSearch();
	~BinaryTreeSearch();
	void Display() const;
	void PrintLeaf(BinaryTreeNode* leaf) const;
	void Insert(int item);
	void Insert(int item, BinaryTreeNode* leaf);
	void Delete(int itemToDelete);
	void Delete(int itemToDelete, BinaryTreeNode* leaf);
	int nextHighest(int itemToSearch) const;
	int nextHighest(int itemToSearch, BinaryTreeNode* leaf, int CurrentHighest) const;
	BinaryTreeNode* nextHighestNode(BinaryTreeNode* leaf) const;
	BinaryTreeNode* getNode(int dataOfNodeToGet) const;
	BinaryTreeNode* getNode(int dataOfNodeToGet, BinaryTreeNode* leaf) const;
	void DeleteFullTree(BinaryTreeNode* leaf);
	void CheckIfInTree(int numToCheck);
	std::string CheckIfInTree(BinaryTreeNode* leaf, int numToCheck) const;
	void InvertBinaryTree(BinaryTreeNode* leaf);
	void InvertBinaryTree();
};

