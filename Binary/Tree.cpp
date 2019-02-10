#include "stdafx.h"
#include "Tree.h"
#include "Node.h"
#include <vector>
#include <cmath>
#include <iostream>
using namespace std;


//constructor
Tree::Tree()
{
	this->root = NULL;
}


//destructor
Tree::~Tree()
{
	delete this->root;
}


Node * Tree::get_root()
{
	return root;
}


//insert value in BST
void Tree::insert(int v, Node * tree)
{
	if (root == NULL) { //tree is empty
		root = new Node;
		root->key = v;
	}

	else if (v < tree->key) {
		if (tree->left != NULL)	//search place to insert in left subtree
			insert(v, tree->left);
		else {
			tree->left = new Node; //initialize child Node
			tree->left->key = v; //set key value
		}
	}

	else if (v >= tree->key) {
		if (tree->right != NULL) //search place to insert in right subtree
			insert(v, tree->right);
		else {
			tree->right = new Node; //initialize child Node
			tree->right->key = v; //set key value
		}
	}
}


//find min value in a BST
Node * Tree::find_min(Node *tree) {
	Node *min = tree;
	while (tree->left != NULL) { //min value = the leftmost node
		min = tree->left;
		tree = tree->left;
	}
	return min;
}


//delete node from BST
void Tree::delete_node(Node * parent, Node * node, bool left)
{
	if (node->left == NULL && node->right == NULL) { //node has no children
		if (left)
			parent->left = NULL;
		else
			parent->right = NULL;
		delete node;
	}

	else if (node->left == NULL && node->right != NULL) { //node has only left child
		if (left)
			parent->left = node->right;
		else
			parent->right = node->right;
		node->right = NULL;
		delete node;
	}

	else if (node->left != NULL && node->right == NULL) { //node has only right child
		if (left)
			parent->left = node->left;
		else
			parent->right = node->left;
		node->left = NULL;
		delete node;
	}
	
	else if (node->left != NULL && node->right != NULL) {	//node has both children
		int min = find_min(node->right)->key;
		remove(min, node); //delete node with minimal value
		node->key = min; //assign min value from right subtree to node
	}
}


void Tree::delete_root()
{
	Node *tmp = new Node;
	tmp->left = root; //hang root as left subtree of tmp
	delete_node(tmp, root, true);
	root = tmp->left; //set root to left child of tmp
	tmp->left = NULL;
	delete tmp;
}


//remove value from BST
void Tree::remove(int v, Node * tree)
{
	if (tree == NULL) {
		cout << "The tree doesn't contain value " << v;
		return; //BST doesn't contain value v
	}

	else if (root->key == v) //root has value to remove
		delete_root();

	else if (v < tree->key) { //search left subtree
		if ((tree->left != NULL) && (v == tree->left->key))
			delete_node(tree, tree->left, true);
		else
			return remove(v, tree->left);
	}

	else if (v >= tree->key) { //search right subtree
		if ((tree->right != NULL) && (v == tree->right->key))
			delete_node(tree, tree->right, false);
		else
			return remove(v, tree->right);
	}



}

//inorder traversal of the BST
string Tree::inorder(Node * n, string & out)
{
	if (n == NULL)
		return out;
	
	else
		inorder(n->left, out);
		out = out + to_string(n->key) + " ";
		inorder(n->right, out);
		return out;
}


//preorder traversal of the BST
string Tree::preorder(Node * n, string & out)
{
	if (n == NULL)
		return out;

	else
		out = out + to_string(n->key) + " ";
		preorder(n->left, out);
		preorder(n->right, out);
		return out;
}


//postorder traversal of the BST
string Tree::postorder(Node * n, string & out)
{
	if (n == NULL)
		return out;

	else
		postorder(n->left, out);
		postorder(n->right, out);
		out = out + to_string(n->key) + " ";
		return out;
}


//count nodes in a BST
int Tree::count_nodes(Node * n)
{
	int count = 0;
	if (n == NULL)
		return count;
	else {
		count++; //count current node
		count = count + count_nodes(n->left); //count nodes in the left subtree
		count = count + count_nodes(n->right); //count nodes in the right subtree
	}
	return count;
}


//count edges in a BST
int Tree::count_edges(Node * n)
{
	if (root != NULL)
		return count_nodes(n) - 1;
	return 0;
}


//get height of a BST
int Tree::height(Node * n)
{
	int count = 0;
	if (n == NULL)
		return count;
	else {
		count++;
		int left_height = height(n->left);
		int right_height = height(n->right);
		left_height < right_height ? count += right_height : count += left_height; //add max{left_height, right_height}
		return count;
	}
}

//method for printing BST
void Tree::print_line(vector<Node*> this_line, int h)
{
	if (h == 1)
		return;

	int spaces = pow(2, h - 1) - 1; //number of spaces to print at the beggining of line
	int between_spaces = pow(2, h) - 1; //number of spaces between nodes on a line
	
	for (int i = 0; i < spaces; i++)
		cout << " ";

	vector<Node*> next_line;
	for (int i = 0; i < this_line.size(); i++) {
		if (this_line[i] != NULL) {
			if (this_line[i]->left == NULL) { //node has no left child
				cout << " ";
				next_line.push_back(NULL);
			}
			else {
				cout << this_line[i]->left->key; //print child value and save in next_line list
				next_line.push_back(this_line[i]->left);
			}

			for (int i = 0; i < between_spaces; i++) //space between nodes
				cout << " ";

			if (this_line[i]->right == NULL) { //node has no right child
				cout << " ";
				next_line.push_back(NULL);
			}
			else {
				cout << this_line[i]->right->key; //print child value and save in next_line list
				next_line.push_back(this_line[i]->right);
			}
		}
		else {
			next_line.push_back(NULL); //NULL node has no children
			next_line.push_back(NULL); 
			for (int i = 0; i < between_spaces + 2; i++)
				cout << " ";
		}
		
		for (int i = 0; i < between_spaces; i++) //space between nodes
			cout << " ";
	}
	cout << endl << endl;
	this_line = next_line; //reassign next line to current line
	print_line(this_line, h - 1);
}


//print BST
void Tree::print(Node * tree)
{
	int h = height(root);
	int spaces = pow(2, h) - 1;

	if (tree == root) {
		for (int i = 0; i < spaces; i++)
			cout << " ";
		cout << root->key << endl << endl;
		vector<Node*> this_line = {root};
		print_line(this_line, h);
	}

}


