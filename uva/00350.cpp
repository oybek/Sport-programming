
#include <map>
#include <iostream>
using namespace std;

typedef long long int64;
typedef unsigned int uint;
typedef unsigned long long uint64;

int main() {
	int64 Z, I, M, L;
	map<int64, int64> S;

	for (int i = 1; ; ++i) {
		S.clear();

		cin >> Z >> I >> M >> L;

		if (!Z && !I && !M && !L)
			break;

		int64 cur = L, period_length = 1;

		for (;;) {
			cur = (Z * cur + I)%M;
			S.insert(make_pair(L, period_length));

			if (S.find(cur) != S.end()) {
				period_length -= S.find(cur)->second;
				break;
			}

			++period_length;
		}

		cout << "Case " << i << ": " << period_length << endl;
	}

	return 0;
}

