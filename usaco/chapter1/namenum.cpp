
/*
ID: aybek.h2
PROG: namenum
LANG: C++11
*/

#include <fstream>
#include <string>

using namespace std;

inline bool isthis(char c, char c2, char c3, char c4)
{
	if ((c == c2) || (c == c3) || (c == c4))
		return true;
	else
		return false;
}

int main()
{
	ifstream fin	("namenum.in");
	ofstream fout	("namenum.out");
	ifstream dict	("dict.txt");

	string name, cell;

	fin >> cell;
	bool flag = 0;

	while (dict >> name) {
		if (name.length() != cell.length())
			continue;

		int i;
		for (i = 0; i < cell.length(); ++i) {
			if (cell[i] == '2' && !isthis(name[i], 'A', 'B', 'C')) break;
			if (cell[i] == '3' && !isthis(name[i], 'D', 'E', 'F')) break;
			if (cell[i] == '4' && !isthis(name[i], 'G', 'H', 'I')) break;
			if (cell[i] == '5' && !isthis(name[i], 'J', 'K', 'L')) break;
			if (cell[i] == '6' && !isthis(name[i], 'M', 'N', 'O')) break;
			if (cell[i] == '7' && !isthis(name[i], 'P', 'R', 'S')) break;
			if (cell[i] == '8' && !isthis(name[i], 'T', 'U', 'V')) break;
			if (cell[i] == '9' && !isthis(name[i], 'W', 'X', 'Y')) break;
		}

		if (i == cell.length()) {
			fout << name << '\n';
			flag = 1;
		}
	}

	if (!flag)
		fout << "NONE\n";

	return 0;
}

