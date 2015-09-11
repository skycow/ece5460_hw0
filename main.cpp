#include <iostream>
#include <fstream>
#include "menu.h"
#include "node.cpp"
#include <cstddef>
#include <stdlib.h>

using namespace std;

//This is the main function for an avl tree. This function will print the menu
//of choices to the user and will take the choices from the user.
int main(){

	
	int choice;
	bool done = false;
	//ifstream inputFile ("Input.txt");
	ofstream outputFile;
	string num;
	node* root = NULL;

	while(!done){
		choice = menu();
	
		switch(choice){
			//Create Tree
			case 1:{
				//check if tree exists
				if(root != NULL){
					root->deleteTree();
					root = NULL;
				}
					//get filename from user
					cout << "Enter name of file to create tree from: ";
					string filename;
					cin >> filename;
					
					ifstream inputFile (filename.c_str());
					if(inputFile.is_open() && inputFile.good()){
						cout << "Creating tree..." << endl;
						


						while( getline(inputFile, num) ){

							int conv = atoi ( num.c_str() );

							node* temp;
							temp = new node(conv); 

							if(root == NULL){
								root = temp;
								root->setBalance(0);
							}else{
								root->nodeInsert(temp);
							}
							
							root->balanceTree();
							
						}

						cout << "Create Tree: ";
						root->traversal('a');
						cout << endl;

					}else{
						cout << "Error opening file." << endl; 
					}
					inputFile.close();
				
				break;
			}
			//Insertion of a node
			case 2:
				//get input from the user
				cout << "Please enter value to insert:";
				int userInsert;
				cin >> userInsert;
				node* temp;
				temp = new node(userInsert); 
				
				//if no tree exists, start a new tree
				if(root == NULL){
					root = temp;
					root->setBalance(0);

				}else{
					cout<<"calling Insert"<<endl;
					root->nodeInsert(temp);
				}
				
				root->balanceTree();
				
				cout << "Node inserted: " << endl;
				
				root->traversal('a');
				cout << endl;

				break;
			//Deletion of a node	
			case 3:
				cout << "Please enter value to delete:";
				int userDelete;
				cin >> userDelete;
				if(root == NULL){
					cout << "Node cannot be deleted. Empty Tree!" << endl;
				}else if(root->getData() == userDelete && root->checkNull()){
					delete root;
					root = NULL;

					cout << "Node deleted: " << endl;
					root->traversal('a');
					cout << endl;

				}else{
					root->deleteNode(userDelete);
					
					//cout << "Node deleted: " << endl;
					//root->traversal('a');
				}
				if(root != NULL){
					root->balanceTree();
				}
				break;
			//Search for a node
			case 4:
				cout << "Please enter value to search for:";
				int userSearch;
				cin >> userSearch;
				root->search(userSearch);
				break;
			//Tree traversals
			case 5:
				cout << "Traversal orders:" << endl;
				cout << "a. Pre-order traversal" << endl;
				cout << "b. In-order traversal" << endl;
				cout << "c. Post-order traversal" << endl;
				cout << "Please enter type of traversal: ";
				char order;
				cin >> order;
				root->traversal(order);
				cout << endl;
				break;
			//Delete the entire tree
			case 6: 
				if(root != NULL){
					cout << "Deleting tree." << endl;
					root->deleteTree();
					root = NULL;
					cout << "Tree deleted." << endl;
				}else{
					cout << "No tree to delete." << endl;
				}
				break;
			//Check balance
			case 7:
				root->balanceTree();
				break;
			//Exit the program
			case 8:
				done = true;
				break;
			//Secret option to print a visual representation 
			//of the tree
			case 9:
				if(root != NULL){
				root->printTree(0);
				}
				break;
		}
	}

	return 0;
}
