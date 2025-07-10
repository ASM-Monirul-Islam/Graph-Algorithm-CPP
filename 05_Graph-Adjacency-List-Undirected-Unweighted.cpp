#include<bits/stdc++.h>
using namespace std;
/* Undirected Unweighted Graph - Adjacency List
A-> B, E 
B-> A, C, E
C-> B, D
D-> C, E
E-> A, B, D
*/

int main() {
	int v, e;
	char n, x, y;
	map<char, int>node;
	map<int, char>inverse_node;
	cout<<"Enter the vertex and edges number: ";
	cin>>v>>e;
	cout<<"Enter the name of the nodes: (e.g.: A, B, C, ...)";
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