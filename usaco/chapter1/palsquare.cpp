
/*
ID: aybek.h2
PROG: palsquare
LANG: C++11
*/

#include <algorithm>
#include <fstream>
#include <string>

using namespace std;

bool palin(const string & s)
{
	int i, n = s.length();
	for (i = 0; i < n>>1; ++i)
		if (s[i] != s[n-i-1])
			return false;
	return true;
}

void changeNotat(int n, int b, string & s)
{
	s.erase();
	for (; n; n /= b) {
		char c = n%b;
		if (c >= 10)
			c='A'+c-10;
		else
			c='0'+c;

		s.push_back(c);
	}
	reverse(s.begin(), s.end());
}

int main()
{
	ifstream fin	("palsquare.in");
	ofstream fout	("palsquare.out");

	int n, i;
	string s, s2;

	fin >> n;

	for (i = 1; i <= 300; ++i) {
		int sqr = i*i;

		changeNotat(sqr, n, s);
		if (palin(s)) {
			changeNotat(i, n, s2);
			fout << s2 << ' ' << s << '\n';
		}
	}

	return 0;
}

