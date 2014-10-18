
#include <map>
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

	long long a, b;
	cin >> a >> b;

	if (a <= b) {
		cout << (a-1)*2 << endl;
	} else {
		cout << b*2-1 << endl;
	}

	return 0;
}

