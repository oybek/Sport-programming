
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

#define X first
#define Y second

#define between(x, a, b)\
	( ((x) > (a) && (x) < (b)) || ((x) > (b) && (x) < (a)) )

int main()
{
	char c;
	vector<pair<pair<float, float>, pair<float, float> > > rectangles;

	while (1)
	{
		scanf("%c", &c);
		if (c == '*')
			break;

		float a, b, c, d;
		scanf("%f%f%f%f", &a, &b, &c, &d);
		rectangles.push_back(make_pair(make_pair(a, b), make_pair(c, d)));
	}

	int point_i = 1;
	while (1)
	{
		float x = 0, y = 0;
		scanf("%f%f", &x, &y);

		if (abs(x-9999.9)<0.1 && abs(y-9999.9)<0.1)
			break;

		bool f = true;
		for (unsigned int i = 0; i < rectangles.size(); ++i)
		{
			if
			(
				between(x, rectangles[i].first.X, rectangles[i].second.X) &&
				between(y, rectangles[i].first.Y, rectangles[i].second.Y)
			)
			{
				f = false;
				printf("Point %d is contained in figure %d\n", point_i, i);
			}
		}

		if (f)
			printf("Point %d is not contained in any figure\n", point_i);

		++point_i;
	}

	return 0;
}

