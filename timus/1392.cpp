
#include <vector>
#include <bitset>
#include <iostream>
using namespace std;

#define REP(i, a, b) for (int i = int(a); i <= int(b); ++i)

vector<int> pset;

void init_set(int _size)
{	pset.resize(_size);
	REP(i, 0, _size-1)
		pset[i] = i;
}

int set_of(int i)
{   return (pset[i] == i) ? i: (pset[i] = set_of(pset[i]));
}

void union_set(int i, int j)
{    pset[ set_of(i) ] = set_of(j);
}

bool is_in_same_set(int i, int j)
{    return set_of(i) == set_of(j);
}

int number_of_sets()
{   int n = 0;
    REP(i, 0, pset.size()-1)
           n += (pset[i] == i);
    return n;
}

int size_of_set(int i)
{	int n = 0;
	REP (j, 0, pset.size()-1)
		n += is_in_same_set(i, j);
    return n;
}

#define MAX_PLANET_SIZE 1000
struct planet_t
{	int x, y, z, r;
} p[ MAX_PLANET_SIZE ];

inline int ssqr(int x, int y)
{	return (x+y)*(x+y);
}

inline int dsqr(int x, int y)
{	return (x-y)*(x-y);
}

int main()
{	init_set(MAX_PLANET_SIZE);
	int K;
	cin >> K;
	for (int i = 0; i < K; ++i)
    {   cin >> p[i].x
            >> p[i].y
            >> p[i].z
            >> p[i].r;

        for (int j = 0; j < i; ++j)
            if (dsqr(p[i].x, p[j].x)
               + dsqr(p[i].y, p[j].y)
               + dsqr(p[i].z, p[j].z)
               < ssqr(p[i].r, p[j].r)) union_set(i, j);
    }

	bitset<1000> was; was.reset();
	for (int i = 0; i < K; ++i)
	{	if (was[i]) continue;
		else was[i] = 1;
		cout << i;
		for (int j = i+1; j < K; ++j)
		{	if (is_in_same_set(i, j))
			{	cout << ", " << j;
				was[j] = 1;
			}
		}
		cout << endl;
	}

    return 0;
}

