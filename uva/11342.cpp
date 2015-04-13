
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

#define K_MIN 1
#define K_MAX 50000

#define in_range(x, a, b) ((x) >= (a) && (x) <= (b))

vector<int> * ans[K_MAX+1];

void init_ans() {
	int a_max = pow(K_MAX, 1.0/2.0)+1;

	for (int a = 0; a <= a_max; ++a)
		for (int b = a; b <= a_max; ++b)
			for (int c = b; c <= a_max; ++c) {
				int sum = a*a + b*b + c*c;
				if (in_range(sum, K_MIN, K_MAX) && ans[sum] == nullptr) {
					ans[sum] = new vector<int>();
					ans[sum]->push_back(a);
					ans[sum]->push_back(b);
					ans[sum]->push_back(c);
				}
			}
}

int main() {
	fill(ans, ans+K_MAX+1, nullptr);
	init_ans();

	int test_n, n;
	cin >> test_n;
	while (test_n--) {
		cin >> n;

		assert(in_range(n, K_MIN, K_MAX));

		if (ans[n] != nullptr) {
			cout	<< ans[n]->at(0) << ' '
					<< ans[n]->at(1) << ' '
					<< ans[n]->at(2) << endl;
		} else {
			cout << "-1\n";
		}
	}

	return 0;
}

