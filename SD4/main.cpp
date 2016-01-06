#include <iostream>
#include "Tree.h"

int main()
{
	char treeOne[1028];
	char treeTwo[1028];

	Tree A, B;

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

	//test:
	std::cout << treeOne << std::endl;
	std::cout << treeTwo << std::endl;

	return 0;
}

