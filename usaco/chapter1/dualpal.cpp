
/*
ID: aybek.h2
PROG: dualpal
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

void changeNotat(string & s, int n, int b)
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
	ifstream fin	("dualpal.in");
	ofstream fout	("dualpal.out");

	int n, i, s, b, num = 0;
	string dig;

	fin >> n >> s;

	for (i = s+1; i < (1<<30); ++i) {

		int pnum = 0;

		for (b = 2; b <= 10; ++b) {
			changeNotat(dig, i, b);
			if (palin(dig)) {
				++pnum;
				if (pnum == 2) {
					++num;
					fout << i << '\n';
					break;
				}
			}
		}

		if (num == n)
			break;
	}

	return 0;
}

