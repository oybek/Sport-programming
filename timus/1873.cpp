
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

#define INF INT_MAX-1
#define SQR(x) ((x)*(x))

typedef unsigned long long uint64;
typedef long long int64;

using namespace std;

int n, ans[] = { 5, 20, 12, 2, 1, 4, 6, 1, 4, 4, 1, 0 };

int main()
{
    cin >> n;
    cout << ans[n];

    return 0;
}

