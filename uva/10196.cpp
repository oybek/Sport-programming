
#include <set>
#include <map>
#include <queue>
#include <cmath>
#include <bitset>
#include <cstdio>
#include <string>
#include <vector>
#include <cassert>
#include <cstring>
#include <climits>
#include <iostream>
#include <algorithm>

using namespace std;

#define INF INT_MAX-1

#define SIZE 8

string board[SIZE];
char get_board(int x, int y)
{
	return x < 0 || x >= SIZE || y < 0 || y >= SIZE ? '.' : board[x][y];
}

bool white_pawn_attacks_king(int x, int y)
{
	return get_board(x-1, y-1) == 'k' || get_board(x-1, y+1) == 'k';
}

bool black_pawn_attacks_king(int x, int y)
{
	return get_board(x+1, y+1) == 'K' || get_board(x+1, y-1) == 'K';
}

bool knight_attacks_king(int x, int y, char c)
{
	return	get_board(x-2, y-1) == c || get_board(x-2, y+1) == c ||
					get_board(x+2, y-1) == c || get_board(x+2, y+1) == c ||
					get_board(x-1, y-2) == c || get_board(x+1, y-2) == c ||
					get_board(x-1, y+2) == c || get_board(x+1, y+2) == c;
}

bool rook_attacks_king(int x, int y, char c)
{
	for (int i = 1; x-i >= 0; ++i)
	{
		if (get_board(x-i, y) == c) return true; else
		if (get_board(x-i, y)!='.') break;
	}
	for (int i = 1; x+i < SIZE; ++i)
	{
		if (get_board(x+i, y) == c) return true; else
		if (get_board(x+i, y)!='.') break;
	}
	for (int i = 1; y-i >= 0; ++i)
	{
		if (get_board(x, y-i) == c) return true; else
		if (get_board(x, y-i)!='.') break;
	}
	for (int i = 1; y+i < SIZE; ++i)
	{
		if (get_board(x, y+i) == c) return true; else
		if (get_board(x, y+i)!='.') break;
	}
	return false;
}

bool bishop_attacks_king(int x, int y, char c)
{
	for (int i = 1; (x-i >= 0) && (y-i >= 0); ++i)
	{
		if (get_board(x-i, y-i) == c) return true; else
		if (get_board(x-i, y-i)!='.') break;
	}
	for (int i = 1; (x+i < SIZE) && (y+i < SIZE); ++i)
	{
		if (get_board(x+i, y+i) == c) return true; else
		if (get_board(x+i, y+i)!='.') break;
	}
	for (int i = 1; (x+i < SIZE) && (y-i >= 0); ++i)
	{
		if (get_board(x+i, y-i) == c) return true; else
		if (get_board(x+i, y-i)!='.') break;
	}
	for (int i = 1; (x-i >= 0) && (y+i < SIZE); ++i)
	{
		if (get_board(x-i, y+i) == c) return true; else
		if (get_board(x-i, y+i)!='.') break;
	}
	return false;
}

bool queen_attacks_king(int x, int y, char c)
{
	return bishop_attacks_king(x, y, c) || rook_attacks_king(x, y, c);
}

bool king_attacks_king(int x, int y, char c)
{
	return	get_board(x-1, y-1) == c || get_board(x-1, y  ) == c ||
					get_board(x-1, y+1) == c || get_board(x  , y-1) == c ||
					get_board(x  , y+1) == c || get_board(x+1, y-1) == c ||
					get_board(x+1, y  ) == c || get_board(x+1, y+1) == c;
}

bool board_empty()
{
	for (int i = 0; i < SIZE; ++i)
		for (int j = 0; j < SIZE; ++j)
			if (board[i][j] != '.')
				return false;
	return true;
}

/*
 * 0 no king is in check
 * 1 white king is in check
 * 2 black king is in check
 */
int solve()
{
	for (int i = 0; i < SIZE; ++i)
		for (int j = 0; j < SIZE; ++j)
		{
			switch (board[i][j])
			{
				case 'p': if (black_pawn_attacks_king(i, j))		return 1; break;
				case 'r': if (rook_attacks_king		(i, j, 'K'))	return 1; break;
				case 'b': if (bishop_attacks_king	(i, j, 'K'))	return 1; break;
				case 'q': if (queen_attacks_king	(i, j, 'K'))	return 1; break;
				case 'n': if (knight_attacks_king	(i, j, 'K'))	return 1; break;
				/*case 'k': if (king_attacks_king(i, j, 'K'))		return 1; break;*/

				case 'P': if (white_pawn_attacks_king(i, j))		return 2; break;
				case 'R': if (rook_attacks_king		(i, j, 'k'))	return 2; break;
				case 'B': if (bishop_attacks_king	(i, j, 'k'))	return 2; break;
				case 'Q': if (queen_attacks_king	(i, j, 'k'))	return 2; break;
				case 'N': if (knight_attacks_king	(i, j, 'k'))	return 2; break;
				/*case 'K': if (king_attacks_king(i, j, 'k'))		return 2; break;*/

				case 'K': case 'k': break;
				case '.': continue;

				default:
					assert(false);
			}
		}
	return 0;
}

int main()
{
	for (int test_i = 1; true; ++test_i)
	{
		for (int i = 0; i < SIZE; ++i)
			cin >> board[i];

		if (board_empty())
			break;

		cout << "Game #" << test_i << ": ";
		switch (solve())
		{
			case 0: cout << "no king is in check.\n";			break;
			case 1: cout << "white king is in check.\n";	break;
			case 2: cout << "black king is in check.\n";	break;
		}
	}

	return 0;
}

