// A.cpp: определяет точку входа для консольного приложения.
//

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

#define int long long
int n, q, f;
queue<int> order;
vector<pair<int, int> > matches;
vector<int> after;

signed main()
{
	cin >> n;
	cin >> f;
	for (int i = 1; i < n; ++i)
	{
		int power;
		cin >> power;
		order.push(power);
	}

	for (int i = 0; i < n; ++i)
	{
		matches.push_back({ f, order.front() });
		if (order.front() < f)
		{
			order.push(order.front());
			order.pop();
		}
		else
		{
			order.push(f);
			f = order.front();
			order.pop();
		}
	}

	while (!order.empty())
	{
		after.push_back(order.front());
		order.pop();
	}

	cin >> q;
	for (int i = 0; i < q; ++i)
	{
		int to;
		cin >> to;
		if (to <= n)
		{
			cout << matches[to - 1].first << " " << matches[to - 1].second << endl;
		}
		else
		{
			cout << f << " " << after[(to - n - 1) % (after.size())] << endl;
		}
	}
    return 0;
}

