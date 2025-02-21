// B.cpp: определяет точку входа для консольного приложения.
//

#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <random>
#include <chrono>

using namespace std;

vector<int> basic;
set<int> g[50];
int n, q;

ostream& operator<<(ostream &out, vector<int> arr)
{
	for (int i = 0; i < arr.size(); ++i)
	{
		out << arr[i] << " ";
	}
	out << endl;
	return out;
}

int main()
{
	cin >> n;

	for (int i = 1; i <= n; ++i)
	{
		basic.push_back(i);
	}

	cout << basic;
	cin >> q;
	int pos = 0;

	while (q != n)
	{
		bool did = 0;

		for (int i = 0; i < n; ++i)
		{
			if (i == pos)
			{
				continue;
			}

			vector<int> next = basic;
			bool flag = 0;

			if (pos < i)
			{
				for (int j = pos; j < i; ++j)
				{
					swap(next[j], next[j + 1]);
				}
			}
			else
			{
				for (int j = pos; j > i; --j)
				{
					swap(next[j], next[j - 1]);
				}
			}

			cout << next;
			int now;
			cin >> now;

			if (now == n)
			{
				return 0;
			}

			if (now > q)
			{
				q = now;
				basic = next;
				did = 1;
			}
		}

		if (!did)
		{
			++pos;
		}
	}
    return 0;
}

