
#include <stdio.h>
#include <stdlib.h>

#define MAX_STACK_NUM 1000

struct node {
	int v;
	struct node * n;
} * tmp;

#define PUSH(c, n)\
	tmp = (struct node *) malloc(sizeof (struct node));\
	tmp->n = c;\
	c = tmp;\
	c->v = n;\

#define POP(c)\
	if (c == NULL) break;\
	printf("%d\n", c->v);\
	tmp = c;\
	c = c->n;\
	free((void *) tmp);\

int n, i, v;
char s[5];
struct node * st[1000];

int main()
{
	scanf("%d", &n);
	while (n--)
	{
		scanf("%s", s);
		switch (s[1])
		{
			case 'U':
				scanf("%d%d", &i, &v); --i;
				PUSH(st[i], v);
				break;

			case 'O':
				scanf("%d", &i); --i;
				POP(st[i]);
				break;
		}
	}


	return 0;
}

