
#include <set>
#include <map>
#include <list>
#include <stack>
#include <queue>
#include <cmath>
#include <bitset>
#include <cstdio>
#include <string>
#include <vector>
#include <cassert>
#include <cstring>
#include <climits>
#include <iomanip>
#include <iostream>
#include <algorithm>

#define INF INT_MAX-1
#define SQR(x) ((x)*(x))

typedef unsigned long long uint64;
typedef long long int64;

using namespace std;

#define N_MAX 26

struct path {
	int len, time;
	path(int alen = 0, int atime = 0)
		: len(alen), time(atime)
	{}
};

int a[N_MAX][N_MAX];
vector<path> paths;

#define FREE -1
#define WALL -2
#define SRC -3
#define DST -4

int main() {
	int N, M;
	string s;

	while (1) {
		cin >> N >> M;
		if (!N && !M)
			break;

		/* input stage */
		for (int i = 0; i < N; ++i) {
			cin >> s;
			for (int j = 0; j < M; ++j) {
				switch (tolower(s[j])) {
					case '#':
						a[i][j] = WALL;
						break;
					case 's':
						a[i][j] = SRC;
						break;
					case '.':
						a[i][j] = FREE;
						break;
					case 't':
						a[i][j] = DST;
						break;
				}
			}
		}
	}

	return 0;
}

