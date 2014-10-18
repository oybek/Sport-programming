#include <iostream>
using namespace std;

#define ONE		1
#define PUTON	0

int parse(const string & s, int i, bool & who)
{
	switch (who) {
		case ONE :
			who = ONE;
			if (s.substr(i, 6) == "output")
				return i+6;
			else
			if (s.substr(i, 5) == "Puton")
				return i+5;
			else
			if (s.substr(i, 3) == "out")
				return i+3;
			else
				return -1;

		case PUTON:
			who = PUTON;
			if (s.substr(i, 5) == "input")
				return i+5;
			else
			if (s.substr(i, 3) == "one")
				return i+3;
			else
			if (s.substr(i, 2) == "in")
				return i+2;
			else
				return -1;
	}
}

int main()
{
	bool c, p; int n, i; string d;

	cin >> n;
	while (n--) {
		cin >> d;

		i = 0;
		for (;;) {
			p = c;
			if ((i = parse(s, i, c)) == -1) {
				cout << "NO" << endl;
				break;
			}
		}
	}

	return 0;
}

