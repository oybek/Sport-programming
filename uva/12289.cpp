
#include <cstdio>
#include <cstring>
using namespace std;

const char one[] = "one";
const char two[] = "two";
const char three[] = "three";

int main() {
	int N;
	scanf("%d", &N);
	while (N--) {
		char str[6];
		scanf("%s", str);

		if (strlen(str) == 3) {
			int mn = 0;
			for (int i = 0; i < 3; ++i)
				if (one[i] == str[i])
					++mn;

			if (mn >= 2) {
				printf("1\n");
			} else {
				int mn = 0;
				for (int i = 0; i < 3; ++i)
					if (two[i] == str[i])
						++mn;
				if (mn >= 2)
					printf("2\n");
			}

		} else {
			printf("3\n");
		}
	}

	return 0;
}

