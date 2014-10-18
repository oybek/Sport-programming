#include <iostream>
#include <cstdio>
#include <map>
using namespace std;

class prefix_tree_t {
	private:

		struct node {
			bool exist;
			struct node * next[26];

			node() : exist(0)
			{
				for (int i = 0; i < 26; ++i)
					next[i] = NULL;
			}
		} * root;

		inline int hash(char c)
		{
			return c-'a';
		}

	public:
		prefix_tree_t() : root(new node) {}

		void add_branch(const string & s) {
			node * curr = root;

			for (int i = 0; i < s.size(); ++i) {
				if (curr->next[hash(s[i])])
					curr = curr->next[hash(s[i])];
				else
					curr = curr->next[hash(s[i])] = new node;
			}
			curr->exist = 1;
		}

		bool isthere(const string & s) {
			node * curr = root;
			for (int i = 0; i < s.size(); ++i) {
				if (curr->next[hash(s[i])] == NULL)
					return 0;
				else
					curr = curr->next[hash(s[i])];
			}
			return curr->exist;
		}
};

#define MAX_LEN 0x100

void getline(char * ptr, int len) {
	char c;
	while (len-- && ((c = getchar()) != '\n'))
		*ptr++ = c;
}

int main() {
	int obj_num;
	string obj_name, assoc;
	map<string, prefix_tree_t> obj;

	cin >> obj_num;
	cin >> obj_name;

	while (--obj_num) {
		while (1) {
			cin >> assoc;
			if (assoc[assoc.size()-1] == ':')
				break;
			else
				obj[obj_name].add_branch(assoc);
		}

		obj_name = assoc;
	}

	
	int req_num;
	cin >> req_num;
	while (req_num--) {
		while ((c = getchar()) != '\n')
	}


	return 0;
}

