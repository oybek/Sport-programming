
/*
ID: aybek.h2
PROG: humble
LANG: C++11
*/

#define PROB_NAME "humble"

#include <set>
#include <cmath>
#include <queue>
#include <bitset>
#include <cstdio>
#include <vector>
#include <cassert>
#include <cstdlib>
#include <utility>
#include <climits>
#include <iostream>
#include <algorithm>
#include <functional>
using namespace std;

typedef long long i64;
typedef int i32;

#define N_MAX 100001
#define K_MAX 101

i32 K, N, p[ K_MAX ];
i64 humble[ N_MAX ];
i32 humble_sz = 0;

void find_next()
{
	humble[ humble_sz ] = INT_MAX;
	i64 last_humble = humble[ humble_sz-1 ];

	for( i32 j = 0; j < K; ++j )
	{
		i64* it = upper_bound( humble, humble+humble_sz, last_humble,
			[&]( i64 val, i64 x ) {
				return val < x * p[ j ];
			});

		if( it != humble+humble_sz )
			humble[ humble_sz ] = min( humble[ humble_sz ], *it * p[ j ] );
	}

	++humble_sz;
}

i32 main()
{
#ifndef LOCAL
	freopen( PROB_NAME".in", "rt", stdin );
	freopen( PROB_NAME".out", "wt", stdout );
#endif

	// reading input
	cin >> K >> N;
	for( i32 i = 0; i < K; ++i )
		cin >> p[ i ];

	sort( p, p+K );

	humble[ humble_sz++ ] = 1;

	while( N-- )
		find_next();

	cout << humble[ humble_sz-1 ] << endl;

	return 0;
}

