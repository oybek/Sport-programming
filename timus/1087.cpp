
#include <cmath>
#include <cstdio>
#include <cctype>
#include <string>
#include <vector>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

class solution_t {
	public:
		bool f(int stone_num, bool turn) {

			if (memo[turn][stone_num] != -1)
				return memo[turn][stone_num];

			if (stone_num == 0) { return turn; }

			int i;
			bool r;

			if (turn) {
				if (stone_num-k[0] >= 0)
					r = f(stone_num-k[0], !turn);

				for (i = 1; i < k_size && !r; ++i)
					if (stone_num-k[i] >= 0)
						r = f(stone_num-k[i], !turn);
			} else {
				if (stone_num-k[0] >= 0)
					r = f(stone_num-k[0], !turn);

				for (i = 1; i < k_size && r; ++i)
					if (stone_num-k[0] >= 0)
						r = f(stone_num-k[i], !turn);
			}

			memo[turn][stone_num] = r;
			return r;
		}

		void run() {
			memset(memo[0], -1, 10000);
			memset(memo[1], -1, 10000);
			// input
			cin >> stone_num >> k_size;
			k = new int [k_size];
			for (int i = 0; i < k_size; ++i) { cin >> k[i]; }

			if (f(stone_num, true)) {
				cout << '1' << endl;
			} else {
				cout << '2' << endl;
			}
		}

	private:
		int8_t memo[2][10000];
		int stone_num, k_size, * k;
};

int main() {
	solution_t solution;
	solution.run();

	return 0;
}

