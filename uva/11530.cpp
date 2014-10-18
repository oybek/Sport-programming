
#include <string>
#include <iostream>
using namespace std;

inline
int pressn(char c) {
	switch ( c ) {
		case 'a': case 'd': case 'g': case 'j':
		case 'm': case 'p': case 't': case 'w':
		case ' ':
			return 1;

		case 'b': case 'e': case 'h': case 'k':
		case 'n': case 'q': case 'u': case 'x':
			return 2;

		case 'c': case 'f': case 'i': case 'l':
		case 'o': case 'r': case 'v': case 'y':
			return 3;

		case 's': case 'z':
			return 4;
	}
	return 0;
}

int main() {
	int N, i, j, pn;
	string s;

	cin >> N;
	getline(cin, s);
	for ( i = 1; i <= N; ++i ) {
		getline(cin, s);

		pn = 0;
		for ( j = 0; j < (int) s.size(); ++j ) {
			pn += pressn(s[ j ]);
		}

		cout << "Case #" << i << ": " << pn << endl;
	}

	return 0;
}

