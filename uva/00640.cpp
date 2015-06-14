
#include <set>
#include <map>
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

#define MLN 1000000

#define SIZE 1000080
bitset<SIZE-1> is_self;

int dig_sum(int n) {
	int s = 0;
	while (n > 0) {
		s += n%10;
		n /= 10;
	}
	return s;
}

void gen_selfs()
{
	is_self.set();
	for_(int, i, 0, MLN)
	{
		is_self[ i+dig_sum(i) ] = 0;
	}
}

int main()
{
	gen_selfs();
	for_(int, i, 0, MLN+1)
	{
		if (is_self[i])
			printf("%d\n", i);
	}

	return 0;
}

