
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
#include <unordered_map>

#define INF INT_MAX-1
#define SQR(x) ((x)*(x))

typedef unsigned long long uint64;
typedef long long int64;

using namespace std;

unordered_map<string, int> str_occ;

int main() {
	int N, max_occ;
	string s;
	string max_occ_str;

	while (cin >> N >> s) {
		str_occ.clear();

		max_occ = 0;

		for (int i = 0; i+N <= s.size(); ++i) {
			string sub_str = s.substr(i, N);

			if (str_occ.find(sub_str) != str_occ.end()) {
				++str_occ[ sub_str ];
			} else {
				str_occ[ sub_str ] = 1;
			}

			if (str_occ[ sub_str ] > max_occ) {
				max_occ = str_occ[ sub_str ];
				max_occ_str = sub_str;
			}
		}

		cout << max_occ_str << endl;
	}

	return 0;
}

