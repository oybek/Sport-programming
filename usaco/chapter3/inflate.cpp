
/*
ID: aybek.h2
PROG: inflate
LANG: C++
*/

#define PROB_NAME "inflate"

#include <cmath>
#include <bitset>
#include <cstdio>
#include <vector>
#include <cassert>
#include <cstdlib>
#include <iostream>
#include <algorithm>
using namespace std;

int weight_lim, n;

struct fraction
{
	int n, d;

	bool operator < (const fraction & a) const
	{
		return n * a.d < a.n * d;
	}
};

vector<fraction> a;

void show_a()
{
	for (int i = 0; i < int(a.size()); ++i)
		cout << a[i].n << ' ' << a[i].d << endl;
}

int main()
{
#ifndef LOCAL
	freopen(PROB_NAME".in", "rt", stdin);
	freopen(PROB_NAME".out", "wt", stdout);
#endif

	cin >> weight_lim >> n;
	a.resize(n);
	for (int i = 0; i < n; ++i)
		cin >> a[i].n >> a[i].d;

	sort(a.rbegin(), a.rend());

	int ans = 0;
	for (int i = 0; i < n; ++i)
	{
		int times = weight_lim / a[i].d;
		if (times == 0)
			continue;

		weight_lim -= times * a[i].d;
		ans += times * a[i].n;
	}

	cout << ans << endl;

	return 0;
}

