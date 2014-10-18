
#include <map>
#include <cctype>
#include <cstdio>
#include <string>
#include <cstring>
#include <iostream>
using namespace std;

#define REP(i, a, b) for (int i = int(a); i <= int(b); i++)

int main() {
	int tt, i, id[2], F;
	char s[2][32];
	map<string, int> name;

	scanf("%d", &tt);
	while (tt--) {
		name.clear();

		scanf("%d", &F);

		i = 0;
		while (F--) {
			scanf("%s %s\n", s[0], s[1]);

			REP (i, 0, 1) {
				string str(s[i], s[i]+strlen(s[i])-1);

				if (name.find(str) == name.end()) {
					id[i] = name[ str ] = i++;
				} else {
					id[i] = name[ str ];
				}
			}
		}
	}

	return 0;
}

