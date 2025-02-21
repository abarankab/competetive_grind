// A.cpp: определяет точку входа для консольного приложения.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <fstream>

using namespace std;

struct event
{
	int x, type, ind;

	event() {}

	event(int _x, int _type, int _ind)
	{
		x = _x;
		type = _type;
		ind = _ind;
	}
};

bool operator<(event a, event b)
{
	return a.x < b.x;
}

const int N = (int)1e5 + 5;
int n, res;
vector<int> arr;
int f[N], l[N];
vector<pair<int, int> > q;
vector<event> ev;
set<pair<int, int> > st;
int r[N];

int main()
{
	ifstream cin("input.txt");
	ofstream cout("output.txt");

	cin >> n;
	arr.resize(n);
	for (int i = 1; i <= n; ++i)
	{
		f[i] = N;
		l[i] = -1;
	}
	for (int i = 0; i < n; ++i)
	{
		cin >> arr[i];
		f[arr[i]] = min(f[arr[i]], i);
		l[arr[i]] = max(l[arr[i]], i);
	}
	for (int i = 1; i <= n; ++i)
	{
		if (l[i] != -1)
		{
			q.push_back({ l[i], f[i] });
		}
	}
	sort(q.begin(), q.end());
	int maxr = -1;
	for (pair<int, int> p : q)
	{
		swap(p.first, p.second);
		if (p.first > maxr)
		{
			maxr = p.second;
		}
		else
		{
			++res;
		}
	}
	cout << res << endl;
    return 0;
}

