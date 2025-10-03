#include<bits/stdc++.h>
using namespace std;

vector<int>DFS_shortest_path(int start, vector<vector<int>>&adj) {
	int v = adj.size();
	vector<int>distance(v, -1);
	vector<bool>visited(v, false);
	stack<int>s;
	visited[start]=true;
	s.push(start);
	distance[start]=0;

	while(!s.empty()) {
		int node = s.top();
		s.pop();
		for(auto i:adj[node]) {
			if(i==start) continue;
			if(!visited[i]) {
				distance[i]=(distance[node]+1);
				s.push(i);
				visited[i]=true;
			}
			if(visited[i]) {
				if(distance[i]>(distance[node]+1)) {
					distance[i]=distance[node]+1;
					s.push(i);
					visited[i]=true;
				}
			}
		}
	}
	return distance;
}

int main() {
	int v, e;
	char ch, x, y, start;
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
	cin>>start;
	vector<int>ans = DFS_shortest_path(node[start], adj);
	for(auto i:ans) {
		cout<<i<<" ";
	}
	return 0;
}