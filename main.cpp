#include <iostream>
#include "menu.h"

int main(){

	
	int choice;
	bool done = false;

	while(!done){
		choice = menu();
	
		switch(choice){
			case 1:
				break;
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