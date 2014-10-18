
/*
http://acm.timus.ru/problem.aspx?space=1&num=1940
*/

#include <list>
#include <cassert>
#include <iostream>
#include <algorithm>

/*
 * number of numbers in set { a+1, a+2, ..., a+l }
 * which are divisible to divisor
 */
int divNum(int a, int l, int divisor)
{
	int i = 1;
	// find first divisor in set
	while ((a+i) % divisor)
	{
		if (++i > l)
			return 0;
	}

	return (l-i+1)/divisor + 1;
}

class primeT
{
	private:
		std::list<int64_t> m_list;

	public:
		primeT(): m_list { 2, 3 } {}
		~primeT() {}

		/* TODO: optimize */
		bool isPrime(int64_t n)
		{
			int sqr_of_n = static_cast<int>(floor(std::sqrt(n)));

			for (int64_t i; m_list.back() < sqrt(n); m_list.push_back(i))
			{
				for (i = m_list.back()+2; !isPrime(i); i += 2);
			}

			for (auto e: m_list)
			{
				if (e > sqr_of_n) break;
				if (n%e == 0) return false;
			}

			return true;
		}

		bool operator()(int64_t n)
		{
			return isPrime(n);
		}

} isPrime;

int main()
{
	//cout << "divNum( " << A << ", " << B << ", " << d << ") = " << divNum(A, B, d) << endl;
	using namespace std;

	int A, B, d, k, S;
	cin >> A >> B >> k;

	d = 2;
	S = B;
	while (k--) {
		S -= divNum(A, B, d);

		while (!isPrime(++d));
		if (d-1 > k)
			break;
	}

	cout << S << endl;


	return 0;
}

