//문제5.정수 n1과 n2를 입력 받는다.그리고 1부터 2까지의 합을 계산해서 그 결과를 출력하되,
//3의 배수이거나 5의 배수이면 총 합에서 제외시키는 프로그램을 작성하세요.
//
//
//문제 5 실행의 예
//
//두 개의 정수 입력 : 2 10
//3는 합에서 제외.
//5는 합에서 제외.
//6는 합에서 제외,
//9는 합에서 제외.
//10는 합에서 제외.
//
//2과 10을 포함하여 그 사이에 있는 정수들의 합 : 21

#include<stdio.h>

int main(void)
{
	int num1, num2, i;
	int sum1 = 0;

	printf("두 개의 정수 입력 : ");
	scanf("%d %d", &num1, &num2);

	if (num1 > num2)                 // num1이 크다면,
	{
		for (int i = num2; i <= num1; i++)   // num2부터 num1사이에 있는 수들의 합을 구함
		{
			if (i % 3 == 0 | i % 5 == 0)
				continue;
			sum1 += i;
		}
		
		for (int i = num2; i <= num1; i++)   // num2부터 num1사이에 있는 수
		{
			if (i % 3 == 0 | i % 5 == 0)
				printf("%d는 합에서 제외\n", i);
		}
		printf("                                 \n");
		printf("%d과 %d을 포함하여 그 사이에 있는 정수들의 합: %d\n", num1, num2, sum1);
	}
	else
	{
		for (int i = num1; i <= num2; i++)   // num1부터 num2사이에 있는 수들의 합을 구함
		{
			if (i % 3 == 0 | i % 5==0)
				continue;
			sum1 += i;
		}

		for (int i = num1; i <= num2; i++)   // num1부터 num2사이에 있는 수
		{
			if (i % 3 == 0 | i % 5 == 0)
				printf("%d는 합에서 제외\n", i);
		}
		printf("                                 \n");
		printf("%d과 %d을 포함하여 그 사이에 있는 정수들의 합: %d\n", num1, num2, sum1);
	}

	return 0;
}

