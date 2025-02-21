// B.cpp: определяет точку входа для консольного приложения.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int N = (int)1e5 + 5;
int n;
vector<int> g[N];
int sz[N];
bool used[N];
bool used2[N];
int res[N];
int par[N];//

void dfs(int v, int p = -1)
{
	par[v] = p;
	++sz[v];
	for (auto u : g[v])
	{
		if (u != p)
		{
			dfs(u, v);
			sz[v] += sz[u];
		}
	}
}

void dfs2(int v, int col)
{
	used2[v] = 1;
	res[v] = col;
	for (auto u : g[v])
	{
		if (!used2[u])
		{
			dfs2(u, col);
		}
	}
}

int main()
{
	cin >> n;

	for (int i = 0; i < n - 1; ++i)
	{
		int u, v;
		cin >> u >> v;
		--u;
		--v;
		g[u].push_back(v);
		g[v].push_back(u);
	}

	dfs(0);
	int all = n;

	for (int i = 0; i < n; ++i)
	{
		vector<pair<int, int> > sons;
		if (par[i] == -1)
		{
			for (auto u : g[i])
			{
				sons.push_back({ sz[u], u });
			}
		}
		else
		{
			for (auto u : g[i])
			{
				if (u != par[i])
				{
					sons.push_back({ sz[u], u });
				}
			}
			sons.push_back({ sz[0] - sz[par[i]] + 1, par[i] });
		}

		sort(sons.begin(), sons.end());
		vector<bool> team(sons.size());

		int now = 0;
		
		for (int j = 0; j < sons.size(); ++j)
		{
			now += sons[j].first;
			team[j] = 1;

			int prince_1 = now + 1, prince_2 = all - now;

			if (2 * prince_1 >= prince_2 && 2 * prince_2 >= prince_1)
			{
				used2[i] = 1;
				res[i] = 0;

				for (int q = 0; q < team.size(); ++q)
				{
					if (team[q])
					{
						dfs2(sons[q].second, 1);
					}
					else
					{
						dfs2(sons[q].second, 2);
					}
				}

				for (int q = 0; q < n; ++q)
				{
					cout << res[q] << " ";
				}
				cout << "\n";
				return 0;
			}
		}
	}
	return 0;
}

