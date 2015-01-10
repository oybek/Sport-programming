
#include <string>
#include <sstream>
#include <iostream>
using namespace std;

#define a_size 101

int n,
		a[ a_size ][ a_size ];

string s;
stringstream ss;

void clear(int n)
{
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= n; ++j)
			a[i][j] = 1;
}

int main()
{
	while(1)
	{
		cin >> n;
		for (int i = 0; i < n; ++i)
		{
			getline(cin, s);
			ss.clear();
			ss = s;

			int count;
			for (count = n; count; --count)
			{
				int x, y;
				ss >> x >> y;
				if (ss.eof())
					break;
			}

			if (count > 0)
			{
				//wrong
			}
			else
			{
			}
		}
	}

	return 0;
}

