/*
🔹 What is Bellman–Ford?
Bellman–Ford is a shortest path algorithm that works on graphs with negative edge weights. 
Unlike Dijkstra, it can detect negative weight cycles too.
Input: A weighted graph (directed or undirected, but usually directed).
Output: The shortest distance from a source node to all other nodes (or detect if a negative cycle exists).

🔹 Why do we need Bellman–Ford if we already have Dijkstra?
Dijkstra fails when the graph has negative weights.
Bellman–Ford handles negative weights.
But it’s slower → O(V × E) time complexity.
So:
Use Dijkstra if weights ≥ 0 (faster).
Use Bellman–Ford if weights can be negative (safer).
*/


#include<bits/stdc++.h>
using namespace std;

vector<int>BellmanFord_algorithm(int start, vector<vector<pair<int, int>>>&adj) {
	int v = adj.size();
	vector<int>distance(v, INT_MAX);
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>pq;
	distance[start]=0;
	pq.push({distance[start], start});

	while(!pq.empty()) {
		auto p = pq.top();
		int d = p.first;
		int node = p.second;
		pq.pop();
		if(d>distance[node]) continue;
		for(auto i:adj[node]) {
			if(distance[i.first]>distance[node]+i.second) {
				distance[i.first]=distance[node]+i.second;
				pq.push({distance[i.first], i.first});
			}
		}
	}
	return distance;
}

int main() {
	int v, e, w;
	char ch, x, y, start;
	cin>>v>>e;
	vector<vector<pair<int, int>>>adj(v);
	unordered_map<char, int>node;
	for(int i=0; i<v; i++) {
		cin>>ch;
		node[ch]=i;
	}
	for(int i=0; i<e; i++) {
		cin>>x>>y>>w;
		adj[node[x]].emplace_back(node[y],w); //Directed
	}
	cin>>start;
	vector<int>ans = BellmanFord_algorithm(node[start], adj);
	for(auto i: ans) {
		cout<<i<<" ";
	}
	return 0;
}