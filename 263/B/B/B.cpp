// B.cpp: определяет точку входа для консольного приложения.
//

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int n, k, dp[1005][1005];
vector<string> arr;
string res[1005][1005], dp2[1005][1005];
bool used[1005][1005];

int main()
{
	string MAXS = "";
	for (int i = 0; i < 20; ++i)
	{
		MAXS = MAXS + "aaaaaaaaaa";
	}
	cin >> n;
	for (int i = 0; i < n; ++i)
	{
		string s;
		cin >> s;
		arr.push_back(s);
	}

	for (int i = 0; i < n; ++i)
	{
		dp2[i][i] = ".";
		dp2[i][i] += arr[i][0];
		for (int j = i - 1; j >= 0; --j)
		{
			dp2[i][j] = dp2[i][j + 1];
			if ((int)arr[j].size() < (int)arr[i].size() && arr[i].substr(0, arr[j].size()) == arr[j])
			{
				dp2[i][j] = MAXS;
			}

			int cnt = dp2[i][j].size();

			while (cnt < arr[j].size() && cnt < arr[i].size() && arr[j].substr(0, cnt) == arr[i].substr(0, cnt) && arr[j] < arr[i])
			{
				dp2[i][j] = dp2[i][j] +  "." + arr[i][cnt];
				++cnt;
			}
		}
		for (int j = n - 1; j > i; --j)
		{
			if (j == n - 1)
			{
				dp2[i][j] = dp2[i][0];
			}
			else
			{
				dp2[i][j] = dp2[i][j + 1];
			}

			if (arr[j].size() < arr[i].size() && arr[i].substr(0, arr[j].size()) == arr[j])
			{
				dp2[i][j] = MAXS;
			}

			int cnt = dp2[i][j].size();

			while (cnt < arr[j].size() && cnt < arr[i].size() && arr[j].substr(0, cnt) == arr[i].substr(0, cnt) && arr[j] < arr[i])
			{
				dp2[i][j] = dp2[i][j] +  "." + arr[i][cnt];
				++cnt;
			}
		}
	}

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			if (!used[i][j])
			{
				swap(dp2[i][j], dp2[j][i]);
				used[i][j] = used[j][i] = 1;
			}
		}
	}

	for (int i = 0; i < n; ++i)
	{
		dp[i][i] = 0;
		res[0][0] = "";
		for (int j = i + 1; j < n; ++j)
		{
			dp[i][j] = dp[i][j - 1] + 1;
			res[i][j] = res[i][j - 1] + ".down";

			for (int m = i; m < j; ++m)
			{
				//TODO
				if (dp[i][m] + (dp2[m][j].size() / 2) + 1 < dp[i][j])
				{
					res[i][j] = res[i][m] + dp2[m][j];
					dp[i][j] = dp[i][m] + (dp2[m][j].size() / 2) + 1;
				}
			}
		}
		for (int j = 0; j < i; ++j)
		{
			if (j == 0)
			{
				dp[i][j] = dp[i][n - 1] + 1;
				res[i][j] = res[i][n - 1] + ".down";
			}
			else
			{
				dp[i][j] = dp[i][j - 1] + 1;
				res[i][j] = res[i][j - 1] + ".down";
			}

			for (int m = i; m < n; ++m)
			{
				//TODO
				if (dp[i][m] + (dp2[m][j].size() / 2) + 1 < dp[i][j])
				{
					res[i][j] = res[i][m] + dp2[m][j];
					dp[i][j] = dp[i][m] + (dp2[m][j].size() / 2) + 1;
				}
			}

			for (int m = 0; m < j; ++m)
			{
				//TODO
				if (dp[i][m] + (dp2[m][j].size() / 2) + 1 < dp[i][j])
				{
					res[i][j] = res[i][m] + dp2[m][j];
					dp[i][j] = dp[i][m] + (dp2[m][j].size() / 2) + 1;
				}
			}
		}

		//UP
		for (int j = i - 1; j >= 0; --j)
		{
			if (dp[i][j + 1] + 1 < dp[i][j])
			{
				dp[i][j] = dp[i][j + 1] + 1;
				res[i][j] = res[i][j + 1] + ".up";
			}

			for (int m = i; m > j; --m)
			{
				//TODO
				if (dp[i][m] + (dp2[m][j].size() / 2) + 1 < dp[i][j])
				{
					res[i][j] = res[i][m] + dp2[m][j];
					dp[i][j] = dp[i][m] + (dp2[m][j].size() / 2) + 1;
				}
			}
		}
		for (int j = n - 1; j > i; --j)
		{
			if (j == n - 1)
			{
				if (dp[i][0] + 1 < dp[i][j])
				{
					dp[i][j] = dp[i][0] + 1;
					res[i][j] = res[i][0] + ".up";
				}
			}
			else
			{
				if (dp[i][j + 1] + 1 < dp[i][j])
				{
					dp[i][j] = dp[i][j + 1] + 1;
					res[i][j] = res[i][j + 1] + ".up";
				}
			}

			for (int m = i; m >= 0; --m)
			{
				//TODO
				if (dp[i][m] + (dp2[m][j].size() / 2) + 1 < dp[i][j])
				{
					res[i][j] = res[i][m] + dp2[m][j];
					dp[i][j] = dp[i][m] + (dp2[m][j].size() / 2) + 1;
				}
			}

			for (int m = n - 1; m > j; --m)
			{
				//TODO
				if (dp[i][m] + (dp2[m][j].size() / 2) + 1 < dp[i][j])
				{
					res[i][j] = res[i][m] + dp2[m][j];
					dp[i][j] = dp[i][m] + (dp2[m][j].size() / 2) + 1;
				}
			}
		}
	}

	cin >> k;
	int lst = 0;
	for (int i = 0; i < k; ++i)
	{
		int nxt;
		cin >> nxt;
		--nxt;
		cout << dp[lst][nxt] << "\n";
		string to = res[lst][nxt];
		if (to[0] == '.')
		{
			to = to.substr(1, to.size() - 1) + ".";
		}
		string now = "";
		for (int j = 0; j < to.size(); ++j)
		{
			if (to[j] == '.')
			{
				if (now != "up" && now != "down")
				{
					cout << "Alt\n" + now + "\n";
					now = "";
				}
				else
				{
					cout << now << "\n";
				}
			}
			else
			{
				now = now + to[j];
			}
		}
		lst = nxt;
	}
    return 0;
}

