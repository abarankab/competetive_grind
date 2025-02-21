// A.cpp: определяет точку входа для консольного приложения.
//

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int k, n, cnt;
string s;
vector<string> t;

bool cmp(string a, string b)
{
	return a[0] < b[0];
}

int main()
{
	cin >> k >> n >> s;
	t.resize(n);
	while (t[0].size() != n)
	{
		for (int i = 0; i < s.size(); ++i)
		{
			t[i] = s[i] + t[i];
		}
		stable_sort(t.begin(), t.end(), cmp);
	}
	cout << t[k - 1];
	return 0;
}

