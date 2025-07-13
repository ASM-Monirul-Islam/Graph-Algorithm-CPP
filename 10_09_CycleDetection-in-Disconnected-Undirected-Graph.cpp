#include<bits/stdc++.h>
using namespace std;

/*
				A			D -- E			E -- G
		       / \						     \  /
		      B   C						       H
*/

bool CycleCheck(int node, int parent, vector<vector<int>>& adj, vector<bool>& visited) {
	visited[node]=true;
	for(auto i: adj[node]){
		if(i==parent) continue;
		if(visited[i]) return true;
		if(CycleCheck(i, node, adj, visited)) return true;
	}
	return false;
}

int main() {
	int v, e;
	char n, x, y;
	unordered_map<char, int>node;
	unordered_map<int, char>inverse_node;
	cout<<"Enter the number of vertices and edges: ";
	cin>>v>>e;
	vector<vector<int>>adj(v);
	cout<<"Enter the name of the nodes: ";
	for(int i=0; i<v; i++) {
		cin>>n;
		node[n]=i;
		inverse_node[i]=n;
	}
	cout<<"Enter the starting node and the ending node: "<<endl;
	for(int i=0; i<e; i++) {
		cin>>x>>y;
		adj[node[x]].push_back(node[y]);
		adj[node[y]].push_back(node[x]);
	}
	vector<bool>visited(v, false);
	bool hasCycle = false;
	for(int i=0; i<v; i++) {
		if(!visited[i]) {
			if(CycleCheck(0, -1, adj, visited)) {
				hasCycle = true;
				break;
			}
		}
	}
	if(hasCycle) {
		cout<<"Cycle Found in the Graph!"<<endl;
	} else {
		cout<<"Cycle not Found!"<<endl;
	}
	return 0;
}

/*
Enter the number of vertices and edges: 8 6
Enter the name of the nodes: A B C D E F G H
Enter the starting node and the ending node: 
A B
A C
D E
F G
F H
G H
Cycle Found in the Graph!
*/