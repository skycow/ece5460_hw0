//Skyler Cowley
//A01209720
//ECE 5460 - hw0

#include <cstddef>
#include <iostream>
#include <fstream>


class node{
	int data;
	int height;
	int balance;
	node* left;
	node* right;
	node* parent;
public: 
	node(int);
	void deleteTree();
	void nodeInsert(node*);
	void setData(int);
	int getData();
	void printTree(int);
	void setBalance(int);
	int getBalance();
	void rotate();
	int balanceTree();
	void search(int);
	void search(int, int);
	void traversal(char);
	bool deleteNode(int);
	int startCopyRight();
	int copyLeft();
	void startDeleteRight();
	void deleteLeft();
	bool checkNull();

};

//this sets the private data member of a 
//node
void node::setData(int value){
	data = value;
}

//this sets the private balance member of a 
//node
void node::setBalance(int value){
	balance = value;
}

//this function returns the private data member
//of a node
int node::getData(){
	return data;
}

//this function calculates the balance factor
//for a requested node
int node::getBalance(){
	int left, right;
	//count left
	if(this->left ==  NULL){
		left = 0;
	}else{
		left = this->left->height;
	}
	//count right
	if(this->right ==  NULL){
		right = 0;
	}else{
		right = this->right->height;
	}
	//return balance factor
	return (left-right);
}

//this is a default constructor that takes an int
//value and sets everything else to null
node::node(int value){
	data =  value;
	height = -1;
	left = NULL;
	right = NULL;
	parent = NULL;
}

//this function deletes the entire avl tree starting
//from the farthest left leaf node and working it's 
//way up to the root
void node::deleteTree(){

//checks if leaf node
	if(this->left == NULL && this->right == NULL){
		return;
	}
	//checks for paths on the left side and deletes them
	//recursively on the return path up
	else if(this->left != NULL){
		//progresses further down the left path
		this->left->deleteTree();
		//deletes the left side as it is returning 
		//up the tree
		delete this->left;
		this->left = NULL;
	}
	//deletes any right side paths
	else{
		//progresses down the right side
		this->right->deleteTree();
		//deletes the right side on the return path
		delete this->right;
		this->right = NULL;

	}
}

//this function inserts a single node into an avl tree
void node::nodeInsert(node* newNode){
	//checs which side of the tree to place the new node
	if(this->data >= newNode->data){
		//if the current node is a leaf node, add the new 
		//node to the end of the tree
		if(this->left == NULL){
			this->left = newNode;
			newNode->parent = this;
			newNode->height = (this->height+1);
			return;

		}else{
			//progress further down the tree if end is not 
			//yet found
			this->left->nodeInsert(newNode);
			return;
		}
	}else{
		//add the new node to the end of a leaf node
		if(this->right == NULL){
			this->right = newNode;
			newNode->parent = this;
			newNode->height = (this->height+1);

			return;

		}else{
			//progress further down the tree if end is not
			//yet found
			this->right->nodeInsert(newNode);
			return;
		}
	}
}

//this prints a sideways visual representation of the tree
//used mostly for testing purposes
void node::printTree(int count){
	if(this->left == NULL && this->right == NULL){
		for( int i =0; i < count; i++){
			std::cout << "   ";
		}
		std::cout << data << std::endl;
		return;
	}

	if(this->left != NULL){
		this->left->printTree(count+1);
		
	}

	for( int i =0; i < count; i++){
			std::cout << "   ";
		}
	std::cout << data << std::endl;

	if(this->right != NULL){
		this->right->printTree(count+1);
		
	}

	return;
}

//this function checks the balance factor for each 
//node in the avl tree and calls rotate if necessary
int node::balanceTree(){
	int right, left;
	//if at a leaf node the node is balanced and has 
	//a height of 1
	if(this->left == NULL && this->right == NULL){
		this->balance = 0;
		this->height = 1;
		return 1;
	}

	//counts height of left subtree
	if(this->left != NULL){
		left = this->left->balanceTree();
	}else{
		left = 0;
	}

	//counts height of right subtree
	if(this->right != NULL){
		right = this->right->balanceTree();
	}else{
		right = 0;
	}

	//calculates balance and rotates if necessary. Also
	//stores the balance value in the node
	this->balance = (left - right);
	if(this->balance < -1 || this->balance > 1){
		this->rotate();
		//store the height of the highest child subtree
		if(left >= right){
			this->height = (left);
			return (left);
		}else{
			this->height = (right);
			return (right);
		}

	}else{
		//stores the hight and returns up the tree
		if(left >= right){
			this->height = (left + 1);
			return (left+1);
		}else{
			this->height = (right + 1);
			return (right+1);
		}
	}
}

//this function does the rotations when the tree 
//has a balance factor greater than 2
void node::rotate() {
	//if left side is heavy
	if (this->balance == 2) {
		//if left side of left side is heavy
		if (this->left->balance >= 0) {
			//rotate right once
			//create temp nodes
			node* node1;
			node* node2;
			node1 = new node(0);
			node2 = new node(0);

			//keep track of the rotating nodes
			node1 = this;
			node2 = this->left;
			//swap the children
			node1->left = node2->left;
			node2->left = node2->right;
			node2->right = node1->right;
			node1->right = node2;
			//swap the values
			int swap;
			swap = node1->data;
			node1->data = node2->data;
			node2->data = swap;		
		}
		//if left side is right side heavy
		else if(this->left->balance == -1) {
			//rotate left then right
			//create temp nodes
			node* node3;
			node* node4;
			node3 = new node(0);
			node4 = new node(0);
			//keep track of rotating nodes
			node3 = this->left;
			node4 = this->left->right;
			//rotate children
			node3->right = node4->right;
			node4->right = node4->left;
			node4->left = node3->left;
			node3->left = node4;
			//swap values
			int swap;
			swap = node3->data;
			node3->data = node4->data;
			node4->data = swap;
			//second rotation 
			node* node1;
			node* node2;
			node1 = new node(0);
			node2 = new node(0);
			//store new rotating values
			node1 = this;
			node2 = this->left;
			//swap children
			node1->left = node2->left;
			node2->left = node2->right;
			node2->right = node1->right;
			node1->right = node2;
			//swap data values
			swap = node1->data;
			node1->data = node2->data;
			node2->data = swap;	
		}
		else {
			//error
			std::cout << "We have a problem";
		}
	}
	//if right side is heavy
	else if (this->balance == -2) {
		//if the right side of the right side is heavy
		if (this->right->balance <= 0) {
			//rotate left once
			//create temp nodes
			node* node1;
			node* node2;
			node1 = new node(0);
			node2 = new node(0);
			//keep track of rotating nodes
			node1 = this;
			node2 = this->right;
			//swap children
			node1->right = node2->right;
			node2->right = node2->left;
			node2->left = node1->left;
			node1->left = node2;
			//swap data values
			int swap;
			swap = node1->data;
			node1->data = node2->data;
			node2->data = swap;	
		}
		//if left side of right side is heavy
		else if (this->right->balance == 1) {
			//rotate right then left
			//create temp nodes
			node* node1;
			node* node2;
			node1 = new node(0);
			node2 = new node(0);
			//keep track of rotating nodes
			node1 = this->right;
			node2 = this->right->left;
			//swap children
			node1->left = node2->left;
			node2->left = node2->right;
			node2->right = node1->right;
			node1->right = node2;
			//swap data values
			int swap;
			swap = node1->data;
			node1->data = node2->data;
			node2->data = swap;	
			//second rotation
			//creating temp values
			node* node3;
			node* node4;
			node3 = new node(0);
			node4 = new node(0);
			//keeping track of rotating nodes
			node3 = this;
			node4 = this->right;
			//swap children
			node3->right = node4->right;
			node4->right = node4->left;
			node4->left = node3->left;
			node3->left = node4;
			//swap data values
			swap = node3->data;
			node3->data = node4->data;
			node4->data = swap;
		}
		else {
			//error
			std::cout << "We have a negative problem";
		}
	}
	else {
		//error
		std::cout << "We have a big problem";
	}
}

//this function searches for a node and prints out the height of 
//the node
void node::search(int input){
	if(this->data == input){
		std::cout << input <<" is at height " << this->height;
		std::cout << " in the tree." << std::endl;
		std::ofstream fout;
		fout.open("cowley-A01209720.txt", std::ios::app);
		fout << input <<" is at height " << this->height;
		fout << " in the tree." << std::endl;
		fout.close();
		return;
	}
	//continues down the tree looking for the value
	if(input < this->data){
		//checks if it is at a leaf node
		if(this->left == NULL){
			std::cout << input << " was not found in the tree." << std::endl;
			std::ofstream fout;
			fout.open("cowley-A01209720.txt", std::ios::app);
			fout << input <<" was not found in the tree. " << std::endl;
			fout.close();
			return;
		}else{
			//continues down the left side if value is bigger than current
			this->left->search(input);
		}
	} else if(input > this->data){
		//checks if it is at a leaf node
		if(this->right == NULL){
			std::cout << input << " was not found in the tree." << std::endl;
			std::ofstream fout;
			fout.open("cowley-A01209720.txt", std::ios::app);
			fout << input <<" was not found in the tree. " << std::endl;
			fout.close();
			return;
		}else{
			//continues down the right side if value is bigger than current
			this->right->search(input);
		}
	} else {
		//error
		std::cout << "We have a problem searching at the end";
	}
	return;
}

//this function traverses the tree and prints out the values
//in the order entered by the user
void node::traversal(char order){
	//pre-order traversal
	if(order == 'a'){
		std::cout << this->data << "  ";
		std::ofstream fout;
		fout.open("cowley-A01209720.txt", std::ios::app);
		fout << this->data << "  ";
		fout.close();
		
	}
	//continues down left side of tree
	if(this->left !=NULL){
		this->left->traversal(order);
	}
	//in order traversal
	if(order == 'b'){
		std::cout << this->data << "  ";	
		std::ofstream fout;
		fout.open("cowley-A01209720.txt", std::ios::app);
		fout << this->data << "  ";
		fout.close();		
	}
	//continues down right side of tree
	if(this->right !=NULL){
		this->right->traversal(order);
	}
	//post order traversal
	if(order == 'c'){
		std::cout << this->data << "  ";
		std::ofstream fout;
		fout.open("cowley-A01209720.txt", std::ios::app);
		fout << this->data << "  ";
		fout.close();
	}
	return;	
}

//this function deletes a single node specified 
//by the user
bool node::deleteNode(int value){
	//checks if node is found
	if(value == this->data){
		//delete this node
		//save children if only on one side
		if(this->left == NULL && this->right != NULL){
			this->data = this->right->data;
			delete this->right;
			this->right = NULL;
		}
		else if(this->right == NULL && this->left != NULL){
			this->data = this->left->data;
			delete this->left;
			this->left = NULL;
		}else{
			//moves a leaf node into place of the node to delete
			this->data = this->startCopyRight();
			//deletes the node
			this->startDeleteRight();
		}
		return true;	
	}
	//continues down the tree 
	if(value < this->data){
		//check for end of branch
		if(this->left != NULL){
			//looks ahead to delete a leaf node if the value is found on a leaf
			if(this->left->data == value && this->left->left == NULL && this->left->right == NULL){
				delete this->left;
				this->left = NULL;
				return true;
			}
			//continue down left side of tree
			return this->left->deleteNode(value);
		}else{
			//node not found in tree
			std::cout << "Node cannot be found. Deletion cannot be performed" << std::endl;
			std::ofstream fout;
			fout.open("cowley-A01209720.txt", std::ios::app);
			fout << "Node cannot be found. Deletion cannot be performed" << std::endl;
			fout.close();
			return false;
		}
	}else if (value > this->data){
		//check for end of branch
		if(this->right !=NULL){
			//looks ahead to delete a leaf node if the value is found on a leaf
			if(this->right->data == value && this->right->left == NULL && this->right->right == NULL){
				delete this->right;
				this->right = NULL;
				return true;
			}
			//continue down right side of tree
			return this->right->deleteNode(value);
		}else{
			//node not found in tree
			std::cout << "Node cannot be found. Deletion cannot be performed" << std::endl;
			std::ofstream fout;
			fout.open("cowley-A01209720.txt", std::ios::app);
			fout << "Node cannot be found. Deletion cannot be performed" << std::endl;
			fout.close();
			return false;
		}
	}else{
		//error
		std::cout << "we have a problem";
		return false;
	}
}

//this function starts looking to swap the node to be 
//deleted with another node
int node::startCopyRight(){
	if(this->right->left == NULL){
		return this->right->data;
	}else{
		return this->right->copyLeft();
	}
}
//this function continues the search and swaps the data
int node::copyLeft(){
	if(this->left->left == NULL){
		return this->left->data;
	}else{
		return this->left->copyLeft();
	}
}

//this function starts the search to delete the node
void node::startDeleteRight(){
	if(this->right->left == NULL && this->right->right == NULL){
		delete this->right;
		this->right = NULL;
	}else if(this->right->left == NULL){
		//copy children
		node* node1;
		node1 = new node(0);

		node1 = this->right->right;
		delete this->right;
		this->right = node1;
	}else{
		this->right->deleteLeft();
	}
	return;
}
//this function deletes the node
void node::deleteLeft(){
	if(this->left->left == NULL && this->right->right == NULL){
		delete this->left;
		this->left = NULL;
	}else if(this->left->left == NULL){
		//copy children
		node* node2;
		node2 = new node(0);

		node2 = this->left->right;
		delete this->left;
		this->left = node2;
	}else{
		this->left->deleteLeft();
	}
}

//this function checks if a node is a leaf
bool node::checkNull(){
	if(this->left == NULL && this->right == NULL){
		return true;
	}else{
		return false;
	}
}
