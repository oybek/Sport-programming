
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

typedef unsigned int uint32;

uint32 n;
const char * s[] = {
	"00\n01\n81",
	"0000\n0001\n2025\n3025\n9801",
	"000000\n000001\n088209\n494209\n998001",
	"00000000\n00000001\n04941729\n07441984\n24502500\n25502500\n52881984\n60481729\n99980001"
};

int main()
{
	while (scanf("%u", &n) != EOF)
	{
		switch (n)
		{
			case 2: puts(s[0]); break;
			case 4: puts(s[1]); break;
			case 6: puts(s[2]); break;
			case 8: puts(s[3]);
		}
	}

	return 0;
}

