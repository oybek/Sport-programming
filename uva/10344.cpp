
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

bool finished;
void backtrack(const int * a, const int n, int v, int i)
{
	if (finished) return;

	if (i == n)
	{
		finished = (v == 23);
		return;
	}

	backtrack(a, n, v+a[i], i+1);
	backtrack(a, n, v-a[i], i+1);
	backtrack(a, n, v*a[i], i+1);
}

int main()
{
	const int n = 5;
	int a[ n ];
	while (1)
	{
		for_(int, i, 0, n)
			scanf("%d", a+i);

		if (a[0] + a[1] + a[2] + a[3] + a[4] == 0)
			break;

		sort(a, a+n);
		do {
			finished = false;
			backtrack(a, n, a[0], 1);
			if (finished)
				break;
		} while (next_permutation(a, a+n));
		cout << (finished ? "Possible" : "Impossible") << endl;
	}

	return 0;
}

