#include "BinaryTreeSearch.h"


BinaryTreeSearch::BinaryTreeSearch()
{
	root = nullptr;
}

BinaryTreeSearch::~BinaryTreeSearch()
{
	DeleteFullTree(root);
}

void BinaryTreeSearch::DeleteFullTree(BinaryTreeNode* leaf)
{
	if (leaf != NULL)
	{
		DeleteFullTree(leaf->left);
		DeleteFullTree(leaf->right);
		delete leaf;
	}
}

void BinaryTreeSearch::Insert(int item)
{
	if (root == nullptr)
	{
		root = new BinaryTreeNode;
		root->data = item;
	}
	else
	{
		Insert(item, root);
	}
}

void BinaryTreeSearch::Insert(int item, BinaryTreeNode* leaf)
{
	if (item< leaf->data)
	{
		if (leaf->left != nullptr)
		{
			Insert(item, leaf->left);
		}
		else
		{
			leaf->left = new BinaryTreeNode;
			leaf->left->data = item;
			leaf->left->parent = leaf;
		}
	}
	else if (item >= leaf->data)
	{
		if (leaf->right != nullptr)
		{
			Insert(item, leaf->right);
		}
		else
		{
			leaf->right = new BinaryTreeNode;
			leaf->right->data = item;
			leaf->right->parent = leaf;
		}
	}
}

void BinaryTreeSearch::Delete(int itemToDelete)
{
	//TO DO 
}

void BinaryTreeSearch::Display() const
{
	PrintLeaf(root);
}

void BinaryTreeSearch::PrintLeaf(BinaryTreeNode* leaf) const
{
	if (leaf != nullptr)
	{
		PrintLeaf(leaf->left);
		std::cout << leaf->data << " ";
		PrintLeaf(leaf->right);
	}
}

void BinaryTreeSearch::InvertBinaryTree()
{
	if (root != nullptr)
	{
		InvertBinaryTree(root);
	}
}

void BinaryTreeSearch::InvertBinaryTree(BinaryTreeNode* leaf)
{
	if (leaf != nullptr)
	{
		InvertBinaryTree(leaf->left);
		InvertBinaryTree(leaf->right);

		BinaryTreeNode* temp = leaf->left;
		leaf->left = leaf->right;
		leaf->right = temp;
	}
}

int BinaryTreeSearch::nextHighest(int itemToSearch) const
{
	if (root->data == NULL)
	{
		return -1;
	}
	else
	{
		return nextHighest(itemToSearch, root, INT_MAX);
	}
}

int BinaryTreeSearch::nextHighest(int itemToSearch, BinaryTreeNode *leaf, int currentHighest) const
{
	if (leaf != nullptr)
	{
		if (itemToSearch < leaf->data)
		{
			currentHighest = std::min(nextHighest(itemToSearch, leaf->left, currentHighest), currentHighest);
		}
		else 
		{
			currentHighest = std::min(nextHighest(itemToSearch, leaf->right, currentHighest), currentHighest);
		}
		if ((leaf->data > itemToSearch && leaf->data < currentHighest))
		{
			return leaf->data;
		}
	}
	return currentHighest;
}


//Previous version
//int BinaryTreeSearch::nextHighest(int itemToSearch, BinaryTreeNode *leaf, int currentHighest)
//{
//	if (leaf != nullptr)
//	{
//		currentHighest = std::min(nextHighest(itemToSearch, leaf->left, currentHighest), currentHighest);
//
//		if ((leaf->data > itemToSearch && leaf->data < currentHighest))
//		{
//			return leaf->data;
//		}
//
//		currentHighest = std::min(nextHighest(itemToSearch, leaf->right, currentHighest), currentHighest);
//	}
//	return currentHighest;
//}]

BinaryTreeNode* BinaryTreeSearch::getNode(int dataOfNodeToGet) const
{
	if (root == nullptr)
	{
		std::cout << "Node Not Found \n";
		return nullptr;
	}
	else
	{
		return getNode(dataOfNodeToGet, root);
	}
}

BinaryTreeNode* BinaryTreeSearch::getNode(int dataOfNodeToGet, BinaryTreeNode* leaf) const
{
	while (leaf != nullptr)
	{
		if (leaf->data == dataOfNodeToGet)
		{
			std::cout << "Found Node \n";
			return leaf;
		}
		else if (dataOfNodeToGet < leaf->data)
		{
			return getNode(dataOfNodeToGet, leaf->left);
		}
		else
		{
			return getNode(dataOfNodeToGet, leaf->right);
		}
			
	}
	std::cout << "Node Not Found \n";
	return nullptr;
}

BinaryTreeNode* BinaryTreeSearch::nextHighestNode(BinaryTreeNode* leaf) const
{
	//TO DO
}

void BinaryTreeSearch::CheckIfInTree(int numToCheck)
{
	if (root == nullptr)
	{
		std::cout << "Empty Tree" << "\n";
	}
	else
	{
		std::cout << CheckIfInTree(root, numToCheck);
	}
}

std::string BinaryTreeSearch::CheckIfInTree(BinaryTreeNode* leaf, int numToCheck) const
{
	while (leaf != nullptr)
	{
		if (leaf->data == numToCheck)
		{
			return "Found \n";
		}
		else if (numToCheck < leaf->data)
		{
			return	CheckIfInTree(leaf->left, numToCheck);
		}
		else
		{
			return CheckIfInTree(leaf->right, numToCheck);
		}
	}
	return "Not Found \n";
}