
#include <cctype>
#include <string>
#include <vector>
#include <iostream>

using namespace std;

class solution_t {
	public:
		solution_t() { cin >> test_num; }

		void run() {
			while (test_num--)
				block();
		}

		void block() {
			cin >> gridx >> gridy;

			grid.resize(gridx);
			for (auto & e: grid) { cin >> e; }

			for (int i = 0; i < gridx; ++i) {
				for (int j = 0; j < gridy; ++j) {
					grid[i][j] = tolower(grid[i][j]);

					chmap[ grid[i][j]-'a' ].push_back(make_pair(i, j));
			} }

			cin >> wordn;
			while (wordn--) {
				cin >> word;

				int first_ch = tolower(word[0])-'a';

				for (auto e: chmap[ first_ch ]) {
					if (isnative(word, e)) {
						cout << (e.first)+1 << ' ' << (e.second)+1 << endl;
						break;
					}
				}
			}
		}

		bool isnative(const string & s, const pair<int, int> & e) {
			int n = 8, i = 0, j = 0, x, y;
			for (auto c: s) {
				c = tolower(c);

				x = (e.first)-i, y = e.second;
				if ((x < 0) || (x >= gridx) || (y < 0) || (y >= gridy)) --n;
				else if (grid[x][y] != c) --n;

				x = (e.first)-i, y = (e.second)+j;
				if ((x < 0) || (x >= gridx) || (y < 0) || (y >= gridy)) --n;
				else if (grid[x][y] != c) --n;

				x = e.first, y = (e.second)+j;
				if ((x < 0) || (x >= gridx) || (y < 0) || (y >= gridy)) --n;
				else if (grid[x][y] != c) --n;

				x = (e.first)+i, y = (e.second)+j;
				if ((x < 0) || (x >= gridx) || (y < 0) || (y >= gridy)) --n;
				else if (grid[x][y] != c) --n;

				x = (e.first)+i, y = e.second;
				if ((x < 0) || (x >= gridx) || (y < 0) || (y >= gridy)) --n;
				else if (grid[x][y] != c) --n;

				x = (e.first)+i, y = (e.second)-j;
				if ((x < 0) || (x >= gridx) || (y < 0) || (y >= gridy)) --n;
				else if (grid[x][y] != c) --n;

				x = (e.first)-i, y = e.second;
				if ((x < 0) || (x >= gridx) || (y < 0) || (y >= gridy)) --n;
				else if (grid[x][y] != c) --n;

				x = (e.first)-i, y = (e.second)-j;
				if ((x < 0) || (x >= gridx) || (y < 0) || (y >= gridy)) --n;
				else if (grid[x][y] != c) --n;

				++i, ++j;
			}
			return n;
		}

	private:
		int test_num;
		int gridx, gridy, wordn;

		vector<string> grid;
		string word;

		/* Used to store key coords */
		vector<pair<int, int> > chmap[26];
};

int main() {
	using namespace std;
	solution_t solution;
	solution.run();

	return 0;
}

