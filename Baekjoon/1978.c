#include<stdio.h>
#include<string.h>

int main()
{
	int N, i ,j,cnt = 0;
	int arr[1000], flag = 1;//1:Yes 0:No
	scanf("%d", &N);

	for (i = 0; i < N; i++)
	{
		scanf("%d", &arr[i]);
	}

	for (i = 0; i < N; i++)
	{
		if (arr[i] != 1) {
			for (j = 2; j < arr[i]; j++)
			{
				if (arr[i] % j == 0)
				{
					flag = 0;
					break;
				}
			}
			if (flag == 1) {
				cnt++;
			}
			else flag = 1;
		}
		
	}

	printf("%d\n", cnt);

	getchar();
	return 0;
}
