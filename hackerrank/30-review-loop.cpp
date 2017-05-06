
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

int main()
{
	int T;
	cin >> T;
	while( T-- )
	{
		string s;
		cin >> s;

		for( int i = 0; i < s.size(); i += 2 )
			cout << s[i];
		cout << ' ';
		for( int i = 1; i < s.size(); i += 2 )
			cout << s[i];
		cout << endl;
	}

	return 0;
}

