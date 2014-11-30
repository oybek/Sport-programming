
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

int main()
{
	set<pair<int, bool> > s;

	int d;
	int a[ 30 ];
	while (scanf("%d", &d) != EOF)
	{
		for (int i = 0; i < d; ++i)
			scanf("%d", a+i);

		s.clear();

		for (int i = 0; i < d; ++i)
		{

			if (s.find(make_pair(a[i], 1)) != s.end())
			{
				puts("This is not an A-sequence.");
			} else
			{
				for (set<pair<int, bool> >::iterator it = s.begin();
					it != s.end(); ++it)
				{
					s.insert(make_pair(it->first+a[i], 1));
				}
				s.insert(make_pair(a[i], 0));
			}
		}
	}

	return 0;
}

