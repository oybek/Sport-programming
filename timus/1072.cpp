
#include <bitset>
#include <cstdio>
#include <vector>
#include <iostream>
using namespace std;

#define MAX_VN 90

int N;
vector<int> G[ MAX_VN+1 ];
vector<pair<unsigned int, unsigned int> > PC[ MAX_VN+1 ];

/* O(n^4) is 90^4 = 65610000 */
void build_graph()
{	for (int i = 0; i < N; ++i)
	for (int j=i+1; j < N; ++j)
		for (int k = 0; k < int(PC[i].size()); ++k)
		for (int l = 0; l < int(PC[j].size()); ++l)
			if ((PC[i][k].first & PC[i][k].second) == (PC[j][l].first & PC[j][l].second))
			{	G[i].push_back(j);
				G[j].push_back(i);
			}
}

bool path_found = false;
vector<int> path, min_path;
bitset<MAX_VN> sign;

void dfs(int i, int d)
{	if (i == d)
	{	path_found = true;
		if (min_path.size() == 0 || path.size() < min_path.size())
		{	min_path.resize(path.size());
			for (int j = 0; j < int(path.size()); ++j)
				min_path[j] = path[j];
		}
		return;
	}

	for (int j = 0; j < int(G[i].size()); ++j)
	{	if (sign[ G[i][j] ]) continue;
		path.push_back(G[i][j]);
		sign[ G[i][j] ] = 1;
		dfs(G[i][j], d);
		sign[ G[i][j] ] = 0;
		path.pop_back();
	}
}

int main()
{	path.reserve(MAX_VN);
	min_path.reserve(MAX_VN);
	scanf("%d", &N);
	for (int i = 0; i < N; ++i)
	{	int K;
		scanf("%d", &K);
		while (K--)
		{	unsigned int a1, a2, a3, a4;
			unsigned int b1, b2, b3, b4;
			scanf("%d.%d.%d.%d%d.%d.%d.%d"
				, &a1, &a2, &a3, &a4
				, &b1, &b2, &b3, &b4);

			unsigned int a, b;
			a = a1;
			a <<= 8; a += a2;
			a <<= 8; a += a3;
			a <<= 8; a += a4;

			b = b1;
			b <<= 8; b += b2;
			b <<= 8; b += b3;
			b <<= 8; b += b4;

			PC[i].push_back(make_pair(a, b));
		}
	}

	build_graph();
	int a, b;
	scanf("%d%d", &a, &b);
	--a, --b;

	sign.reset();
	sign[a] = 1;
	path.push_back(a);
	dfs(a, b);

	if (path_found)
	{	cout << "Yes\n";
		if (min_path.size() > 0)
			cout << min_path[0]+1;
		for (int i = 1; i < int(min_path.size()); ++i)
			cout << ' ' << min_path[i]+1;
		cout << endl;
	} else
	{	cout << "No\n";
	}

	return 0;
}

