
#include <map>
#include <cmath>
#include <iostream>

bool factorize(int, std::map<int, int> &);
bool isPrime(int);

/* Virtual map */
class DivClass {
#define WAS(n) (ind.find(n) != ind.end())
	public:
		/* checks does m divide n! */
		bool divPrime(int n, int mprime) {

			std::map<int, int>::iterator it;
			if (n < mprime) { return false; }

			for (it = ind.begin(); it != ind.end(); ++it) {

				if (it->second % mprime == 0) {
					it->second /= mprime;
					return true;
				}
			}

			int i = 1;
			while (WAS(mprime*i)) {

				if (++i*mprime > n) {
					return false;
				}
			}

			ind.insert(std::make_pair(mprime*i, i));

			return true;
		}

		bool operator()(int n, int m) {

			ind.clear();
			divs.clear();

			std::map<int, int>::iterator it;

			if (n >= m) return true;

			//divs.clear();
			factorize(m, divs);

			for (it = divs.begin(); it != divs.end(); ++it) {

				while (it->second--) {
					if (!divPrime(n, it->first)) {
						return false;
					}
				}
			}

			return true;
		}

	private:
		std::map<int, int> ind;
		std::map<int, int> divs;

} doesDivide; /* checks does m divide n! */

int main() {

	using namespace std;

	int n, m;
	while (cin >> n >> m) {
		if (doesDivide(n, m)) {
			cout << m << " divides " << n << "!\n";
		} else {
			cout << m << " does not divide " << n << "!\n";
		}
	}

	return 0;
}

bool isPrime(int number) {

    if ((number < 2) || (number % 2 == 0))
		return false;
    if (number == 2)
		return true;

    for (int i = 3; (i*i) <= number; i += 2) {
        if (number % i == 0)
			return false;
    }

    return true;
}

bool factorize(int n, std::map<int, int> & pairs) {

#define INCREASE(m, a) if (m.find(a) == m.end()) m[a] = 1 else ++m[a];
		
	if (n == 0)
		return false;

	int i, c;
	for (c = n; c%2 == 0; c /= 2) {
		if (pairs.find(2) == pairs.end())
			pairs[2] = 1;
		else
			++pairs[2];
	}

	int lim = static_cast<int>(sqrt(c))+1;
	for (i = 3; i <= lim; ) {
		if (c%i == 0) {
			if (pairs.find(i) == pairs.end())
				pairs[i] = 1;
			else
				++pairs[i];
			c /= i;
			lim = static_cast<int>(sqrt(c))+1;
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

