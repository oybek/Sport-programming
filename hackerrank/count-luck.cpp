
#include <bits/stdc++.h>

#define inf 1000000001
template< class T > T sqr( T x ) { return x*x; }
#define all(x) x.begin(), x.end()

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

typedef vector<string> vec2dc;
typedef vector<vector<int>> vec2di;

#define N_MAX 101

#define IN_RANGE(x, a, b) (x >= a && x <= b)

#define WALL -2
#define FREE -1

struct coord
{
	int x;
	int y;

	coord(int x, int y) : x(x), y(y) {}

	bool operator== (const coord a) const
	{
		return x == a.x && y == a.y;
	}

	bool operator!= (const coord a) const
	{
		return !operator== (a);
	}
};

// Don't write functions with side effects!

// gets coord of char in maze
coord get_char_coord(const vec2dc& maze, const char c)
{
	for (int i = 0; i < maze.size(); ++i)
	{
		for (int j = 0; j < maze[i].size(); ++j)
		{
			if (maze[i][j] == c)
				return coord(i, j);
		}
	}
	assert(false);
}

// applies function to each element of maze forming new maze [pure function]
vec2di map_maze(const vec2dc& maze, int (*apply)(char c))
{
	vec2di mapped_maze;

	// resize vector to fit maze size, and init
	mapped_maze.resize(maze.size());
	for (int i = 0; i < maze.size(); ++i)
		mapped_maze[i].resize(maze[i].size());

	for (int i = 0; i < maze.size(); ++i) {
		for (int j = 0; j < maze[i].size(); ++j)
			mapped_maze[i][j] = apply(maze[i][j]);
	}

	return mapped_maze;
}

// solves maze [pure function]
vec2di solve_maze(const vec2dc& maze, const coord start)
{
	vec2di solved_maze = map_maze(maze, [](char c) {
		switch (c)
		{
			default: assert(false);
			case '*':
			case 'M':
			case '.': return FREE;
			case 'X': return WALL;
		}
	});

	const int& maxx = maze.size();
	const int& maxy = maze[0].size();

	solved_maze[start.x][start.y] = 0;

	queue<coord> q;
	q.push(start);
	
	while (!q.empty())
	{
		coord pos = q.front(); q.pop();

		for (coord new_pos : {
				coord(pos.x-1, pos.y),
				coord(pos.x+1, pos.y),
				coord(pos.x, pos.y-1),
				coord(pos.x, pos.y+1)
			})
		{
			if (IN_RANGE(new_pos.x, 0, maxx-1) &&
				IN_RANGE(new_pos.y, 0, maxy-1) &&
				solved_maze[new_pos.x][new_pos.y] == FREE)
			{
				solved_maze[new_pos.x][new_pos.y] = solved_maze[pos.x][pos.y]+1;
				q.push(new_pos);
			}
		}
	}

	return solved_maze;
}

// extracts good_path from solved maze [pure function]
vector<coord> get_good_path(const vec2di& solved_maze, const coord start, const coord end)
{
	vector<coord> good_path;

	const int& maxx = solved_maze.size();
	const int& maxy = solved_maze[0].size();

	coord pos = end;

	while (pos != start) {
		for (coord new_pos : {
				coord(pos.x-1, pos.y),
				coord(pos.x+1, pos.y),
				coord(pos.x, pos.y-1),
				coord(pos.x, pos.y+1)
			})
		{
			if (IN_RANGE(new_pos.x, 0, maxx-1) &&
				IN_RANGE(new_pos.y, 0, maxy-1) &&
				solved_maze[new_pos.x][new_pos.y] == solved_maze[pos.x][pos.y]-1)
			{
				pos = new_pos;
				break;
			}
		}

		good_path.push_back(pos);
	}

	return good_path;
}

// count number of path options from current cell [pure function]
int count_options(const vec2di& solved_maze, const coord pos)
{
	const int& maxx = solved_maze.size();
	const int& maxy = solved_maze[0].size();

	int option_num = 0;

	for (coord new_pos : {
			coord(pos.x-1, pos.y),
			coord(pos.x+1, pos.y),
			coord(pos.x, pos.y-1),
			coord(pos.x, pos.y+1)
		})
	{
		if (IN_RANGE(new_pos.x, 0, maxx-1) &&
			IN_RANGE(new_pos.y, 0, maxy-1) &&
			solved_maze[new_pos.x][new_pos.y] == solved_maze[pos.x][pos.y]+1)
			++option_num;
	}

	return option_num;
}

// solve problem [pure function]
string solve(const vec2dc& maze, int K)
{
	const coord& end = get_char_coord(maze, '*');
	const coord& start = get_char_coord(maze, 'M');

	int k = 0;
	vec2di solved_maze = solve_maze(maze, start);
	vector<coord> good_path = get_good_path(solved_maze, start, end);

	for (const coord pos : good_path)
	{
		if (count_options(solved_maze, pos) > 1)
			++k;
	}

	return k == K ? "Impressed" : "Oops!";
}

int main()
{
	int T, N, M, K;
	cin >> T;

	while (T--) {
		cin >> N >> M;

		vec2dc maze(N);
		for (int i = 0; i < maze.size(); ++i)
			cin >> maze[i];

		cin >> K;

		cout << solve(maze, K) << endl;
	}

	return 0;
}

