#include <iostream>
#include "Tree.h"
#include "AdditionalFunctions.h"

int main()
{
	Tree A, B;
	
	std::cout << "Enter First tree: ";
	A = readTreeFromInput();
	std::cout << "Enter Second tree: ";
	B = readTreeFromInput();

	if (checkIsomorphism(A.getRoot(), B.getRoot()))
		std::cout << "YES\n";
	else
		std::cout << "NO\n";		

	return 0;
}