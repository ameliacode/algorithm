#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int H[100] = { NULL };
int n = 1;

void rBuildHeap(int i);
void buildHeap();
void swapElements(int *A, int *B);
void downHeap(int currentPt);
void printHeap();

int main() {

	int N, i;

	scanf("%d", &N);
	n = N;
	for (i = 1; i <= N; i++) {
		scanf("%d", &H[i]);
	}

	//rBuildHeap(1);
	buildHeap();
	printHeap();

	return 0;
}

void swapElements(int *A, int *B) {
	int temp;
	//printf("swaping: %d %d\n", *A, *B);
	temp = *A;
	*A = *B;
	*B = temp;
}

void downHeap(int i) {
	int smaller;
	if (H[i] == NULL) return;
	if (H[2 * i] == NULL && H[2 * i + 1] == NULL) {
		return;
	}
	smaller = 2 * i;
	if (H[2 * i + 1] != NULL) {
		if (H[2 * i + 1] > H[smaller]) {
			smaller = 2 * i + 1;
		}
	}
	if (H[i] >= H[smaller]) return;
	swapElements(&H[i], &H[smaller]);
	downHeap(smaller);
}

void printHeap() {
	int i;
	for (i = 1; i <= n; i++) {
		printf(" %d", H[i]);
	}
	printf("\n");
}

void rBuildHeap(int i) {
	if (i > n) return;
	rBuildHeap(2 * i);
	rBuildHeap(2 * i + 1);
	downHeap(i);
	return;
}

void buildHeap() {
	int i;

	for (i = n / 2; i >= 1; i--) {
		downHeap(i);
	}
}//copyright github @ameliacode 2019
