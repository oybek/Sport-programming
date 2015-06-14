
#include <set>
#include <map>
#include <list>
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

void remove_trailing_blanks(char * s)
{
	while (*s != '\0') ++s;
	while (isblank(*s)) --s;
	*++s = '\0';
}

void get_ints(const char * s, vector<int> & v)
{
	v.resize(0);
	int t;
	while (sscanf(s, "%d", &t) != EOF)
	{
		v.push_back(t);
		while (*s && !isdigit(*s)) ++s;
		while (isdigit(*s)) ++s;
	}
}

#define MAX_N 100

int N;
vector<vector<int> > g;
bitset<MAX_N> was;

void dfs(int cur)
{
	if (was[cur]) return;

	was[cur] = true;

	for (int i = 0; i < int(g[cur].size()); ++i)
		dfs(g[cur][i]);
}

bool is_critical(int cur)
{
	was.reset();
	was[ cur ] = 1;
	dfs(((cur == 1) ? N : cur-1));
	for (int i = 1; i <= N; ++i)
		if (!was[i])
			return 1;
	return 0;
}

int main()
{
	g.reserve(101);

	while (scanf("%d", &N) != EOF)
	{
		while (getchar() != '\n');

		const int s_max_sz = 256;
		char s[ s_max_sz ];

		vector<int> v;

		if (!N) break;

		g.resize(N+1);
		for (int i = 1; i <= N; ++i)
			g[i].resize(0);

		while (1)
		{
			fgets(s, s_max_sz, stdin);

			get_ints(s, v);

			if (!v[0])
				break;

			for (int i = 1; i < int(v.size()); ++i)
			{
				g[ v[0] ].push_back(v[i]);
				g[ v[i] ].push_back(v[0]);
			}
		}

		int ans = 0;
		for (int i = 1; i <= N; ++i)
		{
			ans += is_critical(i);
		}

		printf("%d\n", ans);
	}

	return 0;
}

