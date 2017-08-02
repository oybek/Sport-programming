
#include <bits/stdc++.h>

#define inf 1000000001
#define sqr(x) ((x)*(x))
#define all(x) x.begin(), x.end()

typedef unsigned long long ull;
typedef long long ll;

using namespace std;

int main()
{
	string a, b;
	cin >> a >> b;

	vector<int> cnt( 'z'+1 );

	for( char c : a )
		++cnt[ c ];

	for( char c : b )
		--cnt[ c ];

	cout << accumulate( all(cnt), 0 ) << endl;

	return 0;
}

