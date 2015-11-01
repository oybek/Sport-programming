
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

bool vowel['Z'];

int main() {
	string s;
	cin >> s;
	vowel['A'] = vowel['O'] = vowel['Y'] = vowel['E'] = vowel['U'] = vowel['I'] = true;
	for (int i = 0; i < int(s.size()); ++i)
		if (!vowel[toupper(s[i])])
			cout << '.' << char(tolower(s[i]));
	cout << endl;

	return 0;
}

