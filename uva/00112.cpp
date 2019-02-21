
#include <bits/stdc++.h>

#define inf 1000000001
#define sqr(x) ((x)*(x))
#define all(x) x.begin(), x.end()

typedef unsigned long long ull;
typedef long long ll;

using namespace std;

template<class T>
T calc_sum(stack<T> st) {
   T* end   = &st.top() + 1;
   T* begin = end - st.size();
   vector<T> v(begin, end);
   return accumulate(all(v), 0ll);
}

void TEST__calc_sum() {{
	stack<ll> st;
	assert(calc_sum(st) == 0);
}{
	stack<ll> st;
	st.push(2);
	st.push(3);
	assert(calc_sum(st) == 5);
}}

string process_tree(ll needed_sum) {
	ll sum;
	bool leaf = true;
	char c;
	stack<ll> st;
	bool yes = false;
	while ((c = cin.get()) != EOF) {
		switch (c) {
			default:
				break;

			case '(':
				st.push(0);
				leaf = true;
				break;

			case ')':
				if (leaf) {
					sum = calc_sum(st);
					yes |= (sum == needed_sum);
					leaf = false;
				}

				st.pop();
				if (st.empty())
					return yes ? "yes" : "no";
				break;

			case '0': case '1':
			case '2': case '3':
			case '4': case '5':
			case '6': case '7':
			case '8': case '9':
				st.top() = st.top() * 10 + (st.top() < 0 ? -(c-'0') : c-'0');
				break;

			case '-':
				st.top() = -(cin.get()-'0');
				break;
		}
	}
	return yes ? "yes" : "no";
}

int main() {
#ifdef LOCAL
	TEST__calc_sum();
#endif

	int needed_sum;
	while (cin >> needed_sum) {
		cout << process_tree(needed_sum) << endl;
	}

	return 0;
}

