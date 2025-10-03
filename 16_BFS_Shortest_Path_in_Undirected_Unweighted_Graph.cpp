#include<bits/stdc++.h>
using namespace std;

vector<int>BFS_shortest_distance(int start, vector<vector<int>>&adj) {
	int v = adj.size();
	vector<bool>visited(v, false);
	vector<int>distance(v, -1);
	queue<int>q;
	visited[start]=true;
	q.push(start);
	distance[start]=0;
	while(!q.empty()) {
		int node = q.front();
		q.pop();
		for(auto i:adj[node]) {
			if(!visited[i]) {
				distance[i]=distance[node]+1;
				q.push(i);
				visited[i]=true;
			}
		}
	}
	return distance;
}

int main() {
	int v, e, source;
	char x, y, ch;
	unordered_map<char, int>node;
	cin>>v>>e;
	vector<vector<int>>adj(v);
	for(int i=0; i<v; i++) {
		cin>>ch;
		node[ch]=i;
	}
	for(int i=0; i<e; i++) {
		cin>>x>>y;
		adj[node[x]].push_back(node[y]);
		adj[node[y]].push_back(node[x]);
	}
	cin>>ch;
	source=node[ch];
	vector<int>ans=BFS_shortest_distance(source, adj);
	for(auto i:ans) {
		cout<<i<<" ";
	}
	return 0;
}