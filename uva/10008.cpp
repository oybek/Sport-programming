
#include <cmath>
#include <cctype>
#include <vector>
#include <cassert>
#include <iostream>
#include <algorithm>

#define SIZE 'Z'-'A'+1

struct cfreq {
	char c;
	int n;

	inline friend bool operator < (const cfreq & o1, const cfreq & o2)
	{
		if (o1.n > o2.n)
			return true;
		else
		if (o1.n == o2.n)
			return o1.c < o2.c;
		else
			return false;
	}
};

int main()
{
	using namespace std;

	int i, n, freq[ SIZE ];
	cfreq tmp;
	string s;
	vector<cfreq> v;

	fill(freq, freq+SIZE, 0);

	cin >> n;
	cin.get();

	while ( n-- )
	{
		getline(cin, s);

		for ( auto e : s )
			if ( isalpha(e) )
				++freq[ toupper(e)-'A' ];
	}

	for ( i = 0; i < SIZE; ++i )
		if ( freq[i] > 0 ) {
			tmp.c = i+'A';
			tmp.n = freq[i];
			v.push_back(tmp);
		}

	sort(v.begin(), v.end());
	for ( auto e : v )
		cout << e.c << ' ' << e.n << endl;

	return 0;
}

