#include <iostream>
#include <string>
using namespace std;

void expand(const string & s, int & a, int & b)
{
	while (s[a] == s[b]) {
		--a; ++b;
		if (a == -1)
			break;
		if (b == s.size())
			break;
	}
	++a; --b;
}

void print(const string & s, const int & a, const int & b)
{
	for (int i = a; i <= b; ++i)
		cout << s[i];
}

int main()
{
	string s;
	cin >> s;

	int mi = 0, mj = 0, i, a, b;

	for (i = 0; i+1 < s.size(); ++i) {
		a = i, b = i;
		expand(s, a, b);

		if ((b-a) > (mj-mi))
			mj = b, mi = a;
		
		a = i, b = i+1;
		if (s[a] == s[b]) {
			expand(s, a, b);
			if ((b-a) > (mj-mi))
				mj = b, mi = a;
		}
	}

	print(s, mi, mj); cout << endl;


	return 0;
}

