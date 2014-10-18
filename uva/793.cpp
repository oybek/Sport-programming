
#include <cstdio>
#include <vector>
#include <cstring>
#include <iostream>
using namespace std;

#define REP(i, a, b) for (int i = int(a); i <= int(b); i++)

class disjoin_set {
	private:
		vector<int> pset; // 1000 is just an initial number, it is user-adjustable.

	public:
		disjoin_set(int _size = 0) { pset.reserve(10000); init(_size); }
		void init(int _size) { pset.resize(_size); REP (i, 0, _size - 1) pset[i] = i; }
		int find_set(int i) { return (pset[i] == i) ? i : (pset[i] = find_set(pset[i])); }
		void union_set(int i, int j) { pset[find_set(i)] = find_set(j); }
		bool in_same_set(int i, int j) { return find_set(i) == find_set(j); }
};

int main() {
	int N, tt, a, b, suc, unsuc;
	bool first = true;
	disjoin_set nw;
	const int str_l = 128;
	char str[ str_l ], c;

	scanf("%d", &tt);
	while (getchar() != '\n');

	while (tt--) {
		suc = unsuc = 0;

		scanf("%d", &N);
		while (getchar() != '\n');

		nw.init(N+1);
		while (fgets(str, str_l, stdin) && (sscanf(str, "%c%d%d", &c, &a, &b) == 3)) {
			switch(c) {
				case 'c':
					nw.union_set(a, b);
					break;

				case 'q':
					(nw.in_same_set(a, b) ? ++suc: ++unsuc);
					break;
			}
		}

		if (first) first = false;
		else { puts(""); }
		printf("%d,%d\n", suc, unsuc);
	}

	return 0;
}

