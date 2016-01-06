#include <iostream>
#include "Tree.h"
#include "AdditionalFunctions.h"

int main()
{
	Tree A, B;
	
	std::cout << "Enter First tree: ";
	readTreeFromInput(A);
	std::cout << "Enter Second tree: ";
	readTreeFromInput(B);

	if (checkIsomorphism(A, B))
		std::cout << "YES\n";
	else
		std::cout << "NO\n";		

	return 0;
}

