
#include <vector>
#include <iostream>
using namespace std;

const bool santa_house_M[6][6] = {
	{ 0, 0, 0, 0, 0, 0 },
	{ 0, 0, 1, 1, 0, 1 },
	{ 0, 1, 0, 1, 0, 1 },
	{ 0, 1, 1, 0, 1, 1 },
	{ 0, 0, 0, 1, 0, 1 },
	{ 0, 1, 1, 1, 1, 0 }
};

bool M[6][6];
vector<int> path;

bool santa_house()
{	for (int i = 1; i <= 5; ++i)
	for (int j = 1; j <= 5; ++j)
		if (M[i][j] != santa_house_M[i][j])
			return false;
	return true;
}

void out_path()
{	for (int i = 0; i < int(path.size()); ++i)
		cout << path[i];
	cout << endl;
}

void backtrack(int v)
{	if (M[path.back()][v]) return;

	/*out_path();*/

	path.push_back(v);
	M[path[path.size()-2]][path[path.size()-1]] = 1;
	M[path[path.size()-1]][path[path.size()-2]] = 1;

	if (santa_house())
	{	out_path();
	} else
	{	switch (v)
		{	case 1:
				backtrack(2); backtrack(3); backtrack(5);
				break;
			case 2:
				backtrack(1); backtrack(3); backtrack(5);
				break;
			case 3:
				backtrack(1); backtrack(2); backtrack(4); backtrack(5);
				break;
			case 4:
				backtrack(3); backtrack(5);
				break;
			case 5:
				backtrack(1); backtrack(2); backtrack(3); backtrack(4);
				break;
		}
	}
	M[path[path.size()-2]][path[path.size()-1]] = 0;
	M[path[path.size()-1]][path[path.size()-2]] = 0;
	path.pop_back();
}

int main()
{	for (int i = 1; i < 6; ++i)
	for (int j = 1; j < 6; ++j)
		M[i][j] = 0;

	path.push_back(1);
	backtrack(2);
	backtrack(3);
	backtrack(5);

	return 0;
}

