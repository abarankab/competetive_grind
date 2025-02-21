// C.cpp: определяет точку входа для консольного приложения.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

#pragma GCC optimize("O3")

using namespace std;

int n, m, r, s, cnt[20][20], global = (int)1e9;
vector<int> bond_x, qx;

void get_y()
{
	int pref[20][20], lst = 0;
	memset(pref, 0, sizeof(pref));

	for (int i = 1; i < bond_x.size(); ++i)
	{
		for (int j = lst; j < bond_x[i]; ++j)
		{
			pref[0][i] += cnt[j][0];
		}
		lst = bond_x[i];
	}

	for (int pos = 1; pos <= m; ++pos)
	{
		lst = 0;
		for (int i = 1; i < bond_x.size(); ++i)
		{
			pref[pos][i] = pref[pos - 1][i];
			for (int j = lst; j < bond_x[i]; ++j)
			{
				pref[pos][i] += cnt[j][pos];
			}
			lst = bond_x[i];
		}
	}

	int dp[20][20]; //pos taken

	for (int i = 0; i < 20; ++i)
	{
		for (int j = 0; j < 20; ++j)
		{
			dp[i][j] = (int)1e9;
		}
	}

	for (int pos = 0; pos < m; ++pos)
	{
		int qq = -1;
		for (int i = 1; i < bond_x.size(); ++i)
		{
			qq = max(qq, pref[pos][i]);
		}

		dp[pos][1] = qq;

		for (int lst = 0; lst < pos; ++lst)
		{
			int mx = -1;
			for (int i = 1; i < bond_x.size(); ++i)
			{
				mx = max(mx, pref[pos][i] - pref[lst][i]);
			}

			for (int taken = 1; taken <= s + 1; ++taken)
			{
				dp[pos][taken] = min(max(dp[lst][taken - 1], mx), dp[pos][taken]);
			}
		}
	}

	global = min(global, dp[m - 1][s + 1]);
}

void gen_x()
{
	if (bond_x.size() == r + 1)
	{
		bond_x.push_back(n);
		get_y();
		bond_x.pop_back();
	}
	for (int i = bond_x.back() + 1; i <= n - 1; ++i)
	{
		bond_x.push_back(i);
		gen_x();
		bond_x.pop_back();
	}
}

int main()
{
	ios_base::sync_with_stdio(0);

	cin >> n >> m >> r >> s;
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			cin >> cnt[i][j];
		}
	}

	bond_x.push_back(0);
	gen_x();
	cout << global << "\n";
    return 0;
}

s