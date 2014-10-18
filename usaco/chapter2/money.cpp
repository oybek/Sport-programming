
/*
ID: aybek.h2
PROG: money
LANG: C++11
*/

#define PROB_NAME "money"

#include <map>
#include <vector>
#include <fstream>
#include <iostream>
#include <algorithm>

std::ifstream fin	(PROB_NAME".in");
std::ofstream fout	(PROB_NAME".out");

template <class T>
void showVector(const std::vector<T> & v) {
	for (auto e : v)
		fout << e << ' ';
	fout << std::endl;
}

class dfsClass {
	public:
		dfsClass() {}

		uint64_t dfs(int money, int prev, const std::vector<int> & coins) {

			using namespace std;

			if (money  < 0) { return 0; }
			if (money == 0) { return 1; }

			if ((it = memo.find(make_pair(money, prev))) != memo.end())
				return it->second;
			
			uint64_t s = 0;
			for (size_t i = 0; i < coins.size(); ++i) {

				if (coins[i] >= prev)
					s += dfs(money - coins[i], coins[i], coins);
			}

			memo.insert(make_pair(make_pair(money, prev), s));
			return s;
		}

		inline
		uint64_t operator()(int money, int prev, const std::vector<int> & coins) {
			return dfs(money, prev, coins);
		}

	private:
		std::map<std::pair<int, int>, uint64_t>::iterator it;
		std::map<std::pair<int, int>, uint64_t> memo;
} dfs;

int main() {

	using namespace std;

	int v, n;
	vector<int> coins;
	coins.reserve(25);

	fin >> v >> n;

	coins.resize(v);
	for (auto & e : coins)
		fin >> e;

	sort(coins.begin(), coins.end());
	fout << dfs(n, 0, coins) << endl;


	return 0;
}

