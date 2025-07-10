#include<bits/stdc++.h>
using namespace std;
/*
Directed Weighted Graph
A->B = 1
B->C = 4
B->D = 5
C->D = 3
D->C = 8
E->A = 4
E->B = 6
E->D = 2
E->E = 7
*/

int main() {
	int v, e, weight;
	char n, x, y;
	cout<<"Enter the number of vertex and edges: ";
	cin>>v>>e;
	cout<<"Enter the names of the nodes (e.g.: A B C...): ";
	vector<vector<int>>AdjMat(v, vector<int>(v,0));
	map<char, int>m;
	for(int i=0; i<v; i++) {
		cin>>n;
		m[n]=i;
	}
	for(int i=0; i<e; i++) {
			cout<<"Enter the starting node and ending node and the weight: ";
			cin>>x>>y>>weight;
			AdjMat[m[x]][m[y]]=weight;
	}
	for(int i=0; i<v; i++) {
		for(int j=0; j<v; j++) {
			cout<<AdjMat[i][j]<<" ";
		}
		cout<<endl;
	}
	return 0;
}