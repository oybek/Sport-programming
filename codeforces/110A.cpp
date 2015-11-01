
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
#include <numeric>
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

bool lucky(char c) {
	return c == '4' || c == '7';
}

bool is_lucky(string s) {
	return count_if(s.begin(), s.end(), lucky) == s.size();
}

int main() {
	string s;
	cin >> s;
	cout
	<< (is_lucky(
			to_string(
				count_if(s.begin(), s.end(), lucky))) ? "YES" : "NO")
	<< endl;

	return 0;
}

