#pragma once
#include <iostream>
#include "Tree.h"

bool checkInput(char* string, size_t size)
{
	//counters for "{" and "}":
	size_t countOpenBraceOne = 0;
	size_t countCloseBraceOne = 0;
	//counters for "(" and ")":
	size_t countOpenBraceTwo = 0;
	size_t countCloseBraceTwo = 0;

	for (size_t i = 0; i < size; i++)
	{
		if (string[i] == '{')
			countOpenBraceOne++;
		else
			if (string[i] == '}')
				countCloseBraceOne++;
			else
				if (string[i] == '(')
					countOpenBraceTwo++;
				else
					if (string[i] == ')')
						countCloseBraceTwo++;
					else
						if ((string[i] < '0' || string[i] > '9') && string[i] != ' ')
							return false;
	}

	if (countOpenBraceOne != countCloseBraceOne)
		return false;
	if (countOpenBraceTwo != countCloseBraceTwo)
		return false;

	return true;
}

Tree readTreeFromInput()
{
	Tree A;
	char tree[1028];
	std::cin.getline(tree, 1027, '\n');

	size_t size = strlen(tree);
	if (!checkInput(tree, size))
	{
		std::cerr << "Wrong Input!\n";
		return A;
	}

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
				//add number to tree
				A.addElements(num);
				i--;
			}

		}
		if (tree[i] == '{')
		{
			//move one level down if possible
			A.moveDown();
		}
		if (tree[i] == '}')
		{
			//move one level up if possible
			A.moveUp();
		}
	}

	return A;
}

bool checkIsomorphism(Node* A, Node* B)
{
	if (A == NULL && B == NULL)
	{
		return true;
	}

	while (true)
	{
		for (size_t i = 0; i < A->numOfChildren; i++)
		{
			int match = 0;
			bool check = true;

			for (size_t j = 0; j < B->numOfChildren; j++)
			{
				if (A->children[i]->numOfChildren == B->children[j]->numOfChildren)
				{
					if (!checkIsomorphism(A->children[i], B->children[j]))
					{
						check = false;
					}
					else
					{
						check = true;
						match++;
						break;
					}
				}
			}

			if (check == false || match == 0)
				return false;

		}

		return true;
	}
}