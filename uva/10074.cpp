
#include <iostream>
using namespace std;

int M, N;
int a[ 101 ][ 101 ];
int s[ 101 ][ 101 ];

void count_s() {
	int i, j;
	s[1][1] = a[1][1];

	for ( i = 2; i <= M; ++i )
		s[i][1] = s[i-1][1] + a[i][1];

	for ( j = 2; j <= N; ++j )
		s[1][j] = s[1][j-1] + a[1][j];

	for ( i = 2; i <= M; ++i )
		for ( j = 2; j <= N; ++j )
			s[i][j] = s[i][j-1] + s[i-1][j] - s[i-1][j-1] + a[i][j];
}

/*
void print_s() {
	int i, j;
	for ( i = 1; i <= M; ++i ) {
		for ( j = 1; j <= N; ++j )
			cout << s[i][j] << ' ';
		cout << endl;
	}
}
*/

int main() {
	int i, j, x1, y1, x2, y2, max_area;
	for ( ;; ) {

		cin >> M >> N;
		if ( !M && !N ) break;

		max_area = 0;
		for ( i = 1; i <= M; ++i )
			for ( j = 1; j <= N; ++j )
				cin >> a[i][j];

		count_s();

		for ( x1 = 1; x1 <= M; ++x1 )
		for ( y1 = 1; y1 <= N; ++y1 )
			for ( x2 = x1; x2 <= M; ++x2 )
			for ( y2 = y1; y2 <= N; ++y2 )
				if ( (s[x2][y2] - s[x1-1][y2] - s[x2][y1-1] + s[x1-1][y1-1]) == 0 ) {
					max_area = max( (x2-x1+1)*(y2-y1+1), max_area );
				}

		cout << max_area << endl;
	}

	return 0;
}

