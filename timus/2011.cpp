
#include <cmath>
#include <cstdio>
#include <cctype>
#include <string>
#include <vector>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <algorithm>

/*
 * 01:00 16/08/2014 Osh
 * Hashimov Oybek (Uisi PE-31b)
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
		integer()
			{ *this = 0; }
		integer(const int n)
			{ *this = n; }
		integer(const integer & n)
			{ *this = n; }
		integer(const char * str)
			{ *this = str; }


		const integer & operator = (const int a)
		{
			if (a == 0)
			{
				s = vn = 1;
				v[0] = 0;
				return *this;
			}

			s = a < 0 ? -1: 1;
			int b = std::abs(a);

			for (vn = 0; b > 0; b /= 10)
			{
				v[vn++] = b % 10;
			}

			return *this;
		}

		const integer & operator = (const integer & n)
		{
			s = n.s;
			vn = n.vn;
			for (int i = 0; i < vn; ++i)
			{
				v[i] = n.v[i];
			}

			return *this;
		}
		/* s ~= [-]?[0-9]+ */
		const integer & operator = (const char * str)
		{
			vn = 0;
			int b = 0;

			s = (str[0] == '-' ? ++b, -1: 1);
			if (str[0] == '+')
				++b;

			for (; str[b] == '0';)
				if (str[++b] == '\0') {
					*this = 0;
					return *this;
				}

			for (int i = strlen(str)-1; i >= b; --i)
			{
				v[vn++] = str[i]-'0';
			}
			return *this;
		}


		const integer & operator += (const integer & n)
		{
			s != n.s ? dec(n): add(n);
			zero_justify();
			return *this;
		}

		const integer & operator -= (const integer & n)
		{
			s == n.s ? dec(n): add(n);
			zero_justify();
			return *this;
		}

		const integer & operator *= (const integer & n)
		{
			integer tmp;
			for (int i = n.vn-1; i >= 0; --i)
			{
				tmp <<= 1;
				for (int j = 0; j < n.v[i]; ++j)
				{
					tmp += *this;
				}
			}
			*this = tmp;
			s *= n.s;

			zero_justify();
			return *this;
		}

		const integer & operator /= (const integer & n)
		{
			if (n == 0)
			{
				std::cerr << "const integer & operator /= (integer &): error: division by zero" << std::endl;
				return *this;
			}

			int i;
			integer tmp;
			s *= n.s;

			for (i = vn-1; i >= 0; --i)
			{
				tmp <<= 1;
				tmp.v[0] = v[i];
				v[i] = 0;
				for (; cmp(tmp, n, 1) >= 0; ++v[i])
				{
					n < 0 ? tmp += n: tmp -= n;
				}
			}
			zero_justify();
			return *this;
		}

		const integer & operator %= (const integer & n)
		{
			if (cmp(*this, n, 1) < 0)
				return *this;

			integer m = *this;
			m /= n;
			m *= n;
			m -= *this;
			m.s = s;

			m.zero_justify();
			return *this;
		}

#define gen_(o, type)\
	inline const integer operator o (type b) const\
	{\
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

		const integer & operator <<= (int d)
		{
			if ((d == 0) || ((vn == 1) && (v[vn-1] == 0)))
			{
				return *this;
			}
			vn += d;
			int i;
			for (i = vn-1; i >= d; --i)
				v[i] = v[i-d];
			for (; i >= 0; --i)
				v[i] = 0;
			return *this;
		}

		const integer & operator >>= (int d)
		{
			vn -= d;
			int i;
			for (i = 0; i < vn; ++i)
				v[i] = v[i+d];
			return *this;
		}


		friend std::istream & operator >> (std::istream & in, integer & b)
		{
			std::string s;
			in >> s;
			b.vn = 0;
			for (int i = s.size()-1; i >= 0; --i)
			{
				switch (s[i])
				{
					case '-':
					{
						b.s = -1;
						break;
					}
					case '0':
					case '1':
					case '2':
					case '3':
					case '4':
					case '5':
					case '6':
					case '7':
					case '8':
					case '9':
					{
						b.v[ ++b.vn ] = char(s[i]-'0');
						break;
					}
				}
			}
			return in;
		}

		friend std::ostream & operator << (std::ostream & out, const integer & b)
		{
			if (b.s < 0) out << '-';
			for (int i = b.vn-1; i >= 0; --i)
			{
				out << char(b.v[i] + '0');
			}
			return out;
		}


		friend bool operator <  (const integer & a, const integer & b) { return cmp(a, b) < 0; }
		friend bool operator >  (const integer & a, const integer & b) { return cmp(a, b) > 0; }
		friend bool operator <= (const integer & a, const integer & b) { return cmp(a, b) <= 0; }
		friend bool operator >= (const integer & a, const integer & b) { return cmp(a, b) >= 0; }
		friend bool operator == (const integer & a, const integer & b) { return cmp(a, b) == 0; }
		friend bool operator != (const integer & a, const integer & b) { return cmp(a, b) != 0; }

	private:
		/* *this = |*this| + |n|, doesn't change sign of *this */
		inline void add(const integer & n)
		{
			char carry = 0;
			for (; vn < n.vn; v[vn++] = 0);
			for (int i = 0; i < vn; ++i)
			{
				v[i] = (i < vn ? v[i]: 0) + (i < n.vn ? n.v[i]: 0) + carry;
				carry = v[i] / 10;
				v[i] %= 10;
			}
			if (carry > 0)
			{
				v[ vn++ ] = carry;
			}
		}

		/* *this = |*this| - |n|, doesn't change sign of *this */
		inline void dec(const integer & n)
		{
			char borrow = 0;
			if (cmp(*this, n, 1) < 0)
			{
				for (int i = 0; i < n.vn; ++i)
				{
					if (i < vn)
						v[i] = n.v[i] - borrow - v[i];
					else
						v[ vn++ ] = n.v[i] - borrow;
					if ((borrow = (v[i] < 0)))
						v[i] += 10;
				}
				s = -s;
			} else {
				for (int i = 0; i < vn; ++i)
				{
					v[i] -= borrow;
					if (i < n.vn)
						v[i] -= n.v[i];
					if ((borrow = (v[i] < 0)))
						v[i] += 10;
				}
			}
		}

		friend int cmp(const integer & a, const integer & b, bool ignore_s = 0)
		{
			if (!ignore_s && a.s != b.s)
				return a.s - b.s;
			if (a.vn != b.vn)
				return (a.s ? a.vn - b.vn: b.vn - a.vn);
			int i;
			for (i = a.vn-1; a.v[i] == b.v[i];)
				if (--i < 0) return 0;
			return a.v[i] - b.v[i];
		}

		inline void zero_justify()
		{
			for (; vn > 1 && v[vn-1] == 0; --vn);
			if (vn == 1 && v[vn-1] == 0)
				s = 1;
		}
};

#define SIZE 256

void fact(int n, integer<SIZE> & m) {
	if (n == 0) { m = 1; return; }
	for (m = n; --n; m *= n);
}

int main() {
	using namespace std;

	int n, a[] = { 0, 0, 0 };

	cin >> n;
	for (int t = n; t--; ) {
		int i;
		cin >> i;
		++a[i-1];
	}

	integer<256> nf, af[3];

	fact(n, nf);
	for (int i = 0; i < 3; ++i)
		fact(a[i], af[i]);

	cout << (nf >= af[0]*af[1]*af[2]*6 ? "Yes": "No") << endl;

	return 0;
}

