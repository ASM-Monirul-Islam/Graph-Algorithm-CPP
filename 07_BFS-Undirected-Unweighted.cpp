#include<bits/stdc++.h>
using namespace std;

//Undirected Unweighted Graph

vector<int>BFS(int start, vector<vector<int>>&AdjList, vector<bool>&visited) {
	queue<int>q;
	vector<int>ans;
	q.push(start);
	visited[start]=true;
	while(!q.empty()){
		int node = q.front();
		q.pop();
		ans.push_back(node);
		for(auto i:AdjList[node]){
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
	cout<<"Enter the number of vertices and Edges: ";
	cin>>v>>e;
	vector<vector<int>>AdjList(v);
	map<char, int>node;
	map<int, char>inverse_node;
	cout<<"Enter the name of the nodes (e.g.: A B C D...): "<<endl;
	for(int i=0; i<v; i++) {
		cout<<"Node "<<i+1<<": ";
		cin>>n;
		node[n]=i;
		inverse_node[i]=n;
	}
	for(int i=0; i<e; i++) {
		cout<<"Enter the starting node and the ending node: ";
		cin>>x>>y;
		AdjList[node[x]].push_back(node[y]);
		AdjList[node[y]].push_back(node[x]);
	}
	vector<bool>visited(v, false);
	vector<int>ans = BFS(0, AdjList, visited);
	for(auto i: ans){
		cout<<inverse_node[i]<<" ";
	}
	return 0;
}

/*
Enter the number of vertices and Edges: 5 6
Enter the name of the nodes (e.g.: A B C D...): 
Node 1: A
Node 2: B
Node 3: C
Node 4: D
Node 5: E
Enter the starting node and the ending node: A B
Enter the starting node and the ending node: A C
Enter the starting node and the ending node: B D
Enter the starting node and the ending node: B C
Enter the starting node and the ending node: C E
Enter the starting node and the ending node: D E
A B C D E
*/