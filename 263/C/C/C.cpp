// C.cpp: определяет точку входа для консольного приложения.
//

#include <iostream>
#include <vector>
#include <string>

using namespace std;

int k, w, h, wn, hn;

vector<vector<bool> > p1, p2, mod;

int main()
{
	cin >> k;

	cin >> h >> w;
	wn = w;
	hn = h;
	p2.resize(h, vector<bool>(w));
	for (int i = 0; i < h; ++i)
	{
		string s;
		cin >> s;
		for (int j = 0; j < w; ++j)
		{
			char now = s[j];
			p2[i][j] = (now == 'X');
		}
	}

	cin >> h >> w;
	p1.resize(h, vector<bool>(w));
	mod.resize(k * h, vector<bool>(k * w));

	for (int i = 0; i < h; ++i)
	{
		string s;
		cin >> s;
		for (int j = 0; j < w; ++j)
		{
			char now = s[j];
			p1[i][j] = (now == 'X');
			for (int x = 0; x < k; ++x)
			{
				for (int y = 0; y < k; ++y)
				{
					mod[k * i + x][k * j + y] = p1[i][j];
				}
			}
		}
	}

	int res = 0;
	for (int i = 0; i < k * h; ++i)
	{
		for (int j = 0; j < k * w; ++j)
		{
			if (i + hn - 1 < k * h && j + wn - 1 < k * w)
			{
				bool flag = 1;
				for (int x = 0; x < hn; ++x)
				{
					if (!flag)
					{
						break;
					}

					for (int y = 0; y < wn; ++y)
					{
						if (p2[x][y] && !mod[i + x][j + y])
						{
							flag = 0;
							break;
						}
					}
				}

				if (flag)
				{
					++res;
				}
			}
		}
	}
	cout << res << endl;
    return 0;
}

