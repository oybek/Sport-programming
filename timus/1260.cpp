
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

bool is_good(int * v, int v_sz)
{
	for (int i = 1; i < v_sz; ++i)
		if (abs(v[i] - v[i-1]) > 2)
			return false;
	return true;
}

int main()
{
	int v[ 10 ];
	for (int i = 1; i <= 12; ++i)
	{
		for (int j = 0; j < i; ++j)
			v[j] = j+1;

		int ans = 0;
		do {
			ans += is_good(v, i);
		} while (next_permutation(v+1, v+i));

		printf("f(%d) = %d\n", i, ans);
	}

	return 0;
}

