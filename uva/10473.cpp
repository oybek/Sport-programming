
#include <set>
#include <map>
#include <queue>
#include <cmath>
#include <bitset>
#include <cstdio>
#include <string>
#include <vector>
#include <cstring>
#include <climits>
#include <iostream>
#include <algorithm>

using namespace std;

typedef string::iterator si;

#define INF INT_MAX-1

#define FOR(t, i, a, b) for (t i = t(a); i != t(b); ++i)

int main()
{
	int n;
	string s;

	while (1)
	{
		cin >> s;

		if (s[0] == '-')
			break;

		if (s.size() > 1 && s[1] == 'x')
		{
			sscanf(s.c_str(), "%x", &n);
			printf("%d\n", n);
		}
		else
		{
			sscanf(s.c_str(), "%d", &n);
			printf("0x%X\n", n);
		}
	}

	return 0;
}

