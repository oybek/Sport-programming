
#include <map>
#include <cmath>
#include <cstdio>
#include <string>
#include <vector>
#include <cstdlib>
#include <iostream>
#include <algorithm>

using namespace std;

struct tree_node_t {
	map<string, tree_node_t*> next;
};

class tree_t {
	private:
	public:
};

void parse(const string & s, vector<string> & dir) {
	dir.resize(0);

	size_t s_len = s.size();
	for (auto e: s) {
		string t;

		switch (e) {
			if (e == '\\') {
				dir.push_back(t);
				t.erase();
			} else {
				t.push_back(e);
			}
		}
	}
}

int main() {

#ifndef ONLINE_JUDGE                                                          
	 freopen("input.txt", "rt", stdin);                                        
	 freopen("output.txt", "wt", stdout);                                      
#endif

	int N;
	cin >> N;
	while (N--) {
		string line;
		cin >> line;
	}

	return 0;
}

