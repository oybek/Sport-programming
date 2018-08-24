
#include <vector>
#include <cassert>
#include <iostream>
#include <algorithm>
using namespace std;

struct player {
	int score;
	int rank;
};

void show_ranks(const vector<player>& a) {
	for (auto x : a)
		cout << x.rank << ' ';
	cout << endl;
}

int main() {
	int n;
	int m;
	vector<player> players;
	vector<player> alice;
	
	// read players
	cin >> n;
	players.resize(n);
	for (int i = 0; i < n; ++i) {
		cin >> players[i].score;
	}

	cin >> m;
	alice.resize(m);
	for (int i = 0; i < m; ++i) {
		cin >> alice[i].score;
	}

	// calc players' ranks
	players[0].rank = 1;
	for (int i = 1; i < n; ++i) {
		players[i].rank = players[i-1].rank + (players[i].score == players[i-1].score ? 0 : 1);
	}

	show_ranks(players);

	// run throw alice scores
	for (int i = 0; i < m; ++i) {
		// find min score >= than alice's score
		auto it = lower_bound(players.begin(), players.end(), alice[i]
				, [](auto a1, auto a2) { return a1.score < a2.score; });

		cout << it->rank << endl;

		if (it == players.end())
			alice[i].rank = 1;
		else {
			if (it->score > alice[i].score)
				alice[i].rank = it->rank+1;
			else
			if (it->score == alice[i].score)
				alice[i].rank = it->rank;
			else
				assert(false);
		}
	}

	// print alice score
	for (auto x : alice)
		cout << x.rank << endl;

	return 0;
}

