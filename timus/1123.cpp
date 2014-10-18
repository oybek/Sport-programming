
#include <string>
#include <iostream>
using namespace std;

typedef unsigned int uint;

bool palindrome(int n) {
	string s;
	while (n > 0) {
		s += char(n%10+'0');
		n /= 10;
	}

	for (uint i = 0; i < s.size()/2; ++i)
		if (s[i] != s[s.size()-1-i])
			return false;
	return true;
}

int main() {
	int n;
	cin >> n;
	while (!palindrome(n))
		++n;
	cout << n << endl;

	return 0;
}

