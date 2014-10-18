
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

#define MAX_SZ 1000

vector<pair<int, int> > DP[ MAX_SZ ];

int main() {
	int DP_rown;
	for (int i = 0; i < MAX_SZ; ++i)
		DP[i].reserve(1000);

	int w, iq;
	for (DP_rown = 0; cin >> w >> iq; ++DP_rown) {
		DP[DP_rown].push_back(make_pair(w, iq));
	}

	for (int i = 1; i < DP_rown; ++i) {
		for (int j = 0; j < i; ++j) {
		}
	}

	return 0;
}

