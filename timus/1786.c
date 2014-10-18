
/*
http://acm.timus.ru/problem.aspx?space=1&num=1786
*/

#include <ctype.h>
#include <stdio.h>
#include <string.h>

#define min(a, b) (a) < (b) ? (a): (b)

int cost(const char * s)
{
	int c = 0;
	c += (islower(s[0]) ? (s[0] == 's' ? 5: 10) : (s[0] == 'S' ? 0: 5)); 
	c += (isupper(s[1]) ? (s[1] == 'A' ? 5: 10) : (s[1] == 'a' ? 0: 5)); 
	c += (isupper(s[2]) ? (s[2] == 'N' ? 5: 10) : (s[2] == 'n' ? 0: 5)); 
	c += (isupper(s[3]) ? (s[3] == 'D' ? 5: 10) : (s[3] == 'd' ? 0: 5)); 
	c += (isupper(s[4]) ? (s[4] == 'R' ? 5: 10) : (s[4] == 'r' ? 0: 5)); 
	c += (isupper(s[5]) ? (s[5] == 'O' ? 5: 10) : (s[5] == 'o' ? 0: 5)); 
	return c;
}

int main()
{
	int slen, i, min_price = 100;
	char s[ 201 ];

	scanf("%s", s);
	slen = strlen(s);
	for (i = 0; i+6 <= slen; i++)
		min_price = min(min_price, cost(&s[i]));

	printf("%d\n", min_price);

	return 0;
}

