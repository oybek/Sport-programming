
#include <set>
#include <map>
#include <queue>
#include <cmath>
#include <bitset>
#include <cstdio>
#include <string>
#include <vector>
#include <cstring>
#include <climits>
#include <iostream>
#include <algorithm>

using namespace std;

typedef string::iterator si;

#define INF INT_MAX-1
#define for_(t, i, a, b) for (t i = t(a); i != t(b); ++i)
#define rep_(n) for_(int, i_, 0, n)

/*
 * library for working with fractions
 * Debug version (20:30 28/09/2014)
 */

int gcd(int a, int b) {
	int c;
	while (a != 0) {
		c = a; a = b%a; b = c;
	}
	return b;
}

/* FIXME: denominator must be positive number */
class fraction {
	public:
		fraction(int n = 0, int d = 1)
		{
			set(n, d);
		}

		void set(int n, int d)
		{
			int m = gcd(abs(n), abs(d));
			this->n = n/m;
			this->d = d/m;
			move_sign();
		}

		/* moves sign from denominator to numerator */
		void move_sign() {
			if (d < 0) {
				d = -d;
				n = -n;
			}
		}

		const fraction & operator = (const int n) { this->n = n; this->d = 1; return *this; }

		const fraction operator + (const fraction & f2) const { return fraction(n*f2.d + f2.n*d, d * f2.d); }
		const fraction operator - (const fraction & f2) const { return fraction(n*f2.d - f2.n*d, d * f2.d); }
		const fraction operator * (const fraction & f2) const { return fraction(n*f2.n, d*f2.d); }
		const fraction operator / (const fraction & f2) const { return fraction(n*f2.d, d*f2.n); }

		const fraction & operator += (const fraction & f2) { return *this = *this + f2; }
		const fraction & operator -= (const fraction & f2) { return *this = *this - f2; }
		const fraction & operator *= (const fraction & f2) { return *this = *this * f2; }
		const fraction & operator /= (const fraction & f2) { return *this = *this / f2; }

		const fraction operator * (const int k) { return fraction(n*k, d); }

		const fraction operator - () { return fraction(-n, d); }

		inline friend
		const fraction operator / (const int k, const fraction & f) {
			return fraction(f.d*k, f.n);
		}

		bool operator == (const int n) { return this->n == n*this->d; }
		bool operator < (const fraction & n) const { return this->n*n.d < n.n*this->d; }
		bool operator > (const fraction & n) const { return this->n*n.d > n.n*this->d; }

		string str() {
			move_sign();
			string s;

			if (*this == 0)
				return string("0");
			s = int_to_str(n) + (d != 1 ? "/"+int_to_str(d): "");

			return s;
		}

		friend
		istream & operator >> (istream & in, fraction & f) {
			f.d = 1;
			in >> f.n;
			return in;
		}

		friend
		ostream & operator << (ostream & out, fraction & f) {
			f.move_sign();
			out << f.n << '/' << f.d;

			return out;
		}

		int n, d; /* numerator and denominator */

	private:
		string int_to_str(int n) {
			string s;

			for (int m = abs(n); m > 0; m /= 10)
				s.push_back(m%10 + '0');

			if (n < 0) {
				s.push_back('-');
			}
			reverse(s.begin(), s.end());
			return s;
		}
};

void remove_trailing_blanks(char * s)
{
	while (*s != '\0') ++s;
	while (isblank(*s)) --s;
	*++s = '\0';
}

#define MAX_N 1000
bitset<MAX_N+1> w[MAX_N];
int a_sz;
fraction a[ 400000 ];

void gen_fractions(int n, int k)
{
	a_sz = 0;
	for (int i = 0; i < MAX_N+1; ++i)
		w[i].reset();

	fraction f;
	for (int i = 1; i <= n; ++i)
		for (int j = i+1; j <= n; ++j)
		{
			f.set(i, j);
			if (!w[f.n][f.d])
			{
				a[ a_sz++ ] = f;
				w[f.n][f.d] = 1;
			}
		}
}

int main()
{
	int n, k;
	while (scanf("%d%d", &n, &k) != EOF)
	{
		gen_fractions(n, k);
		sort(a, a+a_sz);
		a[ a_sz++ ].set(1, 1);
		printf("%d/%d\n", a[k-1].n, a[k-1].d);
	}

	return 0;
}

