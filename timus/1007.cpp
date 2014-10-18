
#include <iostream>
#include <vector>
using namespace std;

inline bool sum(const vector<bool> & word)
{
	long sum = 0;
	for (int i = 0; i < word.size(); ++i)
		sum += (i+1)*word[i];

	return sum;
}

// pushes 0, 1 to pos i
inline void push(vector<bool> & vec, int ind, bool val)
{
	vec.push_back(val);
	for (int i = vec.size()-1; i != ind; --i) {
		bool z = vec[i];
		vec[i] = vec[i-1];
		vec[i-1] = z;
	}
}

int main() {
	int n, c;
	vector<bool> word;
	cin >> n;
	while (cin >> c) {
		switch (c) {
			case '0':
				word.push_back(0);
				break;
			case '1':
				word.push_back(1);
				break;
			case '\n':
				if (word.size() == n) {
					int s = sum(word);
					if (s%(n+1))
						word[s-(s%(n+1))] = 0;
				}
				else if (word.size() < n) {
					int s = sum(word);
					if (s%(n+1))
						word.push_back(0);
					else
						push(word, (n-s%n)-1, 1);
				}
				else {
				}
				for (int i = 0; i < n; ++i)
					cout << word[i];
				cout << endl;
				break;
		}
	}

	return 0;
}

