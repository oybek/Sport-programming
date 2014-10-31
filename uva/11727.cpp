
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

#define in_range(x, a, b) ((x >= a) && (x <= b))

void remove_trailing_blanks(char * s)
{
	while (*s != '\0') ++s;
	while (isblank(*s)) --s;
	*++s = '\0';
}

int main()
{
	int tt, a[3];
	cin >> tt;
	for_(int, i, 1, tt+1)
	{
		cout << "Case " << i << ": ";
		cin >> a[0]
			>> a[1]
			>> a[2];
		sort(a, a+3);
		cout << a[1] << endl;
	}

	return 0;
}

