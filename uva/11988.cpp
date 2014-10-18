
#include <list>
#include <string>
#include <iostream>
using namespace std;

#define str_it string::iterator
#define lc_it list<char>::iterator

enum { front, back };

int main() {
	string s;
	list<char> ps;
	lc_it it;

	while ( getline(cin, s) ) {

		ps.clear();
		it = ps.end();

		for ( str_it i = s.begin(); i != s.end(); ++i )
			switch ( *i ) {
				case '[': it = ps.begin(); break;
				case ']': it = ps.end(); break;
				default: ps.insert(it, *i);
				break;
			}

		for ( lc_it i = ps.begin(); i != ps.end(); ++i )
			cout << *i;
		cout << endl;
	}

	return 0;
}

