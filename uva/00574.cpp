
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
#include <unordered_set>

using namespace std;

typedef string::iterator si;

#define INF INT_MAX-1
#define for_(t, i, a, b) for (t i = t(a); i != t(b); ++i)
#define rep_(n) for_(int, i_, 0, n)

set<string> sol;

const int max_n = 12;
int t, n, a[ max_n ];

void backtrack(string s, int sum, int i)
{
	if (sum > t) return;

	if (i == n || sum == t) {
		if (sum == t && sol.find(s) == sol.end()) {
			sol.insert(s);
			printf("%s\n", s.c_str());
		}
		return;
	}

	backtrack(s+(s.size() ? "+": "")+to_string(a[i]), sum+a[i], i+1);
	backtrack(s, sum, i+1);
}

int main()
{
	while (1)
	{
		sol.clear();

		scanf("%d%d", &t, &n);
		if (!t && !n) break;
		for_(int, i, 0, n) {
			scanf("%d", a+i);
		}

		printf("Sums of %d:\n", t);
		backtrack("", 0, 0);

		if (sol.size() == 0)
			printf("NONE\n");
	}

	return 0;
}

