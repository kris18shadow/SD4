#include <iostream>
#include "Tree.h"
#include "AdditionalFunctions.h"

int main()
{
	Tree A, B;
	
	std::cout << "Enter First tree: ";
	writeToTreeFromInput(A);
	std::cout << "Enter Second tree: ";
	writeToTreeFromInput(B);

	if (checkIsomorphism(A.getRoot(), B.getRoot()))
		std::cout << "YES\n";
	else
		std::cout << "NO\n";		

	return 0;
}