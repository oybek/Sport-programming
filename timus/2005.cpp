
#include <map>
#include <cmath>
#include <cstdio>
#include <cctype>
#include <string>
#include <vector>
#include <cstdlib>
#include <iostream>
#include <algorithm>

int Edge[6][6];

int countPathLen(const std::vector<int> & v) {

	int sum = 0;

	sum = Edge[1][ *v.begin() ];

	for (int i = 1; i < v.size(); ++i)
		sum += Edge[ v[i-1] ][ v[i] ];
	
	sum += Edge[ *v.rbegin() ][ 5 ];

	return sum;
}

int main() {
	using namespace std;

	int i, j, minPathLen = 50001;
	for (i = 1; i <= 5; ++i)
	for (j = 1; j <= 5; ++j)
		cin >> Edge[i][j];

	vector<int> Path { 2, 3, 4 };
	vector<int> minPath;

	do {
		if (*Path.rbegin() == 3) continue;

		int pathLen = countPathLen(Path);

		if (pathLen < minPathLen) {
			minPathLen = pathLen;
			minPath = Path;
		}

	} while (next_permutation(Path.begin(), Path.end()));

	cout << minPathLen << endl;
	cout << 1 << ' ';
	for (auto e : minPath) {
		cout << e << ' ';
	}
	cout << 5 << endl;

	return 0;
}

