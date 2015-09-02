#include <iostream>
#include <fstream>
#include "menu.h"
#include "node.cpp"
#include <cstddef>

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
					root.deleteTree();
				}else{

					cout << "Enter name of file to create tree from: ";
					string filename;
					cin >> filename;
					
					ifstream inputFile (filename.c_str());
					if(inputFile.is_open() && inputFile.good()){
						cout << "Creating tree..." << endl;
						while( getline(inputFile, num) ){
							cout << num << endl;
						}
						cout << "Tree created!" << endl << endl;
					}else{
						cout << "Error opening file." << endl; 
					}
					inputFile.close();
				}
				break;
			}
			case 2:
				break;
			case 3:
				break;
			case 4:
				break;
			case 8:
				done = true;
				break;
		}
	}

	return 0;
}