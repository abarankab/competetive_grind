// B.cpp: определяет точку входа для консольного приложения.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

#define int long long

using namespace std;

const int MAXN = 100005;
int k, p, res;
vector<int> arr, pref;
set<int> now;
int mod;

bool can(int x)
{
	int l = -1, r = k;
	while (r - l > 1)
	{
		int m = (l + r) >> 1;
		if (arr[m] >= x)
		{
			l = m;
		}
		else
		{
			r = m;
		}
	}
	
	mod = 0;
	if (r < pref.size())
	{
		mod = pref[r];
	}

	return mod + (l + 1) * x >= x * p;
}

signed main()
{
	cin >> k >> p;
	arr.resize(k);
	pref.resize(k);
	for (int i = 0; i < k; ++i)
	{
		cin >> arr[i];
	}

	sort(arr.begin(), arr.end());
	reverse(arr.begin(), arr.end());

	pref[k - 1] = arr[k - 1];
	for (int i = k - 2; i >= 0; --i)
	{
		pref[i] = pref[i + 1] + arr[i];
	}

	int l = 0, r = (int)1e9 + 5;
	while (r - l > 1)
	{
		int m = (l + r) >> 1;
		if (can(m))
		{
			l = m;
		}
		else
		{
			r = m;
		}
	}

	int x = l;

	l = -1, r = k;
	while (r - l > 1)
	{
		int m = (l + r) >> 1;
		if (arr[m] >= x)
		{
			l = m;
		}
		else
		{
			r = m;
		}
	}

	mod = 0;
	if (r < pref.size())
	{
		mod = pref[r];
	}


	return 0;
}

