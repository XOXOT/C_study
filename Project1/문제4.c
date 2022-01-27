//문제 4 - 1 정수 n을 입력 받습니다.
//그리고 1부터 입력 받은 정수 n까지의 합을 계산해서 그 결과를 출력하는 프로그램을 작성하세요.
//예를 들어서 정수 5를 입력 받으면, 1 + 2 + 3 + 4 + 5 의 연산 결과인 15를 출력해야 합니다.
//
//
//문제 4 - 1 실행 예
//1 이상의 정수 입력 : -10
//1 이상의 정수를 입력해야 합니다.
//1 이상의 정수 입력 : 10
//1부터 10까지의 합은 55.

#include<stdio.h>

int main(void) 
{
	int num, i;
	int sum = 0;
	while (1) //무한반복
	{
		printf("1 이상의 정수 입력 : ");
		scanf("%d", &num);

		if (num < 1)
		{
			printf("1 이상의 정수를 입력해야 합니다.\n");
		}
		else
			break;
	}
	for (i = 1; i <= num; i++) 
		sum += i;

	printf("1부터 %d까지의 합은 %d\n", num, sum);

//문제 4 - 2 정수 n1과 n2를 입력 받습니다.
//그리고 n1부터 n2까지의 합을 계산해서 그 결과를 출력하는 프로그램을 작성하세요.
//예를 들어 2와 5가 입력되면  2 + 3 + 4 + 5 의 연산 결과를 출력해야 합니다.
//
//문제 4 - 2 실행 예
//두 개의 정수 입력 : 12 7
//12과 7을 포함하여 그 사이에 있는 정수들의 합 : 57

getchar();
printf("                                 \n");
printf("n1부터 n2까지의 합 계산 프로그램\n");

	int num1, num2;
	int sum1 = 0;

	printf("두 개의 정수 입력 : ");
	scanf("%d %d", &num1, &num2);

	if (num1 > num2)                        // num1이 크다면,
		for (int i = num2; i <= num1; i++)   // num2부터 num1사이에 있는 수들의 합을 구한다.
			sum1 += i;
	else
		for (int i = num1; i <= num2; i++)   // num1부터 num2사이에 있는 수들의 합을 구한다.
			sum1 += i;

	printf("%d과 %d을 포함하여 그 사이에 있는 정수들의 합: %d\n",num1,num2, sum1);

	return 0;
}