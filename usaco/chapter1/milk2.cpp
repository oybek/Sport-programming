/*
ID: aybek.h2
PROG: milk2
LANG: C++11
*/

#include <algorithm>
#include <fstream>
#include <vector>
using namespace std;

struct interval_t {
	int beg, end;
};

inline bool intersect(const interval_t & a
		, const interval_t & b)
{
	if (a.beg >= b.beg && a.beg <= b.end) {
		return true;
	}
	/*else if (a.end >= b.beg && a.end <= b.end) {
		return true;
	}*/
	else if (b.beg >= a.beg && b.beg <= a.end) {	
		return true;
	}
	/*
	else if (b.end >= a.beg && b.end <= a.end) {
		return true;
	}*/ else {
		return false;
	}

}

bool operator< (const interval_t & a1, const interval_t & a2)
{
	return a1.beg < a2.beg;
}

void merge(interval_t & a1, interval_t & a2)
{
	a1.beg = min(a1.beg, a2.beg);
	a1.end = max(a1.end, a2.end);
	a2.beg = a2.end = 0;
}

void makeMerge(vector<interval_t> & farm)
{
	vector<interval_t>::iterator i1, i2;
	for (i1 = farm.begin(); i1 < farm.end(); ++i1) {
		if (i1->beg == 0)
			continue;

		for (i2 = farm.begin(); i2 < farm.end(); ++i2) {
			if (i1 == i2) continue;

			if (intersect(*i1, *i2)) {
				merge(*i1, *i2);
			}
		}
	}
}

int main()
{
	ifstream fin	("milk2.in");
	ofstream fout	("milk2.out");

	int farmerNum;

	fin >> farmerNum;

	vector<interval_t> farmer(farmerNum);
	vector<interval_t>::iterator it;

	for (it = farmer.begin(); it < farmer.end(); ++it)
		fin >> it->beg >> it->end;

	sort(farmer.begin(), farmer.end());
	makeMerge(farmer);
	sort(farmer.begin(), farmer.end());

	int maxMilk = 0, maxNomilk = 0;

	for (it = farmer.begin(); it < farmer.end(); ++it) {
		if ((it->end - it->beg) > maxMilk)
			maxMilk = it->end - it->beg;

		if ((it != farmer.begin()) && (it->beg - (it-1)->end) > maxNomilk
				&& (it-1)->beg)
			maxNomilk = it->beg - (it-1)->end;
	}

	fout << maxMilk << ' ' << maxNomilk << "\n";


	return 0;
}

