#include <stdio.h>

//5개의 정수를 입력받아 최대 값 찾기
int main(void)
{
	int i=1, num = 0, sum = 0;
	int max;
	int age = 0;
	char name[10] = {NULL};
	char ch;

	//printf("5개의 정수를 입력하세요\n");

	//max = num;

	//for (i = 0; i < 5; i++)
	//{
	//	printf("%d번째 정수 입력->", i + 1);
	//	scanf("%d", &num);

	//	if (max < num)
	//	{
	//		max = num;
	//	}
	//}
	//printf("최대 값은 %d 입니다.",max);

	//printf("나이를 입력하세요\n");
	//scanf("%d", &age);

	////엔터값도 scanf에서 받기 때문에 문자열 반환이 안됨 따라서 getchar() 필요(스트림에 남아있는 개행을 삭제)
	//getchar();

	//printf("이름을 입력하세요\n");
	//scanf("%c", &ch);

	//printf("이름:%c\n나이:%d\n", ch, age);

	printf("1부터 정수까지 합을 구하는 프로그램\n\n");
	printf("정수를 입력하세요->");
	scanf("%d", &num);

	//while (i <= num)
	//{
	//	sum += i;
	//	i++;
	//}

	for (i = 1; i <= num; i++)
	{
		sum += i;
	}

	printf("1부터 %d까지의 합은 %d 입니다.\n", num, sum);

	return 0;
}
