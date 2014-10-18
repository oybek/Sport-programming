
#include <algorithm>
#include <iostream>
#include <cassert>
#include <cstdlib>
#include <map>

#ifdef ONLINE_JUDGE
#pragma comment(linker, "/STACK:33554432")
#endif

#define MINUS	-1
#define PLUS	1

#define cmp_abs(a, b) cmp(a, b, 1)

#ifndef BIGINT_MAX_DIGIT_NUM
#define BIGINT_MAX_DIGIT_NUM 2048
#endif

#define GEN_CMP_OPERATORS_FOR(type) \
		inline friend bool operator <  (const bigint& a, type b) { return cmp_stdint(a, b) < 0; }	\
		inline friend bool operator >  (const bigint& a, type b) { return cmp_stdint(a, b) > 0; }	\
		inline friend bool operator <= (const bigint& a, type b) { return cmp_stdint(a, b) <= 0; }	\
		inline friend bool operator >= (const bigint& a, type b) { return cmp_stdint(a, b) >= 0; }	\
		inline friend bool operator == (const bigint& a, type b) { return cmp_stdint(a, b) == 0; }	\
		inline friend bool operator != (const bigint& a, type b) { return cmp_stdint(a, b) != 0; }

#define GEN_ASSIGN_OPERATOR_FOR(type) \
		inline const bigint& operator = (const type n) { assign_stdint(n); return *this; }	\

#define GEN_CONSTRUCTOR_FOR(type) \
		inline bigint(const type n) : dig(static_cast<char*>(malloc(BIGINT_MAX_DIGIT_NUM))) { assert(dig != NULL); *this = n; }

#define GEN_INC_OPERATOR_FOR(type) \
		inline const bigint & operator += (type n) { bigint tmp = n; return *this += tmp; }

#define GEN_DEC_OPERATOR_FOR(type) \
		inline const bigint & operator -= (type n) { bigint tmp = n; return *this -= tmp; }

#define GEN_MUL_OPERATOR_FOR(type) \
		inline const bigint & operator *= (type n) { bigint tmp = n; return *this *= tmp; }

#define GEN_DIV_OPERATOR_FOR(type) \
		inline const bigint & operator /= (type n) { bigint tmp = n; return *this /= tmp; }

class bigint {
	private:
		int sign, dign; 
		char * const dig;

	public:
		GEN_CONSTRUCTOR_FOR(int);
		GEN_ASSIGN_OPERATOR_FOR(int);
		GEN_CMP_OPERATORS_FOR(int)
		GEN_INC_OPERATOR_FOR(int);
		GEN_DEC_OPERATOR_FOR(int);
		GEN_MUL_OPERATOR_FOR(int);
		GEN_DIV_OPERATOR_FOR(int);

		bigint() : dig(static_cast<char*>(malloc(BIGINT_MAX_DIGIT_NUM))) {
			assert(dig != NULL);
			*this = 0;
		}
		bigint(const bigint & n) : dig(static_cast<char*>(malloc(BIGINT_MAX_DIGIT_NUM))) {
			assert(dig != NULL);
			*this = n;
		}

		~bigint() { free(dig); }

		inline const bigint &
		operator = (const bigint & n) {
			assign(n);
			return *this;
		}

		inline const bigint&
		operator += (const bigint & n) {
			inc(n);
			return *this;
		}
		inline const bigint&
		operator -= (bigint & n) {
			n.sign = -n.sign;
			inc(n);
			n.sign = -n.sign;
			return *this;
		}

		inline const bigint&
		operator *= (const bigint & n) {
			int i, j;
			bigint tmp;
			for (i = 0; i < n.dign; ++i) {
				for (j = 0; j < n.dig[i]; ++j)
					tmp += *this;
				*this <<= 1;
			}
			*this = tmp;
			sign *= n.sign;
			return *this;
		}
		inline const bigint&
		operator /= (bigint & n) {
			bigint tmp;
			int i;
			sign *= n.sign;

			for (i = dign-1; i >= 0; --i) {
				tmp <<= 1;
				tmp.dig[0] = dig[i];
				dig[i] = 0;
				while (cmp_abs(tmp, n) >= 0) {
					++dig[i];
					tmp -= n;
				}
			}
			remove_leading_zeros();
			return *this;
		}

		inline friend bool operator <  (const bigint& a, const bigint& b) {
			return cmp(a, b) < 0;
		}
		inline friend bool operator >  (const bigint& a, const bigint& b) {
			return cmp(a, b) > 0;
		}
		inline friend bool operator <= (const bigint& a, const bigint& b) {
			return cmp(a, b) <= 0;
		}
		inline friend bool operator >= (const bigint& a, const bigint& b) {
			return cmp(a, b) >= 0;
		}
		inline friend bool operator == (const bigint& a, const bigint& b) {
			return cmp(a, b) == 0;
		}
		inline friend bool operator != (const bigint& a, const bigint& b) {
			return cmp(a, b) != 0;
		}

		inline friend std::ostream &
		operator << (std::ostream & out, const bigint & b) {
			if (b.sign == MINUS) out << '-';
			for (int i = (b.dign-1); i >= 0; --i)
				out << static_cast<char>(b.dig[i]+'0');
			return out;
		}

		inline const bigint &
		operator <<= (int d) {
			if ((d == 0) || ((dign == 1) && (dig[ dign-1 ] == 0)))
				return *this;
			int i;
			dign += d;

			if (dign > BIGINT_MAX_DIGIT_NUM) {
				std::cerr << "number is too big\n";
				std::exit(1);
			}

			for (i = dign-1; i >= d; --i) {
				dig[i] = dig[i-d];
			}
			for (; i >= 0; --i)
				dig[i] = 0;
			return *this;
		}

	private:
		template <class T> inline void
		assign_stdint(T b) {
			if (b == 0) {
				sign = PLUS;
				dign = 1;
				dig[0] = 0;
				return;
			}

			sign = (b < 0 ? MINUS: PLUS);
			b = std::abs(b);
			for (dign = 0; b > 0; b /= 10)
				dig[ dign++ ] = b % 10;
		}
		inline void
		assign(const bigint & b) {
			sign = b.sign;
			dign = b.dign;
			for (int i = 0; i < dign; ++i)
				dig[i] = b.dig[i];
		}

		template <class T> friend inline int
		cmp_stdint(const bigint & a, const T b, bool ignore_sign = 0) {
			bigint c; c = b;
			return cmp(a, c, ignore_sign);
		}
		friend inline int
		cmp(const bigint & a, const bigint & b, bool ignore_sign = 0) {
			if (!ignore_sign && a.sign != b.sign)
				return a.sign - b.sign;

			if (a.dign != b.dign)
				return (a.sign ? a.dign - b.dign: b.dign - a.dign);

			int i = a.dign-1;
			while (a.dig[i] == b.dig[i])
				if (--i < 0)
					return 0;

			return a.dig[i] - b.dig[i];
		}

		inline void
		remove_leading_zeros() {
			while ((dign > 1) && (dig[dign-1] == 0))
				--dign;

			if ((dign == 1) && (dig[dign-1] == 0))
				sign = PLUS;
		}

		inline void
		inc (const bigint & n) {
			int i, carry = 0, borrow = 0;
			if (sign == n.sign) {
				if (dign < n.dign) dign = n.dign;
				for (i = 0; i < dign; ++i) {
					dig[i] += carry;
					if (i < n.dign)
						dig[i] += n.dig[i];
					carry = dig[i] / 10;
					dig[i] %= 10;
				}
				if (carry > 0)
					dig[ dign++ ] = carry;
			} else if (cmp_abs(*this, n) < 0) {
				for (i = 0; i < n.dign; ++i) {
					if (i < dign)
						dig[i] = n.dig[i] - dig[i] - borrow;
					else
						dig[ dign++ ] = n.dig[i] - borrow;
					borrow = 0;
					if (dig[i] < 0) {
						dig[i] += 10;
						borrow = 1;
					}
				}
				sign = n.sign;
			} else {
				for (i = 0; i < dign; ++i) {
					dig[i] = dig[i] - borrow;
					if (i < n.dign) dig[i] -= n.dig[i];
					borrow = 0;
					if (dig[i] < 0) {
						dig[i] += 10;
						borrow = 1;
					}
				}
			}
			remove_leading_zeros();
		}
};

using namespace std;

bigint k;
bigint kless1;
map<int, bigint> memo[2];

bigint F(int n, int z) {
	bigint f;

	if (memo[z].find(n) != memo[z].end())
		f = memo[z][n];
	else {
		if (z) {
			f = F(n-1, !z);
			f *= kless1;
		} else {
			f = F(n-1, z);
			f *= kless1;
			f += F(n-1, !z);
		}
		memo[z][n] = f;
	}

	return f;
}

int main() {
	int n, k;
	cin >> n >> k;

	::k = k;
	kless1 = k; kless1 -= 1;

	memo[0][1] = k;
	memo[1][1] = kless1;

	F(n, 1);

	return 0;
}

