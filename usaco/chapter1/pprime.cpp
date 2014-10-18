
/*
ID: aybek.h2
PROG: pprime
LANG: C++11
*/

#define PROB_NAME "pprime"

#include <list>
#include <cmath>
#include <fstream>

int a, b;
std::ifstream cin	(PROB_NAME".in");
std::ofstream cout	(PROB_NAME".out");

/* class to work with prime nums
 *
 * complexity of is_prime is O(sqrt(n))
 * complexity of fermat is O(1)
 *
 * by default functor uses is_prime function
 */
class prime_t {
	private:
		std::list<int> m_list;

	public:
		prime_t(): m_list { 2, 3 } {}
		~prime_t() {}

		/* TODO: optimize */
		bool is_prime(int n) {
			int sqr_of_n = static_cast<int>(floor(std::sqrt(n)));

			for (int i; m_list.back() < sqrt(n); m_list.push_back(i)) {
				for (i = m_list.back()+2; !is_prime(i); i += 2);
			}

			for (auto e: m_list) {
				if (e > sqr_of_n) break;
				if (n%e == 0) return false;
			}

			return true;
		}

		bool operator()(int n) {
			return is_prime(n);
		}

} is_prime;

void handle_pal(int);

void hand1pal()
{
	int d[3];
	for (d[0] = 1; d[0] <= 9; d[0] += 2) {
		int pal
			= d[0];

		handle_pal(pal);
	}
}

void hand2pal()
{
	int d[3];
	for (d[0] = 1; d[0] <= 9; d[0] += 2) {
		int pal
			= d[0]*10
			+ d[0];

		handle_pal(pal);
	}
}

void hand3pal()
{
	int d[3];
	for (d[0] = 1; d[0] <= 9; d[0] += 2)
	for (d[1] = 0; d[1] <= 9; ++d[1]) {
		int pal
			= d[0]*100
			+ d[1]*10
			+ d[0];
		handle_pal(pal);
	}
}

void hand4pal()
{
	int d[3];
	for (d[0] = 1; d[0] <= 9; d[0] += 2)
	for (d[1] = 0; d[1] <= 9; ++d[1]) {
		int pal
			= d[0]*1000
			+ d[1]*100
			+ d[1]*10
			+ d[0];
		handle_pal(pal);
	}
}

void hand5pal()
{
	int d[3];
	for (d[0] = 1; d[0] <= 9; d[0] += 2)
	for (d[1] = 0; d[1] <= 9; ++d[1])
	for (d[2] = 0; d[2] <= 9; ++d[2]) {
		int pal
			= d[0]*10000
			+ d[1]*1000
			+ d[2]*100
			+ d[1]*10
			+ d[0];
		handle_pal(pal);
	}
}

void hand6pal()
{
	int d[6];
	for (d[0] = 1; d[0] <= 9; d[0] += 2)
	for (d[1] = 0; d[1] <= 9; ++d[1])
	for (d[2] = 0; d[2] <= 9; ++d[2]) {
		int pal
			= d[0]*100000
			+ d[1]*10000
			+ d[2]*1000
			+ d[2]*100
			+ d[1]*10
			+ d[0];
		handle_pal(pal);
	}
}

void hand7pal()
{
	int d[7];
	for (d[0] = 1; d[0] <= 9; d[0] += 2)
	for (d[1] = 0; d[1] <= 9; ++d[1])
	for (d[2] = 0; d[2] <= 9; ++d[2])
	for (d[3] = 0; d[3] <= 9; ++d[3]) {
		int pal
			= d[0]*1000000
			+ d[1]*100000
			+ d[2]*10000
			+ d[3]*1000
			+ d[2]*100
			+ d[1]*10
			+ d[0];
		handle_pal(pal);
	}
}

void hand8pal()
{
	int d[9];
	for (d[0] = 1; d[0] <= 9; d[0] += 2)
	for (d[1] = 0; d[1] <= 9; ++d[1])
	for (d[2] = 0; d[2] <= 9; ++d[2])
	for (d[3] = 0; d[3] <= 9; ++d[3]) {
		int pal
			= d[0]*10000000
			+ d[1]*1000000
			+ d[2]*100000
			+ d[3]*10000
			+ d[3]*1000
			+ d[2]*100
			+ d[1]*10
			+ d[0];
		handle_pal(pal);
	}
}

void handle_pal(int pal)
{
	if (pal >= a && pal <= b)
		if (is_prime(pal))
			cout << pal << std::endl;
}

int main()
{
	using namespace std;

	cin >> a >> b;
	hand1pal();
	hand2pal();
	hand3pal();
	hand4pal();
	hand5pal();
	hand6pal();
	hand7pal();
	hand8pal();

	return 0;
}

