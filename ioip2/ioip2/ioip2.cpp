// ioip2.cpp: определяет точку входа для консольного приложения.
//

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

#define int long long


int r1, r2;
vector<int> arr;
vector<int> len;
int res = -1;

void gen(int now = 0)
{
	if (now == 4)
	{
		vector<int> cnt(4);
		vector<int> q(4);
		for (auto x : arr)
		{
			++cnt[x];
			++q[x];
		}
		sort(cnt.begin(), cnt.end());
		reverse(cnt.begin(), cnt.end());
		if (cnt[0] == 1)
		{
			vector<int> asd = len;
			sort(asd.begin(), asd.end());
			if (res < asd[0] * asd[1])
			{
				r1 = asd[0];
				r2 = asd[1];
				res = asd[0] * asd[1];
			}
			if (res < asd[0] * asd[2])
			{
				r1 = asd[0];
				r2 = asd[2];
				res = asd[0] * asd[2];
			}
		}
		else if (cnt[0] == 2 && cnt[1] == 1)
		{
			int a, b = -1, c;
			for (int i = 0; i < 4; ++i)
			{
				if (q[i] == 2)
				{
					a = len[i];
				}
				if (q[i] == 1 && b == -1)
				{
					b = len[i];
				}
				else if (q[i] == 1)
				{
					c = len[i];
				}
			}
			if (res < (a / 2) * min(c, b))
			{
				r1 = a / 2;
				r2 = min(c, b);
				res = max(res, a / 2 * min(c, b)); //TODO
			}
			if (a >= b + c && res < b * c)
			{
				r1 = b;
				r2 = c;
				res = b * c;
			}
			if (b >= a / 2 && c >= a / 2 && res < a / 2 * (a / 2))
			{
				r1 = a / 2;
				r2 = a / 2;
				res = a / 2 * (a / 2);
			}
		}
		else if (cnt[0] == 2)
		{
			int a = -1, b;
			for (int i = 0; i < 4; ++i)
			{
				if (q[i] == 2 && a == -1)
				{
					a = len[i];
				}
				else if (q[i] == 2)
				{
					b = len[i];
				}
			}
			if (res < (int)pow(min(a, b) / 2, 2))
			{
				r1 = min(a, b) / 2;
				r2 = r1;
				res = max(res, (int)pow(min(a, b) / 2, 2));
			}
			if (res < (int)(a / 2) * (b / 2))
			{
				r1 = (a / 2);
				r2 = (b / 2);
				res = max(res, (int)(a / 2) * (b / 2));
			}
		}
		else if (cnt[0] == 3)
		{
			int a, b;
			for (int i = 0; i < 4; ++i)
			{
				if (q[i] == 3)
				{
					a = len[i];
				}
				if (q[i] == 1)
				{
					b = len[i];
				}
			}
			a -= b;
			a /= 2;
			if (res < b * a)
			{
				r1 = b;
				r2 = a;
				res = max(res, b * a);
			}
		}
		else if (cnt[0] == 4)
		{
			if (res < (int)pow(len[arr[0]] / 4, 2))
			{
				r1 = len[arr[0]] / 4;
				r2 = r1;
				res = max(res, (int)pow(len[arr[0]] / 4, 2));
			}
		}
	}
	else
	{
		for (int i = 0; i < 4; ++i)
		{
			arr.push_back(i);
			gen(now + 1);
			arr.pop_back();
		}
	}
}

signed main()
{
	int x, y, z, d;
	cin >> x >> y >> z >> d;
	len.push_back(x);
	len.push_back(y);
	len.push_back(z);
	len.push_back(d);
	gen();
	cout << r1 << " " << r2 << endl;
    return 0;
}

