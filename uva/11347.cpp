
#include <set>
#include <map>
#include <queue>
#include <cmath>
#include <bitset>
#include <cstdio>
#include <string>
#include <vector>
#include <cstring>
#include <climits>
#include <iostream>
#include <algorithm>

using namespace std;

#define INF INT_MAX-1
#define SQR(n) ((n)*(n))
#define EXP18 1000000000000000000ull

typedef unsigned long long uint64;

int prime[] = { 2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97, 101, 103, 107, 109, 113, 127, 131, 137, 139, 149, 151, 157, 163, 167, 173, 179, 181, 191, 193, 197, 199, 211, 223, 227, 229, 233, 239, 241, 251, 257, 263, 269, 271, 277, 281, 283, 293, 307, 311, 313, 317, 331, 337, 347, 349, 353, 359, 367, 373, 379, 383, 389, 397, 401, 409, 419, 421, 431, 433, 439, 443, 449, 457, 461, 463, 467, 479, 487, 491, 499, 503, 509, 521, 523, 541, 547, 557, 563, 569, 571, 577, 587, 593, 599, 601, 607, 613, 617, 619, 631, 641, 643, 647, 653, 659, 661, 673, 677, 683, 691, 701, 709, 719, 727, 733, 739, 743, 751, 757, 761, 769, 773, 787, 797, 809, 811, 821, 823, 827, 829, 839, 853, 857, 859, 863, 877, 881, 883, 887, 907, 911, 919, 929, 937, 941, 947, 953, 967, 971, 977, 983, 991, 997 };

void add(map<int, int> & a, int n)
{
	if (a.find(n) == a.end())
	{
		a.insert(make_pair(n, 1));
	} else
	{
		++a.find(n)->second;
	}
}

void factorize(int n, map<int, int> & a)
{
	for (int i = 0; SQR(prime[i]) <= n; )
	{
		if (n % prime[i] == 0)
		{
			add(a, prime[i]);
			n /= prime[i];
		} else
			++i;
	}
	if (n > 1)
		add(a, n);
}

bool is_prime(int n)
{
	if (n <= 1) return false;
	if (n == 2) return true;
	if (n%2==0) return false;
	for (int d = 3; d*d <= n; d += 2)
		if (n%d == 0)
			return false;
	return true;
}

int main()
{
	int N, test_i;
	string line;
	map<int, int> a;

	cin >> N;
	while (cin.get() != '\n');

	for (test_i = 1; test_i <= N; ++test_i)
	{
		/* initialization phase */
		a.clear();
		int n = 0, i = 0, k = 0;

		/* input phase */
		getline(cin, line);
		while (isdigit(line[i]))
		{
			n *= 10;
			n += line[i]-'0';

			++i;
		}
		while (i < int(line.size()) && line[i] == '!')
		{
			++k;
			++i;
		}

		/* solution and output phase */
		cout << "Case " << test_i << ": ";
		while (n > 0)
		{
			factorize(n, a);
			n -= k;
		}

		uint64 ans = 1;
		for (map<int, int>::const_iterator it = a.begin();
				it != a.end(); ++it)
		{
			if ( ans > (EXP18 / (it->second+1) + 1) )
			{
				ans = 0;
				break;
			}
			ans *= (it->second + 1);
		}

		if (ans == 0)
			cout << "Infinity\n";
		else
			cout << ans << endl;
	}

	return 0;
}

