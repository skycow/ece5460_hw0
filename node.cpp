#include <cstddef>

class node{
	int data;
	int height;
	node* left;
	node* right;
	node* parent;
public: 
	node();
	node(int);
	deleteTree();
};

node::node(){
	data =  -1;
	height = -1;
	left = NULL;
	right = NULL;
	parent = NULL;
}

node::node(int value){
	data =  value;
	height = -1;
	left = NULL;
	right = NULL;
	parent = NULL;
}

void deleteTree(){
	if(this.left == NULL && this.right == NULL)

}