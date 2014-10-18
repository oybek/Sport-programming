
/*
ID: aybek.h2
PROG: castle
LANG: C++
*/

#define PROB_NAME "castle"

#include <cmath>
#include <vector>
#include <cassert>
#include <fstream>
#include <iostream>

std::ifstream cin	(PROB_NAME".in");
std::ofstream cout	(PROB_NAME".out");

#define LEFT	0x01
#define UP		0x02
#define RIGHT	0x04
#define DOWN	0x08

#define MAX_SIZE	50

class solution_t {
	public:

		void run() {
			int i, j, rNum, brSize, biggestRoom = 0;

			cin >> M >> N;

			char c;

			for (i = 0; i < N; ++i)
			for (j = 0; j < M; ++j)
				cin >> wall[i][j];

			initTile();
			rNum = countRoom();
			//showTile();
			brSize = biggestRoomSize(rNum);
			c = findBreakWall(i, j, biggestRoom);

			cout << rNum << "\n";
			cout << brSize << "\n";
			cout << biggestRoom << "\n";
			cout << i+1 << ' ' << j+1 << ' ' << c << "\n";
		}

	private:
		int N, M;
		int wall[ MAX_SIZE ][ MAX_SIZE ];
		int tile[ MAX_SIZE ][ MAX_SIZE ];

		void showTile() {
			std::cout << std::endl;
			for (int i = 0; i < N; ++i) {
				for (int j = 0; j < M; ++j)
					std::cout << tile[i][j] << '|';
				std::cout << std::endl;
			}
		}

		char findBreakWall(int & x, int & y, int & biggestRoom) {
			char c = 0;
			int roomSize;

			for (int j = 0; j < M; ++j)
			for (int i = N-1; i >= 0; --i) {

				if (i > 0)
				if (tile[i][j] != tile[i-1][j]) {
					initTile();

					wall[i][j] &= ~UP;
					wall[i-1][j] &= ~DOWN;

					if ((roomSize = biggestRoomSize(countRoom()))
						> biggestRoom) {

						c = 'N';
						biggestRoom = roomSize;
						x = i; y = j;
					}

					wall[i][j] |= UP;
					wall[i-1][j] |= DOWN;
				}

				if (j < M-1)
				if (tile[i][j] != tile[i][j+1]) {
					initTile();

					wall[i][j] &= ~RIGHT;
					wall[i][j+1] &= ~LEFT;

					if ((roomSize = biggestRoomSize(countRoom()))
						> biggestRoom) {

						//std::cout << roomSize << std::endl;

						c = 'E';
						biggestRoom = roomSize;
						x = i; y = j;
					}

					wall[i][j] |= RIGHT;
					wall[i][j+1] |= LEFT;
				}
			}

			return c;
		}

		void floodFill(int n, int x, int y) {
			//if (x < 0 || y < 0 || x >= N || y >= M)
			//	return;

			if (tile[x][y] != 0)
				return;

			tile[x][y] = n;

			if (!(wall[x][y]&UP))		floodFill(n, x-1, y);
			if (!(wall[x][y]&DOWN))		floodFill(n, x+1, y);
			if (!(wall[x][y]&LEFT))		floodFill(n, x, y-1);
			if (!(wall[x][y]&RIGHT))	floodFill(n, x, y+1);
		}

		int countRoom() {
			int n = 0;
			for (int i = 0; i < N; ++i)
				for (int j = 0; j < M; ++j)
					if (tile[i][j] == 0) {
						++n;
						floodFill(n, i, j);
					}

			return n;
		}

		int biggestRoomSize(int rNum) const {
			int max = 0;
			std::vector<int> a(rNum+1);

			for (int i = 0; i < N; ++i)
			for (int j = 0; j < M; ++j)
				max = std::max(++a[ tile[i][j] ], max);

			return max;
		}

		void initTile() {
			for (int i = 0; i < N; ++i)
			for (int j = 0; j < M; ++j)
				tile[i][j] = 0;
		}
};

int main() {
	solution_t solution;

	solution.run();

	return 0;
}

