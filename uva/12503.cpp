
#include <string>
#include <cstdio>
#include <iostream>
using namespace std;

#define SIZE 101

int history[ SIZE ];
char get_history(int i)
{
	if (history[i] == -1) return 'L';
	if (history[i] == -2) return 'R';
	return get_history(history[i]);
}

int main()
{
	int tt;
	cin >> tt;

	while (tt--)
	{
		int n, label, p = 0;
		cin >> n;

		string s;
		for (int i = 1; i <= n; ++i)
		{
			cin >> s;
			switch (s[0])
			{
				case 'L':
					history[i] = -1;
					--p;
					break;

				case 'R':
					history[i] = -2;
					++p;
					break;

				case 'S':
					cin >> s >> label;
					history[i] = label;
					switch (get_history(label))
					{
						case 'L': --p; break;
						case 'R': ++p; break;
					}
			}
		}
		cout << p << endl;
	}

	return 0;
}

