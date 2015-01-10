
#include <set>
#include <map>
#include <cmath>
#include <cctype>
#include <bitset>
#include <cstdio>
#include <string>
#include <vector>
#include <climits>
#include <iostream>
#include <algorithm>

using namespace std;

#define INF INT_MAX-1

/* We are solving it in C */

/*
 * Given:
 * text
 *
 * Output:
 * text but with some modification described in problem definition
 */

bool is_vowel(char c)
{
	switch (tolower(c))
	{
		case 'a':
		case 'e':
		case 'i':
		case 'o':
		case 'u':
			return true;
	}
	return false;
}

string convert(const string & s)
{
	return (is_vowel(s[0]) ? s : s.substr(1) + s[0]) + "ay";
}

int main()
{
	int c;
	bool in_word = false;
	string word; word.reserve(1024);

	while ((c = getchar()) != EOF)
	{
		if (isalpha(c))
		{
			word.push_back(char(c));
			in_word = true;
		} else
		{
			if (in_word)
			{
				printf("%s", convert(word).c_str());
				in_word = false;
				word.clear();
			}

			putchar(c);
		}
	}

	return 0;
}

