
#include <set>
#include <map>
#include <list>
#include <stack>
#include <queue>
#include <cmath>
#include <bitset>
#include <cstdio>
#include <string>
#include <vector>
#include <cassert>
#include <cstring>
#include <climits>
#include <iomanip>
#include <iostream>
#include <algorithm>

#define INF INT_MAX-1
#define SQR(x) ((x)*(x))

typedef unsigned long long uint64;
typedef long long int64;

using namespace std;

int get_number() {
	int n = 0, c;
	while (1) {
		if ((c = getchar()) == EOF)
			return -1;
		else
		if (!isdigit(c))
			break;

		n *= 10;
		n += c-'0';
	}
	return n;
}

bool check_tree(int goal) {
	stack<int> st;
	while (1) {
		c = getchar();
		if (c == ')') {
			st.pop();
			if (st.size() == 0)
				break;
		} else
		if (c == '(') {
			st.push(0);
		} else
		if (isdigit(c)) {
			st.top() *= 10;
			st.top() += c-'0';
		}
	}
}

int main() {
	int sum, c, t, goal;
	while (1) {
		int goal = get_number();
	}

	return 0;
}

