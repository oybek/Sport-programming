
#include <map>
#include <cmath>
#include <stack>
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

		void run() {
			int32_t n, a, b;
			string s;

			vector<stack<int32_t> > st;
			map<int16_t, int16_t> ind;

			cin >> n;
			while (n--) {
				cin >> s;
				switch (s[1]) {
					case 'U':
						cin >> a >> b;

						if (ind.find(a) == ind.end()) {
							st.push_back(stack<int32_t>());
							ind[a] = st.size()-1;
						}

						st[ ind[a] ].push(b);
						break;

					case 'O':
						cin >> a;
						cout << st[ ind[a] ].top() << endl;
						st[ ind[a] ].pop();
						break;
				}
			}
		}

	private:
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

