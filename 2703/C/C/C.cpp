// C.cpp: определяет точку входа для консольного приложения.
//

#include <iostream>
#include <vector>
#include <map>

using namespace std;

const int N = 100005;
int n, m, k;
vector<int> g[N];
vector<int> check[N]; //1 - towards 2 - opposite
map<pair<int, int>, vector<int> > mp;

int main()
{
	cin >> n >> m;
	for (int i = 0; i < n; ++i)
	{
		int a, b;
		cin >> a >> b;
		g[--a].push_back(--b);
		g[b].push_back(a);
		check[a].push_back(0);
		check[b].push_back(0);
	}
	cin >> k;
	for (int i = 0; i < k; ++i)
	{
		int tmp;
		bool b1 = 0, b2 = 0;
		vector<int> path;
		while (1)
		{
			cin >> tmp;
			--tmp;
			if (tmp == -1)
			{
				break;
			}

			path.push_back(tmp);
		}

		int last = path[0];

		for (int j = 1; j < path.size(); ++j)
		{
			int now = path[j];

			if (!mp.count({ last, now }))
			{
				mp[{ last, now }] = vector<int>(1, i);
			}
			else
			{
				mp[{ last, now }].push_back(i);
			}

			last = now;
		}
	}
    return 0;
}


/*
int last = path[0];
for (int j = 1; j < path.size(); ++j)
{
int now = path[j];
if (path[j] == 1)
{
b1 = 1;
}
else if (path[j] == 2)
{
b2 = 1;
}
}

if (b1 ^ b2)
{
if (b1)
{
color(1, path);
}
else
{
color(2, path);
}
}
else if (b1 && b2)
{
cout << "NO\n";
return 0;
}
else
{

}
*/