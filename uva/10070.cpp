#include <iostream>
using namespace std;

#define leap_year(n) (!(n%4) && ((n%100) || !(n%400)))

#define huluculu_year(n) !(n%15)

#define buluculu_year(n) (leap_year(n) && !(n%55))

int main() {
	long long n;
	while ( cin >> n ) {
		bool nor = false;
		if ( nor = leap_year(n) )
			cout << "This is leap year.\n";
		if ( nor = huluculu_year(n) )
			cout << "This is huluculu festival year.\n";
		if ( nor = buluculu_year(n) )
			cout << "This is buluculu festival year.\n";

		if ( !nor )
			cout << "an ordinary year.\n";
	}

	return 0;
}

