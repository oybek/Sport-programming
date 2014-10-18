
/*
ID: aybek.h2
PROG: beads
LANG: C++11
*/

#include <fstream>
#include <string>
#include <iterator>

#define PROG "beads"

using namespace std;

void shift(string & s)
{
	int i;
	char t = s[0];
	for (i = 0; (i+1) < s.length(); ++i)
		s[i] = s[i+1];
	s[i] = t;
}

int main()
{
	ifstream fin	(PROG".in");
	ofstream fout	(PROG".out");

	string		s;
	uint32_t	N;

	fin >> N;
	fin >> s;

	string::iterator it;
	int max = 0;

	for (int i = 0; i < s.size(); ++i) {

		char c;
		int l = 0;

		c = 0;
		for (it = s.begin(); it < s.end(); ++it) {
			if (*it == 'w') {
				++l;
			} else if (*it == 'r') {
				if (c == 'b') {
					break;
				} else {
					c = 'r';
					++l;
				}
			} else if (*it == 'b') {
				if (c == 'r') {
					break;
				} else {
					c = 'b';
					++l;
				}
			}
		}

		c = 0;
		for (it = s.end()-1; it >= s.begin(); --it) {
			if (*it == 'w') {
				++l;
			} else if (*it == 'r') {
				if (c == 'b') {
					break;
				} else {
					c = 'r';
					++l;
				}
			} else if (*it == 'b') {
				if (c == 'r') {
					break;
				} else {
					c = 'b';
					++l;
				}
			}
		}

		if (l > N) l = N;
		if (l > max) max = l;

		shift(s);
	}

	fout << max << endl;

	return 0;
}

