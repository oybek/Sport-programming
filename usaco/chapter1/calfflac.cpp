
/*
ID: aybek.h2
PROG: calfflac
LANG: C++11
*/

#define PROB_NAME "calfflac"

#include <fstream>
#include <string>
#include <cctype>

using namespace std;

string text;

inline int nxt(int n)
{
	for (++n; n < text.length() && !isalpha(text[n]); ++n);
	if (n == text.length())
		return -1;
	else
		return n;
}

inline int prv(int n)
{
	for (--n; n >= 0 && !isalpha(text[n]); --n);
	return n;
}

int main()
{
	ifstream fin	(PROB_NAME".in");
	ofstream fout	(PROB_NAME".out");

	register int a, b, x, y, mx, my, tx, ty;
	for (char c; fin.get(c); text.push_back(c));

	a = mx = my = 0;
	b = 1;
	while (1) {
		x = a;
		y = b;

		if (tolower(text[x]) == tolower(text[y])) {
			ty = nxt(y);
			tx = prv(x);
			while (	ty >= 0 &&
					tx >= 0 &&
					tolower(text[ty]) == tolower(text[tx])) {
				y = ty, x = tx;

				ty = nxt(y);
				tx = prv(x);
			}
		}

		if (tolower(text[x]) == tolower(text[y]))
			if ((y-x) > (my-mx)) my = y, mx = x;

		if (a < b)
			a = nxt(a);
		else
			b = nxt(b);

		if ((my-mx) > (text.length()-b))
			break;

		if (b == -1)
			break;
	}

	register int l = 0;
	for (int i = mx; i != -1 && i <= my; i = nxt(i)) ++l;
	fout << l << '\n';

	for (int i = mx; i <= my; ++i)
		fout << text[i];
	fout << '\n';

	return 0;
}

