// A.cpp: определяет точку входа для консольного приложения.
//

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

string s;
int k, n, res;
int nxt[1010], last[30], pref[1010][30];
bool used[30];

int main()
{
	cin >> s >> k;
	n = s.size();

	for (int i = 0; i < 30; ++i)
	{
		last[i] = -1;
	}

	for (int i = n - 1; i >= 0; --i)
	{
		nxt[i] = last[s[i] - 'a'];
		last[s[i] - 'a'] = i;
	}

	pref[0][s[0] - 'a'] = 1;
	for (int i = 1; i < n; ++i)
	{
		for (int j = 0; j < 30; ++j)
		{
			pref[i][j] = pref[i - 1][j];
		}
		++pref[i][s[i] - 'a'];
	}

	for (int i = 0; i < n; ++i)
	{
		if (used[s[i] - 'a'])
		{
			used[s[i] - 'a'] = 0;
			++k;
		}
		if (nxt[i] != -1 && k > 0)
		{
			if (k > 1)
			{
				++res;
				used[s[i] - 'a'] = 1;
				--k;
			}
			else
			{
				bool now = 0;
				for (int j = 0; j < 30; ++j)
				{
					if (i != j)
					{
						now |= (pref[nxt[i]][j] - pref[i][j]) >= 2;
					}
				}

				if (!now && k == 1)
				{
					++res;
					used[s[i] - 'a'] = 1;
					--k;
				}
			}
		}
	}
	cout << res << endl;
    return 0;
}

