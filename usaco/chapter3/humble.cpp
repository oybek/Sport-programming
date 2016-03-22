
/*
ID: aybek.h2
PROG: humble
LANG: C++
*/

#define PROB_NAME "humble"

#include <cmath>
#include <queue>
#include <bitset>
#include <cstdio>
#include <vector>
#include <cassert>
#include <cstdlib>
#include <climits>
#include <iostream>
#include <algorithm>
using namespace std;

#define N_max 100001
#define K_max 101

typedef long long ll;
ll cur;
int K, N, S[K_max];
priority_queue<int> pQ;

int main()
{
#ifndef LOCAL
	freopen(PROB_NAME".in", "rt", stdin);
	freopen(PROB_NAME".out", "wt", stdout);
#endif
	cin >> K >> N;
	for (int i = 0; i < K; ++i) {
		cin >> S[i];
	}
	for (int i = 0; i < K; ++i) {
		pQ.push(-S[i]);
	}

	for (int i = 0; i < N; ++i) {
		cur = -pQ.top(); pQ.pop();
		while (!pQ.empty() && -pQ.top() == cur) {
			pQ.pop();
		}

		for (int i = 0; i < K; ++i) {
			if (cur*S[i] <= INT_MAX)
				pQ.push(-cur*S[i]);
		}
	}

	cout << cur << endl;

	return 0;
}

