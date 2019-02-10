#pragma once
#include "Node.h"
#include <string>
#include <vector>
using namespace std;

class Tree
{
public:
	Tree();
	~Tree();

	Node * get_root();
	
	void insert(int v, Node *tree); //insert value in BST
	Node * find_min(Node *tree); //find minimal value in a BST
	void delete_node(Node *parent, Node *node, bool left); //delete node 
	void delete_root(); //delete root
	void remove(int v, Node *tree); //remove value from BST

	//tree traversals
	string inorder(Node *n, string &out); 
	string preorder(Node *n, string &out);
	string postorder(Node *n, string &out);

	int count_nodes(Node * n); 
	int count_edges(Node * n);
	int height(Node * n);

	//functions to display tree in 2D
	void print_line(vector<Node*> this_line, int h); 
	void print(Node * tree);

private:
	Node * root;
};

