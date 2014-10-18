#include <iostream>
#include <vector>
using namespace std; 

struct node {
	int c;
	vector<node *> next;
	node() : c(-1) {}
};

void deep_paint(node * cur, int to, bool & ispos)
{
	cur->c = to;
	for (int i = 0; i < cur->next.size(); ++i) {
		if (cur->next[i]->c == -1)
			deep_paint(cur->next[i], !to, ispos);
		else if (cur->next[i]->c == to)
			ispos = 0;
	}
}

bool city_paint(node * cur, int size)
{
	bool ispos = 1;

	for (int i = 0; i < size; ++i)
		if (cur[i].c == -1) {
			deep_paint(&cur[i], 0, ispos);
			if (!ispos)
				return false;
		}

	return true;
}

int main()
{
	int N, t;
	cin >> N;

	node * city1 = new node [N];
	node * city2 = new node [N];

	for (int i = 0;i < N; ++i) {
		while (1) {
			cin >> t; if (!t) break;
			city1[i].next.push_back(&city1[t-1]);
			city1[t-1].next.push_back(&city1[i]);

			city2[i].next.push_back(&city2[t-1]);
			city2[t-1].next.push_back(&city2[i]);
		}
	}
 
	if (city_paint(city1, N)) {
		for (int i = 0; i < N; ++i)
			cout << city1[i].c;
		cout << endl;
		return 0;
	}
	else if (city_paint(city2, N)) {
		for (int i = 0; i < N; ++i)
			cout << city2[i].c;
		cout << endl;
		return 0;
	}
	else
		cout << -1 << endl;

	return 0;
}

