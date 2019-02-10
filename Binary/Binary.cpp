// Binary.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Tree.h"
#include <cassert>
#include <iostream>
using namespace std;


void tests() {
	Tree *test = new Tree;
	test->insert(4, test->get_root());
	test->insert(2, test->get_root());
	test->insert(1, test->get_root());
	test->insert(3, test->get_root());
	test->insert(6, test->get_root());
	test->insert(5, test->get_root());
	test->insert(7, test->get_root());

	//test traversals
	string in = "";
	assert(test->inorder(test->get_root(), in) == "1 2 3 4 5 6 7 ");
	in = "";
	assert(test->preorder(test->get_root(), in) == "4 2 1 3 6 5 7 ");
	in = "";
	assert(test->postorder(test->get_root(), in) == "1 3 2 5 7 6 4 ");

	//test counting functions
	assert(test->count_nodes(test->get_root()) == 7);
	assert(test->count_edges(test->get_root()) == 6);
	assert(test->height(test->get_root()) == 3);

	//test insert and remove functions
	test->insert(8, test->get_root());
	in = "";
	assert(test->inorder(test->get_root(), in) == "1 2 3 4 5 6 7 8 ");
	test->remove(4, test->get_root());
	in = "";
	assert(test->inorder(test->get_root(), in) == "1 2 3 5 6 7 8 ");

	delete test;
}


void menu() {
	cout << "+-------------------+" << endl;
	cout << "| 1. Draw tree      |" << endl;
	cout << "| 2. Insert value   |" << endl;
	cout << "| 3. Delete value   |" << endl;
	cout << "| 4. Traverse tree  |" << endl;
	cout << "| 5. Count nodes    |" << endl;
	cout << "| 6. Count edges    |" << endl;
	cout << "| 7. Get height     |" << endl;
	cout << "| 0. Exit           |" << endl;
	cout << "+-------------------+" << endl;
}


int main()
{
	tests();

	Tree *bst = new Tree; //create tree
	int values[17] = { 25,19,36,65,3,9,30,20,27,7,10,40,75,2,42,80,70 };
	for (int i = 0; i < 17; i++)
		bst->insert(values[i], bst->get_root()); //initialize tree values

	menu(); //print menu

	while (true) {
		int option;
		cout << "Choose option: ";
		cin >> option;

		if (option == 1) {
			if (bst->get_root() == NULL)
				continue;
			bst->print(bst->get_root());
		}
		else if (option == 2) {
			int v;
			cout << "Type value to insert: ";
			cin >> v;
			bst->insert(v, bst->get_root());
			cout << endl;
		}
		else if (option == 3) {
			int v;
			cout << "Type value to delete: ";
			cin >> v;
			bst->remove(v, bst->get_root());
			cout << endl;
		}
		else if (option == 4) {
			string in = "";
			string pre = "";
			string post = "";
			cout << "Inorder traversal of tree is: " << bst->inorder(bst->get_root(), in) << endl;
			cout << "Preorder traversal of tree is: " << bst->preorder(bst->get_root(), pre) << endl;
			cout << "Postorder traversal of tree is: " << bst->postorder(bst->get_root(), post) << endl;
			cout << endl;
		}
		else if (option == 5)
			cout << "Tree has " << bst->count_nodes(bst->get_root()) << " nodes" << endl << endl;
		else if (option == 6)
			cout << "Tree has " << bst->count_edges(bst->get_root()) << " edges" << endl << endl;
		else if (option == 7)
			cout << "Tree height = " << bst->height(bst->get_root()) << endl << endl;
		else if (option == 0) {
			delete bst;
			break;
		}
			
	}

    return 0;
}

