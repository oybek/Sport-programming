
#include <string>
#include <cassert>
#include <iostream>
#include <algorithm>
using namespace std;

struct bottle_t {
	int b, g, c;
};

int count_moves(bottle_t v[3], string s) {
	int ans = 0;

	switch (s[0]) {
		case 'B': ans += v[1].b + v[2].b; break;
		case 'G': ans += v[1].g + v[2].g; break;
		case 'C': ans += v[1].c + v[2].c; break;
	}

	switch (s[1]) {
		case 'B': ans += v[0].b + v[2].b; break;
		case 'G': ans += v[0].g + v[2].g; break;
		case 'C': ans += v[0].c + v[2].c; break;
	}

	switch (s[2]) {
		case 'B': ans += v[0].b + v[1].b; break;
		case 'G': ans += v[0].g + v[1].g; break;
		case 'C': ans += v[0].c + v[1].c; break;
	}

	return ans;
}

int main() {
	bottle_t b[3];

	while (cin	>> b[0].b >> b[0].g >> b[0].c
				>> b[1].b >> b[1].g >> b[1].c
				>> b[2].b >> b[2].g >> b[2].c)
	{
		string str = "BCG";
		string min_str = "BCG";
		int min_mov = count_moves(b, str);

		do {
			int mov = count_moves(b, str);

			if (mov < min_mov) {
				min_mov = mov;
				min_str = str;
			}
		} while (next_permutation(str.begin(), str.end()));

		cout << min_str << ' ' << min_mov << endl;
	}

	return 0;
}

