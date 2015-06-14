
#include <cmath>
#include <vector>
#include <cassert>
#include <iostream>
#include <algorithm>

using namespace std;

bool prime(int n)
{
	if ( ((n > 2) && !(n%2)) || (n < 2) )
		return false;

	for ( int d = 3; d <= n/2; d += 2 )
		if ( !(n % d) )
			return false;

	return true;
}

inline
void handle_solution(const vector<int> & ring)
{
	size_t i;
	if ( !prime(ring.front() + ring.back()) )
		return;

	/*
	for ( i = 0; i+1 < ring.size(); ++i )
		if ( !prime(ring[i] + ring[i+1]) )
			return;
	*/

	cout << ring.front();
	for ( i = 1; i < ring.size(); ++i )
		cout << ' ' << ring[i];
	cout << endl;
}

/*
 * first argument indicates what numbers are used
 */
void backtrack(int used, const int maxn, vector<int> & ring)
{
	if ( (int)ring.size() == maxn )
		handle_solution(ring);

	int n;
	for ( n = 2; n <= maxn; ++n ) {
		if ( !(used & (1<<n)) && prime(ring.back() + n) )
		{
			ring.push_back(n);
			backtrack(used | (1<<n), maxn, ring);
			ring.pop_back();
		}
	}
}

int main()
{
	int N, i;
	bool first = true;
	vector<int> ring;
	ring.reserve(16);
	for ( i = 1; cin >> N; ++i )
	{
		ring.resize(0);
		ring.push_back(1);

		if (!first) cout << endl;
		else first = false;

		cout << "Case " << i << ":\n";

		if ( (N > 1) && (N % 2) )
			continue;

		backtrack(2, N, ring);
	}

	return 0;
}

