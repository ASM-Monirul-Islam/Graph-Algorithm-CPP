// Problem statement:
/*
1 2 1 1 0 1 
1 1 0 1 1 2
0 1 0 2 1 1
1 1 0 1 0 1
1 0 1 2 0 1
*/

// where, 
// 0 -> Empty
// 1 -> Normal Patient
// 2 -> Covid Patient

#include<bits/stdc++.h>
using namespace std;

bool valid(int r, int c, int i, int j) {
	return i>=0 and j>=0 and i<r and j<c;
}

int checkCovid(int r, int c, vector<vector<int>>& adj, queue<pair<int, int>>& q) {
	int time = 0;
	while(!q.empty()) {
		time++;
		int n = q.size();
		while(n--) {
			int i=q.front().first;
			int j=q.front().second;
			q.pop();
			int rows[4]={-1, 1, 0, 0};
			int cols[4]={0, 0, -1, 1};
			for(int k=0; k<4; k++) {
				if(valid(r,c,i+rows[k], j+cols[k]) and adj[i+rows[k]][j+cols[k]]==1) {
					adj[i+rows[k]][j+cols[k]]=2;
					q.push({i+rows[k],j+cols[k]});
				}
			}
		}
	}
	for(int i=0; i<r; i++) {
		for(int j=0; j<c; j++) {
			if(adj[i][j]==1) {
				return -1;
			}
		}
	}
	return time-1;
}

int main() {
	int r, c;
	cin>>r>>c;
	vector<vector<int>>adj(r, vector<int>(c));
	queue<pair<int, int>>q;
	for(int i=0; i<r; i++) {
		for(int j=0; j<c; j++) {
			cin>>adj[i][j];
			if(adj[i][j]==2) {
				q.push({i,j});
			}
		}
	}

	int result = checkCovid(r,c,adj,q);

	if(result == -1) {
		cout<<"Not all patients are affected by Covid"<<endl;
	} else {
		cout<<"All patients have been affected in "<<result<<" units of time"<<endl;
	}

	return 0;
}