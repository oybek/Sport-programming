
/*
ID: aybek.h2
PROG: transform
LANG: C++11
*/

#include <algorithm>
#include <fstream>

using namespace std;

int8_t ** getGrid(int8_t n)
{
	int8_t ** a	= new int8_t* [n];
	for (int i = 0; i < n; ++i) a[i] = new int8_t [n];
	return a;
}

class boolMatrix {
	public:
		int8_t		size;
		int8_t **	a;
		int8_t **	b;

		boolMatrix(int8_t n) : size(n)
		{
			a = getGrid(size);
			b = getGrid(size);
		}

		inline const boolMatrix & rot90()
		{
			int x, y;
			for (x = 0; x < size; ++x)
				for (y = 0; y < size; ++y)
					b[y][size-x-1] = a[x][y];

			swap(a, b);

			return *this;
		}

		inline const boolMatrix & reflect()
		{
			int x, y;
			for (x = 0; x < size; ++x)
				for (y = 0; y < size; ++y)
					b[x][size-y-1] = a[x][y];
			swap(a, b);
			
			return *this;
		}

		void operator= (const boolMatrix & a2)
		{
			int x, y;
			for (x = 0; x < size; ++x)
				for (y = 0; y < size; ++y)
					a[x][y] = a2.a[x][y];
		}

		void show(ofstream & fout)
		{
			int x, y;
			for (x = 0; x < size; ++x) {
				for (y = 0; y < size; ++y)
					fout << a[x][y];
				fout << '\n';
			}
		}
};

bool operator== (const boolMatrix & a1
		, const boolMatrix & a2)
{
	int x, y;
	for (x = 0; x < a1.size; ++x)
		for (y = 0; y < a1.size; ++y)
			if (a1.a[x][y] != a2.a[x][y])
				return false;
	return true;
}

int main()
{
	ifstream fin	("transform.in");
	ofstream fout	("transform.out");

	int n, x, y;

	fin >> n;
	boolMatrix m1(n), m2(n), m3(n);

	for (x = 0; x < n; ++x) for (y = 0; y < n; ++y) fin >> m1.a[x][y];
	for (x = 0; x < n; ++x) for (y = 0; y < n; ++y) fin >> m2.a[x][y];

	m3 = m1;
	m3.rot90();
	if (m3 == m2) 	{ fout << "1\n"; return 0; }
	m3.rot90();
	if (m3 == m2) 	{ fout << "2\n"; return 0; }
	m3.rot90();
	if (m3 == m2)	{ fout << "3\n"; return 0; }

	if (m1 == m2)	{ fout << "6\n"; return 0; }

	m3 = m1;
	m3.reflect();
	if (m3 == m2)	{ fout << "4\n"; return 0; }
	else {
		m3.rot90();
		if (m3 == m2) { fout << "5\n"; return 0; }
		m3.rot90();
		if (m3 == m2) { fout << "5\n"; return 0; }
		m3.rot90();
		if (m3 == m2) { fout << "5\n"; return 0; }
	}

	fout << "7\n"; return 0;
}

