#include<bits/stdc++.h>
using namespace std;
//Undirected Weighted Graph - Adjacency List
int main() {
	int v, e, weight;
	char n, x, y;
	cout<<"Enter the vertices and edges number: ";
	cin>>v>>e;
	map<char, int>node;
	map<int, char>inverse_node;
	vector<vector<pair<char, int>>>AdjList(v);
	cout<<"Enter the names of nodes: "<<endl;
	for(int i=0; i<v; i++) {
		cout<<" Node "<<i+1<<": ";
		cin>>n;
		node[n]=i;
		inverse_node[i]=n;
	}
	for(int i=0; i<e; i++) {
		cout<<"Enter the starting node and the ending node and the weight: ";
		cin>>x>>y>>weight;
		AdjList[node[x]].emplace_back(y, weight);
		AdjList[node[y]].emplace_back(x, weight);
	}

	for(int i=0; i<v; i++) {
		cout<<inverse_node[i]<<"-> ";
		for(int j=0; j<AdjList[i].size(); j++) {
			cout<<"("<<AdjList[i][j].first<<","<<AdjList[i][j].second<<")";
			if(j<AdjList[i].size()-1) cout<<",";
		}
		cout<<endl;
	}
	return 0;
}

/*
Enter the vertices and edges number: 5 6
Enter the names of nodes: 
 Node 1: A
 Node 2: B
 Node 3: C
 Node 4: D
 Node 5: E
Enter the starting node and the ending node and the weight: A B 2
Enter the starting node and the ending node and the weight: A D 1
Enter the starting node and the ending node and the weight: B C 4
Enter the starting node and the ending node and the weight: B D 3
Enter the starting node and the ending node and the weight: C E 7
Enter the starting node and the ending node and the weight: D E 9
A-> (B,2),(D,1)
B-> (A,2),(C,4),(D,3)
C-> (B,4),(E,7)
D-> (A,1),(B,3),(E,9)
E-> (C,7),(D,9)
*/