#include<stdio.h>
#include<string.h>

int search(char *ptr, char find, int total)
{
	if (*ptr == NULL)
		return total;
	else {
		if (*(ptr) == find) ++total;
		++ptr;
		//printf("%c %d\n", *ptr,total);
		search(ptr, find, total);
	}
}

int main()
{
	char input[101];
	char find;
	char *ptr;

	scanf("%s", input);
	getchar();
	scanf("%c", &find);

	ptr = input;
	printf("%d", search(ptr, find, 0));

	return 0;
}
