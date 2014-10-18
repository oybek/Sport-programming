
#include <map>
#include <cmath>
#include <cstdio>
#include <string>
#include <vector>
#include <cstdlib>
#include <iostream>
#include <algorithm>

namespace nums {

	/*
	 * Remember forever:
	 * (a1 +-* a2 +-* ... +-* aN) % n
	 * = ((a1 % n) +-* (a2 % n) +-* ... +-* (aN % n)) % n
	 *
	 * Remember forever:
	 * a^b % n = (a % n)^b % n
	 *
	 */

	/* don't call with double or float */
	template <class T>
	T gcd(T a, T b) {
		T c;
		while (a != 0) {
			c = a; a = b%a; b = c;
		}
		return b;
	}

	/* TODO: bad algorithm, overflow threat in multiplication */
	template <class T>
	T lcm(T a, T b) {
		return a*b/gcd(a, b);
	}

	/* function will add factors of the numbers to the end of vector */
	template <class T>
	inline bool factorize(T n, std::map<T, size_t> & pairs) {
		if (n == 0) return false;
		T i, c;
		for (c = n; c%2 == 0; c /= 2) {
			if (pairs.find(2) == pairs.end())
				pairs[2] = 1;
			else
				++pairs[2];
		}
		T lim = static_cast<T>(sqrt(c))+1;
		for (i = 3; i <= lim; ) {
			if (c%i == 0) {
				if (pairs.find(i) == pairs.end())
					pairs[i] = 1;
				else
					++pairs[i];
				c /= i;
				lim = static_cast<T>(sqrt(c))+1;
			} else { i += 2; }
		}
		if (c > 1) {
			if (pairs.find(c) == pairs.end())
				pairs[c] = 1;
			else
				++pairs[c];
		}
		return true;
	}

	/* Returns number of dividers of n */
	template <class T>
	std::size_t div_num_of(T n) {
		if (n == 0 || n == 1)
			return n;

		std::map<T, size_t> v;
		std::size_t div_num = 1;

		factorize(n, v);
		for (auto e: v) { div_num *= (e.second+1); }

		return div_num;
	}
}

int main() {
	using namespace std;
	using namespace nums;

#ifndef ONLINE_JUDGE                                                          
	freopen("input.txt", "rt", stdin);                                        
	freopen("output.txt", "wt", stdout);                                      
#endif

	int32_t t, n = 1;
	map<int, size_t> v;

	for (size_t i = 0; i < 10; ++i) {
		cin >> t;
		factorize(t, v);
	}

	for (auto e: v) { n *= (e.second+1); }
	cout << n%10 << endl;


	return 0;
}

