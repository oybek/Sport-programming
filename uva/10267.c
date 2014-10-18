#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAXX 252
#define MAXY 252

struct image {
	int M, N;
	char title[20];
	char pic[MAXX][MAXY];
};

struct image file;

void create_image(void);
void save_image(void);
void clear_image(void);
void draw_pixel(int, int, char);
void draw_hline(int, int, int, char);
void draw_vline(int, int, int, char);
void draw_frec(int, int, int, int, char);
void fill(int, int, char, int);

int main()
{
	char c; int x, y, x1, x2, y1, y2;

	for (x = 0; x < MAXX; x++)
		for (y = 0; y < MAXY; y++)
			file.pic[x][y] = 0;

	char commandline[100];

	while (1) {
		fgets(commandline, 100, stdin);

		if (commandline[0] == 'X')
			break;

		switch (commandline[0]) {
			case 'I' :
				sscanf(commandline, "%c %d %d", &c, &file.M, &file.N);
				create_image();
				break;

			case 'C' :
				clear_image();
				break;
			case 'L' :
				sscanf(commandline, "%c %d %d %c", &c, &x, &y, &c);
				draw_pixel(x, y, c);
				break;
			case 'V' :
				sscanf(commandline, "%c %d %d %d %c", &c, &x, &y1, &y2, &c);
				draw_vline(x, y1, y2, c);
				break;
			case 'H' :
				sscanf(commandline, "%c %d %d %d %c", &c, &x1, &x2, &y, &c);
				draw_hline(x1, x2, y, c);
				break;
			case 'K' :
				sscanf(commandline, "%c %d %d %d %d %c", &c, &x1, &x2, &y1, &y2, &c);
				draw_frec(x1, x2, y1, y2, c);
				break;
			case 'F' :
				sscanf(commandline, "%c %d %d %c", &c, &x, &y, &c);
				fill(x, y, c, 0);
				break;

			case 'S' :
				sscanf(commandline, "%c %s", &c, (file.title));
				save_image();
				break;

			default :
				break;
		}
	}

	return 0;
}

void create_image(void)
{
	int i, j;

	for (i = 1; i <= file.M; i++)
		for (j = 1; j <= file.N; j++)
			file.pic[i][j] = 'O';
}
void save_image(void)
{
	int i, j;

	/*int len = strlen(file.title);

	  */
	/*
	if ((file.title[len-1] == 'p') && (file.title[len-2] == 'm') && (file.title[len-3] == 'b') && (file.title[len-4] == '.'))
	*/
	printf("%s\n", file.title);
		/*
	else
		printf("%s.bmp\n", file.title);
		*/

	for (i = 1; i <= file.N; i++) {
		for (j = 1; j <= file.M; j++)
			printf("%c", file.pic[j][i]);
		printf("\n");
	}
}
void clear_image(void)
{
	int i, j;
	for (i = 1; i <= file.M; i++)
		for (j = 1; j <= file.N; j++)
			file.pic[i][j] = 'O';
}
void draw_pixel(int x, int y, char c)
{
	file.pic[x][y] = c;
}
void draw_hline(int x1, int x2, int y, char c)
{
	int d;
	/*if (x1 > x2) {
		int z = x2; x2 = x1; x1 = z;
	}
	*/
	for (d = x1; d <= x2; d++)
		file.pic[d][y] = c;
}
void draw_vline(int x, int y1, int y2, char c)
{
	int d;
	/*
	if (y1 > y2) {
		int z = y2; y2 = y1; y1 = z;
	}
	*/
	for (d = y1; d <= y2; d++)
		file.pic[x][d] = c;
}
void draw_frec(int x1, int x2, int y1, int y2, char c)
{
	int dx, dy;

	/*if ((x1 > x2) || (y1 > y2))
		return;
		*/

	/*int z;
	if (x1 > x2)
		z = x1, x1 = x2, x2 = z;
	if (y1 > y2)
		z = y1, y1 = y2, y2 = z;

		*/
	for (dx = x1; dx <= x2; dx++)
		for (dy = y1; dy <= y2; dy++)
			file.pic[dx][dy] = c;
}
void fill(int x, int y, char c, int flag)
{
	if ((file.pic[x][y] != c) && !flag)
		flag = file.pic[x][y];

	if (file.pic[x][y] == flag) {
		file.pic[x][y] = c;

		fill(x-1, y, c, flag);
		fill(x, y+1, c, flag);
		fill(x+1, y, c, flag);
		fill(x, y-1, c, flag);
	}
}

