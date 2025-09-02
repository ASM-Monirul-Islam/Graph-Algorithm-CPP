#include<bits/stdc++.h>
using namespace std;

bool hasCycle(int node, int parent, vector<vector<int>>&adj, vector<bool>& visited) {
	visited[node]=true;
	for(auto i: adj[node]) {
		if(parent == i) {
			continue;
		}  if(visited[i]) {
			return true;
		}  if(hasCycle(i, node, adj, visited)) {
			return true;
		}
	}
	return false;
}


int main() {
	int v, e;
	char n, x, y;
	unordered_map<char, int>node;
	unordered_map<int, char>inverseNode;
	cout<<"Enter the number of vertices and edges: ";
	cin>>v>>e;
	vector<vector<int>>adj(v);
	cout<<"Enter the name of the nodes: ";
	for(int i=0; i<v; i++) {
		cin>>n;
		node[n]=i;
		inverseNode[i]=n;
	}

	cout<<"Node1 Node2: "<<endl;
	for(int i=0; i<e; i++) {
		cin>>x>>y;
		adj[node[x]].push_back(node[y]);
		adj[node[y]].push_back(node[x]);
	}
	vector<bool>visited(v, false);
	bool cycle = false;
	for(int i=0; i<v; i++) {
		if(!visited[i]) {
			if(hasCycle(i, -1, adj, visited)) {
				cycle = true;
				break;
			}
		}
	}
	if(cycle) {
		cout<<"Graph has a cycle"<<endl;
	} else {
		cout<<"Graph has no cycle"<<endl;
	}
	return 0;
}