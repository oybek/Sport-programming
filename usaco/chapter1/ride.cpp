
/*
ID: aybek.h2
PROG: ride
LANG: C++
*/

#include <fstream>
#include <string>

using namespace std;

int main()
{
	ifstream fin	("ride.in");
	ofstream fout	("ride.out");

	size_t i;
	string a1, a2;
	int32_t n1, n2;

	fin >> a1
		>> a2;

	n1 = 1;
	n2 = 1;

	for (i = 0; i < a1.size(); ++i)
		n1 *= (a1[i]-'A'+1);

	for (i = 0; i < a2.size(); ++i)
		n2 *= (a2[i]-'A'+1);

	if (n1%47 == n2%47)
		fout << "GO" << endl;
	else
		fout << "STAY" << endl;

	return 0;
}

