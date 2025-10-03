#include<bits/stdc++.h>
using namespace std;

void Floyd_Warshall_Alg(vector<vector<int>>&matrix) {
	int v = matrix.size();

	for(int k=0; k<v; k++) {
		for(int i=0; i<v; i++) {
			for(int j=0; j<v; j++) {
				if(matrix[i][k] == INT_MAX or matrix[k][j] == INT_MAX) {
					continue;
				} else {
					matrix[i][j]=min(matrix[i][j], (matrix[i][k]+matrix[k][j]));
				}
			}
		}
	}
}

int main() {
	int v, e, w;
	char ch, x, y;
	unordered_map<char, int>node;
	cin>>v>>e;
	vector<vector<int>>matrix(v, vector<int>(v, INT_MAX));
	for(int i=0; i<v; i++) {
		cin>>ch;
		node[ch]=i;
	}
	for(int i=0; i<e; i++) {
		cin>>x>>y>>w;
		matrix[node[x]][node[y]]=w;
	}
	for(int i=0; i<v; i++) {
		for(int j=0; j<v; j++) {
			if(i==j) {
				matrix[i][j]=0;
			}
		}
	}
	
	Floyd_Warshall_Alg(matrix);
	
	for(int i=0; i<v; i++) {
		for(int j=0; j<v; j++) {
			cout<<matrix[i][j]<<" ";
		}
		cout<<endl;
	}
	return 0;
}