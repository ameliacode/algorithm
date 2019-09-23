#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int H[100] = { NULL };
int n;

void inPlaceHeapSort();
void printArray();
void downHeap(int i,int last);
void upHeap(int i);
void buildHeap();
void swapElements(int *A, int *B);

int main() {

	int N, i;
	scanf("%d", &N);
	n = N;

	for (i = 1; i <= N; i++) {
		scanf("%d", &H[i]);
	}

	inPlaceHeapSort();
	printArray();

	return 0;
}

void inPlaceHeapSort() {
	int i;
	int last = n;

	buildHeap();
	for (i = n; i >= 2; i--) {
		swapElements(&H[1], &H[i]);
		downHeap(1,i-1);
	}
	return;
}

void printArray() {
	int i;

	for (i = 1; i <= n; i++) {
		printf("%d ", H[i]);
	}
	printf("\n");
}

void swapElements(int *A, int *B) {
	int temp;
	temp = *A;
	*A = *B;
	*B = temp;
}

void upHeap(int i) {
	if (i == 1) return;
	if (H[i] >= H[i / 2]) return;
	else {
		swapElements(&H[i], &H[i / 2]);
		upHeap(i / 2);
	}
}

void downHeap(int i, int last) {
	int left = 2 * i;
	int right = 2 * i + 1;
	int greater;

	if (left > last) return;
	greater = left;
	if (right <= last) {
		if (H[right] > H[greater]) {
			greater = right;
		}
	}
	if (H[i] >= H[greater]) return;
	swapElements(&H[i], &H[greater]);
	downHeap(greater, last);
}


void buildHeap() {
	int i;

	for (i = n / 2; i >= 1; i--) {
		downHeap(i,n);
	}
}
