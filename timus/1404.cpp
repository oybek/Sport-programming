
#include <cmath>
#include <cstdio>
#include <cctype>
#include <string>
#include <vector>
#include <cstdlib>
#include <iostream>
#include <algorithm>

#define TO_ASCII(a)		((a)+'a')
#define FROM_ASCII(a)	((a)-'a')

int main() {
	using namespace std;

#ifndef ONLINE_JUDGE
	freopen("input.txt", "rt", stdin);
	freopen("output.txt", "wt", stdout);
#endif

	string s;
	cin >> s;

	size_t i;
	for (i = 0; i < s.size(); ++i)		s[i] = FROM_ASCII(s[i]);
	for (i = 1; i < s.size(); ++i)		s[i] += 26;
	for (i = s.size()-1; i > 0; --i)	s[i] -= s[i-1];
	s[0] -= 5;

	for (i = 0; i < s.size(); ++i) s[i] = TO_ASCII(s[i]);
	cout << s << endl;

	return 0;
}

