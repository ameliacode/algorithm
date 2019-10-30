#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>

int N;

void swapElements(int *A, int *B);
int find_pivot_index(int *L, int l, int r);
int inPlacePartition(int *L, int l, int r, int k);
void inPlaceQuickSort(int *L, int l, int r);
void printArray(int *L);

int main() {

	int i, j;
	int *L;

	scanf("%d", &N);

	L = (int*)malloc(sizeof(int)*N);

	for (i = 0; i < N; i++) {
		scanf("%d",&L[i]);
	}
	
	inPlaceQuickSort(L, 0, N - 1);
	printArray(L);

	return 0;
}

void swapElements(int *A, int *B) {
	int temp = *A;
	*A = *B;
	*B = temp;
}

int find_pivot_index(int *L, int l, int r) {

	int median;

	/*int i, j;
	int random_index[3];
	int random[3];
	
	srand(time(NULL));
	for (i = 0; i < 3; i++) {

		random_index[i] = l + rand() % (r - l);
		random[i] = *(L + random_index[i]);
	}

	for (i = 0; i < 3; i++) {
		for (j = i; j < 3; j++) {
			if (random[i] > random[j]) {
				swapElements(&random[i], &random[j]);
				swapElements(&random_index[i], &random_index[j]);
			}
		}
	}
	median = random_index[1];*/

	//굳이 pivot을 따로 설정할 필요는 없다..(l,r 사이에서 아무 숫자나 고르면 되기 때문..) -> 최악인 경우 O(n^2)의 경우도 발생할 수도
	median = l;
	return median;
}

int inPlacePartition(int *L, int l, int r, int k) {

	int i, j;
	int p = *(L + k);
	swapElements(&L[k], &L[r]);
	//printArray(L);
	i = l;
	j = r - 1;
	while (i <= j) {
		while (i <= j && *(L + i) <= p) {
			i++;
		}
		while (j >= i && *(L + j) >= p) {
			j--;
		}
		if (i < j) {
			swapElements(&L[i], &L[j]);
			//printArray(L);
		}
	}
	swapElements(&L[i], &L[r]);
	//printArray(L);
	return i;
}

void inPlaceQuickSort(int *L, int l, int r) {

	int k, a, b;

	if (l >= r) return;
	k = find_pivot_index(L, l, r);
	a = inPlacePartition(L, l, r, k);
	b = inPlacePartition(L, l, r, k);
	inPlaceQuickSort(L, l, a - 1);
	inPlaceQuickSort(L, b + 1, r);
}

void printArray(int *L) {

	int i;

	for (i = 0; i < N; i++) {
		printf(" %d", *(L + i));
	}
	printf("\n");
}
