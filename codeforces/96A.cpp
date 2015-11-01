
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

#define INF 1000000001
#define SQR(x) ((x)*(x))

typedef unsigned long long uint64;
typedef long long int64;

using namespace std;

int main() {
	string s;
	cin >> s;
	if (s.size() < 7 ||
		(s.find("1111111") == string::npos &&
		 s.find("0000000") == string::npos)) {
		cout << "NO";
	} else {
		cout << "YES";
	}

	return 0;
}

