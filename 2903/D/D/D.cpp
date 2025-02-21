// D.cpp: определяет точку входа для консольного приложения.
//

#include <iostream>
#include <map>
#include <vector>
#include <bitset>
#include <algorithm>

using namespace std;

struct edge
{
	int s, r, ds, dr;
	bitset<20> police;

	edge() {}

	edge(int _s, int _r, int _ds, int _dr, bitset<20> _police)
	{
		s = _s;
		r = _r;
		ds = _ds;
		dr = _dr;
		police = _police;
	}

	void increase()
	{
		s += ds;
		r += dr;
	}

	void clear()
	{
		s = 0;
		r = 0;
		ds = 0;
		dr = 0;
		police &= 0;
	}
};

const int N = 100005;
int n, m, k, start;
vector<int> g[N];
map<pair<int, int>, edge> mp;
edge now;
int res = -(int)1e9;

vector<edge> dfs(int v, int pr = -1, int profit = 0)
{
	int mx0[2] = { -(int)1e9, -(int)1e9 };
	int mx1[2] = { -(int)1e9, -(int)1e9 };

	for (auto u : g[v])
	{
		if (u != pr)
		{
			now.police ^= mp[{ u, v }].police;
			pair<int[2], int[2]> nw = dfs(u, v, profit + mp[{ u, v }].s - mp[{ u, v }].r);
			now.police ^= mp[{ u, v }].police;

			int nw0[4];
			int nw1[4];

			for (int i = 0; i < 2; ++i)
			{
				nw0[i] = mx0[i];
				nw0[i + 2] = nw0[i];
				nw1[i] = mx0[i];
				nw1[i + 2] = nw0[i];
			}

			sort(nw0, nw0 + 4);
			sort(nw1, nw1 + 4);

			mx0[0] = nw0[0];
			mx0[1] = nw0[1];
			mx1[0] = nw1[0];
			mx1[1] = nw1[1];
		}
	}

	res = 
}

int main()
{
	cin >> n >> m >> k;
	for (int i = 0; i < n - 1; ++i)
	{
		int u, v, s, r, ds, dr, q;
		cin >> u >> v >> s >> r >> ds >> dr >> q;
		--u; --v;
		g[u].push_back(v);
		g[v].push_back(u);
		bitset<20> tmp;
		for (int i = 0; i < q; ++i)
		{
			int type;
			cin >> type;
			tmp.set(type - 1);
		}
		mp[{u, v}] = edge(s, r, ds, dr, tmp);
		mp[{v, u}] = edge(s, r, ds, dr, tmp);
	}

	for (int asd = 0; asd < k; ++asd)
	{
		now.clear();
		dfs(0);

		for (auto p : mp)
		{
			mp[p.first].increase();
		}

		if (res == -(int)1e9)
		{
			cout << "Sadness!\n";
		}
		else
		{
			cout << res << "\n";
		}

		res = -(int)1e9;
	}

    return 0;
}

