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
	void print(bool showData) const;
};

Node::Node()
{
	parent = NULL;
	numOfChildren = 0;
	data = 0;
}

void Node::addChild(Node &child)
{
	//children.resize(numOfChildren + 1);
	//children.begin();//
	children.push_back(&child);
	child.parent = this;
	numOfChildren++;
}

void Node::setParent(Node parent)
{
	this->parent = &parent;
}

void Node::print(bool showData) const
{
	if(showData)
		std::cout << data << std::endl;

	for (size_t i = 0; i < numOfChildren; i++)
	{
		std::cout << children[i] << " ";
	}

	for (size_t i = 0; i < numOfChildren; i++)
	{
		children[i]->print(false);
		std::cout << std::endl;
	}
}

class Tree
{
private:
	Node* root;
	void delTree(Node & root);
	Node* current;

public:
	Tree();
	~Tree();

	bool isEmpty() const;

	Node* getCurrent() const;

	Node* getRoot() const;
	void addElements(int num);
	void moveDown();
	void moveUp();
	void begin();
	void print() const;
};

void Tree::delTree(Node & root)
{
	for (int i = 0; i < root.numOfChildren; i++)
	{
		delTree(*root.children[i]);
		delete root.children[i];
	}

	delete &root;
}

Tree::Tree()
{
	root = NULL;
	current = root;
}

Tree::~Tree()
{
	//delTree(root);
}

bool Tree::isEmpty() const
{
	return root == NULL;
}

Node* Tree::getCurrent() const
{
	return current;
}

Node* Tree::getRoot() const
{
	return root;
}

void Tree::addElements(int num)
{
	Node * newNode = new Node;

	newNode->data = num;

	if (root == NULL)
	{
		root = newNode;
		current = root;
	}
	else
	{
		current->addChild(*newNode);
	}
}

void Tree::moveDown()
{
	if(current != NULL)
		if (current->numOfChildren > 0)
			current = current->children[current->numOfChildren - 1];
}

void Tree::moveUp()
{
	if (current->parent != NULL)
		current = current->parent;
}

void Tree::begin()
{
	this->current = root;
}

void Tree::print() const
{
	if (!isEmpty())
	{
		//print
	}
	else
	{
		std::cout << "Tree is empty!\n";
	}
}