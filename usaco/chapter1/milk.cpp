
/*
ID: aybek.h2
PROG: milk
LANG: C++11
*/

#define PROB_NAME "milk"

#include <algorithm>
#include <fstream>
#include <vector>

using namespace std;

struct milk_t {
	int prise;
	int amount;
};

bool operator< (const milk_t & a1, const milk_t & a2)
{
	return a1.prise < a2.prise;
}

int main()
{
	ifstream fin	(PROB_NAME".in");
	ofstream fout	(PROB_NAME".out");

	int reqMilk, farmNum;
	fin >> reqMilk >> farmNum;

	vector<milk_t> farmer(farmNum);
	for (int i = 0; i < farmNum; ++i)
		fin >> farmer[i].prise >> farmer[i].amount;

	sort(farmer.begin(), farmer.end());

	int totalPrise = 0;

	for (int i = 0; i < farmNum; ++i) {
		if (farmer[i].amount <= reqMilk) {
			totalPrise += farmer[i].amount * farmer[i].prise;
			reqMilk -= farmer[i].amount;
		} else {
			totalPrise += reqMilk * farmer[i].prise;
			reqMilk -= reqMilk;
		}

		if (reqMilk == 0)
			break;
	}

	fout << totalPrise << '\n';
 
	return 0;
}

