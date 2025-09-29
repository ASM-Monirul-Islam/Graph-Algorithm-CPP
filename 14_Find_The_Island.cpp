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

bool valid(int r, int c, int i, int j) {
	return i>=0 and j>=0 and i<r and j<c;
}

void checkIsland(vector<vector<int>>&v, queue<pair<int,int>>&q, vector<vector<bool>>&visited, int r, int c) {
	while(!q.empty()) {
		int i=q.front().first;
		int j=q.front().second;
		visited[i][j]=true;
		q.pop();
		int rows[8]={-1, -1, -1, 0, 0, 1, 1, 1};
		int cols[8]={-1, 0, 1, -1, 1, -1, 0, 1};
		for(int k=0; k<8; k++) {
			if(valid(r, c, i+rows[k], j+cols[k]) and !visited[i+rows[k]][j+cols[k]] and v[i+rows[k]][j+cols[k]]==1) {
				q.push({i+rows[k], j+cols[k]});
			}
		}
	}
}

int main() {
	int r, c;
	cin>>r>>c;
	vector<vector<int>>v(r, vector<int>(c));
	for(int i=0; i<r; i++) {
		for(int j=0; j<c; j++) {
			cin>>v[i][j];
		}
	}
	vector<vector<bool>>visited(r,vector<bool>(c, false));
	queue<pair<int, int>>q;
	int count=0;
	for(int i=0; i<r; i++) {
		for(int j=0; j<c; j++) {
			if(!visited[i][j] and v[i][j]==1) {
				q.push({i,j});
				checkIsland(v, q, visited, r, c);
				count++;
			}
		}
	}
	cout<<count<<endl;
	return 0;
}