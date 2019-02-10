#include "stdafx.h"
#include "Node.h"


Node::Node()
{
	this->left = NULL;
	this->right = NULL;
}


Node::~Node()
{
	delete this->left;
	delete this->right;
}
