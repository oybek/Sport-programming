
#include <map>
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
	private:
		int pack_size;
		bool impossible;
		vector<map<string, int8_t> > pack;
		vector<string> task;
	public:
		solution_t() {}
		~solution_t() {}
		void run() {
			int i;
			bool found;
			string s;
			impossible = false;

			cin >> pack_size;
			pack.resize(pack_size);

			for (auto & e: pack)
				repeat(3) { cin >> s; e[s] = 1; }

			repeat(pack_size) {
				cin >> i; --i;
				found = false;

				for (auto e: pack[i]) {
					if (task.size() == 0) {
						task.push_back(e.first);
						found = true;
						break;
					} else
					if (task.back() < e.first) {
						task.push_back(e.first);
						found = true;
						break;
					}
				}

				if (!found) { impossible = true; break; }
			}

			if (impossible) {
				cout << "IMPOSSIBLE" << endl;
			} else {
				for (auto e: task) { cout << e << endl; }
			}
		}
};

int main() {
	using namespace std;

#ifndef ONLINE_JUDGE
	freopen("input.txt", "rt", stdin);
	freopen("output.txt", "wt", stdout);
#endif

	solution_t solution;
	solution.run();

	return 0;
}

