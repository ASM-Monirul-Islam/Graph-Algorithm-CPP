#include<bits/stdc++.h>
using namespace std;

bool DetectCycle(int node, int parent, vector<vector<int>>& adj, vector<bool>& visited) {
	visited[node]=true;
	for(auto i: adj[node]) {
		if(parent == i) {
			continue;
		}
		if(visited[i]) {
			return true;
		}
		if(DetectCycle(i, node, adj, visited)) return true;
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
	cout<<"Enter the starting node and ending node: "<<endl;
	for(int i=0; i<e; i++) {
		cin>>x>>y;
		adj[node[x]].push_back(node[y]);
		adj[node[y]].push_back(node[x]);
	}
	vector<bool>visited(v, false);
	bool ans = DetectCycle(0, -1, adj, visited);
	if(ans) {
		cout<<"Cycle Detected!"<<endl;
	} else {
		cout<<"No Cycle Found"<<endl;
	}
	return 0;
}