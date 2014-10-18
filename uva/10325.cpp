
#include <iostream>
#include <algorithm>
using namespace std;

#define SIZE 15

int main() {
	int N, M;
	while (cin >> N >> M) {
		int divs[ SIZE ];

		for (int i = 0; i < SIZE; ++i)
			divs[i] = 0;

		for (int i = 0; i < M; ++i)
			cin >> divs[i];

		sort(divs, divs+M);

		for (int i = 0; i < M; ++i)
			for (int j = i+1; j < M; ++j)
				if (divs[j]%divs[i] == 0)
					divs[j] = 0;

		int n = N;
		for (int i = 0; i < M; ++i)
			if (divs[i] != 0)
				n -= N/divs[i];

		cout << n << endl;
	}

	return 0;
}

