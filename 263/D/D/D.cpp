// D.cpp: определяет точку входа для консольного приложения.
//

#include <iostream>
#include <vector>
#include <string>

using namespace std;

int arr[400][400];
int sum[400][400];

int get(int x1, int y1, int x2, int y2)
{
	return sum[x2][y2] - sum[x1][y2] - sum[x2][y1] + sum[x1][y1];
}

int main()
{
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; ++i)
	{
		string s;
		cin >> s;
		for (int j = 0; j < m; ++j)
		{
			arr[i][j] = s[j];
		}

		for (int j = 0; j < m; ++j)
		{
			if (i == 0 && j == 0)
			{
				sum[i][j] = arr[i][j];
			}
			else if (i == 0)
			{
				sum[i][j] = sum[i][j - 1] + arr[i][j];
			}
			else if (j == 0)
			{
				sum[i][j] = sum[i - 1][j] + arr[i][j];
			}
			else
			{
				sum[i][j] = sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1] + arr[i][j];
			}
		}
	}

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			for (int i1 = i; i1 < n; ++i1)
			{
				for (int j1 = j; j1 < m; ++j1)
				{
					if (get(i, j, i1, j1) == 0)
					{

					}
				}
			}
		}
	}

    return 0;
}

