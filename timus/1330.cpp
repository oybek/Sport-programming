
#include <iostream>
using namespace std;

#define MAX_N 10000

int main() {
	int N, Q;
	int a[ MAX_N+1 ], S[ MAX_N+1 ];

	cin >> N;
	for (int i = 1; i <= N; ++i)
		cin >> a[i];

	S[0] = 0;
	for (int i = 1; i <= N; ++i)
		S[i] = S[i-1]+a[i];

	cin >> Q;
	while (Q--) {
		int x, y;
		cin >> x >> y;
		cout << S[y]-S[x-1] << endl;
	}

	return 0;
}

