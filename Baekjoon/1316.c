#include<stdio.h>
#include<string.h>

int main()
{
	int N,i,j,result, k, len, flag = 0;	//repeated? 1: Yes, 0:NO
	char input[101] = "";
	int check[26];

	for (i = 0; i < 26; i++)
	{
		check[i] = 0;	//checkin' whether it repeated 1: Yes, 0: No
	}

	scanf("%d", &N);
	result = N;
	for (i = 0; i < N; i++)
	{
		scanf("%s", input);
		len = strlen(input);
		for (j = 0; j < len; j++)
		{
			if (j == 0) check[input[j] - 97] = 1;	//가장 처음 글자는 무조건 Yes
			else{									//앗 처음 글자가 아니라구요?
				if (input[j - 1] == input[j]) continue;	//그럼 그 이전 글자와 같다면 pass
				else {                                 //전 글자와 같지 않다구요?
														//변화하는 구간에서 해당 글자가 이전에 쓰였는지 확인해봅시다.
					if (check[input[j] - 97] == 0) check[input[j] - 97] = 1;
					else
					{
						flag = 1;
						break;
					}
					
				}
			}

		}
		if (flag == 1)
		{
			result--;
			flag = 0;
		}
		for (k = 0; k < 26; k++) check[k] = 0;	//check초기화
		
	}

	printf("%d\n", result);

	return 0;
}
