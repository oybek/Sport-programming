
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

#define SONG_SZ 16

const char * song[ SONG_SZ ] = {
	"Happy",
	"birthday",
	"to",
	"you",
	"Happy",
	"birthday",
	"to",
	"you",
	"Happy",
	"birthday",
	"to",
	"Rujia",
	"Happy",
	"birthday",
	"to",
	"you"
};

int main()
{
	int n, name_sz;
	char name[ 101 ][ 256 ];

	scanf("%d", &n);
	for_(int, i, 0, n)
		scanf("%s", name[i]);

	name_sz = n;
	while (n%SONG_SZ) ++n;

	int i = 0;
	int j = 0;
	while (n--)
	{
		printf("%s: %s\n", name[i], song[j]);

		i = (i+1)%name_sz;
		j = (j+1)%SONG_SZ;
	}

	return 0;
}

