
#include <vector>
#include <string>
#include <cstdio>
#include <iostream>

std::vector<bool> sign;
int graphSize;
struct graphNode {
	std::vector<int> parent;
	std::vector<int> child;
} * G;

void dfsChild(int v) {

	//if (sign[v] == false) return;
	sign[v] = false;
	for (int i = 0; i < G[v].child.size(); ++i)
		if (sign[G[v].child[i]])
			dfsChild(G[v].child[i]);
}

void dfsParent(int v) {

	//if (sign[v] == false) return;
	sign[v] = false;
	for (int i = 0; i < G[v].parent.size(); ++i)
		if (sign[G[v].parent[i]])
			dfsParent(G[v].parent[i]);
}
     
int main() {
	using namespace std;

	cin >> graphSize;

	sign.resize(graphSize+1);
	fill(sign.begin(), sign.end(), true);

	G = new graphNode [graphSize+1];

	string s;
	getline(cin, s);
	while (1) {
		string s;
		getline(cin, s);

		if (s == "BLOOD") {
			break;
		}

		int child, parent;
		sscanf(s.c_str(), "%d%d", &child, &parent);

		G[child].parent.push_back(parent);
		G[parent].child.push_back(child);
	}

	for (int node; cin >> node; ) {
		dfsChild(node);
		dfsParent(node);
	}
    
	bool flag = true;
	for (int i = 1; i < sign.size(); ++i)
		if (sign[i]) {
			cout << i << ' ';
			flag = false;
		}

	if (flag) cout << "0";
	cout << endl;

	return 0;
}

