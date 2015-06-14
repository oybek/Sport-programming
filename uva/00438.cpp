
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
#define for_(t, i, a, b) for (t i = t(a); i != t(b); ++i)
#define rep_(n) for_(int, i_, 0, n)

void remove_trailing_blanks(char * s)
{
	while (*s != '\0') ++s;
	while (isblank(*s)) --s;
	*++s = '\0';
}

#define x first
#define y second

#define sqr(x) (x)*(x)

#define PI 3.141592653589793

typedef pair<double, double> dd;

double dist(const dd a, const dd b)
{
	return
	sqrt( sqr(a.x - b.x) + sqr(a.y - b.y) );
}

int main()
{
	dd v[3];
	double a, b, c, p, R;

	while (scanf("%lf%lf%lf%lf%lf%lf\n",
		&v[0].x, &v[0].y,
		&v[1].x, &v[1].y,
		&v[2].x, &v[2].y) != EOF)
	{
		a = dist(v[0], v[1]);
		b = dist(v[0], v[2]);
		c = dist(v[1], v[2]);

		p = (a+b+c) / 2;

		R = (a*b*c)
			/ ( 4*sqrt(p*(p-a)*(p-b)*(p-c)) );

		printf("%.2lf\n", 2*PI*R);
	}

	return 0;
}

