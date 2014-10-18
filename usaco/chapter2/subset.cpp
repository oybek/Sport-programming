
/*
ID: aybek.h2
PROG: subset
LANG: C++11
*/

#define PROB_NAME "subset"

#include <map>
#include <fstream>
//#include <iostream>

#define USE_MEMOIZATION

/*
 * functor to count number of ways to represent
 * positive integer as the sum of increasing
 * positive integers
 */
class _f {
	public:
		_f() {}

		inline
		uint32_t operator()(const int n, const int a, const int b) {
			return f(n, a, b);
		}

	private:
#ifdef USE_MEMOIZATION
		std::map<std::pair<uint32_t, int>, int> memo;
		std::map<std::pair<uint32_t, int>, int>::iterator it;
#endif

		uint32_t f(const int n, const int a, const int b) {
			using std::make_pair;

			if (!n)		return 1;
			if (n <	0)	return 0;

#ifdef USE_MEMOIZATION
			if ((it = memo.find(make_pair(n, a))) != memo.end())
				return it->second;
#endif

			uint32_t s = 0;
			for (int i = a; i <= b; ++i)
				s += f(n-i, i+1, b);

#ifdef USE_MEMOIZATION
			memo.insert(make_pair(make_pair(n, a), s));
#endif

			return s;
		}
} f;

int main() {
	std::ifstream cin	(PROB_NAME".in");
	std::ofstream cout	(PROB_NAME".out");

	int n, sum;

	cin >> n;

	sum = n*(n+1)/2;

	if (sum%2) {
		/* if the sum of first positive integers is not
		 * even than it is senselessly to split
		 * it into two sets */
		cout << 0 << std::endl;
	} else {
		cout << f(sum/2, 1, n)/2 << std::endl;
	}


	return 0;
}

