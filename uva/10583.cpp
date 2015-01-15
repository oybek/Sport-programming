
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

#define INF INT_MAX-1

/*
 * Given:
 * n m
 * n - number of students
 * m - number of pairs of student you asked
 * m lines with pairs, each line indicate two students
 * that stubscribes same religion
 *
 * Find:
 * N - max. number of different religion in campus
 *
 * Solution:
 *
 */

#define n_MAX 50001

/* Union find disjoint set data-structure */
int parent[ n_MAX ];
int parent_of(int x) { return (parent[x] == x ? x : parent[x] = parent_of(parent[x])); }
void union_set(int x, int y) { parent[parent_of(x)] = parent_of(y); }

int solve()
{
	int i, n, m, x, y, N;
	cin >> n >> m;

	/* terminate a program */
	if (!n && !m) { exit(0); }

	for (i = 1; i <= n; ++i)
		parent[i] = i;

	while (m--)
	{
		cin >> x >> y;
		union_set(x, y);
	}

	/* count N - number of religions */
	N = 0;
	for (i = 1; i <= n; ++i)
	{
		if (parent[i] == i)
			++N;
	}

	return N;
}

int main()
{
	int test_i;
	for (test_i = 1; true; ++test_i)
	{
		cout << "Case " << test_i << ": " << solve() << endl;
	}

	return 0;
}

