
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
#define SQR(x) ((x)*(x))
#define ALL(a) a.begin(), a.end()
#define DIVC(a, b) (a/b+(a%b?1:0))

typedef unsigned long long uint64;
typedef long long int64;

using namespace std;

int main() {
	string s;
	cin >> s;
	reverse(s.begin(), s.end());
	for (int i = 0; i < s.size(); ) {
		if (s.substr(i, 1) == "1")
			i += 1;
		else
		if (s.substr(i, 2) == "41")
			i += 2;
		else
		if (s.substr(i, 3) == "441")
			i += 3;
		else {
			cout << "NO";
			return 0;
		}
	}
	cout << "YES";

	return 0;
}

