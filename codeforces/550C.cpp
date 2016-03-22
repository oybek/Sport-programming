
/* Use <F5> to compile & run program */
/* file.in will be redirected to stdin */
/* in file.out you'll get program stdout */

#include <algorithm>
#include <bitset>
#include <cassert>
#include <climits>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <functional>
#include <iomanip>
#include <iostream>
#include <iterator>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>

#define INF 1000000001

template <class T> inline T SQR(T x) { return x*x; }
template <class T> inline T DIVC(T a, T b) { return a/b+(a%b?1:0); }

typedef unsigned long long ull;
typedef long long ll;

using namespace std;

int Int(char a, char b, char c) {
	return a*100 + b*10 + c;
}

int main() {
	string s;
	cin >> s;

	for (int i = 0; i < s.size(); ++i) {
		if (Int(0, 0, s[i])%8 == 0) {
			cout << "YES\n" << s[i];
			return 0;
		}
		for (int j = i+1; j < s.size(); ++j) {
			if (Int(0, s[i], s[j])%8 == 0) {
				cout << "YES\n" << s[i] << s[j];
				return 0;
			}
			for (int k = j+1; k < s.size(); ++k) {
				if (Int(s[i], s[j], s[k])%8 == 0) {
					cout << "YES\n" << s[i] << s[j] << s[k];
					return 0;
				}
			}
		}
	}
	cout << "NO";

	return 0;
}

