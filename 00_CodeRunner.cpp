#include<bits/stdc++.h>
using namespace std;

int main() {
	char n;
	map<char, int>node;
	map<int, char>inverse_node;
	for(int i=0; i<5; i++) {
		cout<<"Enetr the nodes: ";
		cin>>n;
		node[n]=i;
		inverse_node[i]=n;
	}

	return 0;
}