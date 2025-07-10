#include<bits/stdc++.h>
using namespace std;
// Undirected Unweighted Graph - Adjacency List


int main() {
	int v, e;
	char n, x, y;
	map<char, int>node;
	map<int, char>inverse_node;
	cout<<"Enter the vertex and edges number: ";
	cin>>v>>e;
	cout<<"Enter the name of the nodes: (e.g.: A, B, C, ...): ";
	for(int i=0; i<v; i++) {
		cin>>n;
		node[n]=i;
		inverse_node[i]=n;
	}
	vector<vector<int>>AdjList(v);
	for(int i=0; i<e; i++) {
		cout<<"Enter the starting node and the ending node: ";
		cin>>x>>y;
		AdjList[node[x]].push_back(node[y]);
		AdjList[node[y]].push_back(node[x]);
	}
	for(int i=0; i<v; i++) {
		cout<<inverse_node[i]<<"-> ";
		for(int j=0; j<AdjList[i].size(); j++) {
			cout<<inverse_node[AdjList[i][j]]<<" ";
		}
		cout<<endl;
	}
	return 0;
}

/*
Enter the vertex and edges number: 5 6
Enter the name of the nodes: (e.g.: A, B, C, ...): A B C D E
Enter the starting node and the ending node: A B
Enter the starting node and the ending node: A C
Enter the starting node and the ending node: B D
Enter the starting node and the ending node: B C
Enter the starting node and the ending node: C E
Enter the starting node and the ending node: D E
A-> B C 
B-> A D C
C-> A B E
D-> B E
E-> C D
*/