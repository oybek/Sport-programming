
#include <cmath>
#include <cstdio>
#include <cctype>
#include <string>
#include <vector>
#include <cstdlib>
#include <iostream>
#include <algorithm>

int main() {
	using namespace std;

#ifndef ONLINE_JUDGE
	freopen("input.txt", "rt", stdin);
	freopen("output.txt", "wt", stdout);
#endif

	string s;
	cin >> s;

	char c;
	int last = s.size()-1, i;
	for (i = last; s[i] == '0' && s[i-1] == '9'; --i);
	c = s[i]; s[i] = '0';
	for (--i; i >= 0 && s[i] == '9'; --i);

	if (i >= 0) {
		s[i]++;
		s[last] += c-1-'0';

		cout << s << endl;

		return 0;
	}

	cout << "-1" << endl;

	return 0;
}

