#include <stdio.h>

int main(void)
{
	char str[80] = "a";

	printf("기존 문자열: %s\n", str);
	printf("문자열 입력: ");
	scanf("%s", str);
	printf("입력 문자열: %s\n", str);

	return 0;
}