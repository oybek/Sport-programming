
#include <vector>
#include <iostream>
using namespace std;

int gcd(int a, int b)
{
	int c;
	while ( a != 0 ) {
		c = a;
		a = b%a;
		b = c;
	}
	return b;
}

int K, S, N;

bool finished = false;

void show(vector<int> & a)
{
	for (auto e : a)
		cout << e << ' ';
	cout << endl;
}

bool is_candidate(const vector<int> & a, int c)
{
	int i, gcd = c;
	for ( i = 0; i < (int) a.size(); ++i )
		gcd = ::gcd(a[i], gcd);

	return (gcd > 1);
}

void backtrack(vector<int> & a)
{
	int c;

	if ( (int) a.size() == K ) {
		show(a);
		finished = (++N >= 10000);
	} else {
		if (a.size() == 0)
			c = 2;
		else
			c = a.back() + 1;

		for ( ; c <= S; ++c ) {
			if ( is_candidate(a, c) ) {
				a.push_back(c);
				backtrack(a);
				a.pop_back();
			}

			if ( finished )
				return;
		}
	}
}

int main()
{
	cin >> K >> S;

	vector<int> a;
	a.reserve(50);

	backtrack(a);
	cout << N << endl;

	return 0;
}

