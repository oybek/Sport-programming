
#include <cmath>
#include <cstdio>
#include <string>
#include <vector>
#include <cstdlib>
#include <iostream>
#include <algorithm>
using namespace std;

#if 0
int main() {

#ifndef ONLINE_JUDGE
	freopen("input.txt", "rt", stdin);
	freopen("output.txt", "wt", stdout);
#endif

	int n;
	cin >> n;

	// allocating dymanic array
	char ** s = new int* [n];
	for (int i = 0; i < n; ++i) {
		s[i] = new int [n];
	}

	// input datas
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			cin >> s[i][j];
		}
	}

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
		}
	}



	return 0;
}
#endif

namespace LFA {
	class Polygon {
		public:
		private:
		protected:
	};
};

int main()
{
}

