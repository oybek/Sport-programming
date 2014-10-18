
#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <iostream>
#include <vector>
#include <cstdio>
#include <iomanip>
using namespace std;

int main() {

#ifndef ONLINE_JUDGE                                                          
	 freopen("input.txt", "rt", stdin);                                        
	 freopen("output.txt", "wt", stdout);                                      
#endif
	 int n, t, s, time;

	 cin >> n >> t >> s;

	 cout.precision(6);
	 cout.setf(std::ios::fixed, std::ios::floatfield);
	 for (int i = 0; i < n; ++i) {
		 cin >> time;
		 cout << time+(t-(time-s))/2.0 << endl;
	 }

	 return 0;
}

