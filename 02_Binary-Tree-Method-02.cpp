#include<bits/stdc++.h>
using namespace std;

class node{
	public:
	int data;
	node *right, *left;
	node (int value){
		data = value;
		left=right=nullptr;
	}
};

void preOrder(node *temp){
	if(temp == nullptr) return;
	cout<<temp->data<<" ";
	preOrder(temp->left);
	preOrder(temp->right);
}

int main() {
	int x, first, second;
	cout<<"Enter the root node: ";
	cin>>x;
	queue<node *>q;
	node *root = new node(x);
	q.push(root);
	while(!q.empty()){
		node *temp = q.front();
		q.pop();
		cout<<"Enter the left child of "<<temp->data<<": ";
		cin>>first;
		if(first != -1) {
			temp->left =  new node(first);
			q.push(temp->left);
		}
		cout<<"Enter the right child of "<<temp->data<<": ";
		cin>>second;
		if(second!= -1){
			temp->right = new node(second);
			q.push(temp->right);
		}
	}
	preOrder(root);
	return 0;
}