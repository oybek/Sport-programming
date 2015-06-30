
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

#define INF 1000000001
#define SQR(x) ((x)*(x))

typedef unsigned long long uint64;
typedef long long int64;

using namespace std;

#define n_MAX 1001
typedef pair<int, int> pii;

vector<int> S;
vector<pii> sum;

void reset() {
	sum.resize(0);
	S.resize(0);
}

bool cmp(pii a1, pii a2) {
	return a1.first + a1.second < a2.first + a2.second;
}

bool read_test() {
	int n;
	cin >> n;
	S.resize(n);
	for (int i = 0; i < n; ++i)
		cin >> S[i];
	return !(n == 0);
}

void solve() {
	sort(S.begin(), S.end());

	for (int i = 0; i < S.size(); ++i)
		for (int j = i+1; j < S.size(); ++j)
			sum.push_back(make_pair(S[i], S[j]));

	sort(sum.begin(), sum.end(), cmp);

	int t = -INF;
	for (int i = 0; i < S.size(); ++i)
		for (int j = i+1; j < S.size(); ++j) {
			vector<pii>::iterator it = lower_bound(sum.begin(), sum.end(), make_pair(0, S[j]-S[i]), cmp);

			if (it->first != S[i] && it->first != S[j] &&
				it->second!= S[i] && it->second!= S[j] &&
				it->first + it->second + S[i] == S[j]) {
				/*cout	<< it->first << ' '*/
						/*<< it->second << ' '*/
						/*<< S[i] << ' '*/
						/*<< S[j] << endl;*/
				t = max(S[j], t);
			}
		}

	if (t != -INF) {
		cout << t << endl;
	} else {
		cout << "no solution\n";
	}
}

int main() {
	sum.reserve(1000000);
	S.reserve(1001);

	while (1) {
		reset();
		if (!read_test())
			break;
		solve();
	}

	return 0;
}

