// ioip3.cpp: определяет точку входа для консольного приложения.
//

#include <iostream>
#include <algorithm>

using namespace std;

#define int long long

const int INF = (int)1e18;
int n, m, mat[305][305];//, dpto[305][305], dpfrom[305][305];
int res = (int)1e18;

int get(int x, int y)
{
	int dpto[305][305];

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			if (i == x && y == j)
			{
				dpto[i][j] = -INF;
			}
			else
			{
				if (i == 0 && j == 0)
				{
					dpto[i][j] = mat[i][j];
				}
				else if (i == 0)
				{
					dpto[i][j] = mat[i][j] + dpto[i][j - 1];
				}
				else if (j == 0)
				{
					dpto[i][j] = mat[i][j] + dpto[i - 1][j];
				}
				else
				{
					dpto[i][j] = max(mat[i][j] + dpto[i][j - 1], mat[i][j] + dpto[i - 1][j]);
				}
			}
		}
	}

	return dpto[n - 1][m - 1];
}

signed main()
{
	cin >> n >> m;
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			cin >> mat[i][j];
		}
	}

	for (int x = 0; x < n; ++x)
	{
		for (int y = 0; y < m; ++y)
		{
			if (!(x == 0 && y == 0) && !(x == n - 1 && y == m - 1))
			{
				res = min(res, get(x, y));
			}
		}
	}

	/*for (int i = n - 1; i >= 0; --i)
	{
		for (int j = m - 1; j >= 0; --j)
		{
			if (i == n - 1 && j == m - 1)
			{
				dpto[i][j] = mat[i][j];
			}
			else if (i == n - 1)
			{
				dpto[i][j] = mat[i][j] + dpto[i][j + 1];
			}
			else if (j == m - 1)
			{
				dpto[i][j] = mat[i][j] + dpto[i + 1][j];
			}
			else
			{
				dpto[i][j] = max(mat[i][j] + dpto[i][j + 1], mat[i][j] + dpto[i + 1][j]);
			}
		}
	}

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			int tmp = -1;
			if (i != 0 && j != 0)
			{
				for (int k = i + 1; k < n; ++k)
				{
					tmp = max(tmp, dpto[k][j - 1] + dpfrom[k][j]);
				}
				for (int k = j + 1; k < m; ++k)
				{
					tmp = max(tmp, dpto[i - 1][k] + dpfrom[i][k]);
				}
			}
			else if (i != 0)
			{
				for (int k = j + 1; k < m; ++k)
				{
					tmp = max(tmp, dpto[i - 1][k] + dpfrom[i][k]);
				}
			}
			else if (j != 0)
			{
				for (int k = i + 1; k < n; ++k)
				{
					tmp = max(tmp, dpto[k][j - 1] + dpfrom[k][j]);
				}
			}

			if (tmp != -1)
			{
				res = max(res, tmp);
			}
		}
	}*/

	cout << res << endl;
    return 0;
}

