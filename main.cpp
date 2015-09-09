#include <iostream>
#include <fstream>
#include "menu.h"
#include "node.cpp"
#include <cstddef>
#include <stdlib.h>

using namespace std;

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
			case 1:{
				//check if tree exists
				if(root != NULL){
					root->deleteTree();
					root = NULL;
				}

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

							//temp->setData(conv);

							if(root == NULL){
								root = temp;
								root->setBalance(0);
								//cout << "root";
							}else{
								root->nodeInsert(temp);
								//cout<<"test";
							}
							//cout << temp->getData();
							//delete temp;
							root->balanceTree();
						}
						//root->printTree(0);

						//cout << "Tree created!" << endl << endl;

						cout << "Create Tree: " << endl;
						root->traversal('a');

					}else{
						cout << "Error opening file." << endl; 
					}
					inputFile.close();
				
				break;
			}
			//Insertion
			case 2:
				cout << "Please enter value to insert:";
				int userInsert;
				cin >> userInsert;
				node* temp;
				temp = new node(userInsert); 
				if(root == NULL){
					root = temp;
					root->setBalance(0);

				}else{
					cout<<"calling Insert"<<endl;
					root->nodeInsert(temp);
				}
				//cout<<"calling print"<<endl;
				//root->printTree(0);
				//cout<<"calling balance"<<endl;
				root->balanceTree();
				//cout<<"calling print again"<<endl;
				//root->printTree(0);

				cout << "Node inserted: " << endl;
				root->traversal('a');

				break;
			//Deletion	
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

				}else{
					root->deleteNode(userDelete);
					
					//cout << "Node deleted: " << endl;
					//root->traversal('a');
				}
				if(root != NULL){
					root->balanceTree();
				}
				break;
			//Search
			case 4:
				cout << "Please enter value to search for:";
				int userSearch;
				cin >> userSearch;
				root->search(userSearch);
				break;
			case 5:
				cout << "Traversal orders:" << endl;
				cout << "a. Pre-order traversal" << endl;
				cout << "b. In-order traversal" << endl;
				cout << "c. Post-order traversal" << endl;
				cout << "Please enter type of traversal: ";
				char order;
				cin >> order;
				root->traversal(order);
				break;
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
			case 7:
				root->balanceTree();
				break;
			case 8:
				done = true;
				break;
			case 9:
				if(root != NULL){
				root->printTree(0);
				}
				break;
		}
	}

	return 0;
}
