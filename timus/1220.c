
#include <stdio.h>
#include <stdlib.h>

#define MAX_STACK_NUM 1000

typedef struct node {
	unsigned int v;
	struct node * next;
} node;

typedef struct stack {
	node * top;
} stack;

char com[5];
node * tmp;
stack st[ MAX_STACK_NUM ];
unsigned int v, i, op;

void push(stack * st, unsigned int v)
{
	tmp = st->top;
	st->top = (node *) malloc(sizeof (node));

	st->top->next = tmp;
	st->top->v = v;
}

unsigned int pop(stack * st)
{
	tmp = st->top;
	st->top = tmp->next;
	v = tmp->v;
	free((void *) tmp);
	return v;
}

int main()
{
	printf("%ld\n", sizeof (stack));
	scanf("%d", &op);

	while ( op-- )
	{
		scanf("%s", com);

		switch ( com[1] )
		{
			case 'U':
				scanf("%d%d", &i, &v);
				push(st+i-1 , v);
			break;

			case 'O':
				scanf("%d", &i);
				printf("%d\n", pop(st+i-1));
			break;
		}
	}

	return 0;
}

