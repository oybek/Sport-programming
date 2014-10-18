
/*
ID: aybek.h2
PROG: concom
LANG: C++
*/

#define PROB_NAME "concom"

#include <vector>
#include <fstream>
#include <iostream>

#define repeat(n) for (int _i = 0; _i < (n); ++_i)

std::ifstream fin	(PROB_NAME".in");
std::ofstream fout	(PROB_NAME".out");

#define MAX_COM 101

int owns[ MAX_COM ][ MAX_COM ] = {}, n;
int control[ MAX_COM ][ MAX_COM ] = {};

bool does_control(int i, int j) {
	using namespace std;
	//cout << i << ' ' << j << endl;

	if (i == j || owns[i][j] > 50)
		return true;
	if (control[i][j] != -1)
		return control[i][j];

	int s = 0, x;
	for (x = 1; x <= n; ++x) {
		//cout << x << ' ' << i << ' ' << j << endl;
		if ((x != i) && (x != j) &&
			(control[i][x] = does_control(i, x)))
			s += owns[x][j];
	}

	return (control[i][j] = (s > 50));
}

int main() {
	using namespace std;

	int i, j, p;
	fin >> n;
	repeat(n) {
		fin >> i >> j >> p;
		owns[i][j] = p;
	}

	for (i = 1; i <= n; ++i)
		for (j = 1; j <= n; ++j)
			control[i][j] = -1;

	for (i = 1; i <= n; ++i)
		for (j = 1; j <= n; ++j) {
			cout << i << ' ' << j << endl;
			control[i][j] = does_control(i, j);
		}

	for (i = 1; i <= n; ++i)
		for (j = i+1; j <= n; ++j)
			if (control[i][j])
				fout << i << ' ' << j << endl;

	return 0;
}

