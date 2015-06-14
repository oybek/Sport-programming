
#include <string>
#include <cstdlib>
#include <iostream>
#include <algorithm>
using namespace std;

int n;
bool is_any_sol;

string int_to_str(int n) {
	string s; s.reserve(8);
	for (; n > 0; n /= 10)
		s.push_back((n%10 + '0'));
	reverse(s.begin(), s.end());
	return s;
}

int str_to_int(const string & s, int sz) {
	int n = 0;
	for (int i = 0; i < sz; ++i) {
		n *= 10;
		n += (s[i]-'0');
	}
	return n;
}

#define CONTINUE 0
#define BREAK 1

bool backtrack(string & s2, int s2_sz, int was) {
	if (s2_sz == 5) {
		string s1 = int_to_str( n*str_to_int(s2, s2_sz) );

		if (s1.size() == 5) {
			for (int i = 0; i < 5; ++i)
				was |= 1<<(s1[i]-'0');

			if (was == 1023) {
				is_any_sol = true;
				cout << s1 << " / " << s2 << " = " << n << endl;
			}
		} else
		if (s1.size() > 5) {
			return BREAK;
		}
	}

	for (int i = 0; i <= 9; ++i) {
		if (!(was&(1<<i))) {
			s2[s2_sz] = char(i+'0');
			if (backtrack(s2, s2_sz+1, was|(1<<i)) == BREAK) {
				return BREAK;
			}
		}
	}

	return CONTINUE;
}

int main() {
	string s; s.resize(5);

	bool first = true;

	while (1) {
		cin >> n;

		if (!n)
			break;

		if (first) first = false;
		else cout << endl;

		is_any_sol = false;
		backtrack(s, 0, 0);

		if (!is_any_sol) {
			cout << "There are no solutions for " << n << ".\n";
		}
	}

	return 0;
}

