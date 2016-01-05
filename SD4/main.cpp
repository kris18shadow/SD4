#include <iostream>
#include <string>

int main()
{
	char treeOne[1028];
	char treeTwo[1028];

	//std::string treeOne, treeTwo;

	std::cout << "Enter first tree: ";
	std::cin.getline(treeOne, 1027, '\n');

	std::cout << "Enter second tree: ";
	std::cin.getline(treeTwo, 1027, '\n');

	//test:
	std::cout << treeOne << std::endl;
	std::cout << treeTwo << std::endl;

	return 0;
}