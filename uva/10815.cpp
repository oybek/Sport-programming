
#include <cctype>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

#define every(i, a, b) for (int i = (a); i <= int(b); ++i)
#define repeat(n) every (i, 1, n)

#define SIZE 1000

int main() {
	int c;
	char buf[ SIZE ], * p;
	vector<string> dict;

	p = buf;
	while ((c = getchar()) != EOF) {
		if (isalpha(c)) {
			*p++ = tolower(c);
		} else
		if (p != buf) {
			*p++ = '\0';
			dict.push_back(string(buf, p));
			p = buf;
		}
	}

	sort(dict.begin(), dict.end());
	for (int i = 0; i < int(dict.size()); ++i) {
		if (i == 0 || dict[i] != dict[i-1])
			printf("%s\n", dict[i].c_str());
	}

	return 0;
}

