
#include <cassert>
#include <iostream>
using namespace std;

#define f91(N) ( N <= 100 ? 91: N-10 )

/*
int f91(int N)
{
	if ( N <= 100 ) return f91( f91( N + 11 ) );
	if ( N >= 101 ) return N - 10;
}
*/


int main()
{
	int n;

	/*
	for ( n = 0; n <= 1000000; ++n ) {
		cout << f91(n) << ' ' << f91c(n) << endl;
		assert( f91(n) == f91c(n) );
	}
	*/

	while ( 1 )
	{
		cin >> n;
		if (!n) break;
		cout << "f91(" << n << ") = " << f91(n) << endl;
	}

	return 0;
}

