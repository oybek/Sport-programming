
#include <stdio.h>

struct date {
	int day, month, year;
};

int Casenum;
struct date born, curr, diff;

int main()
{
	register int i;

	scanf("%d", &Casenum);
	for (i = 1; i <= Casenum; i++)
	{
		scanf("%d/%d/%d", &curr.day, &curr.month, &curr.year);
		scanf("%d/%d/%d", &born.day, &born.month, &born.year);

		diff.year = curr.year - born.year;
		diff.month = curr.month - born.month;
		diff.day = curr.day - born.day;

		if (diff.year >= 0) {
			diff.year -= (diff.month < 0) || (diff.month == 0 && diff.day < 0);
			/*
			if (diff.month < 0)
				diff.year--;
			else if ( (diff.month == 0) && (diff.day < 0) )
				diff.year--;
			*/
		}

		printf("Case #%d: ", i);
		if (diff.year < 0)
			puts("Invalid birth date");
		else if (diff.year > 130)
			puts("Check birth date");
		else
			printf("%d\n", diff.year);
	}

	return 0;
}

