
#include <cctype>
#include <string>
#include <iostream>
using namespace std;

/*int str_to_int(const string & s, int i, int j) {*/
	/*int n = 0;*/
	/*while (i < j) {*/
		/*n *= 10;*/
		/*n += s[i];*/
		/*++i;*/
	/*}*/
	/*return n;*/
/*}*/

int main() {
	int tt;
	string s;

	cin >> tt;
	for (int i = 1; i <= tt; ++i) {
		cout <<"Case "<<i<<": ";
		cin >> s;

		for (int i = 0; i < int(s.size());) {
			if (isdigit(s[i])) {
				int j = i;
				int n = 0;
				for (j = i; isdigit(s[j]); ++j) {
					n *= 10;
					n += s[j]-'0';
				}

				while (n--)
					cout <<s[i-1];
				i = j;
			} else {
				++i;
			}
		}
		cout <<endl;
	}

	return 0;
}

