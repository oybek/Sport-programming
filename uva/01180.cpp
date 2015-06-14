
#include <cmath>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

bool is_prime(long long n) {
	if ( n < 2 ) return false;
	if ( n == 2 ) return true;
	if ( !(n%2) ) return false;

	long long i, m = sqrt(n);
	for ( i = 3; i <= m; i += 2 ) {
		if ( !(n % i) )
			return false;
	}
	return true;
}

int main() {
	int N, curline;
	char c;
	vector<long long> p;

	cin >> N;
	p.resize(N);
	for ( int i = 0; i < (int) p.size(); ++i ) {
		while ( !isdigit(c = cin.get()) );
		cin.putback(c);
		cin >> p[i];
	}

	sort(p.begin(), p.end());

	curline = 1;
	for ( int i = 0; i < (int) p.size(); ++i ) {
		while ( curline < p[i] ) {
			cout << endl;
			++curline;
		}	

		cout << (is_prime(p[i]) && is_prime((1ll<<p[i]) - 1) ? "Yes": "No");
	}
	cout << endl;

	return 0;
}

