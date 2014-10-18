
/*
ID: aybek.h2
PROG: friday
LANG: C++
*/

#include <fstream>

#define PROG "friday"

using namespace std;


int getwday(int day, int month, int year)
{
	int a = (14 - month)/12;
	int y = year - a;
	int m = month + 12*a - 2;
	return (7000 + (day + y + y/4 - y/100 + y/400 + (31*m)/12)) % 7;
}

int main()
{
	ifstream fin	(PROG".in");
	ofstream fout	(PROG".out");

	int32_t N;
	fin >> N;

	int day[7] = {};
	for (int i = 0; i < N; ++i)
		for (int j = 1; j <= 12; ++j)
			++day[ getwday(13, j, 1900+i) ];

	fout	<< day[6] << ' '
			<< day[0] << ' '
			<< day[1] << ' '
			<< day[2] << ' '
			<< day[3] << ' '
			<< day[4] << ' '
			<< day[5] << endl;

	return 0;
}

