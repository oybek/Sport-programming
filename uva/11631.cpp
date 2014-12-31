
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

		for (int i = 0; i < m; ++i)
			scanf("%d%d%d", &(edge[i].x), &(edge[i].y), &(edge[i].w));

		sort(edge.begin(), edge.end());

		/*kruskal*/
		int mst_w = 0, total_w = 0;
		for (int i = 0; i < int(edge.size()); ++i)
		{
			total_w += edge[i].w;
			if ( ! S.in_same_set(edge[i].x, edge[i].y))
			{
				mst_w += edge[i].w;
				S.union_set(edge[i].x, edge[i].y);
			}
		}

		printf("%d\n", (total_w-mst_w));
	}

	return 0;
}

