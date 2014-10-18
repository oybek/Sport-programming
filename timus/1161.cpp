
#include <map>
#include <cmath>
#include <queue>
#include <cstdio>
#include <cctype>
#include <string>
#include <vector>
#include <cstdlib>
#include <iostream>
#include <algorithm>

#define MAX_SIZE 10000

int main() {
	using namespace std;

	int q_size;
	priority_queue<float> q;

	cin >> q_size;
	for (float n; q_size--; q.push(n))
		cin >> n;

	while (q.size() > 1) {
		float m1 = q.top(); q.pop();
		float m2 = q.top(); q.pop();

		//cout << '(' << m1 << ", " << m2 << ')' << endl;
		q.push(2 * sqrt(m1*m2));
	}

	printf("%.2f\n", q.top());


	return 0;
}

