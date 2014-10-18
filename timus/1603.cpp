
#include <cmath>
#include <cstdio>
#include <cctype>
#include <string>
#include <vector>
#include <cstdlib>
#include <iostream>
#include <algorithm>

#define repeat(a) for (int i_ = 0; i_ < (a); ++i_)
#define whole(a) a.begin(), a.end()

using namespace std;

class solution_t {
	public:
		solution_t() {}
		~solution_t() {}

		bool isthere(const string & s, int i, int x, int y) {
			bool st;
			if (x >= 0 && y < 4) {
				if (s[i] == grid_copy[x][y]) {
					st = isthere(s, i+1, x-1, y);
					st = isthere(s, i+1, x, y+1);
					st = isthere(s, i+1, x+1, y);
					st = isthere(s, i+1, x, y-1);
				} else {
					st = false;
				}
			} else {
				st = false;
			}

			return st;
		}

		void run() {
			for (i = 0; i < 4; ++i)
				cin >> grid;

			cin >> word_numn;
			for (i = 0; i < word_num; ++i) {
				cin >> word;

				for (i = 0; i < 4; ++i)
					grid_copy[i] = grid[i];

				for (x = 0; x < 4; ++x)
				for (y = 0; y < 4; ++y) {
					isthere(word, x, y);
				}
			}
		}

	private:
		int i, j, x, y, word_num;
		string grid[4];
		string word;

		string grid_copy[4];
};

int main(int argc, char ** argv) {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "rt", stdin);
	freopen("output.txt", "wt", stdout);
#endif
	
	solution_t solution;
	solution.run();


	return 0;
}

