#include <stdio.h>
#include <string.h> /*문자열 관련 소스코드*/

int main(void)
{
	char fruit[20] = "strawberry";

	printf("딸기: %s\n", fruit);
	printf("딸기쨈: %s %s\n", fruit, "jam");
	printf("좋아하는 과일: %s\n", fruit);
	strcpy(fruit, "banana");
	printf("%s\n", fruit);

	return 0;
}