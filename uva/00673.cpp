
#include <stack>
#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;

bool is_correct(const char* s) {
	const char* c;
	stack<char> st;

	while (!st.empty())
		st.pop();

	for (c = s; (*c != '\n') && (*c != '\0'); ++c) {
		switch (*c) {
			case ']':
				if (st.empty() || st.top() != '[')
					return false;
				else
					st.pop();
				break;

			case ')':
				if (st.empty() || st.top() != '(')
					return false;
				else
					st.pop();
				break;

			case '(':
				st.push(*c);
				break;

			case '[':
				st.push(*c);
				break;
		}
	}
	return st.empty();
}

int main() {
	const int s_max_sz = 256;
	char s[ s_max_sz ];

	int N;
	scanf("%d", &N);
	getchar();

	while (N--) {
		fgets(s, s_max_sz, stdin);
		puts((is_correct(s) ? "Yes": "No"));
	}

	return 0;
}

