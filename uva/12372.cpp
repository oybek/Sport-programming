
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
#define for_(t, i, a, b) for (t i = t(a); i != t(b); ++i)
#define rep_(n) for_(int, i_, 0, n)

int main()
{
	int n, a, b, c;
	scanf("%d", &n);
	for_(int, i, 1, n+1)
	{
		scanf("%d%d%d", &a, &b, &c);
		printf("Case %d: %s\n", i, (a > 20 || b > 20 || c > 20 ? "bad" : "good"));
	}

	return 0;
}

