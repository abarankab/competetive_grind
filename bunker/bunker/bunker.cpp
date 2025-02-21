// bunker.cpp: определяет точку входа для консольного приложения.
//

#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>

using namespace std;

const int N = 2 * 300005;
int l[N], n, cnt, color[N], cl;
vector<int> e[N];
vector<pair<int, int> > g[N];
bool used[N];
vector<int> order, comp;

int dfs(int v, int size, int &center, int pr = -1)
{
	int sum = 1;
	for (auto u : g[v])
	{
		if (!used[u.first] && u.first != pr)
		{
			sum += dfs(u.first, size, center, v);
		}
	}
	if (center == -1 && (pr == -1 || sum * 2 >= size))
	{
		center = v;
	}
	return sum;
}

vector<pair<int, int> > get(int v, int size, int pr = -1)
{
	int center = -1;
	dfs(v, size, center);
	used[center] = 1;
	vector<pair<int, int> > arr(1, { 0, center });
	for (auto u : g[center])
	{
		vector<pair<int, int> > nxt = get(u.first, size / 2, center), tmp;
		for (int i = 0; i < n; ++i)
		{
			nxt[i].first += u.second;
		}
		merge(arr.begin(), arr.end(), nxt.begin(), nxt.end(), back_inserter(tmp));
		arr = tmp;
	}
	
	int bg = cnt;
	for (int i = 0; i < arr.size(); ++i)
	{
		if (i != 0)
		{
			e[cnt].push_back(cnt - 1);
			e[cnt].push_back(arr[i].second);
		}
		else
		{
			e[cnt].push_back(arr[i].second);
		}
		++cnt;
	}

	if (arr.size() != 0)
	{
		e[center].push_back(upper_bound(arr.begin(), arr.end(), l[center]) - arr.begin() + bg - 1);
	}

	return arr;
}

void dfs2(int v)
{
	used[v] = 1;
	for (int u : e[v])
	{
		if (!used[u])
		{
			dfs2(u);
		}
	}
	order.push_back(v);
}

void dfs3(int v)
{
	used[v] = 1;
	comp.push_back(v);
	color[v] = cl;

	for (auto u : e[v])
	{
		if (!used[u])
		{
			dfs3(u);
		}
	}
}

int main()
{
	cin >> n;
	cnt = n + 1;
	for (int i = 0; i < n; ++i)
	{
		cin >> l[i];
	}
	for (int i = 1; i < n; ++i)
	{
		int u, v, d;
		cin >> u >> v >> d;
		--u; --v;
		g[u].push_back({ v, d });
		g[v].push_back({ u, d });
	}
	
	get(0, n);
	memset(used, 0, sizeof(used));
	for (int i = 0; i < n; ++i)
	{
		if (!used[i])
		{
			dfs2(i);
		}
	}
	memset(used, 0, sizeof(used));
	for (int i = n - 1; i >= 0; --i)
	{
		int v = order[i];
		if (!used[i])
		{
			dfs3(v);
			comp.clear();
			++cl;
		}
	}
	
    return 0;
}

