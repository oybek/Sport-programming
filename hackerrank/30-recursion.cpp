
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

#define INF 1000000001
#define SQR(x) ((x)*(x))

typedef unsigned long long uint64;
typedef long long int64;

using namespace std;

int factorial( int n )
{
	if( n == 0 ) return 1;
	return n * factorial( n-1 );
}

int main() {
	int n;
	cin >> n;
	cout << factorial( n );

	return 0;
}

