
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

		void run() {
			cin >> m;

			int max_e = 0;

			for (i = 0; i < m; ++i) {
				cin >> t;
				if (t > max_e)
					max_e = t;
			}

			cout << max_e << endl;

			for (; 1; ++i) {
				cin >> t;

				if (t == -1)
					break;

				cout << max(max_e, t) << endl;
			}
		}

	private:
		int a[25001], m, i, t;
};

int main(int argc, char ** argv) {
	solution_t solution;
	solution.run();


	return 0;
}

