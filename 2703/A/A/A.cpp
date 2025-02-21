// A.cpp: определяет точку входа для консольного приложения.
//

#include <iostream>
#include <vector>

using namespace std;

#define int long long

int n, m;
vector<pair<int, int> > arr;

signed main()
{
	cin >> n >> m;
	for (int i = 0; i < m; ++i)
	{
		int a, b;
		cin >> a >> b;
		while (!arr.empty() && a - arr.back().first < arr.back().second)
		{
			arr.back().second += b;
			a = arr.back().first;
			b = arr.back().second;
			arr.pop_back();
		}
		arr.push_back({ a, b });
	}
	cout << arr.back().first + arr.back().second - 1 << endl;
    return 0;
}

