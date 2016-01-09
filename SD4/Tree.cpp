#include "Tree.h"

//////////////////////////
//Node member functions://
//////////////////////////
Node::Node()
{
	parent = NULL;
	numOfChildren = 0;
	data = 0;
}

void Node::addChild(Node &child)
{
	children.push_back(&child);
	child.parent = this;
	numOfChildren++;
}

void Node::setParent(Node parent)
{
	this->parent = &parent;
}

//////////////////////////
//Tree member functions://
//////////////////////////
void Tree::delTree(Node* root)
{
	std::vector<Node*> temp = root->children;
	delete root;

	for (size_t i = 0; i < temp.size(); i++)
		delTree(temp[i]);
}

void Tree::copyTree(Node* other)
{
	Node* temp = new Node;
	*temp = *other;
	this->current = temp;
	if (this->root == NULL)
		this->root = current;

	for (size_t i = 0; i < other->numOfChildren; i++)
	{
		Node* temp2 = new Node;
		*temp2 = *other->children[i];
		current->addChild(*temp2);
		temp2->parent = current;
		this->current = temp2;
		copyTree(temp2);
	}
}

Tree::Tree()
{
	root = NULL;
	current = root;
}

Tree::Tree(const Tree& other)
{
	begin();
	copyTree(other.getRoot());
}

Tree::~Tree()
{
	delTree(root);
}

Tree& Tree::operator=(const Tree& other)
{
	if (this != &other)
	{
		begin();
		copyTree(other.getRoot());
	}
	return *this;
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
	if (current != NULL)
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