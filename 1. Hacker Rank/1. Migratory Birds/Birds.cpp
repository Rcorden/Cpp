// Birds.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <vector>

int main()
{
	std::vector<int> birds = { 1,2,3,4,5,4,3,2,1,3,4 };
	std::vector<int> bucket = { 0,0,0,0,0 };
	int LargestNum = INT_MIN, largestNumPosition = 0;

	for (int i = 0; i < birds.size(); i++)
	{
		bucket[birds[i] - 1]++;
	}

	for (int i = 0; i < bucket.size(); i++)
	{
		if (bucket[i] > LargestNum)
		{
			LargestNum = bucket[i];
			largestNumPosition = i + 1;
		}
	}

	std::cout << largestNumPosition;
	return 0;
}

