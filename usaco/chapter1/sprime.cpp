
/*
ID: aybek.h2
PROG: sprime
LANG: C++11
*/

#define PROB_NAME "sprime"

#include <list>
#include <cmath>
#include <fstream>

std::ifstream cin	(PROB_NAME".in");
std::ofstream cout	(PROB_NAME".out");

class prime_t {
	private:
		std::list<int64_t> m_list;

	public:
		prime_t(): m_list { 2, 3 } {}
		~prime_t() {}

		/* TODO: optimize */
		bool is_prime(int64_t n) {
			int sqr_of_n = static_cast<int>(floor(std::sqrt(n)));

			for (int64_t i; m_list.back() < sqrt(n); m_list.push_back(i)) {
				for (i = m_list.back()+2; !is_prime(i); i += 2);
			}

			for (auto e: m_list) {
				if (e > sqr_of_n) break;
				if (n%e == 0) return false;
			}

			return true;
		}

		bool operator()(int64_t n) {
			return is_prime(n);
		}
} is_prime;

void f(int * d, const int d_size, int i) {
	int n = 0;
	for (int j = 0; j < i; ++j) {
		n *= 10;
		n += d[j];
	}

	if (is_prime(n)) {
		if (i == d_size) {
			cout << n << std::endl;
			return;
		}

		for (d[i] = 1; d[i] <= 9; d[i] += 2)
			f(d, d_size, i+1);
	}
}

int main()
{
	int n;
	int d[8];
	cin >> n;

	d[0] = 2; f(d, n, 1);
	d[0] = 3; f(d, n, 1);
	d[0] = 5; f(d, n, 1);
	d[0] = 7; f(d, n, 1);

	return 0;
}

