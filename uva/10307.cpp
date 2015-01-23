
#include <set>
#include <map>
#include <list>
#include <stack>
#include <queue>
#include <cmath>
#include <bitset>
#include <cstdio>
#include <string>
#include <vector>
#include <cassert>
#include <cstring>
#include <climits>
#include <iomanip>
#include <iostream>
#include <algorithm>

using namespace std;

#define INF INT_MAX-1
#define SQR(x) ((x)*(x))

#define WALL -2
#define SPACE -1

#define maze_height_MAX 51
#define maze_width_MAX 51
#define vertices_num_max 102

int maze_height, maze_width, vertices_num;
int maze[ maze_height_MAX ][ maze_width_MAX ];
int weights[ vertices_num_max ][ vertices_num_max ];

struct edge
{
	int x, y, w;

	edge(int ax, int ay, int aw)
		: x(ax)
		, y(ay)
		, w(aw)
	{}

	bool operator < (const edge & a) const
	{
		return w < a.w;
	}
};

int parent[ vertices_num_max ];
int find_set(int x) { return x == parent[x] ? x : parent[x] = find_set(parent[x]); }
void union_set(int x, int y) { parent[ find_set(x) ] = parent[ find_set(y) ]; }

/* generate edges from node i to other */
void bfs(int x, int y, int v)
{
	queue<edge> Q;
	bitset<maze_width_MAX> was[ maze_height_MAX ];

	for (int i = 0; i < maze_height_MAX; ++i)
		for (int j = 0; j < maze_width_MAX; ++j)
			was[i][j] = (maze[i][j] == WALL);

	Q.push(edge(x, y, 0));
	was[x][y] = 1;

	while (!Q.empty())
	{
		edge cur = Q.front(); Q.pop();

		if (maze[cur.x][cur.y] >= 0)
		{
			weights[v][ maze[cur.x][cur.y] ] = cur.w;
		}

#define PUSH(x, y, w)\
	if ((x >= 0) && (y >= 0) && (!was[x][y]))\
	{\
		Q.push(edge(x, y, w));\
		was[x][y] = 1;\
	}

		PUSH(cur.x-1, cur.y, cur.w+1);
		PUSH(cur.x, cur.y-1, cur.w+1);
		PUSH(cur.x+1, cur.y, cur.w+1);
		PUSH(cur.x, cur.y+1, cur.w+1);
	}
}

int solve()
{
	for (int x = 0; x < maze_height; ++x)
		for (int y = 0; y < maze_width; ++y)
			if (maze[x][y] >= 0)
				bfs(x, y, maze[x][y]);

	vector<edge> edges;
	edges.reserve(3000);

	for (int x = 0; x < vertices_num; ++x)
		for (int y = x+1; y < vertices_num; ++y)
			edges.push_back(edge(x, y, weights[x][y]));

	sort(edges.begin(), edges.end());

	int mst_cost = 0;
	for (vector<edge>::const_iterator it = edges.begin();
		it != edges.end(); ++it)
	{
		if (find_set(it->x) == find_set(it->y))
			continue;

		mst_cost += it->w;
		union_set(it->x, it->y);
	}

	return mst_cost;
}

int main()
{
	int test_n, alien_count;
	string line;

	cin >> test_n;

	while (test_n--)
	{
		/* preparing */
		for (int i = 0; i < vertices_num_max; ++i)
			parent[i] = i;

		for (int x = 0; x < maze_height_MAX; ++x)
			for (int y = 0; y < maze_width_MAX; ++y)
				maze[x][y] = SPACE;

		/* input */
		cin >> maze_width >> maze_height; while (cin.get() != '\n');

		alien_count = 1;
		for (int i = 0; i < maze_height; ++i)
		{
			getline(cin, line);
			for (int j = 0; j < maze_width; ++j)
			{
				switch (line[j])
				{
					case 'A': maze[i][j] = alien_count++;	break;
					case '#': maze[i][j] = WALL;			break;
					case ' ': maze[i][j] = SPACE;			break;
					case 'S': maze[i][j] = 0;				break;
				}
			}
		}

		vertices_num = alien_count;
		cout << solve() << endl;
	}

	return 0;
}

