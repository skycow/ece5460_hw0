#include <iostream>
#include <fstream>
#include "node.cpp"
#include <cstddef>
#include <stdlib.h>

using namespace std;

//prototype
int menu();

//This is the main function for an avl tree. This function will print the menu
//of choices to the user and will take the choices from the user.
int main(){

	
	int choice;
	bool done = false;
	ofstream fout("cowley-A01209720.txt");
	fout.close();
	fout.open("cowley-A01209720.txt");
	if(fout.is_open()){
	}else{
		cout << "There is a problem with the output file." << endl; 
	}
	string num;
	node* root = NULL;

	while(!done){
		choice = menu();
	
		switch(choice){
			//Create Tree
			case 1:{
				//get filename from user
				cout << "Enter name of file to create tree from: ";
				string filename;
				cin >> filename;
				
				ifstream inputFile (filename.c_str());
				if(inputFile.is_open() && inputFile.good()){

					//check if tree exists
					if(root != NULL){
						root->deleteTree();
						root = NULL;
					}

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
					fout << "Create Tree: ";
					fout.close();
					root->traversal('a');
					fout.open("cowley-A01209720.txt", ios::app);
					cout << endl;
					fout << endl;
					cout << "Check balance: " << root->getBalance() << endl;
					fout << "Check balance: " << root->getBalance() << endl;

				}else{
					cout << "Create Tree: Error opening file." << endl; 
					fout << "Create Tree: Error opening file." << endl; 
				}
				inputFile.close();
				
				break;
			}
			//Insertion of a node
			case 2:
				//get input from the user
				cout << "Please enter value to insert: ";
				int userInsert;
				cin >> userInsert;
				node* temp;
				temp = new node(userInsert); 
				
				//if no tree exists, start a new tree
				if(root == NULL){
					root = temp;
					root->setBalance(0);

				}else{
					root->nodeInsert(temp);
				}
				
				root->balanceTree();
				
				
				cout << "Node inserted: ";
				fout << "Node inserted: ";
				fout.close();
				root->traversal('a');
				fout.open("cowley-A01209720.txt", ios::app);
				cout << endl;
				fout << endl;
				cout << "Check balance: " << root->getBalance() << endl;
				fout << "Check balance: " << root->getBalance() << endl;

				break;
			//Deletion of a node	
			case 3:
				//get user input
				cout << "Please enter value to delete: ";
				int userDelete;
				bool success;
				cin >> userDelete;
				if(root == NULL){
					cout << "Deletion: Node cannot be deleted. Empty Tree!" << endl;
					fout << "Deletion: Node cannot be deleted. Empty Tree!" << endl;
					success = false;
				}else if(root->getData() == userDelete && root->checkNull()){
					//deletes the root if it is the only node in the tree
					delete root;
					root = NULL;
					success = false;

					cout << "Deletion: Root node deleted." << endl;
					fout << "Deletion: Root node deleted." << endl;
					cout << "Check balance: 0" << endl;
					fout << "Check balance: 0" << endl;

				}else{
					//searches tree and deletes node if found
					success = root->deleteNode(userDelete);
				}

				if(success){
						cout << "Deletion: ";
						fout << "Deletion: ";
						fout.close();
						root->traversal('a');
						fout.open("cowley-A01209720.txt", ios::app);
						cout << endl;
						fout << endl;
						root->balanceTree();
						cout << "Check balance: " << root->getBalance() << endl;
						fout << "Check balance: " << root->getBalance() << endl;
				}

				break;
			//Search for a node
			case 4:
				//get user input
				cout << "Please enter value to search for: ";
				int userSearch;
				cin >> userSearch;
				cout << "Search: ";
				fout << "Search: ";
				//checks for empty tree
				if(root == NULL){
					cout << "Node cannot be found. Empty Tree!" << endl;
					fout << "Node cannot be found. Empty Tree!" << endl;
				}else{
					fout.close();
					//making sure heights are updated
					root->balanceTree();
					//performing search
					root->search(userSearch);
					fout.open("cowley-A01209720.txt", ios::app);
				}
				break;
			//Tree traversals
			case 5:
				//get user input
				cout << "Traversal orders:" << endl;
				cout << "1. Pre-order traversal" << endl;
				cout << "2. In-order traversal" << endl;
				cout << "3. Post-order traversal" << endl;
				cout << "Please enter type of traversal: ";
				int orderIn;
				char order;
				cin >> orderIn;
				cout << endl;
				//convert from int to char
				if(orderIn == 1){
					order = 'a';
				}else if(orderIn == 2){
					order = 'b';
				}else if(orderIn == 3){
					order = 'c';
				}else{
					order = 'd';
				}
				if(order == 'd'){
				}else{
					//check for empty tree
					if(root == NULL){
						cout << "Traversal: Cannot traverse tree. Empty Tree!" << endl;
						fout << "Traversal: Cannot traverse tree. Empty Tree!" << endl;
					}else{

						if(order == 'a'){
							cout << "Traversal: Pre-Order: ";
							fout << "Traversal: Pre-Order: ";
						}else if(order == 'b'){
							cout << "Traversal: In-Order: ";
							fout << "Traversal: In-Order: ";
						}else{
							cout << "Traversal: Post-Order: ";
							fout << "Traversal: Post-Order: ";
						}

						fout.close();
						//traverse tree
						root->traversal(order);
						fout.open("cowley-A01209720.txt", ios::app);
						cout << endl;
						fout << endl;
					}
				}
				break;
			//Delete the entire tree
			case 6: 
				if(root != NULL){
					root->deleteTree();
					root = NULL;
					cout << "Tree deleted." << endl;
					fout << "Tree deleted." << endl;
				}else{
					cout << "No tree to delete." << endl;
					fout << "No tree to delete." << endl;
				}
				break;
			//Check balance
			case 7:
				if(root == NULL){
					cout << "Cannot balance tree. Empty Tree!" << endl;
					fout << "Cannot balance tree. Empty Tree!" << endl;
				}else{
					root->balanceTree();
					cout << "Check balance: " << root->getBalance() << endl;
					fout << "Check balance: " << root->getBalance() << endl;
				}
				break;
			//Exit the program
			case 8:
				done = true;
				fout << endl << endl;
				fout.close();
				break;
			//Secret option to print a visual representation 
			//of the tree
			case 9:
				if(root != NULL){
				root->printTree(0);
				}
				break;
		}
		cout << endl;
	}

	return 0;
}

int menu(){

	int choice;

	cout << "Menu options:" << endl;
	cout << "1. Create Tree" << endl;
	cout << "2. Insertion" << endl;
	cout << "3. Deletion" << endl;
	cout << "4. Search" << endl;
	cout << "5. Traversal" << endl;
	cout << "6. Delete Tree" << endl;
	cout << "7. Check Balance" << endl;
	cout << "8. Exit" << endl;
	cout << "Choose the option to be performed: " ;
	cin >> choice;
	cout << endl;
	return choice;
}
