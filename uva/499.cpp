
#include <cctype>
#include <cstdio>
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int freq[ 256 ], c;
	string s;

	while (1) {
		fill(freq, freq+256, 0);
		s.clear();

		int max_freq = 0;
		while (((c = getchar()) != '\n') && (c != EOF))
			if (isalpha(c))
				max_freq = max(max_freq, ++freq[c]);

		if (feof(stdin))
			break;

		if (max_freq == 0)
			break;

		for (int i = 0; i < 256; ++i)
			if (freq[i] == max_freq)
				s.push_back(char(i));

		cout << s << ' ' << max_freq << endl;
	}

	return 0;
}

