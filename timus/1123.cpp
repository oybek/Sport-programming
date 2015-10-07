
#include <string>
#include <iostream>
using namespace std;

typedef unsigned int uint;

string make_pal(string s) {
	string tmp = s;
	int i = 0, j = tmp.size()-1;
	while (i < j) {
		tmp[j] = tmp[i];
		++i, --j;
	}
	return tmp;
}

void inc_mid(string & s) {
	int i;
	for (i = s.size()-s.size()/2-1; i >= 0 && s[i] == '9'; --i)
		s[i] = '0';
	++s[i];
}

int main() {
	string s;
	cin >> s;
	string pal = make_pal(s);
	if (pal < s) {
		inc_mid(pal);
		cout << make_pal(pal) << endl;
	} else {
		cout << pal << endl;
	}

	return 0;
}

