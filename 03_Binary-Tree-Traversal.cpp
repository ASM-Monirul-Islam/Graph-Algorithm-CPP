#include<bits/stdc++.h>
using namespace std;

class node{
	public:
	int data;
	node *left, *right;
	node(int value){
		data=value;
		left=right=nullptr;
	}
};

void PreOrder(node *temp) {
	if(temp == nullptr) return;
	cout<<temp->data<<" ";
	PreOrder(temp->left);
	PreOrder(temp->right);
}

void InOrder(node *temp) {
	if(temp == nullptr) return;
	InOrder(temp->left);
	cout<<temp->data<<" ";
	InOrder(temp->right);
}

void PostOrder(node *temp) {
	if(temp == nullptr) return;
	PostOrder(temp->left);
	PostOrder(temp->right);
	cout<<temp->data<<" ";
}

node *Binary_Tree(){
	int x;
	cin>>x;
	if(x== -1) return nullptr;
	node *temp = new node(x);
	cout<<"Enter the left child of "<<temp->data<<": ";
	temp->left = Binary_Tree();
	cout<<"Enter the right child of "<<temp->data<<": ";
	temp->right=Binary_Tree();
	return temp;
}

int main() {
	cout<<"Enter the root node: ";
	node *root = Binary_Tree();
	cout<<"Pre Order Traversal: ";
	PreOrder(root); //Pre Order Traversal: 1 2 3 4 5 6 7 8 9 10
	cout<<"In Order Traversal: ";
	InOrder(root); //In Order Traversal: 4 3 5 2 6 1 7 9 8 10
	cout<<"Post Order Traversal: ";
	PostOrder(root); //Post Order Traversal: 4 5 3 6 2 9 10 8 7 1
	return 0;
}

/* Input:
				1
			2		7
		3		6		8
	4		5		9		10
	
*/