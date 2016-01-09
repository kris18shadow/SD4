#pragma once

#include <iostream>
#include <vector>

struct Node
{
	int data;
	Node* parent;
	std::vector<Node*> children;
	int numOfChildren;

	Node();
	void addChild(Node &child);
	void setParent(Node parent);
};


class Tree
{
private:
	Node* root;
	Node* current;

	void delTree(Node* root);
	void copyTree(Node* root);

public:
	Tree();
	Tree(const Tree& other);
	~Tree();

	Tree& operator=(const Tree& other);

	bool isEmpty() const;

	Node* getCurrent() const;
	Node* getRoot() const;

	void addElements(int num);
	void moveDown();
	void moveUp();
	void begin();
};