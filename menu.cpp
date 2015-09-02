#include "menu.h"
#include <iostream>

using namespace std;

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
	cout << "Choose the option to be performed: " << endl;
	cin >> choice;
	return choice;
}
