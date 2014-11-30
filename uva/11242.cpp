
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

/*
 * library for working with fractions
 * Debug version (20:30 28/09/2014)
 */

typedef unsigned int uint32;

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

		bool operator != (const fraction & n) const { return this->n*n.d != n.n*this->d; }
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

void show_vector(vector<fraction> & a)
{
	for (uint32 i = 0; i < a.size(); ++i)
		printf("%d/%d\t%f\n", a[i].n, a[i].d, float(a[i].n) / a[i].d);
}

int main()
{
	int n_front, n_rear;
	vector<int> front, rear;
	vector<fraction> ratios;

	while (1)
	{
		ratios.resize(0);

		scanf("%d", &n_front);
		if (n_front == 0)
			break;
		scanf("%d", &n_rear);

		front.resize(n_front);
		rear.resize(n_rear);

		for (int i = 0; i < n_front; ++i)
			scanf("%d", &front[i]);

		for (int i = 0; i < n_rear; ++i)
			scanf("%d", &rear[i]);

		for (int i = 0; i < n_front; ++i)
			for (int j = 0; j < n_rear; ++j)
				ratios.push_back(fraction(rear[j], front[i]));

		sort(ratios.begin(), ratios.end());

		/*{*/
			/*vector<fraction> t;*/
			/*t.push_back(ratios[0]);*/
			/*for (uint32 i = 1; i < ratios.size(); ++i)*/
			/*{*/
				/*if (ratios[i] != ratios[i-1])*/
					/*t.push_back(ratios[i]);*/
			/*}*/
			/*ratios = t;*/
		/*}*/

		fraction spreadMax(0, 1);
		for (uint32 i = 1; i < ratios.size(); ++i)
		{
			fraction t = ratios[i]/ratios[i-1];
			if (t > spreadMax)
				spreadMax = t;
		}

		printf("%.2f\n", roundf(spreadMax.n * 100.0 / spreadMax.d)/100);
	}

	return 0;
}

