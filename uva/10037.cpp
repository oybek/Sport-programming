
#include <deque>
#include <sstream>
#include <iostream>
using namespace std;

void insert(deque<int> & v, int e) {
	v.push_back(e);
	int j, x = v.back();
	for ( j = v.size()-2; j >= 0 && v[ j ] < x; --j )
		v[ j+1 ] = v[ j ];
	v[ j+1 ] = x;
}

void show(deque<int> & v) {
	int i;
	for (i = 0; i < (int) v.size(); ++i)
		cout << v[i] << endl;
	cout << endl;
}

int main() {
	bool first;
	int N, x, sz, i, a, b, t;
	deque<int> b1, b2;

	cin >> N;
	while ( N-- ) {
		t = 0;
		first = true;
		b1.resize(0);
		b2.resize(0);

		cin >> sz;
		if ( sz == 1 ) {
			cin >> x;
			cout << x << endl;
			continue;
		}

		for ( i = 0; i < sz; ++i ) {
			cin >> x;
			insert(b1, x);
		}

		while ( ! b1.empty() ) {
			if ( first ) first = false;
			else {
				a = b2.back();
				b2.pop_back();

				insert(b1, a);
				t += a;
			}

			a = b1.back();
			b1.pop_back();
			b = b1.back();
			b1.pop_back();

			insert(b2, a);
			insert(b2, b);

			t += max(a, b);
		}

		cout << t << endl;
	}

	return 0;
}

