
#include <cmath>
#include <bitset>
#include <vector>
#include <cstdio>
#include <cassert>
#include <iostream>
#include <algorithm>
using namespace std;

#define MAX_SZ 1000000

int main()
{
	bitset<MAX_SZ> pp; pp.reset();

	vector<int> a, d, p;
	int t;

	while (scanf("%d", &t) != EOF)
		a.push_back(t);

	int size = a.size();
	d.resize(size);
	p.resize(size);

	for (int i = 0; i < size; ++i)
	{
		d[i] = 1;
		for (int j = 0; j < i; ++j)
			if (a[j] < a[i])
				if (d[i] < d[j]+1)
				{
					d[i] = d[j]+1;
					p[i] = j;
					pp[i] = 1;
				}
	}

	int i = 0;
	for (int j = 1; j < size; ++j)
		if (d[j] > d[ i ])
			i = j;

	vector<int> ans;

	printf("%d\n-\n", d[ i ]);
	while (pp[i])
	{
		ans.push_back(a[i]);
		i = p[i];
	}
	ans.push_back(a[i]);
	reverse(ans.begin(), ans.end());
	for (int i = 0; i < int(ans.size()); ++i)
		printf("%d\n", ans[i]);

	return 0;
}

