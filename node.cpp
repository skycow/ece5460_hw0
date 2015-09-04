#include <cstddef>
#include <iostream>

class node{
	int data;
	int height;
	int balance;
	node* left;
	node* right;
	node* parent;
public: 
	node();
	node(int);
	void deleteTree();
	void nodeInsert(node*);
	void setData(int);
	int getData();
	void printTree();
	void setBalance(int);
	//void createTree();

};

//node::node(){
//	//data =  -1;
//	height = -1;
//	left = NULL;
//	right = NULL;
//	parent = NULL;
//}

void node::setData(int value){
	data = value;
}

void node::setBalance(int value){
	balance = value;
}

int node::getData(){
	return data;
}

node::node(int value){
	data =  value;
	height = -1;
	left = NULL;
	right = NULL;
	parent = NULL;
}

void node::deleteTree(){


	if(this->left == NULL && this->right == NULL){
		
		return;
	}
	else if(this->left != NULL){
		this->left->deleteTree();
		delete this->left;
		this->left = NULL;
	}
	else{
		this->right->deleteTree();
		delete this->right;
		this->right = NULL;

	}
}

void node::nodeInsert(node* newNode){
	//if no tree exists
	//if(this == NULL){
	//	this = newNode;
	//	newNode->height = 0;
	//}

	if(this->data >= newNode->data){
		if(this->left == NULL){
			this->left = newNode;
			newNode->height = (this->height+1);
			//if(this->right == NULL){
			//	this->balance = 
			//}
			return;

		}else{
			this->left->nodeInsert(newNode);
			return;
		}
	}else{
		if(this->right == NULL){
			this->right = newNode;
			newNode->height = (this->height+1);

			//std::cout<<this->right->data;
			//std::cout<<newNode->data;

			return;

		}else{
			this->right->nodeInsert(newNode);
			return;
		}
	}
}

void node::printTree(){
	if(this->left == NULL && this->right == NULL){
		for( int i =0; i <= this->height; i++){
			std::cout << "   ";
		}
		std::cout << data << std::endl;
		return;
	}

	if(this->left != NULL){
		this->left->printTree();
		
	}

	for( int i =0; i <= this->height; i++){
			std::cout << "   ";
		}
	std::cout << data << std::endl;

	if(this->right != NULL){
		this->right->printTree();
		
	}

	return;
}

int node::balanceTree(){

	int right, left;

	if(this->left == NULL && this->right == NULL){
		this->balance = 0;
		return 1;
	}

	if(this->left != NULL){
		left = this->left->balanceTree();
	}else{
		left = 0;
	}

	if(this->right != NULL){
		right = this->right->balanceTree();
	}else{
		right = 0;
	}

	this->balance = (left - right);

	if(this->balance < -1 || this->balance >= 1){
		//need rotation
	}else{
		if(left >= right){
			return left;
		}else{
			return right;
		}
	}
}