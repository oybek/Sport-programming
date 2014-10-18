
#include <map>
#include <cmath>
#include <cstdio>
#include <cctype>
#include <string>
#include <vector>
#include <cstdlib>
#include <iostream>
#include <algorithm>

int main() {
	using namespace std;

#ifndef ONLINE_JUDGE
	freopen("input.txt", "rt", stdin);
	freopen("output.txt", "wt", stdout);
#endif

	
	map<string, vector<string> > facul;

	const char * fname[4] = {
		"Slytherin",
		"Hufflepuff",
		"Gryffindor",
		"Ravenclaw",
	};

	int n;
	cin >> n;

	string name, faculty;
	cin.get();

	while (n--) {
		getline(cin, name);
		getline(cin, faculty);

		facul[faculty].push_back(name);
	}

	for (int i = 0; i < 4; ++i) {
		cout << fname[i] << ':' << endl;
		for (int j = 0; j < facul[fname[i]].size(); ++j)
			cout << facul[fname[i]][j] << endl;
		cout << endl;
	}

	return 0;
}

