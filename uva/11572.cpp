
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
	int test_n, n, t, count;
	set<int> was;

	scanf("%d", &test_n);

	while (test_n--)
	{
		scanf("%d", &n);

		was.clear();

		count = 0;

		while (n--)
		{
			scanf("%d", &t);

			if (was.find(t) == was.end())
			{
				++count;
				was.insert(t);
			}
		}

		printf("%d\n", count);
	}

	return 0;
}

