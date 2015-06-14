
#include <string>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

/*
 * 01:00 16/08/2014 Osh
 * Hashimov Oybek
 * Little library for working with big integers
 * Write me about bugs and suggestions: aybek_hashimov@mail.ru
 */

template <const int V_SIZE>
class integer {
	private:
		int s;			/* number is negative if s < 0 otherwise positive */
		int vn;			/* size of vector v */
		char v[ V_SIZE ];

	public:
		integer() { *this = 0; }
		integer(const int n) { *this = n; }
		integer(const integer & n) { *this = n; }
		integer(const char * str) { *this = str; }

		const integer & operator = (const int a) {
			if (a == 0) {
				s = vn = 1;
				v[0] = 0;
				return *this;
			}

			s = a < 0 ? -1: 1;
			int b = std::abs(a);
			for (vn = 0; b > 0; b /= 10) v[vn++] = b % 10;

			return *this;
		}

		const integer & operator = (const integer & n) {
			s = n.s;
			vn = n.vn;
			for (int i = 0; i < vn; ++i) v[i] = n.v[i];

			return *this;
		}
		/* s ~= [-]?[0-9]+ */
		const integer & operator = (const char * str) {
			int i = 0, j = strlen(str)-1;
			vn = 0;

			switch (str[0]) {
				case '-': s = -1; ++i; break;
				case '+': s = +1; ++i; break;
			}

			while (str[i] == '0')
				if (str[++i] == '\0')
					return *this = 0;

			while (j >= i)
				v[vn++] = str[j--]-'0';

			return *this;
		}

		const integer & operator += (const integer & n) {
			s != n.s ? dec(n): add(n);
			correct();

			return *this;
		}

		const integer & operator -= (const integer & n) {
			s == n.s ? dec(n): add(n);
			correct();

			return *this;
		}

		const integer & operator *= (const integer & n) {
			integer tmp;
			for (int i = n.vn-1; i >= 0; --i) {
				tmp <<= 1;
				for (int j = 0; j < n.v[i]; ++j)
					tmp += *this;
			}

			*this = tmp;
			s *= n.s;
			correct();

			return *this;
		}

		const integer & operator /= (const integer & n) {
			if (n == 0) {
				std::cerr << "const integer & operator /= (integer &): error: division by zero" << std::endl;
				return *this;
			}

			int i;
			integer tmp;
			s *= n.s;

			for (i = vn-1; i >= 0; --i) {
				tmp <<= 1;
				tmp.v[0] = v[i];
				v[i] = 0;
				for (; cmp(tmp, n, 1) >= 0; ++v[i])
					if (n < 0) tmp += n;
					else tmp -= n;
			}

			correct();

			return *this;
		}

		const integer & operator %= (const integer & n) {
			if (cmp(*this, n, 1) < 0)
				return *this;

			integer m = *this;
			m /= n;
			m *= n;

			*this -= m;

			correct();
			return *this;
		}

#define gen_(o, type)\
	inline const integer operator o (type b) const {\
		integer tmp(*this);\
		tmp o ## = b;\
		return tmp;\
	}
	gen_(+, const integer &)
	gen_(-, const integer &)
	gen_(*, const integer &)
	gen_(/, const integer &)
	gen_(%, const integer &)
#undef gen_

		const integer & operator <<= (int d) {
			if (d == 0 || *this == 0) return *this;

			int i = (vn += d) - 1;
			for (; i >= d; --i) v[ i ] = v[ i-d ];
			for (; i >= 0; --i) v[ i ] = 0;

			correct();
			return *this;
		}

		const integer & operator >>= (int d) {
			if (d == 0 || *this == 0) return *this;

			vn -= d;
			for (int i = 0; i < vn; ++i) v[ i ] = v[ i+d ];

			correct();
			return *this;
		}


		friend std::istream & operator >> (std::istream & in, integer & b) {
			std::string s;
			in >> s;
			b.vn = 0;
			for (int i = s.size()-1; i >= 0; --i) {
				switch (s[i]) {
					case '-':
						b.s = -1;
						break;
					case '0': case '1': case '2': case '3': case '4':
					case '5': case '6': case '7': case '8': case '9':
						b.v[ b.vn++ ] = char(s[i]-'0');
						break;
				}
			}
			return in;
		}

		friend std::ostream & operator << (std::ostream & out, const integer & b) {
			if (b.s < 0) out << '-';
			for (int i = b.vn-1; i >= 0; --i)
				out << char(b.v[i] + '0');

			return out;
		}

		friend bool operator <  (const integer & a, const integer & b) { return cmp(a, b) < 0; }
		friend bool operator >  (const integer & a, const integer & b) { return cmp(a, b) > 0; }
		friend bool operator <= (const integer & a, const integer & b) { return cmp(a, b) <= 0; }
		friend bool operator >= (const integer & a, const integer & b) { return cmp(a, b) >= 0; }
		friend bool operator == (const integer & a, const integer & b) { return cmp(a, b) == 0; }
		friend bool operator != (const integer & a, const integer & b) { return cmp(a, b) != 0; }

		void reverse() {
			char * i = v, * j = v+vn-1;
			while (i < j)
				std::swap(*i++, *j--);
			correct();
		}

	private:
		/* *this = |*this| + |n|, doesn't change sign of *this */
		inline void add(const integer & n) {
			char carry = 0;
			for (; vn < n.vn; v[vn++] = 0);
			for (int i = 0; i < vn; ++i) {
				v[i] = (i < vn ? v[i]: 0) + (i < n.vn ? n.v[i]: 0) + carry;
				carry = v[i] / 10;
				v[i] %= 10;
			}
			if (carry > 0) {
				v[ vn++ ] = carry;
			}
		}

		/* *this = |*this| - |n|, doesn't change sign of *this */
		inline void dec(const integer & n) {
			char borrow = 0;
			if (cmp(*this, n, 1) < 0) {
				for (int i = 0; i < n.vn; ++i) {
					if (i < vn)
						v[i] = n.v[i] - borrow - v[i];
					else
						v[ vn++ ] = n.v[i] - borrow;
					if ((borrow = (v[i] < 0)))
						v[i] += 10;
				}
				s = -s;
			} else {
				for (int i = 0; i < vn; ++i) {
					v[i] -= borrow;
					if (i < n.vn)
						v[i] -= n.v[i];
					if ((borrow = (v[i] < 0)))
						v[i] += 10;
				}
			}
		}

		friend int cmp(const integer & a, const integer & b, bool ignore_s = 0) {
			if (!ignore_s && a.s != b.s)
				return a.s - b.s;
			if (a.vn != b.vn)
				return (a.s ? a.vn - b.vn: b.vn - a.vn);
			int i;
			for (i = a.vn-1; a.v[i] == b.v[i];)
				if (--i < 0) return 0;
			return a.v[i] - b.v[i];
		}

		inline void correct() {
			for ( ; vn > 1 && v[ vn-1 ] == 0; --vn);	/* remove leading zeroes */
			if (vn == 1 && v[ vn-1 ] == 0) s = 1;		/* -0 is impossible */
			if (vn < 1) *this = 0;						/* vn can't be less 1 */
		}
};

using namespace std;

int main() {
	int tt;
	cin >> tt;
	while (tt--) {
		integer<256> a, b;

		cin >> a >> b;

		a.reverse();
		b.reverse();
		a += b;
		a.reverse();

		cout << a << endl;
	}

	return 0;
}

