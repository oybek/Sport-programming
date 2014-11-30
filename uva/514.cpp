
#include <set>
#include <map>
#include <queue>
#include <cmath>
#include <stack>
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
	int n,
		a[ 1001 ];
	stack<int> st;

	while (1)
	{
		while (! st.empty()) st.pop();

		scanf("%d", &n);
		if (!n)
			break;

		for (int i = 0; i < n; ++i)
		{
			scanf("%d", a+i);
		}

		int cur = 1;
		bool yes = true;
		for (int i = 0; i < n; ++i)
		{
			while (st.size() == 0 || st.top() != a[i])
			{
				st.push(cur);

				if (++cur > n)
				{
					yes = false;
					break;
				}
			}

			st.pop();
		}
	}

	return 0;
}

