#pragma once
#include <iostream>
#include "Tree.h"

void readTreeFromInput(Tree A)
{
	char tree[1028];
	std::cin.getline(tree, 1027, '\n');

	size_t size = strlen(tree);

	for (size_t i = 0; i < size; i++)
	{
		if (tree[i] >= '0' && tree[i] <= '9')
		{
			//if digit is >9
			int num = 0;
			while (isdigit(tree[i]))
			{
				num = 10 * num + tree[i] - '0';
				i++;
			}
			if (num > 0)
			{
				//add number
				A.addElements(num);
				i--;
			}

		}
		if (tree[i] == '{')
		{
			A.moveDown();
		}
		if (tree[i] == '}')
		{
			A.moveUp();
		}
	}
}

void readTreesFromInput(Tree A, Tree B)
{
	char treeOne[1028];
	char treeTwo[1028];

	std::cout << "Enter first tree: ";
	std::cin.getline(treeOne, 1027, '\n');

	std::cout << "Enter second tree: ";
	std::cin.getline(treeTwo, 1027, '\n');


	size_t oneSize = strlen(treeOne);
	size_t twoSize = strlen(treeTwo);

	for (size_t i = 0; i < oneSize; i++)
	{
		if (treeOne[i] >= '0' && treeOne[i] <= '9')
		{
			//if digit is >9
			int num = 0;
			while (isdigit(treeOne[i]))
			{
				num = 10 * num + treeOne[i] - '0';
				i++;
			}
			if (num > 0)
			{
				//add number
				A.addElements(num);
				i--;
			}

		}
		if (treeOne[i] == '{')
		{
			A.moveDown();
		}
		if (treeOne[i] == '}')
		{
			A.moveUp();
		}
	}

	for (size_t i = 0; i < twoSize; i++)
	{
		if (treeTwo[i] >= '0' && treeTwo[i] <= '9')
		{
			//if digit is >9
			int num = 0;
			while (isdigit(treeTwo[i]))
			{
				num = 10 * num + treeTwo[i] - '0';
				i++;
			}
			if (num > 0)
			{
				//add number
				B.addElements(num);
				i--;
			}

		}
		if (treeOne[i] == '{')
		{
			B.moveDown();
		}
		if (treeOne[i] == '}')
		{
			B.moveUp();
		}
	}
}

bool checkIsomorphism(Tree A, Tree B)
{
	if (A.getRoot() == NULL && B.getRoot() == NULL)
	{
		//std::cout << "YES\n";
		return true;
	}

	A.begin(); B.begin();
	while (true)
	{
		if (A.getCurrent()->numOfChildren != B.getCurrent()->numOfChildren)
		{
			//std::cout << "NO\n";
			return false;
		}

		if (A.getCurrent()->numOfChildren == 0 && B.getCurrent()->numOfChildren == 0)
		{
			//std::cout << "YES\n";
			return true;
		}

		for (size_t i = 0; i < A.getCurrent()->numOfChildren; i++)
		{
			int match = 0;
			for (size_t j = 0; j < B.getCurrent()->numOfChildren; j++)
			{
				if (A.getCurrent()->children[i]->numOfChildren == B.getCurrent()->children[j]->numOfChildren)
					match++;
			}
			if (match == 0)
			{
				//std::cout << "NO\n";
				return false;
			}
		}

		A.moveDown(); B.moveDown();
	}
}
