#include<bits/stdc++.h>
using namespace std;

void DFS(int node, vector<vector<int>>&adj, vector<bool>& visited, stack<int>&s) {
	visited[node]=true;
	for(auto i:adj[node]) {
		if(!visited[i]) {
			DFS(i, adj, visited, s);
		}
	}
	s.push(node);
}

vector<int>TopologicalSort(int v, vector<vector<int>>&adj) {
	stack<int>s;
	vector<bool>visited(v, false);
	for(int i=0; i<v; i++) {
		if(!visited[i]) {
			DFS(i, adj, visited, s);
		}
	}
	vector<int>ans;
	while(!s.empty()) {
		ans.push_back(s.top());
		s.pop();
	}
	return ans;
}

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
	vector<vector<int>>adj(v);
	for(int i=0; i<e; i++) {
		cout<<"Enter the starting node and the ending node: ";
		cin>>x>>y;
		adj[node[x]].push_back(node[y]);
	}
	vector<int>ans = TopologicalSort(v, adj);
	for(auto i: ans) {
		cout<<inverse_node[i]<<" ";
	}
	return 0;
}