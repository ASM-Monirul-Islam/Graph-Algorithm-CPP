#include<bits/stdc++.h>
using namespace std;

class node {
	public:
	int data;
	node *right, *left;
	node(int value){
		data = value;
		left = right = nullptr;
	}
};

node *binaryTree(){
	int x;
	cin>>x;
	if(x== -1) {
		return nullptr;
	}
	node *temp = new node(x);
	cout<<"Enter the left child of "<<temp->data<<": ";
	temp->left = binaryTree();
	cout<<"Enter the right child of "<<temp->data<<": ";
	temp->right = binaryTree();
	return temp;
}

void preOrder(node *root){
	if(root == nullptr){
		return;
	}
	cout<<root->data<<" ";
	preOrder(root->left);
	preOrder(root->right);
}

int main() {
	cout<<"Enter the root node: ";
	node *root = binaryTree();
	preOrder(root);
	return 0;
}