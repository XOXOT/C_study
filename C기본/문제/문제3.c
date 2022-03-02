//문제 3 - 1
//두 개의 숫자를 입력 받아서 그 중 큰 수를 출력하는 프로그램을 작성하세요.
//단, if 관련 문장을 사용한다면 삼항연산자(조건연산자)를 사용하는 프로그램도 작성해보세요.

#include <stdio.h>
int main(void)
{
	int d = 0, e = 0;
	printf("두 개의 숫자를 입력하세요:");
	scanf_s("%d %d", &d, &e);//d,e에 두개의 정수를 입력
	if (d > e)//조건 d가 e보다 크면
	{
		printf("큰 수는 %d\n", d);//d를 출력
	}
	else//그렇지 않으면
	{
		printf("큰 수는 %d\n", e);//e를 출력
	}

getchar();
printf("                                 \n");

//문제 3 - 2
//세 개의 숫자를 입력 받아서 그 중 가장 큰 수를 출력하는 프로그램을 구현하세요.
//삼항연산자(조건연산자)를 사용해서 작성해보세요.


int a = 0, b = 0, c = 0;

printf("세 개의 정수:");
scanf_s("%d%d%d", &a, &b, &c);//a,b,c 에 세 개의 정수를 입력

if (a > b && a > c)
printf("큰 수는 : %d", a);
else if (b > a && b > c)
printf("큰 수는 : %d", b);
else
printf("큰 수는 : %d", c);

return 0;
}
