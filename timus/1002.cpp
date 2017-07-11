
#include <bits/stdc++.h>

#define inf 1000000001
#define sqr(x) ((x)*(x))
#define all(x) x.begin(), x.end()

typedef unsigned long long ull;
typedef long long ll;

using namespace std;

// input data
string phone;
vector< string > a;
vector< string > a2;

string convert(string s)
{
	char to[ 'z'+1 ];
	to['a'] = to['b'] = to['c'] = '2';
	to['i'] = to['j'] = '1';
	to['d'] = to['e'] = to['f'] = '3';
	to['g'] = to['h'] = '4';
	to['k'] = to['l'] = '5';
	to['m'] = to['n'] = '6';
	to['p'] = to['r'] = to['s'] = '7';
	to['t'] = to['u'] = to['v'] = '8';
	to['w'] = to['x'] = to['y'] = '9';
	to['o'] = to['q'] = to['z'] = '0';

	for( char& c : s )
		c = to[ c ];

	return s;
}


vector<int> min_sol;

bool mless( const string& s1, const string& s2 )
{
	return strncmp( s1.c_str(), s2.c_str(), min( s1.size(), s2.size() ) ) < 0;
}

void find_solution( int i, vector<int>& sol )
{
	if( i > phone.size() )
		return;

	if( min_sol.size() > 0 && min_sol.size() <= sol.size() )
		return;

	if( i == phone.size() )
	{
		min_sol = sol;
		return;
	}

	auto range = equal_range( all(a2), phone.substr(i), mless );

	for ( ; range.first < range.second; ++range.first )
	{
		sol.push_back( range.first - a2.begin() );
		find_solution( i + range.first->size(), sol );
		sol.pop_back();
	}
}


string fuck()
{
	map< string, string > phone2word;

	a2.reserve( a.size() );

	for( string s : a )
	{
		string s2 = convert( s );

		// ignore duplicates
		if( phone2word.find( s2 ) == phone2word.end() )
		{
			phone2word[ s2 ] = s;
			a2.push_back( s2 );
		}
	}

	sort( all(a2) );
	//show( a2 );
	//show( phone2word );

	vector<int> sol;
	find_solution( 0, sol );
	
	if( min_sol.size() == 0 )
	{
		return "No solution.";
	}
	else
	{
		string s;
		for( int i : min_sol )
			s += phone2word[ a2[ i ] ] + ' ';

		return s;
	}
}

int main()
{
	phone.reserve(101);
	a.reserve(50001);

	for( ;; )
	{
		cin >> phone;
		if( phone == "-1" )
		{
			break;
		}
		else
		{
			int n;
			cin >> n;
			a.resize(n);
			for( string& s : a )
				cin >> s;

			min_sol.clear();
			cout << fuck() << endl;
		}
	}

	return 0;
}

