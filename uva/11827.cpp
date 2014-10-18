
#include <cmath>
#include <vector>
#include <cassert>
#include <sstream>
#include <iostream>
#include <algorithm>
using namespace std;

int gcd( int a, int b ) {
  int c;
  while ( a != 0 ) {
     c = a; a = b%a; b = c;
  }
  return b;
}

int main() {
	int N, n, i, j, max_gcd;
	string s;
	vector<int> num; num.reserve(100);
	stringstream ss;

	cin >> N; getline(cin, s);
	while ( N-- ) {
		getline(cin, s);
		ss.clear();
		ss.str(s);

		num.resize(0);
		while ( ss >> n ) {
			num.push_back(n);
		}

		max_gcd = 1;
		for ( i = 0; i < (int) num.size(); ++i )
			for ( j = i + 1; j < (int) num.size(); ++j )
				max_gcd = max( max_gcd, gcd( num[i], num[j] ) );

		cout << max_gcd << endl;
	}

	return 0;
}

