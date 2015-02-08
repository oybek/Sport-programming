
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

using namespace std;

#define a_sz_MAX 100001

int clp2(int x) {
	--x;
	x |= x>>1;
	x |= x>>2;
	x |= x>>4;
	x |= x>>8;
	x |= x>>16;
	return ++x;
}

template <class T>
class segment_tree {
	private:
		int a_sz;
		vector<T> t;

		int query(int cur, int a, int b, int l, int r) {
			if (l > r) {
				return 0;
			} else if (a == l && b == r) {
				return t[cur];
			} else {
				int m = (a+b)/2;
				return max(
					query(2*cur+1, a, m, l, min(m, r)),
					query(2*cur+2, m+1, b, max(m+1, l), r)
				);
			}
		}

	public:
		segment_tree()
		{}

		void build(const vector<T> & a) {
			a_sz = clp2(a.size());
			t.resize(2*a_sz);
			for (int i = 0; i < a.size(); ++i) {
				t[a_sz-1+i] = a[i];
			}
			for (int i = a_sz-2; i >= 0; --i) {
				t[i] = max(t[2*i+1], t[2*i+2]);
			}
		}

		int query(int l, int r) {
			return query(0, 0, a_sz-1, l, r);
		}
};

int a_sz, query_sz;
vector<int> a, freq, left_bound, right_bound;
segment_tree<int> rmq;

int main() {
	a.reserve(a_sz_MAX);
	freq.reserve(a_sz_MAX);
	left_bound.reserve(a_sz_MAX);
	right_bound.reserve(a_sz_MAX);

	for (;;) {
		/* prepare stage */
		int i, j, k;

		/* input stage */
		cin >> a_sz;
		if (a_sz == 0) break;
		cin >> query_sz;

		a.resize(a_sz);
		freq.resize(a_sz);
		left_bound.resize(a_sz);
		right_bound.resize(a_sz);

		for (vector<int>::iterator it = a.begin(); it != a.end(); ++it) {
			cin >> *it;
		}

		/* precalc frequencies, boundaries */
		for (i = 0; i < a_sz; ) {
			for (j = i+1; j < a_sz && a[i] == a[j]; ++j);
			for (k = i; k < j; ++k) {
				freq[k] = j-i;
				left_bound[k] = i-1;
				right_bound[k] = j;
			}
			i = j;
		}

		rmq.build(freq);

		/* query handle stage */
		while (query_sz--) {
			int x, y;
			cin >> x >> y;
			--x, --y;
			cout << max(
				rmq.query(right_bound[x], left_bound[y]),
				min(y-x+1, max(y-left_bound[y], right_bound[x]-x))
			);
			cout << endl;
		}
	}

	return 0;
}

