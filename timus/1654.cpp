
#include <map>
#include <cmath>
#include <stack>
#include <cstdio>
#include <cctype>
#include <string>
#include <vector>
#include <cstdlib>
#include <iostream>
#include <algorithm>

int main() {
	using namespace std;

	char c;
	stack<char> st;

	while (cin.get(c)) {

		if (st.empty())
			st.push(c);
		else
		if (st.top() == c)
			st.pop();
		else
			st.push(c);
	}

	string s; s.reserve(20000);
	for (; !st.empty(); st.pop())
		s.push_back(st.top());

	reverse(s.begin(), s.end());
	cout << s << endl;

	return 0;
}

