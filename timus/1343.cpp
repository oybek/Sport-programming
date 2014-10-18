
/*
http://acm.timus.ru/problem.aspx?space=1&num=1343
*/

#include <list>
#include <cmath>
#include <string>
#include <cassert>
#include <iomanip>
#include <iostream>
#include <algorithm>

#define MEMO_SIZE 1000000

class prime_t {
	private:
		size_t top;
		int64_t memo[ MEMO_SIZE ];

	public:
		prime_t() {
			top = 1;
			memo[0] = 2;
			memo[1] = 3;
		}

		/* TODO: optimize */
		bool is_prime(int64_t n) {

			if (n == 1) return false;

			int64_t i, sqr_of_n = std::floor(std::sqrt(n));

			for (; memo[ top ] < sqr_of_n; ) {
				for (i = memo[ top ] + 2; !is_prime(i); i += 2);
				memo[ ++top ] = i;
			}

			for (i = 0; memo[i] < sqr_of_n; ++i)
				if (n % memo[i] == 0)
					return false;

			return true;
		}

		inline
		bool operator()(int64_t n) {
			return is_prime(n);
		}
} is_prime;

int64_t str_to_int64(std::string s) {

	int64_t n = 0;
	std::string::iterator it = s.begin();

	while (it != s.end()) {
		n *= 10;
		n += (*it-'0');
		++it;
	}

	return n;
}

int main() {
	using namespace std;

	int n;
	string s; s.reserve(12);

	cin	>> n;
	if (n != 0) {
		cin	>> s;
	}

	for (; n < 12; ++n) s += '0';
	int64_t primen = str_to_int64(s);

	if (primen % 2 == 0) ++primen;
	while (!is_prime(primen)) primen += 2;
	cout << std::setw(12) << std::setfill('0') << primen << endl;

	return 0;
}

