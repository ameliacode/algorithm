#include<stdio.h>
typedef long long ll;	//감당하기 큰 수라면 long long 사용

int main()
{
	ll T, x, y, m, i, save;
	ll dis;

	scanf("%lld", &T);
	
	for (i = 0; i < T; i++)
	{
		scanf("%lld %lld", &x, &y);
		dis = y - x;
		for (m = 0; ; m++)
		{
			if (m*m < dis&&dis <= m*m+2*m+1)
			{
				save = m;
				break;
			}
		}
		if (dis<=m*m+m) printf("%lld\n", save * 2);
		else printf("%lld\n", save*2+1);
	}

	return 0;
}
