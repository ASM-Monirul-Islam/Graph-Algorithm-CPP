#include<bits/stdc++.h>
using namespace std;

bool valid(int i, int j, int r, int c) {
	return i>=0 and j>=0 and i<r and j<c;
}

int count_island(vector<vector<int>>&adj) {
	int r = adj.size();
	int c = adj[0].size();
	int rows[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
	int cols[8] = {-1, 0, 1, -1, 1, -1, 0, 1};
	queue<pair<int, int>>q;
	int count=0;
	for(int i=0; i<r; i++) {
		for(int j=0; j<c; j++) {
			if(adj[i][j]==1) {
				q.push({i, j});
				adj[i][j]=0;
				count++;	
				while(!q.empty()) {
					int x = q.front().first;
					int y = q.front().second;
					q.pop();
					for(int k=0; k<8; k++) {
						if(valid(x+rows[k], y+cols[k], r, c) and adj[x+rows[k]][y+cols[k]]==1) {
							adj[x+rows[k]][y+cols[k]]=0;
							q.push({x+rows[k], y+cols[k]});
						}
					}
				}
			}
		}
	}
	return count;
}

int main() {
	int r, c;
	cin>>r>>c;
	vector<vector<int>>adj(r, vector<int>(c));
	for(int i=0; i<r; i++) {
		for(int j=0; j<c; j++) {
			cin>>adj[i][j];
		}
	}
	int count = count_island(adj);
	cout<<count<<endl;
	return 0;
}