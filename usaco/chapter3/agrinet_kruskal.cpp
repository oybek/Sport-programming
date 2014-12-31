
/*
ID: aybek.h2
PROG: agrinet
LANG: C++
*/

#define PROB_NAME "agrinet"

#include <cmath>
#include <bitset>
#include <cstdio>
#include <vector>
#include <cassert>
#include <cstdlib>
#include <iostream>
#include <algorithm>
using namespace std;

#define N_MAX 101

struct edge
{
	int w, a, b;

	edge(int aa, int ba, int wa)
		: w(wa)
		, a(aa)
		, b(ba)
	{}

	bool operator < (const edge & a) const
	{
		return w < a.w;
	}
};

// union find disjoint sets
struct ufd_sets
{
	private:
		vector<int> s;

	public:
		ufd_sets(int size)
		{
			s.resize(size);
			for (int i = 0; i < size; ++i)
				s[i] = i;
		}

		int find_set(int i)
		{
			return (s[i] == i) ? i : (s[i] = find_set(s[i]));
		}

		void union_set(int i, int j)
		{
			s[ find_set(i) ] = find_set(j);
		}

		bool in_same_set(int i, int j)
		{
			return find_set(i) == find_set(j);
		}
};

int N;
ufd_sets S(N_MAX);
vector<edge> edges;
int G[N_MAX][N_MAX];

int main()
{
#ifndef LOCAL
	freopen(PROB_NAME".in", "rt", stdin);
	freopen(PROB_NAME".out", "wt", stdout);
#endif

	scanf("%d", &N);
	for (int i = 0; i < N; ++i)
	for (int j = 0; j < N; ++j)
		scanf("%d", &G[i][j]);

	for (int i = 0; i < N; ++i)
	for (int j=i+1; j < N; ++j)
		edges.push_back(edge(i, j, G[i][j]));

	/* kruskal begin */
	sort(edges.begin(), edges.end());

	int s = 0;
	for (int i = 0; i < int(edges.size()); ++i)
		if (!S.in_same_set(edges[i].a, edges[i].b))
		{
			s += edges[i].w;
			S.union_set(edges[i].a, edges[i].b);
		}
	/* kruskal begin */

	printf("%d\n", s);

	return 0;
}

