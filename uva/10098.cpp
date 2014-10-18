
#include <cmath>
#include <vector>
#include <cassert>
#include <iostream>
#include <algorithm>
using namespace std;

int main() {

	int N;
	/*bool first = true;*/
	string s;

	cin >> N;
	while ( N-- ) {
		/*if (first) first = false;
		else cout << endl;*/

		cin >> s;

		sort(s.begin(), s.end());

		do {
			cout << s << endl;
		} while ( next_permutation(s.begin(), s.end()) );
		cout << endl;
	}

	return 0;
}

