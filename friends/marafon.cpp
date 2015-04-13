
#include <cmath>
#include <iostream>
#include <algorithm>
using namespace std;

#define INF 1000000001

struct coordinate {
	int x, y;

	friend
	bool operator < (const coordinate & a1, const coordinate & a2) {
		if (a1.x == a2.x)
			return a1.y < a2.y;
		else
			return a1.x < a2.x;
	}
};

const int N_MAX = 10;
int N;
coordinate start;
coordinate zdaniye[N_MAX];

inline
int dist(const coordinate & a1, const coordinate & a2) {
	return abs(a1.x - a2.x) + abs(a1.y - a2.y);
}

inline
int get_length() {
	register int len = 0;

	len += dist(start, zdaniye[0]);
	for (register int i = 1; i < N; ++i)
		len += dist(zdaniye[i-1], zdaniye[i]);
	len += dist(zdaniye[N-1], start);

	return len;
}

int main() {
	cin >> start.x >> start.y;
	cin >> N;
	for (register int i = 0; i < N; ++i)
		cin >> zdaniye[i].x >> zdaniye[i].y;

	sort(zdaniye, zdaniye+N);

	register int ans = INF;
	do {
		ans = min(ans, get_length());
	} while (next_permutation(zdaniye, zdaniye+N));

	cout << ans << endl;

	return 0;
}

