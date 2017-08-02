
#include <bits/stdc++.h>

#define inf 1000000001
template< class T > T sqr( T x ) { return x*x; }
#define all(x) x.begin(), x.end()

typedef unsigned long long ull;
typedef long long ll;

using namespace std;

int N;
string s;
int K;

int main()
{
	cin >> N
		>> s
		>> K;

	for( char& c : s )
		if( isalpha( c ) )
		{
			if( isupper( c ) )
			{
				c = (c-'A'+K)%26+'A';
			}
			else
			{
				c = (c-'a'+K)%26+'a';
			}
		}

	cout << s << endl;

	return 0;
}

