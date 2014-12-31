
#include <map>
#include <cctype>
#include <cstdio>
#include <string>
#include <vector>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <unordered_map>
using namespace std;

#define SIZE 100001
int parent[ SIZE ];
int size[ SIZE ];

int find_set(int x)
{
	return (x == parent[x] ? x : parent[x] = find_set(parent[x]));
}

void link(int x, int y)
{
	if (x == y)
		return;

	if (size[x] > size[y])
	{
		parent[y] = x;
		size[x] += size[y];
	}
	else
	{
		parent[x] = y;
		size[y] += size[x];
	}
}

void union_set(int x, int y)
{
	link(find_set(x), find_set(y));
}

int size_set(int x)
{
	return size[ find_set(x) ];
}

unordered_map<string, int> id;

int main()
{
	char s1[32], s2[32];
	int test_n, friendship_n;

	cin >> test_n;

	while (test_n--)
	{
		int ind = 0;
		for (int i = 0; i < SIZE; ++i)
		{
			parent[i] = i;
			size[i] = 1;
		}

		id.clear();

		scanf("%d", &friendship_n);
		while (friendship_n--)
		{
			scanf("%s%s", s1, s2);

			if (id.find(string(s1)) == id.end())
				id.insert(make_pair(string(s1), ind++));
			if (id.find(string(s2)) == id.end())
				id.insert(make_pair(string(s2), ind++));

			union_set(id.find(string(s1))->second, id.find(string(s2))->second);
			printf("%d\n", size_set(id.find(string(s1))->second));
		}
	}

	return 0;
}

