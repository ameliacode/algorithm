#include<stdio.h>
#include<string.h>
#include<stdlib.h>

void insertItem(int key, int *A, int last);
void upHeap(int *A, int last);
void swapElements(int *A, int *B);
void removeMax(int *A, int last);
void downHeap(int *A, int last, int currentPt);
void printHeap(int *A, int last);

int main() {

	char oper;
	int key, last;
	int A[101] = { NULL };
	last = 1;

	while (1) {
		scanf("%c", &oper);
		getchar();
		if (oper == 'i') {
			scanf("%d", &key);
			getchar();
			insertItem(key, A, last);
			printf("0\n");
			last++;
		}
		else if (oper == 'd') {
			//printf("deleting\n");
			last--;
			removeMax(A, last);
		}
		else if (oper == 'p') {
			printHeap(A, last);
		}
		else if (oper == 'q') break;
	}

	return 0;
}

void insertItem(int key, int *A, int last) {
	int i;
	*(A + last) = key;
	//expandExternal(A, last);
	upHeap(A, last);
	return;
}

void upHeap(int *A, int last) {
	int i;
	if (last == 1) return;
	if (*(A + last) <= *(A + (last / 2))) {
		//printf("%d %d ", last, last / 2);
		//printf("%d %d\n",*(A+last), *(A+last/2));
		return;
	}
	else {
		swapElements(A + last, A + (last / 2));
		upHeap(A, last / 2);
	}
}

void swapElements(int *A, int *B) {
	int temp;
	//printf("swaping: %d %d\n", *A, *B);
	temp = *A;
	*A = *B;
	*B = temp;
}

void removeMax(int *A, int last) {
	int currentPt = 1;

	printf("%d\n", *(A + 1));
	*(A + 1) = *(A + last);
	*(A + last) = NULL;
	//last--;
	//printHeap(A, last);
	downHeap(A, last, currentPt);
	return;
}
void downHeap(int *A, int last, int currentPt) {
	if (*(A + currentPt) == NULL) return;
	if (*(A + currentPt * 2) == NULL && *(A + currentPt * 2 + 1) == NULL) {
		return;
	}
	else if (*(A + currentPt * 2) == NULL || *(A + currentPt * 2 + 1) == NULL) {
		if (*(A + currentPt * 2) == NULL) {
			if (*(A + currentPt) < *(A + currentPt * 2 + 1)) {
				swapElements((A + currentPt * 2 + 1), (A + currentPt));
			}
		}
		else {
			if (*(A + currentPt) < *(A + currentPt * 2)) {
				swapElements((A + currentPt * 2), (A + currentPt));
			}
		}
	}
	else {
		if (*(A + currentPt * 2) >= *(A + currentPt * 2 + 1)) {
			swapElements((A + currentPt * 2), (A + currentPt));
			downHeap(A, last, currentPt * 2);
		}
		else if (*(A + currentPt * 2) < *(A + currentPt * 2 + 1)) {
			swapElements((A + currentPt * 2 + 1), (A + currentPt));

			downHeap(A, last, currentPt * 2 + 1);
		}
	}

	return;
}

void printHeap(int *A, int last) {
	int i;
	for (i = 1; i < last; i++) {
		printf(" %d", A[i]);
	}
	printf("\n");
}//copyright github @ameliacode 2019
