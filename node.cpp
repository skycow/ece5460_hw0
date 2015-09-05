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
	void printTree(int);
	void setBalance(int);
	//void createTree();
	void rotate();
	int balanceTree();

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
			newNode->parent = this;
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
			newNode->parent = this;
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

void node::printTree(int count){
	if(this->left == NULL && this->right == NULL){
		for( int i =0; i <= count; i++){
			std::cout << "   ";
		}
		std::cout << data << std::endl;
		return;
	}

	if(this->left != NULL){
		this->left->printTree(count+1);
		
	}

	for( int i =0; i <= this->height; i++){
			std::cout << "   ";
		}
	std::cout << data << std::endl;

	if(this->right != NULL){
		this->right->printTree(count+1);
		
	}

	return;
}

int node::balanceTree(){

	int right, left;

	if(this->left == NULL && this->right == NULL){
		this->balance = 0;
		this->height = 1;
		return 1;
	}

	//counts left subtree
	if(this->left != NULL){
		left = this->left->balanceTree();
	}else{
		left = 0;
	}

	//counts right subtree
	if(this->right != NULL){
		right = this->right->balanceTree();
	}else{
		right = 0;
	}

	//calculates balance
	this->balance = (left - right);

	if(this->balance < -1 || this->balance > 1){
		this->rotate();
		std::cout<<"after call"<<this->data<<std::endl;
	}else{
		if(left >= right){
			this->height = (left + 1);
			return (left+1);
		}else{
			this->height = (right + 1);
			return (right+1);
		}
	}
}

void node::rotate() {
	if (this->balance == 2) {
		if (this->left->balance == 1) {
			//rotate right once
			std::cout<<"this begins at:"<<this->data<<std::endl;
			node* node1;
			node* node2;
			node1 = new node(0);
			node2 = new node(0);

			node1 = this;
			std::cout<<"node1"<<node1->data<<std::endl;
			node2 = this->left;
			std::cout<<"node2"<<node2->data<<std::endl;
			
			//new
			node1->left = node2->left;
			node2->left = node2->right;
			node2->right = node1->right;
			node1->right = node2;
			int swap;
			swap = node1->data;
			node1->data = node2->data;
			node2->data = swap;	
			


//			if(node2->right == NULL){
//				node1->left = NULL;
//			}else{
//				node1->left = node2->right;
//			}
//			node2->right = node1;
//			if(node1->parent == NULL){
//				this = node2;
//				node2->parent = NULL;
//			} else {
//				node2->parent = node1->parent;
//			}
//			node1->parent = node2;

			std::cout<<"this ends at:"<<this->data<<std::endl;
			std::cout << "Rotated right" << std::endl;	
		}
		else if(this->left->balance == -1) {
			//rotate left then right
		}
		else {
			std::cout << "We have a problem";
		}
	}
	else if (this->balance == -2) {
		if (this->right->balance == -1) {
			//rotate left once
		}
		else if (this->right->balance == 1) {
			//rotate right then left
		}
		else {
			std::cout << "We have a negative problem";
		}
	}
	else {
		std::cout << "We have a big problem";
	}
}
