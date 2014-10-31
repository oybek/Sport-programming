
#include <set>
#include <map>
#include <queue>
#include <cmath>
#include <bitset>
#include <cstdio>
#include <string>
#include <vector>
#include <utility>
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

int main()
{
	string s;

	int n;
	cin >> n;
	while (n--)
	{
		cin >> s;
		if (
			s == "1" ||
			s == "4" ||
			s == "78"
	   	)
		{
			cout << '+';
		}
		else
		if (s.substr(s.size()-2, 2) == "35")
		{
			cout << '-';
		}
		else
		if (*s.begin() == '9' && *s.rbegin() == '4')
		{
			cout << '*';
		}
		else
		if (s.substr(0, 3) == "190")
		{
			cout << '?';
		}
		cout << endl;
	}

	return 0;
}

