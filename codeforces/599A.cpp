
#include <algorithm>
#include <bitset>
#include <cassert>
#include <climits>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <functional>
#include <iomanip>
#include <iostream>
#include <iterator>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>

#define INF 1000000001
#define SQR(x) ((x)*(x))
#define ALL(a) a.begin(), a.end()
#define DIVC(a, b) ( a/b+(a%b?1:0) )

typedef unsigned long long uint64;
typedef long long int64;

using namespace std;

template< class iteratorT >
void show( string s, iteratorT a, iteratorT b )
{
	cout << s << ':';
	for( ; a != b; ++a )
		cout << ' ' << *a;
	cout << endl;
}

int main()
{
	int a, b, c;
	cin >> a >> b >> c;
	vector<int> v { 2*a+2*c, 2*b+2*c, 2*a+2*b, a+b+c };
	cout << *min_element( v.begin(), v.end() ) << endl;

	return 0;
}

