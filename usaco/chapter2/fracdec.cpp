
/*
ID: aybek.h2
PROG: fracdec
LANG: C++
*/

#define PROB_NAME "fracdec"

#include <map>
#include <cmath>
#include <bitset>
#include <cstdio>
#include <string>
#include <vector>
#include <cstdlib>
#include <iostream>
#include <algorithm>
using namespace std;

string get_period(int n, int d)
{
	if (!n) return ".0";

	map<int, int> was;
	string s;

	while (1)
	{
		if (!n)
		{
			s = "."+s;
			break;
		} else
		if (was.find(n) != was.end())
		{
			s.insert(was.find(n)->second, "(");
			s = "."+s+")";
			break;
		}

		was.insert(make_pair(n, s.size()));
		n *= 10;
		s.push_back(n/d + '0');
		n %= d;
	}
	return s;
}

int dign(int n)
{
	if (!n) return 1;
	int l;
	for (l = 0; n > 0; n /= 10)
		++l;
	return l;
}

int main()
{
#ifndef LOCAL
	freopen(PROB_NAME".in", "rt", stdin);
	freopen(PROB_NAME".out", "wt", stdout);
#endif
	int n, d;
	scanf("%d%d", &n, &d);

	printf("%d", n/d);
	int l = dign(n/d);

	n %= d;

	string s = get_period(n, d);
	for (const char * c = s.c_str(); *c; ++c)
	{
		if (++l > 76)
		{
			puts("");
			l = 1;
		}
		putchar(*c);
	}
	puts("");

	return 0;
}

