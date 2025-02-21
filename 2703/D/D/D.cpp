// D.cpp: определяет точку входа для консольного приложения.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

const int MAXN = 20;
int n, res;
bool used[MAXN];
vector<int> g[MAXN];
vector<int> permutation;

int count_size(int v, int pr = -1)
{
	int sz = 0;
	for (int u : g[v])
	{
		if (u != pr && !used[u])
		{
			sz += count_size(u, v);
		}
	}
	return sz + 1;
}

int main()
{
	cin >> n;
	for (int i = 0; i < n - 1; ++i)
	{
		permutation.push_back(i);
		int u, v;
		cin >> u >> v;
		g[--u].push_back(--v);
		g[v].push_back(u);
	}
	permutation.push_back(n - 1);
	do
	{
		memset(used, 0, sizeof(used));
		for (int v : permutation)
		{
			res += count_size(v);
			used[v] = 1;
		}
	} while (next_permutation(permutation.begin(), permutation.end()));
	cout << res << endl;
    return 0;
}

