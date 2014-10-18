
#include <cstdio>
#include <vector>
#include <string>
#include <iostream>

using namespace std;

#define every(i, a, b) for (int i = (a); i <= int(b); ++i)

#define repeat(n) every (i, 1, n)

class disjoint_sets {
	private:
		vector<int> pset;

	public:
		void init(int _size) {
			pset.resize(_size);
			every (i, 0, _size-1)
				pset[i] = i;
		}

		int set_of(int i) {
			return (pset[i] == i) ? i: (pset[i] = set_of(pset[i]));
		}

		void union_set(int i, int j) {
			pset[ set_of(i) ] = set_of(j);
		}

		bool is_in_same_set(int i, int j) {
			return set_of(i) == set_of(j);
		}

		int number_of_sets() {
			int n = 0;
			every (i, 0, pset.size()-1)
				n += (pset[i] == i);
			return n;
		}

		int size_of_set(int i) {
			int n = 0;
			every (j, 0, pset.size()-1)
				n += is_in_same_set(i, j);
			return n;
		}
};


int main() {
	int N;
	char c;
	bool first = true;
	string s;
	disjoint_sets dsets;

	cin >> N;
	while (N--) {
		cin >> c; cin.get();
		dsets.init(c-'A'+1);

		while (1) {
			getline(cin, s);
			if (s.size() == 0)
				break;
			dsets.union_set(s[0]-'A', s[1]-'A');
		}

		if (first) first = false;
		else cout << endl;
		cout << dsets.number_of_sets() << endl;
	}

	return 0;
}

