
#include <set>
#include <map>
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

bool is_palindrome(char * s1, char * s2)
{
	while (s1 < s2) {
		if (*s1 != *s2)
			return false;
		++s1;
		--s2;
	}
	return true;
}

#define SIZE 81
int main()
{
	char s[ SIZE ];
	set<string> was;

	while (scanf("%s\n", s) != EOF)
	{
		was.clear();

		register int ans = 0;
		int s_sz = strlen(s);

		for (int l = 0; l < s_sz; ++l)
			for (int i = 0; i < s_sz-l; ++i) {
				if (is_palindrome(s+i, s+i+l) &&
					was.find(string(s+i, s+i+l+1)) == was.end())  {
					was.insert(string(s+i, s+i+l+1));
					++ans;
				}
			}

		printf("The string '%s' contains %d palindromes.\n", s, ans);
	}

	return 0;
}

