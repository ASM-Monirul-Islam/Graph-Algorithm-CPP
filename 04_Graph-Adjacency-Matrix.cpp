#include<bits/stdc++.h>
using namespace std;

//Directed Weighted Graph


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

/*
Enter the number of vertex and edges: 5 9
Enter the names of the nodes (e.g.: A B C...): A B C D E
Enter the starting node and ending node and the weight: A B 1
Enter the starting node and ending node and the weight: B C 4
Enter the starting node and ending node and the weight: B D 5
Enter the starting node and ending node and the weight: C D 3
Enter the starting node and ending node and the weight: D C 8
Enter the starting node and ending node and the weight: E A 4
Enter the starting node and ending node and the weight: E B 6
Enter the starting node and ending node and the weight: E D 2
Enter the starting node and ending node and the weight: E E 7
0 1 0 0 0 
0 0 4 5 0
0 0 0 3 0
0 0 8 0 0
4 6 0 2 7
*/