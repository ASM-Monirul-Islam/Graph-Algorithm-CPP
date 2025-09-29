/*
Problem Statement

You are given a map represented as a 2D grid of size R×C, 
where each cell of the grid is either land or water.
	Land is represented by 1
	Water is represented by 0

An island is defined as a group of connected land cells (1s) 
where connectivity is considered in all 8 directions:
Horizontally (left, right)
Vertically (up, down)
Diagonally (top-left, top-right, bottom-left, bottom-right)

Two land cells belong to the same island if they are directly or 
indirectly connected through these eight directions.
Your task is to determine the total number of islands present in the given map.

Input Format:
The first line contains two integers 𝑅 and 𝐶 — the number of rows and columns of the grid.
The next 𝑅 lines contain C integers (either 0 or 1), representing the map.

Output Format:
Print a single integer — the total number of islands in the map.

Input:
	5 6
	1 1 1 0 1 1
	0 1 1 0 0 1
	1 0 0 0 0 0
	1 0 1 0 1 1
	1 1 0 0 1 1


Output:
3
*/


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