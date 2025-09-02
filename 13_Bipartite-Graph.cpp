// Bipartite graph is a graph in which the vertices can be divided into two disjoint sets, 
// such that no two vertices within the same set are adjacent. In other words, it is a graph
// in which every edge connects a vertex of one set to a vertex of other set.

#include<bits/stdc++.h>
using namespace std;

bool Bipartite(int v, vector<vector<int>>& adj) {
	vector<int>color(v, -1);
	queue<int>q;
	for(int i=0; i<v; i++) {
		if(color[i]== -1) {
			q.push(i);
			color[i] = 0;
			while(!q.empty()) {
				int node = q.front();
				q.pop();
				for(auto i: adj[node]) {
					if(color[i]== -1) {
						color[i] = (color[node]+1)%2;
						q.push(i);
					} else  {
						if(color[node]==color[i]) {
							return false;
						}
					}
				}
			}
		}
	}
	return true;
}


int main() {
	int v, e;
	char n, x, y;
	unordered_map<char, int>node;
	cout<<"Enter the vertex and edges number: ";
	cin>>v>>e;
	cout<<"Enter the name of the nodes: (e.g.: A, B, C, ...): ";
	for(int i=0; i<v; i++) {
		cin>>n;
		node[n]=i;
	}
	vector<vector<int>>adj(v);
	for(int i=0; i<e; i++) {
		cout<<"Enter the starting node and the ending node: ";
		cin>>x>>y;
		adj[node[x]].push_back(node[y]);
		adj[node[y]].push_back(node[x]);
	}
	bool isBipartite = Bipartite(v, adj);
	if(isBipartite) {
		cout<<"The graph is a Bipartite graph"<<endl;
	} else {
		cout<<"The graph is not a Bipartite graph"<<endl;
	}

	return 0;
}