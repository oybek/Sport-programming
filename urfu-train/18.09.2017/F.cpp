
#include <bits/stdc++.h>

#define inf 1000000001
#define sqr(x) ((x)*(x))
#define all(x) x.begin(), x.end()

typedef unsigned long long ull;
typedef long long ll;

using namespace std;

int count_lower( string s )
{
	int c = 0;
	for( char x : s )
	{
		if( islower(x) )
			++c;
	}
	return c;
}

int count_upper( string s )
{
	int c = 0;
	for( char x : s )
	{
		if( isupper(x) )
			++c;
	}
	return c;
}

int main()
{
	string s;
	cin >> s;

	if( count_lower(s) < count_upper(s) )
	{
		for( char& c : s )
			c = toupper(c);
	}
	else
	{
		for( char& c : s )
			c = tolower(c);
	}
	cout << s << endl;

	return 0;
}

