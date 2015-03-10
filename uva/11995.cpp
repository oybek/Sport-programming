
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

stack<int> S;
queue<int> Q;
priority_queue<int> PQ;

int main() {
	int query_n;
	bool is_queue, is_stack, is_pqueue;

	while (cin >> query_n) {
		is_queue = is_stack = is_pqueue = true;

		while (! S.empty()) S.pop();
		while (! Q.empty()) Q.pop();
		while (!PQ.empty()) PQ.pop();

		bool impossible = false;

		while (query_n--) {
			int q, x;
			cin >> q >> x;

			switch (q) {
				case 1:
					if (is_stack) S.push(x);
					if (is_queue) Q.push(x);
					if (is_pqueue) PQ.push(x);
					break;

				case 2:
					if (is_stack) {
						if (S.empty()) {
							impossible = true;
							break;
						}
						if (S.top() == x)
							S.pop();
						else
							is_stack = false;
					}

					if (is_queue) {
						if (Q.empty()) {
							impossible = true;
							break;
						}
						if (Q.front() == x)
							Q.pop();
						else
							is_queue = false;
					}

					if (is_pqueue) {
						if (PQ.empty()) {
							impossible = true;
							break;
						}
						if (PQ.top() == x)
							PQ.pop();
						else
							is_pqueue = false;
					}
					break;
			}
		}

		if (impossible) {
			cout << "impossible";
		} else
		if (is_queue + is_stack + is_pqueue >= 2) {
			cout << "not sure";
		} else {
			if (is_queue) {
				cout << "queue";
			} else
			if (is_stack) {
				cout << "stack";
			} else
			if (is_pqueue) {
				cout << "priority queue";
			} else {
				cout << "impossible";
			}
		}
		cout << endl;
	}

	return 0;
}

