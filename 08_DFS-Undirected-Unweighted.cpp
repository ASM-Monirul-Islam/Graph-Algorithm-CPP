#include<bits/stdc++.h>
using namespace std;

// Undirected Unweighted Graph

vector<int>DFS(int start, vector<vector<int>>& adj, vector<bool>& visited) {
	stack<int>s;
	s.push(start);
	visited[start]=true;
	vector<int>ans;
	while(!s.empty()){
		int node = s.top();
		s.pop();
		ans.push_back(node);
		for(auto i: adj[node]) {
			if(!visited[i]) {
				s.push(i);
				visited[i]=true;
			}
		}
	}
	return ans;
}

int main() {
	int v, e;
	char n, x, y;
	unordered_map<char, int>node;
	unordered_map<int, char>inverse_node;
	cout<<"Enter the number of vertices and edges: ";
	cin>>v>>e;
	cout<<"Enter the names of the nodes: ";
	for(int i=0; i<v; i++) {
		cin>>n;
		node[n]=i;
		inverse_node[i]=n;
	}
	vector<vector<int>>adj(v);
	cout<<"Enter the starting edge and ending node: "<<endl;
	for(int i=0; i<e; i++) {
		cout<<"node 1 -> node 2 : ";
		cin>>x>>y;
		adj[node[x]].push_back(node[y]);
		adj[node[y]].push_back(node[x]);
	}
	vector<bool>visited(v, false);
	cout<<"Starting Node: ";
	cin>>n;
	vector<int>Traverse = DFS(node[n], adj, visited);
	for(auto i:Traverse){
		cout<<inverse_node[i]<<" ";
	}
	return 0;
}

/*
Enter the number of vertices and edges: 5 6
Enter the names of the nodes: A B C D E
Enter the starting edge and ending node: 
node 1 -> node 2 : A B
node 1 -> node 2 : A C
node 1 -> node 2 : B C
node 1 -> node 2 : B D
node 1 -> node 2 : C E
node 1 -> node 2 : D E
Starting Node: A
A C E D B 
*/