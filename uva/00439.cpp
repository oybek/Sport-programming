
#include <set>
#include <map>
#include <queue>
#include <cmath>
#include <bitset>
#include <cstdio>
#include <string>
#include <vector>
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

#define PUSH(x, y, c) if (is_val(x, y)) { q.push(make_pair(make_pair(x, y), c)); was[x][y] = 1; }
#define is_val(x, y) (in_range(x, 1, 8) && in_range(y, 1, 8) && !was[x][y])
#define in_range(x, a, b) (((x) >= (a)) && ((x) <= (b)))

bitset<9> was[ 9 ];

int bfs(pair<int, int> a, pair<int, int> b)
{
#define x first
#define y second

	queue<pair<pair<int, int>, int> > q;
	pair<pair<int, int>, int> c;

	for_(int, i, 0, 9)
		was[i].reset();

	PUSH(a.x, a.y, 0);

	while (!q.empty())
	{
		c = q.front(); q.pop();
		if (c.x == b) {
			return c.second;
		}

		PUSH(c.first.x-2, c.first.y+1, c.second+1);
		PUSH(c.first.x-2, c.first.y-1, c.second+1);

		PUSH(c.first.x+2, c.first.y+1, c.second+1);
		PUSH(c.first.x+2, c.first.y-1, c.second+1);

		PUSH(c.first.x+1, c.first.y-2, c.second+1);
		PUSH(c.first.x-1, c.first.y-2, c.second+1);

		PUSH(c.first.x+1, c.first.y+2, c.second+1);
		PUSH(c.first.x-1, c.first.y+2, c.second+1);
	}

#undef x
#undef y

	return 0;
}

int main()
{
	char a[3], b[3];
	a[2] = b[2] = '\0';
	while (scanf("%c%c %c%c\n", a, a+1, b, b+1) != EOF) {
		printf("To get from %s to %s takes ", a, b);

		a[0] -= ('a' - 1);
		b[0] -= ('a' - 1);
		a[1] -= '0';
		b[1] -= '0';

		printf("%d knight moves.\n", bfs(make_pair(a[0], a[1]), make_pair(b[0], b[1])));
	}

	return 0;
}

