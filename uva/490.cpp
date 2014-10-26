
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;

#define SIZE 100

int main() {
	string text[ SIZE ];

	int rown = 0;
	int coln = 0;
	while (getline(cin, text[rown])) {
		coln = max(coln, int(text[rown].size()));
		++rown;
	}

	for (int i = 0; i < coln; ++i) {
		for (int j = rown-1; j >= 0; ++j) {
			if (int(a[i].size()) < coln)
		}
	}

	return 0;
}

