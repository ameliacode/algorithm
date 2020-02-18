#include<stdio.h>
#include<string.h>

int main()
{
	char alpha[10][4] = { {NULL}, {'A','B','C', NULL}, {'D','E','F', NULL },{'G','H','I',NULL},{'J','K','L',NULL },{'M','N','O',NULL},{'P','Q','R','S'},{'T','U','V',NULL},{'W','X','Y','Z'}, {NULL} };
	char input[16] = "";
	int sec[10] = { 2,3,4,5,6,7,8,9,10,11 };
	int i, j, k;
	int len, input_ind, ind, total = 0;

	scanf("%s", input);
	len = strlen(input);

	for (i = 0; i < len; i++)
	{
		for (j = 1; j < 9; j++)
		{
			for (k = 0; alpha[j][k]; k++)
			{
				if (input[i] == alpha[j][k])
				{
					//printf("%c %c\n", input[i], alpha[j][k]);
					input_ind = j;
				}
			}
		}
		total += sec[input_ind] ;
		//printf("%d\n", total);
	}

	printf("%d", total);

	return 0;
}