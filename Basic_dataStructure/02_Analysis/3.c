#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int floorCeil(double x)
{
	x+=0.5;
	x=x*10;
	x=(int)x/10;
	return x;
}

int prefixAverages1(int X[], int n, int A[])
{
	int i, j;
	double sum;

	for(i=0;i<n;i++)
	{
		sum=0;
		for(j = 0; j<=i; j++)
		{
			sum+=X[j];
		}
		*(A+i)=floorCeil(sum/(double)(i+1));
	}
	return *A;
}

int prefixAverages2(int X[], int n, int A[])
{
	double total=0;
	int i, j;

	for(i=0;i<n;i++)
	{
		total+=X[i];
		*(A+i)=floorCeil(total/(double)(i+1));
	}
	return *A;
}

int main()
{
	int N,i,j;
	int *X;
	int *A1, *A2;
	scanf("%d",&N);
	X=(int*)malloc(sizeof(int)*N);
	A1=(int*)malloc(sizeof(int)*N);
	A2=(int*)malloc(sizeof(int)*N);

	for(i=0;i<N;i++) scanf("%d",&X[i]);
	*A1=prefixAverages1(X,N,A1);
	*A2=prefixAverages1(X,N,A2);

	for(i=0;i<N;i++)
	{
		printf("%d ",*(A1+i));
	}
	printf("\n");
	for(i=0;i<N;i++)
	{
		printf("%d ",*(A2+i));
	}

	return 0;
}
