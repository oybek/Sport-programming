
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

int side_len;
vector<int> a;

bool backtrack(int i, int s1, int s2, int s3, int s4)
{
	if (i == int(a.size()))
	{
		return	(s1 == s2) &&
				(s2 == s3) &&
				(s3 == s4);
	}

	if (s1 > side_len ||
		s2 > side_len ||
		s3 > side_len ||
		s4 > side_len)
		return	false;

	if (backtrack(i+1, s1+a[i], s2, s3, s4)) return true;
	if (backtrack(i+1, s1, s2+a[i], s3, s4)) return true;
	if (backtrack(i+1, s1, s2, s3+a[i], s4)) return true;
	if (backtrack(i+1, s1, s2, s3, s4+a[i])) return true;
	return	false;
}

int main()
{
	int test_n, size, t, sum;

	scanf("%d", &test_n);
	while (test_n--)
	{
		sum = 0;
		a.resize(0);

		scanf("%d", &size);
		while (size--)
		{
			scanf("%d", &t);
			sum += t;
			a.push_back(t);
		}

		sort(a.rbegin(), a.rend());

		if
		(
			(sum%4) ||
			(a[0]*4 > sum)
		)
		{
			printf("no\n");
			continue;
		}

		side_len = sum / 4;
		puts( backtrack(0, 0, 0, 0, 0) ? "yes" : "no" );
	}

	return 0;
}

#if 0
void sub_sums(const vector<int> & a, vector<int> & b, int sum)
{
	int size = a.size();

	for (int i = 0; i < (1<<size); ++i)
	{
		int s = 0;
		for (int j = 0; j < size; ++j)
			if (i&(1<<j))
				s += a[j];

		if (s == sum)
		{
			b.push_back(i);
		}
	}
}

int main()
{
	int tt, size;
	vector<int> a,
				sub_sets;

	scanf("%d", &tt);
	while (tt--)
	{
		int sum = 0;
		a.resize(0);
		sub_sets.resize(0);

		scanf("%d", &size);
		while (size--)
		{
			int t;
			scanf("%d", &t);
			sum += t;
			a.push_back(t);
		}

		if (sum%4)
		{
			printf("no\n");
			continue;
		}

		sum /= 4;
		sub_sums(a, sub_sets, sum);
		printf("%d\n", int(sub_sets.size()));
	}

	return 0;
}

#endif
