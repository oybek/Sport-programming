
#include <bits/stdc++.h>

#define inf 1000000001
#define sqr(x) ((x)*(x))
#define all(x) x.begin(), x.end()

typedef unsigned long long ull;
typedef long long ll;

using namespace std;

int main()
{
	string s;
	getline( cin, s );

	for( int i = s.size()-1; i >= 0; --i )
	{
		if( isalpha( s[i] ) )
		{
			switch( toupper(s[i]) )
			{
				case 'A':
				case 'E':
				case 'I':
				case 'O':
				case 'U':
				case 'Y':
					cout << "YES" << endl;
					break;
				default:
					cout << "NO" << endl;
					break;
			}
			break;
		}
	}

	return 0;
}

