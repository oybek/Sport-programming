
/*
 * rectangle can be rotated
 */

#include <cmath>
#include <cstdio>
#include <vector>
#include <cfloat>
#include <limits>
#include <cassert>
#include <iostream>
#include <algorithm>

int main()
{
	using namespace std;

	int n;
	double minx, maxx, miny, maxy, area, x, y;

	while (scanf("%d", &n) != EOF)
	{
		if (!n) break;

		minx = miny = DBL_MAX;
		maxx = maxy = -DBL_MAX;

		while (n--)
		{
			scanf("%lf%lf", &x, &y);

			minx = min(minx, x);
			maxx = max(maxx, x);

			miny = min(miny, y);
			maxy = max(maxy, y);
		}

		area = (maxx - minx) * (maxy - miny);
		area *= 10000;
		area = round(area);
		area /= 10000;

		printf("%.4lf\n", area);
	}

	return 0;
}

