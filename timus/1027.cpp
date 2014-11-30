
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

#define IN_SPACE	0
#define IN_ARIF_EXP	1
#define IN_COMMENT	2

#define DIGIT '0': case '1': case '2': case '3': case '4': case '5': case '6': case '7': case '8': case '9'

int main()
{
	int c, prevc = -1, state = IN_SPACE;

	while ((c = getchar()) != EOF)
	{
		switch (state)
		{
			case IN_SPACE:
				switch (c)
				{
					case '*':
						if (prevc == '(')
						{
							state = IN_COMMENT;
						}
						break;

					case DIGIT:
					case '+':
					case '-':
					case '/':
					case '=':
						state = IN_ARIF_EXP;
						break;
				}
				break;

			case IN_ARIF_EXP:
				break;

			case IN_COMMENT:
				if (c == ')' && prevc == '*')
					state = IN_SPACE;
				break;
		}

		prevc = c;
	}

	return 0;
}

