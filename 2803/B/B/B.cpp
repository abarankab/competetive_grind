// B.cpp: определяет точку входа для консольного приложения.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <map>

using namespace std;

const int N = 1005;
int n;
int dp[N][N];
vector<int> gt[N][N];
vector<pair<int, int> > arr;
vector<pair<pair<int, int>, int> > tmp;
map<int, int> itoi;

int main()
{
	cin >> n;
	for (int i = 0; i < n; ++i)
	{
		int t, d;
		cin >> t >> d;
		arr.push_back({ d, t });
		tmp.push_back({ { d, t } , i });
	}

	sort(arr.begin(), arr.end());
	sort(tmp.begin(), tmp.end());

	for (int i = 0; i < n; ++i)
	{
		auto p = tmp[i];
		itoi[i] = p.second + 1;
	}

	memset(dp, -1, sizeof(dp));

	for (int i = 1; i < n; ++i)
	{
		for (int j = 1; i <= N; ++i)
		{

		}
	}
	return 0;
}

