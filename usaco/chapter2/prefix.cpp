
/*
ID: aybek.h2
PROG: prefix
LANG: C++
*/

#define PROB_NAME "prefix"

#include <cmath>
#include <string>
#include <cassert>
#include <fstream>
#include <iostream>
#include <algorithm>

std::ifstream fin	(PROB_NAME".in");
std::ofstream fout	(PROB_NAME".out");

template <const unsigned int SIZE>
class trie {
	private:
		struct nodeT {
			bool sign;
			nodeT * child[ SIZE ];

			nodeT() : sign(false) {
				unsigned int i;
				for (i = 0; i < SIZE; ++i)
					child[i] = NULL;
			}
		} * root;
	public:
		trie() : root(new nodeT) {}
		void insert(const std::string & s) {
			nodeT * curr = root;
			for (size_t i = 0; i < s.size(); ++i) {
				if (curr->child[ s[i]-'A' ] == NULL)
					curr->child[ s[i]-'A' ] = new nodeT;

				curr = curr->child[ s[i]-'A' ];
			}
			curr->sign = true;
		}
		bool find(const std::string s) const {
			nodeT * curr = root;
			for (size_t i = 0; i < s.size(); ++i) {
				if (curr->child[ s[i]-'A' ] == NULL)
					return false;
				curr = curr->child[ s[i]-'A' ];
			}
			return curr->sign;
		}
		/* TODO: write destructor */
};

int main() {
	using namespace std;

	const size_t strMaxLen = 200001;

	bool canReach[ strMaxLen ] = {};
	string s; s.reserve(strMaxLen);

	size_t maxPrimitiveLen = 0, maxPrefix = 0, i, l;

	trie<'Z'-'A'+1> primitives;

	// INPUT AREA
	do {
		primitives.insert(s);
		fin >> s;
		maxPrimitiveLen = max(maxPrimitiveLen, s.size());
	} while (s != ".");

	s.clear();
	s = " ";
	for (string t; fin >> t; s += t);

	//cout << "maxPrimitiveLen: " <<  maxPrimitiveLen << endl;

	fill(canReach, canReach + strMaxLen, false);
	canReach[0] = true;

	//cout << string("hello").substr(2, 1) << endl;

	//cout << s.size() << endl;
	//cout << s.size() << endl;
	for (i = 1; i < s.size(); ++i) {

		if (canReach[i-1]) {
			for (l = 1; (l <= maxPrimitiveLen) && (i+l <= s.size()); ++l) {

				if (primitives.find(s.substr(i, l))) {

					//cout << s.substr(i, l) << endl;
					canReach[i+l-1] = true; 
					maxPrefix = max(maxPrefix, i+l-1);
	} } } } 

	fout << maxPrefix << endl;

	return 0;
}

