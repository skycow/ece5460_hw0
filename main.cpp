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
//
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
//							delete temp;

						}
						root->printTree();

						cout << "Tree created!" << endl << endl;
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
					root->nodeInsert(temp);
				}
				root->printTree();
				break;
			//Deletion	
			case 3:
				break;
			//Search
			case 4:
				cout << "Please enter value to insert:";
				int userSearch;
				cin >> userSearch;
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
				balanceTree
				break;
			case 8:
				done = true;
				break;
		}
	}

	return 0;
}