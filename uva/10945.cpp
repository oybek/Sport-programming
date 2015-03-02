
#include <set>
#include <map>
#include <list>
#include <stack>
#include <queue>
#include <cmath>
#include <bitset>
#include <cstdio>
#include <string>
#include <vector>
#include <cassert>
#include <cstring>
#include <climits>
#include <iomanip>
#include <iostream>
#include <algorithm>

#define INF INT_MAX-1
#define SQR(x) ((x)*(x))

typedef unsigned long long uint64;
typedef long long int64;

using namespace std;

bool is_palindrome(const string & s) {
	int i = 0;			while (i < s.size()	&& !isalpha(s[i])) ++i;
	int j = s.size()-1;	while (j >= 0		&& !isalpha(s[j])) --j;

	while (i < j) {
		if (tolower(s[i]) != tolower(s[j]))
			return false;
		++i, --j;
		while (i < s.size()	&& !isalpha(s[i])) ++i;
		while (j >= 0		&& !isalpha(s[j])) --j;
	}
	return true;
}

int main() {
	string s;
	while (1) {
		getline(cin, s);

		if (s == "DONE")
			break;

		cout << (is_palindrome(s) ? "You won't be eaten!" : "Uh oh..") << endl;
	}

	return 0;
}

