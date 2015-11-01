
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

#define INF 1000000009
#define SQR(x) ((x)*(x))

typedef unsigned long long uint64;
typedef long long int64;

using namespace std;

string read_word() {
	char c;
	string s;
	while (!cin.eof()) {
		cin.get(c);
		if (!isalpha(c)) {
			cin.putback(c);
			break;
		}
		s.push_back(c);
	}
	return s;
}

int main() {
	string s;
	char c;
	int tram_count = 0, trolley_count = 0;

	while (!cin.eof()) {
		cin.get(c);
		if (isalpha(c)) {
			cin.putback(c);
			s = read_word();
			if (s == "tram")
				++tram_count;
			else
			if (s == "trolleybus")
				++trolley_count;
		}
	}

	if (tram_count > trolley_count)
		cout << "Tram driver\n";
	else
	if (tram_count < trolley_count)
		cout << "Trolleybus driver\n";
	else
		cout << "Bus driver\n";

	return 0;
}

