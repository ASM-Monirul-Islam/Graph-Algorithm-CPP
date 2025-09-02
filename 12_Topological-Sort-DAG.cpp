// TOPOLOGICAL SORT

// Topological sorting for a DAG (Directed Acyclic Graph) is 
// a linear ordering of vertices such that for every directed 
// edge U->V, the vertex U comes before V

// A->B
// A->C
// C->D
// B->D

// Topological sort: A->B->C->D
// Topological sort: A->C->B->D

#include<bits/stdc++.h>
using namespace std;

void DFS(int node, stack<int>&s, vector<vector<int>>& adj, vector<bool>& visited) {
	visited[node]=true;
	for(auto i:adj[node]) {
		if(!visited[i]) {
			DFS(i, s, adj, visited);
		}
	}
	s.push(node);
}

vector<int>Topo_sort(int v, vector<vector<int>>& adj) {
	stack<int>s;
	vector<bool>visited(v, false);
	vector<int>ans;
	for(int i=0; i<v; i++) {
		if(!visited[i]) {
			DFS(i, s, adj, visited);
		}
	}
	while(!s.empty()) {
		ans.push_back(s.top());
		s.pop();
	}
	return ans;
}

int main() {
	int v, e;
	char x, y, n;
	unordered_map<char, int>node;
	unordered_map<int, char>inverseNode;
	cout<<"Enter the number of vertices and edges: ";
	cin>>v>>e;
	cout<<"Enter the name of the vertices: ";
	for(int i=0; i<v; i++) {
		cin>>n;
		node[n]=i;
		inverseNode[i]=n;
	}
	vector<vector<int>>adj(v);

	cout<<"Enter the edges: (A -> B): "<<endl;
	for(int i=0; i<e; i++) {
		cin>>x>>y;
		adj[node[x]].push_back(node[y]);
	}
	vector<int>ans = Topo_sort(v, adj);
	cout<<"Topological Sort: ";
	for(auto i: ans) {
		cout<<inverseNode[i];
		if(i<ans.size()-1) {
			cout<<"->";
		}
	}
	return 0;
}