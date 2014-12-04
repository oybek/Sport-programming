
#include <cmath>
#include <cstdio>
#include <vector>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

/*
 * 01:00 16/08/2014 Osh
 * Hashimov Oybek
 * Little library for working with big integers
 * Write me about bugs and suggestions: aybek_hashimov@mail.ru
 */

#define GEN_OPERATOR(o, type)							\
	inline const integer operator o (type b) const		\
	{													\
		integer tmp(*this);								\
		tmp o ## = b;									\
		return tmp;										\
	}

template <const int V_SIZE>
class integer
{
	private:
		int k;			/* number is negative if k < 0 otherwise positive */
		int sn;			/* size of vector s */
		char s[ V_SIZE ];

	public:
		integer() { *this = 0; }
		integer(const int n) { *this = n; }
		integer(const char * str) { *this = str; }
		integer(const integer & n) { *this = n; }

		const integer & operator = (int a)
		{
			if (a == 0)
			{
				k = 1; sn = 1; *s = 0;
				return *this;
			}

			k = a < 0 ? -1: 1;
			a = std::abs(a);
			for (sn = 0; a > 0; a /= 10)
				s[sn++] = a % 10;

			return *this;
		}

		const integer & operator = (const integer & n)
		{
			k = n.k;
			sn = n.sn;
			for (int i = 0; i < sn; ++i) s[i] = n.s[i];

			return *this;
		}

		/* s ~= [-]?[0-9]+ */
		const integer & operator = (const char * str)
		{
			int i = 0, j = strlen(str)-1;
			sn = 0;

			k = +1;
			switch (str[0])
			{
				case '-': k = -1; ++i; break;
				case '+': k = +1; ++i; break;
			}

			while (str[i] == '0')
				if (str[++i] == '\0')
					return *this = 0;

			while (j >= i)
				s[sn++] = str[j--]-'0';

			return *this;
		}

		const integer & operator += (const integer & n)
		{
			k != n.k ? dec(n): add(n);
			correct();

			return *this;
		}

		const integer & operator -= (const integer & n)
		{
			k == n.k ? dec(n) : add(n);
			correct();

			return *this;
		}

		const integer & operator *= (const integer & n)
		{
			integer tmp;
			for (int i = n.sn-1; i >= 0; --i)
			{
				tmp <<= 1;
				for (int j = 0; j < n.s[i]; ++j)
					tmp += *this;
			}

			*this = tmp;
			k *= n.k;
			correct();

			return *this;
		}

		const integer & operator /= (const integer & n)
		{
			if (n == 0)
			{
				std::cerr
					<< "const integer & operator /= (integer &): error: division by zero"
					<< std::endl;
				return *this;
			}

			int i;
			integer tmp;
			k *= n.k;

			for (i = sn-1; i >= 0; --i)
			{
				tmp <<= 1;
				tmp.s[0] = s[i];
				s[i] = 0;
				for (; cmp(tmp, n, 1) >= 0; ++s[i])
					if (n < 0) tmp += n;
					else tmp -= n;
			}

			correct();

			return *this;
		}

		const integer & operator %= (const integer & n)
		{
			if (cmp(*this, n, 1) < 0)
				return *this;

			integer m = *this;
			m /= n;
			m *= n;

			*this -= m;

			correct();
			return *this;
		}

		GEN_OPERATOR(+, const integer &)
		GEN_OPERATOR(-, const integer &)
		GEN_OPERATOR(*, const integer &)
		GEN_OPERATOR(/, const integer &)
		GEN_OPERATOR(%, const integer &)

		const integer & operator <<= (int d)
		{
			if (d == 0 || *this == 0)
				return *this;

			int i = (sn += d) - 1;

			for (; i >= d; --i)
				s[ i ] = s[ i-d ];

			for (; i >= 0; --i)
				s[ i ] = 0;

			correct();

			return *this;
		}

		const integer & operator >>= (int d)
		{
			if (d == 0 || *this == 0)
				return *this;

			sn -= d;
			for (int i = 0; i < sn; ++i)
				s[ i ] = s[ i+d ];

			correct();

			return *this;
		}

		friend std::istream & operator >> (std::istream & in, integer & b)
		{
			std::string k;
			in >> k;
			b = k.c_str();
			b.correct();
			return in;
		}

		friend std::ostream & operator << (std::ostream & out, const integer & b)
		{
			if (b.k < 0)
				out << '-';

			for (int i = b.sn-1; i >= 0; --i)
				out << char(b.s[i] + '0');

			return out;
		}

		friend bool operator <  (const integer & a, const integer & b) { return cmp(a, b) < 0; }
		friend bool operator >  (const integer & a, const integer & b) { return cmp(a, b) > 0; }
		friend bool operator <= (const integer & a, const integer & b) { return cmp(a, b) <= 0; }
		friend bool operator >= (const integer & a, const integer & b) { return cmp(a, b) >= 0; }
		friend bool operator == (const integer & a, const integer & b) { return cmp(a, b) == 0; }
		friend bool operator != (const integer & a, const integer & b) { return cmp(a, b) != 0; }

		inline int dign() { return sn; }

	private:
		/* *this = |*this| + |n|, doesn't change sign of *this */
		inline void add(const integer & n)
		{
			char carry = 0;

			while ( sn < n.sn )
				s[ sn++ ] = 0;

			for (int i = 0; i < sn; ++i)
			{
				s[i] = (i < sn ? s[i]: 0) + (i < n.sn ? n.s[i]: 0) + carry;
				carry = s[i] / 10;
				s[i] %= 10;
			}
			if (carry > 0) {
				s[ sn++ ] = carry;
			}
		}

		/* *this = |*this| - |n|, doesn't change sign of *this */
		inline void dec(const integer & n)
		{
			char borrow = 0;
			if ( cmp(*this, n, 1) < 0 )
			{
				for (int i = 0; i < n.sn; ++i)
				{
					if (i < sn)
						s[i] = n.s[i] - borrow - s[i];
					else
						s[ sn++ ] = n.s[i] - borrow;

					if ((borrow = (s[i] < 0)))
						s[i] += 10;
				}
				k = -k;
			}
			else
			{
				for (int i = 0; i < sn; ++i)
				{
					s[i] -= borrow;

					if (i < n.sn)
						s[i] -= n.s[i];

					if ((borrow = (s[i] < 0)))
						s[i] += 10;
				}
			}
		}

		friend int cmp(const integer & a, const integer & b, bool ignore_s = 0)
		{
			if (!ignore_s && a.k != b.k)
				return a.k - b.k;

			if (a.sn != b.sn)
				return (a.k ? a.sn - b.sn: b.sn - a.sn);

			int i;
			for (i = a.sn-1; a.s[i] == b.s[i];)
				if (--i < 0) return 0;

			return a.s[i] - b.s[i];
		}

		inline void correct()
		{
			for ( ; sn > 1 && s[ sn-1 ] == 0; --sn);	/* remove leading zeroes */

			if (sn == 1 && s[ sn-1 ] == 0)
				k = 1;		/* -0 is impossible */

			if (sn < 1) *this = 0;						/* sn can't be less 1 */
		}
};

#define SIZE 256

integer<SIZE> fib[ 512 ], a, b;

int main()
{
	fib[0] = 0;
	fib[1] = 1;
	fib[2] = 2;
	int fib_sz = 3;
	while (1)
	{
		fib[ fib_sz ] = fib[ fib_sz-1 ] + fib[ fib_sz-2 ];

		if (fib[fib_sz].dign() > 100)
			break;

		++fib_sz;
	}

	while (1)
	{
		cin >> a >> b;
		if (a == 0 && b == 0)
			break;

		integer<SIZE> * p1 = lower_bound(fib, fib+fib_sz, a);
		integer<SIZE> * p2 = lower_bound(fib, fib+fib_sz, b);

		if (*p1 == a)
		{
			cout << p2 - p1 + 1 << endl;
		}
		else
		{
			cout << p2 - p1 << endl;
		}
	}

	return 0;
}

