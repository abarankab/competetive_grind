// ioip4.cpp: определяет точку входа для консольного приложения.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int r, c, n;
vector<pair<int, int> > arr;

int get(pair<int, int> p, int x, int y)
{
	return abs(x - p.first) + abs(y - p.second);
}

int main()
{
	cin >> r >> c >> n;
	if (n == 1)
	{
		int r1, r2, r3, r4;

		for (int i = 0; i < n; ++i)
		{
			int x, y;
			cin >> x >> y;
			r1 = get({ x, y }, 1, 1);
			r2 = get({ x, y }, 1, c);
			r3 = get({ x, y }, r, 1);
			r4 = get({ x, y }, r, c);
		}

		cout << max(max(r1, r2), max(r3, r4)) << endl;
	}
	else
	{
		int res = -1;

		for (int i = 0; i < n; ++i)
		{
			int x, y;
			cin >> x >> y;
			arr.push_back({ x, y });
		}

		for (int i = 1; i <= r; ++i)
		{
			for (int j = 1; j <= c; ++j)
			{
				int dist = (int) 1e9;
				for (pair<int, int> p : arr)
				{
					dist = min(dist, get(p, i, j));
				}
				res = max(res, dist);
			}
		}

		cout << res << endl;
	}
    return 0;
}

