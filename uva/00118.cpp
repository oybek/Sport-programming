
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

#define INF 1000000001
#define SQR(x) ((x)*(x))

typedef unsigned long long uint64;
typedef long long int64;

using namespace std;

int world_x, world_y;
bool scent[ 51 ][ 51 ];

struct robots {
	bool dead;
	char o;
	int x;
	int y;

	string program;

	void move( char c ) {
		// save yourself
		int old_x = x;
		int old_y = y;
		int old_o = o;

		//
		switch( c ) {
			case 'F': {
					switch( o ) {
						case 'N': ++y; break;
						case 'S': --y; break;
						case 'E': ++x; break;
						case 'W': --x; break;
						default: assert( false );
					}
					break;
				}

			case 'R': {
					switch( o ) {
						// S
						//W E
						// N
						case 'N': o = 'E'; break;
						case 'S': o = 'W'; break;
						case 'E': o = 'S'; break;
						case 'W': o = 'N'; break;
						default: assert( false );
					}
					break;
				}

			case 'L': {
					switch( o ) {
						case 'N': o = 'W'; break;
						case 'S': o = 'E'; break;
						case 'E': o = 'N'; break;
						case 'W': o = 'S'; break;
						default: assert( false );
					}
					break;
				}
		}

		if( x < 0 || y < 0 || x > world_x || y > world_y ) {
			dead = !scent[ old_x ][ old_y ];

			scent[ old_x ][ old_y ] = true;

			o = old_o;
			x = old_x;
			y = old_y;
		}
	}
};

vector< robots > robot;

#ifdef DEBUG
void draw( robots r )
{
	char grid[51][51];
	for( int x = 0; x <= world_x; ++x )
	{
		for( int y = 0; y <= world_y; ++y )
		{
			grid[x][y] = scent[x][y] ? 's' : '.';
		}
	}

	grid[r.x][r.y] = r.o;

	for( int x = 0; x <= world_x; ++x )
	{
		for( int y = 0; y <= world_y; ++y )
			cout << grid[x][y];
		cout << endl;
	}
	cout << endl;
}
#endif

int main() {
	// read input

	// read world sizes
	cin >> world_x >> world_y;

	// read robots
	robots rob;
	rob.dead = false;

	while( cin >> rob.x >> rob.y >> rob.o >> rob.program )
		robot.push_back( rob );

	for( auto& r : robot )
	{
		for( int i = 0; i < r.program.size(); ++i )
		{
#ifdef DEBUG
			draw( r );
#endif
			if( !r.dead )
				r.move( r.program[i] );
		}

#ifdef DEBUG
		cout << "----------------" << endl;
#endif
	}

	for( auto r : robot )
		cout << r.x << ' ' << r.y << ' ' << r.o << (r.dead ? " LOST" : "") << endl;

	return 0;
}

