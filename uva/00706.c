#include <stdio.h>
#include <string.h>

#define MAXROW 24
#define MAXCOL 104

char board[ MAXROW ][ MAXCOL ] = {};
int rown, coln;
int s;
char num[9];

void draw_0(int);
void draw_1(int);
void draw_2(int);
void draw_3(int);
void draw_4(int);
void draw_5(int);
void draw_6(int);
void draw_7(int);
void draw_8(int);
void draw_9(int);

void showboard(void)
{
	int i, j;
	int n = strlen(num)*(s+3)-1;

	for (i = 1; i <= rown; i++) {
		for (j = 1; j <= n; j++)
			printf("%c", board[i][j]);
		printf("\n");
	}
}

void initboard(void)
{
	int i, j;
	int n = strlen(num)*(s+3)-1;
	for (i = 1; i <= rown; i++) {
		for (j = 1; j <= n; j++)
			board[i][j] = ' ';
	}
}

int main()
{
	while (1) {
		int i;
		for (i = 0; i < 9; i++)
			num[i] = 0;

		scanf("%d%s", &s, num);

		if (!s)
			break;

		rown = 2*s+3;
		coln = s+2;

		initboard();

		for (i = 0; num[i] != '\0'; i++) {
			switch (num[i]) {
				case '0' :
					draw_0(i*(s+3)+1);
					break;
				case '1' :
					draw_1(i*(s+3)+1);
					break;
				case '2' :
					draw_2(i*(s+3)+1);
					break;
				case '3' :
					draw_3(i*(s+3)+1);
					break;
				case '4' :
					draw_4(i*(s+3)+1);
					break;
				case '5' :
					draw_5(i*(s+3)+1);
					break;
				case '6' :
					draw_6(i*(s+3)+1);
					break;
				case '7' :
					draw_7(i*(s+3)+1);
					break;
				case '8' :
					draw_8(i*(s+3)+1);
					break;
				case '9' :
					draw_9(i*(s+3)+1);
					break;
			}
		}
		showboard();
		printf("\n");
	}

	return 0;
}

void draw_1(int d)
{
	int i, j; d--;
	for (i = 1; i <= rown; i++)
		for (j = 1; j <= coln; j++)
			board[i][d+j] = ' ';

	for (i = 1; i <= s; i++) {
		board[i+1][d+coln] = '|';
		board[s+2+i][d+coln] = '|';
	}
}

void draw_2(int d)
{
	int i, j; d--;
	for (i = 1; i <= rown; i++)
		for (j = 1; j <= coln; j++)
			board[i][d+j] = ' ';

	for (i = 1; i <= s; i++) {
		board[1][d+i+1] = board[s+2][d+i+1] = board[2*s+3][d+i+1] = '-';
		board[i+1][d+coln] = board[s+2+i][d+1] = '|';
	}
}

void draw_3(int d)
{
	draw_1(d);
	int i; d--;
	for (i = 1; i <= s; i++)
		board[1][d+i+1] = board[s+2][d+i+1] = board[2*s+3][d+i+1] = '-';
}

void draw_4(int d)
{
	draw_1(d);
	int i, j; d--;
	for (i = 1; i <= s; i++) {
		board[i+1][d+1] = '|';
		board[s+2][d+1+i] = '-';
	}
}

void draw_5(int d)
{
	int i, j; d--;
	for (i = 1; i <= rown; i++)
		for (j = 1; j <= coln; j++)
			board[i][d+j] = ' ';

	for (i = 1; i <= s; i++) {
		board[1][d+i+1] = board[s+2][d+i+1] = board[2*s+3][d+i+1] = '-';
		board[i+1][d+1] = board[s+2+i][d+coln] = '|';
	}
}

void draw_6(int d)
{
	draw_5(d);
	int i; d--;
	for (i = 1; i <= s; i++)
		board[s+2+i][d+1] = '|';
}

void draw_7(int d)
{
	draw_1(d);
	int i; d--;
	for (i = 1; i <= s; i++)
		board[1][d+i+1] = '-';
}

void draw_8(int d)
{
	draw_2(d); d--; int i;
	for (i = 1; i <= s; i++) {
		board[i+1][d+1] = board[s+2+i][d+coln] = '|';
	}
}

void draw_9(int d)
{
	draw_8(d);
	int i; d--;
	for (i = 1; i <= s; i++)
		board[s+2+i][d+1] = ' ';
}

void draw_0(int d)
{
	draw_8(d);
	int i; d--;
	for (i = 1; i <= s; i++)
		board[s+2][d+i+1] = ' ';
}

