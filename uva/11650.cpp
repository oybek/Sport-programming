
#include <cstdio>
using namespace std;

int main() {
	int t, h, m;
	scanf("%d", &t);
	while ( t-- ) {
		scanf("%d:%d", &h, &m);

		h = 12 - h;
		m = ( -m < 0 ? --h, 60-m: 0 );
		if ( h <= 0 ) h = 12 - h;

		printf("%02d:%02d\n", h, m);
	}

	return 0;
}

