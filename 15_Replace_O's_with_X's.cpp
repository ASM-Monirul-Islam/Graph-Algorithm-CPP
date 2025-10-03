/*
Problem Statement

You are given a 2D matrix consisting of characters 'X' and 'O'. 
The goal is to replace certain 'O's with 'X's according to the following rule:
Any 'O' that is completely surrounded by 'X' in all four directions 
(up, down, left, right) should be replaced with 'X'.
If a group of 'O's forms a connected region (connected horizontally or vertically) 
that is entirely surrounded by 'X', the entire region should be converted to 'X'.
'O's that are connected to the boundary of the matrix 
(first row, last row, first column, last column) cannot be replaced, since they are not fully surrounded.

Example

Input matrix:

X X X X
X O X X
X O O X
X O X X
X X O O

Output matrix after replacement:

X X X X
X X X X
X X X X
X X X X
X X O O


Explanation:
The group of 'O's in the middle is fully surrounded by 'X', so all of them are replaced with 'X'.
The 'O's at the bottom right are connected to the boundary, so they remain 'O'.

*/

#include<bits/stdc++.h>
using namespace std;

bool valid(int r, int c, int i, int j) {
	return i>=0 and i<r and j>=0 and j<c;
}

void replace_the_O(vector<vector<char>>&grid, queue<pair<int, int>>&q) {
	int r = grid.size();
	int c = grid[0].size();
	int row[4]={-1, 1, 0, 0};
	int col[4]={0, 0, -1, 1};
	while(!q.empty()) {
		int i = q.front().first;
		int j = q.front().second;
		grid[i][j]='T';
		q.pop();

		for(int k=0; k<4; k++) {
			int ni = i+row[k];
			int nj = j+col[k];

			if(valid(r, c, ni, nj) and grid[ni][nj]=='O') {
				q.push({ni, nj});
			}
		}
	}
	for(int i=0; i<r; i++){
		for(int j=0; j<c; j++) {
			if(grid[i][j]=='O') {
				grid[i][j]='X';
			}
			if(grid[i][j]=='T') {
				grid[i][j]='O';
			}
		}
	}
}

int main() {
	int r, c;
	cin>>r>>c;
	vector<vector<char>>grid(r, vector<char>(c));
	queue<pair<int, int>>q;
	for(int i=0; i<r; i++) {
		for(int j=0; j<c; j++) {
			cin>>grid[i][j];
		}
	}

	for(int i=0; i<r; i++) {
		if(grid[i][0]=='O') {
			q.push({i,0});
		}
		if(grid[i][c-1]=='O') {
			q.push({i, c-1});
		}
	}
	
	for(int j=0; j<c; j++) {
		if(grid[0][j]=='O') {
			q.push({0, j});
		}
		if(grid[r-1][j]=='O') {
			q.push({r-1, j});
		}
	}
	replace_the_O(grid, q);
	for(int i=0; i<r; i++) {
		for(int j=0; j<c; j++) {
			cout<<grid[i][j];
			if(j<c-1) cout<<" ";
		}
		cout<<endl;
	}
	return 0;
}