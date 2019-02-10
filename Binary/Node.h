#pragma once

class Node
{
private:
	int key; //key value
	Node *left; //left subtree
	Node *right; //right subtree

	friend class Tree; //class Tree can access private members of class Node

public:
	Node();
	//Node(int key);
	~Node();
};

