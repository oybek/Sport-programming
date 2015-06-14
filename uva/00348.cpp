
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

#define N_MAX 10

int N,
	order[] = { 0, 1, 2, 3, 4, 5, 6, 7, 8 },
	optimal_order[] = { 0, 1, 2, 3, 4, 5, 6, 7, 8 },
	minimal_count;

pair<int, int> A[ N_MAX ];
pair<int, int> a[ N_MAX ];

string expression[ N_MAX ];

void save_optimal_order()
{
	for (int i = 0; i < N; ++i)
		optimal_order[i] = order[i];
}

void backtrack(int count, int used, int n)
{
	int tmp1, tmp2, x, y;

	if (count >= minimal_count) return;

	if (n == N-1)
	{
		minimal_count = count;
		save_optimal_order();
		return;
	}

	for (int i = 0; i < N-1; ++i)
	{
		if (used&(1<<i))
			continue;

		x = i;
		y = i+1;

		while (a[x].first == -1) --x;
		while (a[y].first == -1) ++y;

		count += a[x].first * a[y].second * a[x].second;
		tmp1 = a[x].second;
		tmp2 = a[y].first;

		a[x].second = a[y].second;
		a[y].first = -1;
		order[n] = i;
		backtrack(count, used | (1<<i), n+1);

		a[x].second = tmp1;
		a[y].first = tmp2;
		count -= a[x].first * a[y].second * a[x].second;
	}
}

void form_exp_of_optimal_order()
{
	for (int i = 0; i < N-1; ++i)
	{
		int x = optimal_order[i];
		int y = optimal_order[i]+1;

		while (expression[x].size() == 0) --x;
		while (expression[y].size() == 0) ++y;

		expression[x] = "(" + expression[x] + " x " + expression[y] + ")";

		expression[y].erase();
	}
}

int main()
{
	for (int test_i = 1; true; ++test_i)
	{
		/* initialization */
		minimal_count = INF;
		sort(order, order+N_MAX-1);
		for (int i = 0; i < N_MAX; ++i)
			expression[i] = "A" + to_string(i+1);

		/* input */
		cin >> N;
		if (!N) break;
		for (int i = 0; i < N; ++i)
			cin >> a[i].first >> a[i].second;

		/* solution */
		backtrack(0, 0, 0);

		/* output */
		form_exp_of_optimal_order();
		cout << "Case " << test_i << ": " << expression[0] << endl;
	}

	return 0;
}

