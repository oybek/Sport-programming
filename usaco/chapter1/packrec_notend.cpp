
/*
ID: aybek.h2
PROG: packrec
LANG: C++11
*/

#define PROB_NAME "packrec"

#include <algorithm>
#include <fstream>
#include <vector>

#define REC_NUM 	4

using namespace std;

struct rec_t {
	int i, a, b;

	rec_t() : a(0), b(0)		{}

	inline void rotate()
	{
		swap(a, b);
	}

	inline int area() { return a*b; }
};

bool operator== (const rec_t & r1, const rec_t & r2)
{
	return (r1.i == r2.i);
}

bool operator< (const rec_t & r1, const rec_t & r2)
{
	return (r1.i < r2.i);
}

int		minArea = 0x8000000;
rec_t	minRec[ 100 ];
int		tos = 0;

void insert(const rec_t & r)
{
	int i;
	for (i = tos%REC_NUM; i > 0 && r.a < minRec[i].a; --i)
		minRec[i] = minRec[i-1];
	minRec[i] = r;
	++tos;
}

rec_t makePack(const vector<rec_t> & r, int way)
{
	int i, size = r.size()-1;
	rec_t big;
	switch (way) {

		case 1:
			for (i = 0; i < r.size(); ++i) {
				big.a += r[i].a;
				big.b = max(big.b, r[i].b);
			}
		break;

		case 2:
			for (i = 0; i < size-1; ++i) {
				big.a += r[i].a;
				big.b = max(big.b, r[i].b);
			}
			big.b += r[size-1].b;
			big.a = max(big.a, r[size-1].a);
		break;

		case 3:
			big.a = r[0].a + r[1].a;
			big.b = max(r[0].b, r[1].b);
			big.b += r[2].b;
			big.a = max(big.a, r[2].a);
			big.a += r[3].a;
			big.b = max(big.b, r[3].b);
		break;

		case 4:
		case 5:
			big.a = r[0].a + r[1].a;
			big.b = max(r[0].b, r[1].b);
			big.a += max(r[2].a, r[3].a);
			big.b = max(big.b, r[2].b+r[3].b);
		break;

		case 6:
			big.b = max(r[0].b+r[2].b, r[1].b+r[3].b);
			big.a = r[0].a+r[1].a;

			if (r[0].b < r[1].b)
				big.a = max(big.a, r[2].a+r[1].a);
			if (r[0].b+r[2].b > r[1].b)
				big.a = max(big.a, r[2].a+r[3].a);
			if (r[1].b < r[0].b)
				big.a = max(big.a, r[0].a+r[3].a);

			big.a = max(big.a, r[2].a);
			big.a = max(big.a, r[3].a);
		break;
	}

	return big;
}

int main()
{
	ifstream fin	(PROB_NAME".in");
	ofstream fout	(PROB_NAME".out");

	vector<rec_t> rec(REC_NUM);

	for (int i = 0; i < REC_NUM; ++i) {
		fin >> rec[i].a >> rec[i].b;
		if (rec[i].a > rec[i].b)
			rec[i].rotate();
		rec[i].i = i;
	}

	do {
		for (int i = 1; i <= 6; ++i) {
			rec_t curRec = makePack(rec, i);

			if (curRec.area() < minArea) {
				tos = 0;
				minRec[tos++] = curRec;
				minArea = curRec.area();
			} else if (curRec.area() == minArea) {
				insert(curRec);
			}
		}
	} while (next_permutation(rec.begin(), rec.end()));

	fout << minArea << '\n';
	for (int i = 0; minArea == minRec[i].area(); ++i)
		fout << minRec[i].a << ' ' << minRec[i].b << '\n';


	return 0;
}

