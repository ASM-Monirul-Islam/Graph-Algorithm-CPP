#include<bits/stdc++.h>
using namespace std;

vector<int>Dijkstras_algorithm(int start, vector<vector<pair<int, int>>>&adj) {
	int v = adj.size();
	vector<int>distance(v, INT_MAX);
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>pq;

	distance[start]=0;

	pq.push({distance[start], start});

	while(!pq.empty()) {
		auto p = pq.top();
		pq.pop();
		int d = p.first;
		int node = p.second;

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
		adj[node[x]].emplace_back(node[y], w);
		adj[node[y]].emplace_back(node[x], w); //Undirected
	}

	cin>>start;
	vector<int>ans = Dijkstras_algorithm(node[start], adj);

	for(auto i:ans) {
		cout<<i<<" ";
	}
	return 0;
}