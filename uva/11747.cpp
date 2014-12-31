
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

// union find disjoint sets
struct ufd_sets
{
	private:
		vector<int> s;

	public:
		void init(int size)
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

struct edges
{
	int w, x, y;

	bool operator < (const edges & a) const
	{
		return w < a.w;
	}
};

ufd_sets S;
vector<edges> edge;
vector<int> odd_w;

int main()
{
	while (1)
	{
		int n, m;
		scanf("%d%d", &n, &m);

		if (!n && !m)
			break;

		S.init(n);
		edge.resize(m);
		odd_w.resize(0);

		for (int i = 0; i < m; ++i)
			scanf("%d%d%d", &(edge[i].x), &(edge[i].y), &(edge[i].w));

		sort(edge.begin(), edge.end());

		/*kruskal*/
		for (int i = 0; i < int(edge.size()); ++i)
		{
			if ( ! S.in_same_set(edge[i].x, edge[i].y))
				S.union_set(edge[i].x, edge[i].y);
			else
				odd_w.push_back(edge[i].w);
		}

		sort(odd_w.begin(), odd_w.end());

		if (odd_w.size() == 0)
			puts("forest");
		else
		{
			printf("%d", odd_w[0]);
			for (int i = 1; i < int(odd_w.size()); ++i)
				printf(" %d", odd_w[i]);
			puts("");
		}
	}

	return 0;
}

