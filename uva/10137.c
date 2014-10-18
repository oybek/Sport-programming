#include <stdio.h>
#include <assert.h>

#define MAX_STUDENT 1000

int main()
{
	int n;
	int sum;
	int mod; // sum of spents % average
	int ave; // average of spents
	int spent[MAX_STUDENT];

	while (1) {
		scanf("%d", &n);
		if (!n)
			break;

		int i;
		float g;
		for (i = sum = 0; i < n; i++) {
			scanf("%f", &g);

			spent[i] = g*100;
			sum += spent[ i ];
		}

		ave = sum/n;
		mod = sum%n;

		int mcent=0; // moved cents
		int mdoll=0; // moved dollars

		for (i = 0; i < n; i++) {
			if (ave-spent[i] > 0)
				mdoll += (ave-spent[i]);
		}

		if (mod)
			printf("$%.2f\n", (float)(mdoll+mcent)/100);

		printf("$%.2f\n", (float)mcent/100);
		printf("$%.2f\n", (float)mdoll/100);
	}

	return 0;
}

