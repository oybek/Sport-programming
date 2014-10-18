
#include <iostream>
#include <algorithm>
using namespace std;

#define MAX_N 2000

int N;
int a[ MAX_N+1 ];

int main() {
	cin >> N;
	for (int i = 0; i < N; ++i)
		cin >> a[i];
	sort(a, a+N);

	return 0;
}

