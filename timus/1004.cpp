
#include <map>
#include <cmath>
#include <cstdio>
#include <cctype>
#include <string>
#include <vector>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <algorithm>

#define MAX_VERTEX	100
#define MAX_EDGE	9900

struct edge_t {
	int v, w;
};

struct Graph {
	edge_t edge[MAX_VERTEX][MAX_EDGE];
	int vertex_num;
	int degree[MAX_VERTEX];

	Graph() : vertex_num(0) {
		memset(degree, 0, MAX_VERTEX);
	}

	void insert_edge(int a, int b, int w, bool directed) {
		edge[a][ degree[a] ].v = b;
		edge[a][ degree[a] ].w = w;

		++degree[a];
		if (!directed) insert_edge(b, a, w, true);
	}
};

void prima_sst(Graph & G, edge_t * edge) {
	int * d = new int [G.vertex_num];
	int * p = new int [G.vertex_num];

	for (int i = 0; i < G.vertex_num; ++i) {
		d[i] = -1;
		p[i] = 0;
	}

	d[0] = 0;
}

int main() {
	using namespace std;
	Graph G;

	int vertex_num, edge_num, a, b, w;

	while (1) {
		cin >> vertex_num;
		if (vertex_num == -1)
			break;

		cin >> edge_num;

		while (edge_num--) {
			cin >> a >> b >> w;
			G.insert_edge(a, b, w, false);
		}
	}


	return 0;
}

