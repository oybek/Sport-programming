
#include <iostream>
using namespace std;

#define INF 1000000001

int main() {
	int M, N, T, m, n, t;
	cin >> M >> N >> T;

	struct {
		int s, t;
	} ans;

	ans.t = INF;
	ans.s = 0;
	for (m = 0; m*M <= T; ++m) {
		n = (T-m*M) / N;
		t = T-m*M-n*N;

		if (t <= ans.t) {
			ans.t = t;
			ans.s = max(n+m, ans.s);
		}
	}

	cout << ans.s;
	if (ans.t > 0)
		cout << ' ' << ans.t;

	return 0;
}

