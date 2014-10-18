
#include <iostream>
#include <cmath>
#include <list>

#define TEST_NUM 10

namespace nums {

	template <class T>
	T pow_mod(T base, T exp, T mod) {
		T x = 1;
		T power = base % mod;

		for (T i = 0; i < sizeof(T) * 8; i++) {
			T least_sig_bit = 0x00000001 & (exp >> i);
			if (least_sig_bit)
				x = (x * power) % mod;
			power = (power * power) % mod;
		}

		return x;
	}
	template <class T>
	class c_rand {
		public:
			c_rand() {
				int * p = new int;
				srand(reinterpret_cast<int64_t>(p));
				delete p;
			}
			T num_from(T min, T max) {
				return min
					+ static_cast<T>(ceil(max * (rand() / (RAND_MAX + 1.0))));
			}
		private:
	};

	class c_prime {
		private:
			c_rand<int32_t> rander;
			std::list<int64_t> m_list;

		public:
			c_prime(): m_list { 2, 3 } {}
			~c_prime() {}

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
			bool fermat(int64_t n) {
				for (size_t i = 0; i < TEST_NUM; ++i) {
					int64_t a = rander.num_from(2, n-1);

					if (pow_mod(a, n, n) != a) {
						return false;
					}
				}

				return true;
			}
	} is_prime;
}

int main() {
	using namespace std;
	using namespace nums;

	c_rand<int32_t> rander;

	for (;;) {
		int32_t n;

		cin >> n;
		if (n == 0) break;

		if (is_prime(n)) {
			cout << n << " is normal." << endl;
		} else {
			if (is_prime.fermat(n)) {
				cout << "The number " << n
					 << " is a Carmichael number." << endl;
			} else {
				cout << n << " is normal." << endl;
			}
		}
	}


	return 0;
}

