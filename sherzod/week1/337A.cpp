#include <iostream>
#include <algorithm>
using namespace std;

#define SIZE 1000
#define INF 1000000009

int main() {
    int n, m, f[SIZE], ans = INF;
    cin >> n >> m;
    for (int i = 0; i < m; ++i)
        cin >> f[i];
    sort(f, f+m);
    for (int i = 0; i+n <= m; ++i)
        ans = min(f[i+n-1]-f[i], ans);
    cout << ans;
    
	return 0;
}
