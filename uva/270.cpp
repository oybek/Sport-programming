
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

bool f = true;
int test_n, x, y, a, b, c;

const int s_len_max = 256;
char s[ s_len_max ];

vector<pair<int, int> > p;

int main()
{
	scanf("%d", &test_n);

	while (getchar() != '\n');
	while (getchar() != '\n');

	while (test_n--)
	{
		p.resize(0);

		while (1)
		{
			if (fgets(s, s_len_max, stdin) == NULL || s[0] == '\n' || s[0] == '\0')
				break;

			sscanf(s, "%d %d", &x, &y);
			p.push_back(make_pair(x, y));
		}

		int max_on_line = 0, count;
		for (int i = 0; i < int(p.size()); ++i)
		{
			for (int j = i+1; j < int(p.size()); ++j)
			{
				count = 0;
				if (p[i].first == p[j].first)
				{
					a = 1;
					b = 0;
					c = -p[i].first;
				}
				else if (p[i].second == p[j].second)
				{
					a = 0;
					b = 1;
					c = -p[i].second;
				}
				else
				{
					a = p[i].second - p[j].second;
					b = p[j].first - p[i].first;
					c = p[i].first*p[j].second - p[j].first*p[i].second;
				}

				for (int k = 0; k < int(p.size()); ++k)
					count += (a * p[k].first + b * p[k].second + c == 0);

				max_on_line = max(count, max_on_line);
			}
		}

		if (f) f = false;
		else puts("");
		printf("%d\n", max_on_line);
	}

	return 0;
}

