
#include <vector>
#include <cstdio>
#include <iostream>
using namespace std;

typedef long long int64;

void vector_sub(vector<int64> & a, int mask)
{
	vector<int64> tmp;
	for (int i = 0; i < int(a.size()); ++i)
		if ( !(mask & (1<<i)) )
			tmp.push_back(a[i]);
	a = tmp;
}

int main()
{
	int test_n;
	vector<int64> a;

	scanf("%d", &test_n);
	while (test_n--)
	{
		int n, k;

		scanf("%d%d", &n, &k);
		a.resize(0);
		for (int i = 0; i < n; ++i)
		{
			int64 t;
			scanf("%lld", &t);
			a.push_back(t);
		}

		int64 s = 0;
		for (int i = 0; i < int(a.size()); ++i)
			s += a[i];

		if (s%k)
		{
			puts("no");
			continue;
		}

		s /= k;

		for (; k; --k)
		{
			bool f = false;
			for (int mask = 0; mask < (1<<a.size()); ++mask)
			{
				int64 sub_s = 0;
				for (int i = 0; i < int(a.size()); ++i)
					if ( mask & (1<<i) )
						sub_s += a[i];

				if ( sub_s == s )
				{
					f = true;
					vector_sub(a, mask);
					break;
				}
			}
			if (!f) break;
		}

		puts( !k ? "yes" : "no" );
	}

	return 0;
}

