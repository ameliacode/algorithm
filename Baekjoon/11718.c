#include<stdio.h>
#include<string.h>

int main() {

	int i;
	char str[101];
	while (fgets(str, 101, stdin))
	{
		printf("%s", str);
	}
	return 0;
}