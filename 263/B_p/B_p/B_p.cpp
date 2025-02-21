// B_p.cpp: определяет точку входа для консольного приложения.
//

#include <iostream>
#include <string>
#include <vector>

using namespace std;

int n, k;
vector<string> s;

int main()
{
	cin >> n;
	s.resize(n);
	for (int i = 0; i < n; ++i)
	{
		cin >> s[i];
	}
	int lst = 0;
	cin >> k;
	for (int i = 0; i < n; ++i)
	{
		int nxt;
		cin >> nxt;
		--nxt;
		if (nxt < lst)
		{
			if ((n - lst - 1) + nxt + 1 < lst - nxt)
			{
				cout << (n - lst - 1) + nxt + 1 << "\n";
				for (int j = 0; j < (n - lst - 1) + nxt + 1; ++j)
				{
					cout << "down\n";
				}
			}
			else
			{
				cout << lst - nxt << "\n";
				for (int j = 0; j < lst - nxt; ++j)
				{
					cout << "up\n";
				}
			}
		}
		else
		{
			swap(lst, nxt);
			if ((n - lst - 1) + nxt + 1 < lst - nxt)
			{
				cout << (n - lst - 1) + nxt + 1 << "\n";
				for (int j = 0; j < (n - lst - 1) + nxt + 1; ++j)
				{
					cout << "up\n";
				}
			}
			else
			{
				cout << lst - nxt << "\n";
				for (int j = 0; j < lst - nxt; ++j)
				{
					cout << "down\n";
				}
			}
			swap(lst, nxt);
		}
		lst = nxt;
	}
    return 0;
}

