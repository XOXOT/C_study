//문제 6 - 1. 입력 받은 정수 n 이하의 자연수 중에서 짝수의 합과, 홀수의 합을 각각 계산하여
//출력하는 프로그램을 구현하세요.참고로 자연수라 함은 0보다 큰 정수를 의미합니다.
//
//문제 6 - 1 실행의 예
//
//자연수 입력 : 12
//12 이하 홀수 합 : 36
//12 이하 짝수 합 : 42

#include<stdio.h>

int main(void)
{
	int i, num;
	int sumeven, sumodd;

	sumeven = 0;
	sumodd = 0;

	printf("자연수 입력: ");
	scanf("%d", &num);


	for (int i = 1; i <= num; i++)   // 
	{
		if (i % 2 == 0)
			continue;
		sumodd += i;
	}

	for (int i = 1; i <= num; i++)   // 
	{
		if (i % 2 == 1)
			continue;
		sumeven += i;
	}

	printf("%d이하 홀수 합: %d\n", num, sumodd);
	printf("%d이하 짝수 합: %d\n", num, sumeven);

	getchar();

//문제 6 - 2. 정수 n을 입력 받습니다(단 n은 2 이상이 입력되어야 합니다).
//그리고 1부터 시작해서 다음과 같은 형태로 점진적인 덧셈을 진행합니다.
//1 + 2 + 3 + 4 + 5 + 6 + .......
//이 때 얼마를 더하는 순간부터 덧셈의 결과가 n보다 커지기 시작하는지,
//그리고 n보다커지기 전과 n보다 커진 후의 덧셈 결과를 출력하는 프로그램을 구현하세요.
//
//문제 6 - 2 실행의 예
//
//2 이상 입력 : 20
//6를 더할 때 처음 20를 넘기 시작한다.
//20를 넘기 이전의 합 : 15
//20를 넘은 이후의 합 : 21
	

	
	return 0;
}