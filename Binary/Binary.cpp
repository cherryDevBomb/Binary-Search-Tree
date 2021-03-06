// Binary.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Tree.h"
#include <cassert>
#include <iostream>


void menu() {
	std::cout << "+--------------------------------------------------+" << endl;
	std::cout << "| 1. Insert value | 2. Delete value                |" << endl;
	std::cout << "| 3. Preorder | 4. Inorder | 5. Postorder          |" << endl;
	std::cout << "| 6. Count nodes | 7. Count edges | 8. Get height  |" << endl;
	std::cout << "| q.EXIT                                           |" << endl;
	std::cout << "+--------------------------------------------------+" << endl << endl;
}


int main()
{
	Tree *bst = new Tree;

	char option;
	while (true) {
		if (bst->get_root() == NULL) {	//insert initial values
			string typed;
			while (true) {
				system("cls");
				std::cout << "Your tree is empty." << endl << endl;
				if (bst->get_root() != NULL)
					bst->print(bst->get_root());
				std::cout << "Type a value to insert or 'q' to finish inserting: ";
				std::cin >> typed;
				if (typed == "q")
					break;
				else {
					int v = stoi(typed);
					bst->insert(v, bst->get_root());
				}
			}
		}
		else {
			system("cls");
			menu();
			bst->print(bst->get_root());
			std::cout << "Choose option: ";
			std::cin >> option;
			std::cin.ignore();

			if (option == 'q')
				break;
			else if (option == '1') {
				int v;
				std::cout << "Insert value : ";
				std::cin >> v;
				bst->insert(v, bst->get_root());
			}
			else if (option == '2') {
				int v;
				std::cout << "Type value to delete: ";
				std::cin >> v;
				bst->remove(v, bst->get_root());
				std::cout << endl;
			}
			else if (option == '3') {
				string pre = "";
				std::cout << "Preorder traversal of tree is: " << bst->preorder(bst->get_root(), pre) << endl;
				cout << endl;
				system("pause");
			}				
			else if (option == '4') {
				string in = "";
				std::cout << "Inorder traversal of tree is: " << bst->inorder(bst->get_root(), in) << endl;
				cout << endl;
				system("pause");
			}
			else if (option == '5') {
				string post = "";
				std::cout << "Postorder traversal of tree is: " << bst->postorder(bst->get_root(), post) << endl;
				cout << endl;
				system("pause");
			}
			else if (option == '6') {
				std::cout << "Tree has " << bst->count_nodes(bst->get_root()) << " nodes" << endl << endl;
				cout << endl;
				system("pause");
			}
			else if (option == '7') {
				std::cout << "Tree has " << bst->count_edges(bst->get_root()) << " edges" << endl << endl;
				cout << endl;
				system("pause");
			}
			else if (option == '8') {
				std::cout << "Tree height is " << bst->height(bst->get_root()) << endl << endl;
				cout << endl;
				system("pause");
			}
			else {
				std::cout << "ERROR. Try again!" << endl;
				system("pause");
				continue;
			}
		}
	}

    return 0;
}

