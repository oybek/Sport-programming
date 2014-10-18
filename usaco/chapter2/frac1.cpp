
/*
ID: aybek.h2
PROG: frac1
LANG: C++
*/

#define PROB_NAME "frac1"

#include <vector>
#include <fstream>
#include <algorithm>

#define MAX_FRAC_NUM 7805

std::ifstream cin	(PROB_NAME".in");
std::ofstream cout	(PROB_NAME".out");

struct frac_t {
	int num;
	int dom;

	friend bool operator < (const frac_t & f1, const frac_t & f2) {
		if (f1.num*f2.dom < f2.num*f1.dom)
			{ return true; }
		else
			{ return false; }
	}
};

inline int gcd(int a, int b) {
	int c;
	while (a != 0) {
		c = a; a = b%a; b = c;
	}
	return b;
}

int main()
{
	using namespace std;

	vector<frac_t> frac;
	frac.reserve( MAX_FRAC_NUM );

	int n;
	cin >> n;

	/* count all possible fractions */
	frac_t tf;
	for (int i = 1; i <= n; ++i)
		for (int j = i+1; j <= n; ++j) {
			if (gcd(i, j) == 1) {
				tf.num = i;
				tf.dom = j;
				frac.push_back(tf);
			}
		}

	/* sort in ascending order */
	sort(frac.begin(), frac.end());

	/* write answer */
	cout << "0/1\n";
	for (vector<frac_t>::iterator it = frac.begin(); it != frac.end(); ++it)
		cout << it->num << '/' << it->dom << endl;
	cout << "1/1\n";

	return 0;
}

