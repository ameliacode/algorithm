#include<stdio.h>
#include<math.h>

int gcd(int a, int b)
{
	if (a < b) return gcd(b, a);
	else if (a%b == 0) return b;
	else return gcd(b, a%b);
}

int lcm(int a, int b)
{
	return a * b / gcd(a, b);
}

int main()
{
	int T, M, N, x, y;
	int i, j, k = 0;
	int x2 = 1, y2 = 1, flag = 0; //does it exists? 1:Yes ,No: 0
	int end;
	scanf("%d", &T);

	for (i = 0; i < T; i++)
	{//시간초과로 다시 짜게된 코드 이번에는 여러가지 경우의 수를 두어서
	//노트에 직접 적으면 보이긴 한다. 2차원배열화: 행렬 개념으로 생각하자
		scanf("%d %d %d %d", &M, &N, &x, &y);
		end = (lcm(M, N)) / M;	//같은 행에 있는 (x가 어떤 수 일때 그 해당 행) 열만 찾으면 되므로 end설정
		flag = 0;
		for(j=0;j<=end+1;j++)
		{
			y2 = (x + (j*M)) % N;//찾고자하는 숫자 계산, y는 N을 넘지 않는다는 점과 행의 갯수는 M개인 점 이용
			if (y2 == 0) y2 = N;//N으로 나누어 버리면 N자체의 숫자는 0으로 처리 되므로 그리고 이 문제의 0은 없다...
			//printf("%d %d\n", y, y2);
			if (y2 == y) {
				flag = 1;
				//printf("!");
				break;
			}
		}
		if(flag == 1) printf("%d\n", x+j*M);
		else printf("-1\n");
		
		y2 = 0;


		//first trial
		/*while (1)
		{
			//printf("%d %d\n", x2, y2); //카잉 달력 확인
			x2++;
			y2++;
			if (x2 == M+1) x2 = 1;
			if (y2 == N+1) y2 = 1;
			k++;
			
			if (x2 == x && y2 == y) break;
			if (x2 == M && y2 == N) {	//끝까지 도달했으면 없으므로 존재하지 않다라고 처리
				flag = 0;
				break;
			}
		}
		if (flag == 0) printf("-1\n");
		else printf("%d\n", k+1);
		k = 0;
		flag = 1;*/
	}


	return 0;
}