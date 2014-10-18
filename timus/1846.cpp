
#include <map>
#include <cmath>
#include <vector>
#include <iostream>
using namespace std;

void factorize(int n, vector<int> & f)
{	if (n == 0)	return;

	int i, c, lim;
	for (c = n; c%2 == 0; c /= 2)
		f.push_back(2);

	lim = int(sqrt(c))+1;
	for (i = 3; i <= lim; )
	{	if (c%i == 0)
		{	f.push_back(i);
			c /= i;
			lim = int(sqrt(c))+1;
		}
		else i += 2;
	}

	if (c > 1) f.push_back(c);
}

int main()
{	int N;
	cin >> N;

	while (N--)
	{	char c;
		int n;

		cin >> c >> n;
		switch (c)
		{	case '+':
			break;

			case '-':
			break;
		}
	}

	return 0;
}

