
/*
ID: aybek.h2
PROG: holstein
LANG: C++
*/

#define PROB_NAME "holstein"

#include <cmath>
#include <limits>
#include <cassert>
#include <fstream>
//#include <iostream>

#define MAX_VITAMIN_TYPE	25
#define MAX_FEED			15

std::ifstream cin	(PROB_NAME".in");
std::ofstream cout	(PROB_NAME".out");

inline void sum(int * a, int * b, int size) {
	for (; size--; ++a, ++b) *a += *b;
}

inline bool does_req(int * a, int * b, int size) {
	for (; size--; ++a, ++b)
		if (*a < *b)
			return false;
	return true;
}

inline int number_of1(int n) {
	int m;
	for (m = 0; n; n >>= 1)
		if (n&1)
			++m;
	return m;
}

int main()
{
	using namespace std;

	int v_size, g_size, i, j, ind, lim;
	int v[ MAX_VITAMIN_TYPE ];
	int g[ MAX_FEED ][ MAX_VITAMIN_TYPE ];
	int food[ MAX_VITAMIN_TYPE ];
	int minimal = numeric_limits<int>::max();

/* input area */
	cin >> v_size;
	for (i = 0; i < v_size; ++i)
		cin >> v[i];

	cin >> g_size;
	lim = 1<<g_size;

	for (i = 0; i < g_size; ++i)
		for (j = 0; j < v_size; ++j)
			cin >> g[i][j];


/* brute force */
	for (ind = 1; ind < lim; ++ind) {
		for (i = 0; i < v_size; ++i)
			food[i] = 0;

		for (i = 0; i < g_size; ++i) {
			if (ind&(1<<i))
				sum(food, g[i], v_size);
		}

		if (does_req(food, v, v_size)) {
			if (number_of1(minimal) > number_of1(ind))
				minimal = ind;
		}
	}

/* output */
	cout << number_of1(minimal);
	for (i = 0; i < g_size; ++i)
		if (minimal&(1<<i))
			cout << ' ' << i+1;
	cout << endl;


	return 0;
}

