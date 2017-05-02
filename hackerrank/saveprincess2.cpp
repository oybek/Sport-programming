
#include <iostream>
#include <vector>
using namespace std;
void nextMove(int n, int r, int c, vector <string> grid){
	int px = 0, py = 0;
	for( int i = 0; i < n; ++i )
	{
		for( int j = 0; j < n; ++j )
		{
			if( grid[ i ][ j ] == 'p' )
			{
				px = i, py = j;
				break;
			}
		}
	}

	if( px - r < 0 )
		cout << "UP";
	else if( px - r > 0 )
		cout << "DOWN";
	else if( py - c < 0 )
		cout << "LEFT";
	else if( py - c > 0 )
		cout << "RIGHT";
}

int main(void) {

    int n, r, c;
    vector <string> grid;

    cin >> n;
    cin >> r;
    cin >> c;

    for(int i=0; i<n; i++) {
        string s; cin >> s;
        grid.push_back(s);
    }

    nextMove(n, r, c, grid);
    return 0;
}

