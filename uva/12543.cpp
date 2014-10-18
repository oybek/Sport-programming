
#include <cctype>
#include <cassert>

#include <string>
#include <iostream>
using namespace std;

inline
bool is_word(const string & s) {
	for ( auto e : s )
		if ( !isalpha(e) && e != '-' )
			return false;
	return true;
}

int main() {
	string ml_word;
	string s;
	while ( cin >> s ) {
		while ( !isalpha(s.front()) && (s.front() != '-') && s.size() )
			s.erase(0, 1);

		while ( !isalpha(s.back()) && (s.back() != '-') && s.size() )
			s.pop_back();

		if ( is_word(s) && s.size() > ml_word.size() )
			ml_word = s;
	}

	for ( auto & e : ml_word )
		e = tolower(e);

	cout << ml_word << endl;

	return 0;
}

