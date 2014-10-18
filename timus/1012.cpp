#include <iostream>
#include <algorithm>
#include <map>

#ifdef ONLINE_JUDGE
#pragma comment(linker, "/STACK:33554432")
#endif

#include <vector>

#define MINUS	-1
#define PLUS	1

#define cmp_abs(a, b) cmp(a, b, 1)

#ifndef BIGINT_MAX_DIGIT_NUM
#define BIGINT_MAX_DIGIT_NUM 1400
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
		inline bigint(const type n) { dig.reserve( BIGINT_MAX_DIGIT_NUM ); *this = n; }

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
		int sign;
		std::vector<char> dig;

	public:
		GEN_CONSTRUCTOR_FOR(int);
		GEN_ASSIGN_OPERATOR_FOR(int);
		GEN_CMP_OPERATORS_FOR(int)
		GEN_INC_OPERATOR_FOR(int);
		GEN_DEC_OPERATOR_FOR(int);
		GEN_MUL_OPERATOR_FOR(int);
		GEN_DIV_OPERATOR_FOR(int);

		inline bigint() {
			dig.reserve( BIGINT_MAX_DIGIT_NUM );
			*this = 0;
		}
		inline bigint(const bigint & n) {
			dig.reserve( BIGINT_MAX_DIGIT_NUM );
			*this = n;
		}

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
			size_t i; char j;
			bigint tmp;
			for (i = 0; i < n.dig.size(); ++i) {
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

			for (i = dig.size()-1; i >= 0; --i) {
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
			for (int i = b.dig.size()-1; i >= 0; --i)
				out << char(b.dig[i] + '0');
			return out;
		}

		inline const bigint &
		operator <<= (int d) {
			if ((d == 0) || ((dig.size() == 1) && (dig.back() == 0)))
				return *this;
			int i;
			dig.resize(dig.size() + d);
			for (i = dig.size()-1; i >= d; --i) {
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
				dig.resize(0);
				dig.push_back(0);
				return;
			}

			if (b < 0) { sign = MINUS; b = -b; }
			else { sign = PLUS; }
			for (dig.resize(0); b > 0; b /= 10)
				dig.push_back(b % 10);
		}
		inline void
		assign(const bigint & b) {
			sign = b.sign;
			dig.resize(b.dig.size());
			std::copy(b.dig.begin(), b.dig.end(), dig.begin());
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

			if (a.dig.size() != b.dig.size())
				return (a.sign ? a.dig.size() - b.dig.size(): b.dig.size() - a.dig.size());

			int i = a.dig.size()-1;
			while (a.dig[i] == b.dig[i])
				if (--i < 0)
					return 0;

			return a.dig[i] - b.dig[i];
		}

		inline void
		remove_leading_zeros() {
			while (dig.size() > 1 && dig.back() == 0)
				dig.pop_back();

			if (dig.size() == 1 && dig.back() == 0)
				sign = PLUS;
		}

		inline void
		inc (const bigint & n) {
			if (sign == n.sign) {
				if (dig.size() < n.dig.size()) dig.resize(n.dig.size());
				size_t carry = 0;
				for (size_t i = 0; i < dig.size(); ++i) {
					dig[i] += (i < n.dig.size() ? n.dig[i] + carry: carry);
					carry = dig[i] / 10;
					dig[i] %= 10;
				}
				if (carry > 0)
					dig.push_back(carry);
			} else if (cmp_abs(*this, n) < 0) {
					size_t borrow = 0;
					for (size_t i = 0; i < n.dig.size(); ++i) {
						if (i < dig.size()) dig[i] = n.dig[i] - dig[i] - borrow;
						else dig.push_back(n.dig[i] - borrow);
						borrow = 0;
						if (dig[i] < 0) {
							dig[i] += 10;
							borrow = 1;
						}
					}
					sign = n.sign;
			} else {
					size_t borrow = 0;
					for (size_t i = 0; i < dig.size(); ++i) {
						dig[i] = dig[i] - borrow;
						if (i < n.dig.size()) dig[i] -= n.dig[i];
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
	x = (++x > 10 ? 0: x);

	int n, k;
	cin >> n >> k;

	::k = k;
	kless1 = k; kless1 -= 1;

	memo[0][1] = k;
	memo[1][1] = kless1;

	cout << F(n, 1) << endl;

	return 0;
}

