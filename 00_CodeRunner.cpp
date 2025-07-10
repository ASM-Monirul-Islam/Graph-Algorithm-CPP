#include<bits/stdc++.h>
using namespace std;

vector<int>BFS(int start, vector<vector<int>>& Adj, vector<bool> &visited) {
	queue<int>q;
	vector<int>ans;
	q.push(start);
	visited[start]=true;
	while(!q.empty()){
		int node = q.front();
		q.pop();
		ans.push_back(node);
		for(auto i:Adj[node]){
			if(!visited[i]) {
				visited[i]=true;
				q.push(i);
			}
		}
	}
	return ans;
}

int main() {
	int v, e;
	char n, x, y;
	cin>>v>>e;
	vector<vector<int>>Adj(v);
	map<char, int>node;
	map<int, char>inverse_node;
	cout<<"Nodes: ";
	for(int i=0; i<v; i++) {
		cin>>n;
		node[n]=i;
		inverse_node[i]=n;
	}
	for(int i=0; i<e; i++) {
		cin>>x>>y;
		Adj[node[x]].push_back(node[y]);
		// Adj[node[y]].push_back(node[x]);
	}
	vector<bool>visited(v, false);
	cout<<"Starting node: ";
	cin>>n;
	vector<int>Traverse = BFS(node[n], Adj, visited);
	for(auto i: Traverse){
		cout<<inverse_node[i]<<" ";
	}
	return 0;
}