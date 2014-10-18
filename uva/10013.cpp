
#include <cmath>
#include <vector>
#include <cassert>
#include <iostream>
#include <algorithm>

int main()
{
	using namespace std;

	bool first = true;
	int N, M, i, carry;
	vector<int> a; a.reserve(1000000);
	vector<int> b; b.reserve(1000000);

	cin >> N;
	while ( N-- )
	{
		cin >> M;
		a.resize(M);
		b.resize(M);

		for ( i = 0; i < M; ++i )
			cin >> a[i] >> b[i];

		carry = 0;
		for ( i = M-1; i >= 0; --i ) {
			a[i] += b[i] + carry;
			carry = a[i] / 10;
			a[i] %= 10;
		}

		if (first == true) first = false;
		else cout << endl;
		for ( auto e : a )
			cout << e;
		cout << endl;
	}

	return 0;
}

