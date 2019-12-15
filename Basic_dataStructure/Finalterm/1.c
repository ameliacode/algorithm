#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int checkWord(char a[], int n) {
	int i, j;
	int flag = 1;

	for (i = 0, j = n - 1; i < n, j >= 0; i++, j--) {
		//printf("%d %d\n", i, j);
		//printf("%c %c\n", a[i], a[j]);
		if (a[i] != a[j]) {
			flag = 0;
			break;
		}
	}
	return flag;
}

int main() {
	
	int i;
	int len;
	char word[500];
	int judge;

	scanf("%d", &len);
	//word = (char*)malloc(sizeof(char)*len);

	scanf("%s", word);

	judge = checkWord(word, len);
	if (judge == 1) {
		printf("1\n");
	}
	else {
		for (i = 0; i < len; i++) {
			printf("%c", word[i]);
		}
		for (i = len - 1; i >= 0; i--) {
			printf("%c", word[i]);
		}
	}

	return 0;
}
