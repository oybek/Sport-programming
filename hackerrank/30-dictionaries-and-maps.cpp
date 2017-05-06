
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
	int n;
	cin >> n;
	map< string, string > book;

	while( n-- )
	{
		string name, number;
		cin >> name >> number;

		book[ name ] = number;
	}

	string name;
	while( cin >> name )
	{
		if( book.find( name ) != book.end() )
			cout << name << "=" << book[ name ] << "\n";
		else
			cout << "Not found\n";
	}

	return 0;
}

