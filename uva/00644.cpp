
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

#define SIZE 16

void remove_trailing_blanks(char * s)
{
	while (*s != '\0') ++s;
	while (isblank(*s)) --s;
	*++s = '\0';
}

bool is_prefix(const char * s1, const char * s2)
{
	while (*s1 && *s2 && (*s1 == *s2))
	{
		++s1;
		++s2;
	}
	return (*s1 == '\0');
}

int main()
{
	int s_sz, i, j;
	char s[10][SIZE];

	bool flag;
	int set_i = 1;
	while (!feof(stdin))
	{
		for_(, s_sz, 0, INF)
		{
			scanf("%s\n", s[s_sz]);

			if (s[s_sz][0] == '9')
				break;
		}

		flag = false;
		printf("Set %d ", set_i++);

		for_(, i, 0, s_sz)
		for_(, j, i+1, s_sz)
			if (is_prefix(s[i], s[j]) ||
				is_prefix(s[j], s[i]) )
			{
				puts("is not immediately decodable");
				flag = true;
				i = s_sz-1;
				break;
			}

		if (!flag)
			puts("is immediately decodable");
	}

	return 0;
}

