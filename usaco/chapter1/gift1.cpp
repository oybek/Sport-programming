
/*
ID: aybek.h2
PROG: gift1
LANG: C++
*/

#include <fstream>
#include <string>
#include <vector>
#include <map>

#define PROG	"gift1"

using namespace std;

int main()
{
	ifstream fin	(PROG ".in");
	ofstream fout	(PROG ".out");

	string	tmp;
	int32_t N, i, mon, num;
	map<string, int32_t> pson;

	fin >> N;

	vector<string> name(N);

	for (i = 0; i < N; ++i) {
		fin >> name[i];
		pson[ name[i] ] = 0;
	}

	for (i = 0; i < N; ++i) {
		fin >> tmp;
		fin >> mon >> num;

		pson[ tmp ] -= mon;
		int32_t eachget;

		if (num) {
			pson[ tmp ] += mon%num;
			eachget	= mon/num;
		}

		while (num--) {
			fin >> tmp;
			pson[ tmp ] += eachget;
		}
	}

	for (i = 0; i < N; ++i)
		fout << name[i] << ' ' << pson[ name[i] ] << endl;

	return 0;
}

