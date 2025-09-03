#include <bits/stdc++.h>
using namespace std;

bool valid(int i, int j, int r, int c)
{
	return i >= 0 and i < r and j >= 0 and j < c;
}

int CovidCheck(int r, int c, vector<vector<int>> &adj, queue<pair<int, int>> &q)
{
	int time = 0;
	while (!q.empty())
	{
		time++;
		int s = q.size();
		while (s--)
		{
			int i = q.front().first;
			int j = q.front().second;
			q.pop();
			int row[4] = {-1, 1, 0, 0};
			int col[4] = {0, 0, -1, 1};
			for (int k = 0; k < 4; k++)
			{
				if (valid(i + row[k], j + col[k], r, c) and adj[i + row[k]][j + col[k]] == 1)
				{
					adj[i + row[k]][j + col[k]] = 2;
					q.push({i + row[k], j + col[k]});
				}
			}
		}
	}
	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
		{
			if (adj[i][j] == 1)
			{
				return -1;
			}
		}
	}
	return time-1;
}

int main()
{
	int r, c;
	cout << "Enter the number of row and column: ";
	cin >> r >> c;
	vector<vector<int>> adj(r, vector<int>(c));
	queue<pair<int, int>> q;
	cout << "Enter the nodes: " << endl;
	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
		{
			cin >> adj[i][j];
			if (adj[i][j] == 2)
			{
				q.push({i, j});
			}
		}
	}
	int ans = CovidCheck(r, c, adj, q);
	if(ans == -1) {
		cout<<"Whole hospital is not affected by Covid 19"<<endl;
	} else {
		cout<<"It will take "<<ans<<" units of time to spread Covid 19"<<endl;
	}
	return 0;
}