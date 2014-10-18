
/*
ID: aybek.h2
PROG: clocks
LANG: C++11
*/

#define PROB_NAME "clocks"

#include <algorithm>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <queue>
#include <list>

#define repeat(a) for (size_t i_ = 0; i_ < (a); ++i_)

const int move[9][3][3] = {
	{
		{ 3, 3, 0 },
		{ 3, 3, 0 },
		{ 0, 0, 0 }
	}, {
		{ 3, 3, 3 },
		{ 0, 0, 0 },
		{ 0, 0, 0 }
	}, {
		{ 0, 3, 3 },
		{ 0, 3, 3 },
		{ 0, 0, 0 }
	}, {
		{ 3, 0, 0 },
		{ 3, 0, 0 },
		{ 3, 0, 0 }
	}, {
		{ 0, 3, 0 },
		{ 3, 3, 3 },
		{ 0, 3, 0 }
	}, {
		{ 0, 0, 3 },
		{ 0, 0, 3 },
		{ 0, 0, 3 }
	}, {
		{ 0, 0, 0 },
		{ 3, 3, 0 },
		{ 3, 3, 0 }
	}, {
		{ 0, 0, 0 },
		{ 0, 0, 0 },
		{ 3, 3, 3 }
	}, {
		{ 0, 0, 0 },
		{ 0, 3, 3 },
		{ 0, 3, 3 }
	}
};

class clock_st {
	public:
		int s[3][3];

		bool is_all_12() {
			for (size_t x = 0; x < 3; ++x) {
				for (size_t y = 0; y < 3; ++y) {
					if (s[x][y] != 12)
						return false;
			} }
			return true;
		}
		void make_move(int i) {
			for (size_t x = 0; x < 3; ++x) {
				for (size_t y = 0; y < 3; ++y) {
					s[x][y] += move[i][x][y];
					if (s[x][y] > 12) { s[x][y] = 3; }
			} }
		}
};

bool next(std::vector<int> & moves) {
	size_t i;
	for (i = 0; i < moves.size() && moves[i] == 3; ++i)
		moves[i] = 0;

	if (i == moves.size()) {
		return false;
	} else {
		++moves[i];
		return true;
	}
}
/* there is no difference in order of moves */
void backtrack(const clock_st & clocks, std::vector<int> & moves) {
	while (next(moves)) {
		clock_st t_clocks = clocks;
		for (size_t i = 0; i < moves.size(); ++i) {
			repeat(moves[i]) t_clocks.make_move(i);
		}
		if (t_clocks.is_all_12())
			break;
	}
}

int main() {
	using namespace std;

	ifstream fin	(PROB_NAME".in");
	ofstream fout	(PROB_NAME".out");

	clock_st clocks;
	vector<int> moves(9);

	for (size_t i = 0; i < 3; ++i)
		for (size_t j = 0; j < 3; ++j)
			fin >> clocks.s[i][j];

	backtrack(clocks, moves);

	size_t i;
	vector<int> sol;
	for (i = 0; i < moves.size(); ++i)
		repeat(moves[i]) sol.push_back(i+1);

	for (i = 0; i+1 < sol.size(); ++i)
		fout << sol[i] << ' ';
	fout << sol.back() << endl;

	return 0;
}

