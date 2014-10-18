
/*
 * I used kmp algorithm to solve it
 */

#include <iostream>
#include <cstdio>
#include <vector>
#include <string>
using namespace std;

/* computing prefixes vector */
inline void get_prefix(const string & s, vector<int> & p)
{
	int len = s.length();

	p[0] = 0;

	int k = 0;
	for (int i = 1; i < len; ++i) {

		while ((k > 0) && (s[k] != s[i]))
			k = p[k-1];

		if (s[k] == s[i])
			++k;

		p[i] = k;
	}
}

int kmp(const string & s, const string & p)
{
	vector<int>pfx(p.length());
	get_prefix(p, pfx);

	int i, k;
	for (k = 0, i = 0; i < s.length(); ++i) {
		while ((k > 0) && (p[k] != s[i]))
			k = pfx[k-1];

		if (p[k] == s[i])
			++k;

		if (k == p.length())
			return (i-p.length()+1);
	}
	return -1;
}

int main()
{
	string	s, t;
	size_t	size, mov, d, i;

	cin >> size; cin.get(); /* pop endl */

	s.resize(size);
	t.resize(size);

	for (i = 0; i < size; ++i)
		s[i] = cin.get();
	cin.get(); /* pop endl */
	for (i = 0; i < size; ++i)
		t[i] = cin.get();
	t += t;
	cout << kmp(t, s) << endl;

	
	return 0;
}

