// ioip.cpp: определяет точку входа для консольного приложения.
//

#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <algorithm>

using namespace std;

#define int long long

int n, k, arr[100005];
int min0 = (int)1e9 + 5, min1 = (int)1e9 + 5, res = 0;
long double avg;

signed main()
{
	cin >> n >> k;
	for (int i = 0; i < n; ++i)
	{
		cin >> arr[i];
		avg += arr[i];
	}

	avg /= n;

	int ans = (int)1e18;
	for (int x0 = avg + (k / 2) - 50; x0 <= avg + (k / 2) + 50; ++x0)
	{
		int res = 0;
		for (int i = 0; i < n; i += 2)
		{
			res += abs(arr[i] - x0);
		}

		int v1 = 0, v2 = 0;

		for (int i = 1; i < n; i += 2)
		{
			v1 += abs(k + x0 - arr[i]);
		}

		for (int i = 1; i < n; i += 2)
		{
			v2 += abs(x0 - k - arr[i]);
		}

		res += min(v1, v2);

		ans = min(ans, res);
	}

	for (int x0 = avg - (k / 2) - 50; x0 <= avg - (k / 2) + 50; ++x0)
	{
		int res = 0;
		for (int i = 0; i < n; i += 2)
		{
			res += abs(arr[i] - x0);
		}

		int v1 = 0, v2 = 0;

		for (int i = 1; i < n; i += 2)
		{
			v1 += abs(k + x0 - arr[i]);
		}

		for (int i = 1; i < n; i += 2)
		{
			v2 += abs(x0 - k - arr[i]);
		}

		res += min(v1, v2);

		ans = min(ans, res);
	}

	cout << ans << endl;

    return 0;
}

