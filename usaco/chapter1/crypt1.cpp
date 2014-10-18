
/*
ID: aybek.h2
PROG: crypt1
LANG: C++11
*/

#include <algorithm>
#include <fstream>
#include <string>

using namespace std;

int dig[10] = {};

inline bool isvalid(int n, int max)
{
	if (n >= max)
		return false;

	for (; n; n /= 10) {
		int c = n%10;
		if (!dig[c])
			return false;
	}

	return true;
}

int main()
{
	ifstream fin	("crypt1.in");
	ofstream fout	("crypt1.out");

	int n, t;
	fin >> n;
	while (n--) {
		fin >> t;
		dig[t] = 1;
	}

	int solNum = 0;
	for (int i = 111; i <= 999; ++i) {
		for (int j = 11; j <= 99; ++j) {
			if (isvalid(i,			1000)	&&
				isvalid(j,			100)	&&
				isvalid(i*(j/10),	1000)	&&
				isvalid(i*(j%10),	1000)	&&
				isvalid(i*j,		10000))
			{
				++solNum;
			}
		}
	}

	fout << solNum << '\n';

	return 0;
}

