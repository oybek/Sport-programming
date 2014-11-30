
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
const int vertexNumMax = 101;
typedef unsigned int uint32;

vector<vector<int> > G;
bitset<vertexNumMax> ans;

void backtrack(bitset<vertexNumMax> black, int iStart)
{
	vector<int> candidates; candidates.resize(0);

	for (uint32 i = iStart; i < G.size(); ++i)
		if (! black[i])
		{
			bool f = true;
			for (uint32 j = 0; j < G[i].size(); ++j)
				if (black[ G[i][j] ])
				{
					f = false;
					break;
				}

			if (f)
				candidates.push_back(i);
		}

	if (candidates.size() == 0)
	{
		if (black.count() >= ans.count())
			ans = black;
		return;
	}

	for (uint32 i = 0; i < candidates.size(); ++i)
	{
		black[candidates[i]] = 1;
		backtrack(black, candidates[i]+1);
		black[candidates[i]] = 0;
	}
}

int main()
{
	G.reserve(vertexNumMax);

	int testNum;
	scanf("%d", &testNum);

	while (testNum--)
	{
		int vertexNum, edgeNum;

		scanf("%d%d", &vertexNum, &edgeNum);

		ans.reset();
		G.resize(vertexNum+1);
		for (int i = 1; i < int(G.size()); ++i)
			G[i].resize(0);

		while (edgeNum--)
		{
			int x, y;
			scanf("%d%d", &x, &y);
			G[x].push_back(y);
			G[y].push_back(x);
		}

		backtrack(ans, 1);

		printf("%d\n", int(ans.count()));

		bool f2 = true;
		for (int i = 1; i <= vertexNum; ++i)
		{
			if (ans[i])
			{
				if (f2) f2 = false;
				else putchar(' ');
				printf("%d", i);
			}
		}
		puts("");
	}


	return 0;
}

