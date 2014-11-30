
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

void remove_trailing_blanks(char * s)
{
	while (*s != '\0') ++s;
	while (isblank(*s)) --s;
	*++s = '\0';
}

#define MAX_V_NUM 2048

bitset<MAX_V_NUM> was;
vector<vector<int> > g;

void bfs(int n, int ttl)
{
	queue<pair<int, int> > q;

	was.reset();

	if (!was[n] && ttl > 0)
	{
		q.push(make_pair(n, ttl));
	}
	was[n] = true;

	while (! q.empty())
	{
		pair<int, int> cur = q.front(); q.pop();

		if (cur.second <= 0)
			continue;

		for (int i = 0; i < int(g[ cur.first ].size()); ++i)
			if (! was[ g[ cur.first ][i] ])
			{
				was[ g[ cur.first ][i] ] = true;
				q.push(make_pair(g[ cur.first ][i], cur.second-1));
			}
	}
}

int main()
{
	int NC, tt = 1;
	while (1)
	{
		map<int, int> imap;

		scanf("%d", &NC);
		if (!NC)
			break;


		g.resize(0);
		imap.clear();


		while (NC--)
		{
			int a, b;

			scanf("%d%d", &a, &b);

			if (imap.find(a) != imap.end())
			{
				if (imap.find(b) != imap.end())
				{
				}
				else
				{
					imap[ b ] = g.size();
					g.resize(g.size()+1);
				}
			}
			else
			{
				if (imap.find(b) != imap.end())
				{
					imap[ a ] = g.size();
					g.resize(g.size()+1);
				}
				else
				{
					imap[ b ] = g.size();
					g.resize(g.size()+1);

					imap[ a ] = g.size();
					g.resize(g.size()+1);
				}
			}

			g[ imap[a] ].push_back( imap[b] );
			g[ imap[b] ].push_back( imap[a] );
		}

		while (1)
		{
			int n, ttl;

			scanf("%d%d", &n, &ttl);
			if (!n && !ttl)
				break;

			n = imap[ n ];

			bfs(n, ttl);

			printf("Case %d: %d nodes not reachable from node %d with TTL = %d.\n",
					tt++, int(g.size() - was.count()), n, ttl);
		}
	}

	return 0;
}

