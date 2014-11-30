
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

void get_divs(int n, vector<int> & d)
{
	for (int i = 1; i*i <= n; ++i)
	{
		if (n%i == 0)
		{
			d.push_back(i);
			if (n != i*i)
				d.push_back(n/i);
		}
	}
}

int main()
{
	int test_n, c, r;
	vector<int> d;
	d.reserve(1024);

	scanf("%d", &test_n);
	for (int test_i = 1; test_i <= test_n; ++test_i)
	{
		scanf("%d%d", &c, &r);

		printf("Case #%d:", test_i);
		if (c == r)
		{
			printf(" 0");
			continue;
		}

		d.resize(0);
		get_divs(c-r, d);
		sort(d.begin(), d.end());

		int i = 0;
		while
		(
			(i < int(d.size())) &&
			(d[i] <= r)
		)
			++i;

		while (i < int(d.size()))
		{
			printf(" %d", d[i]);
			++i;
		}
		puts("");
	}

	return 0;
}

