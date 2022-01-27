#include <stdio.h>

int main(void)
{
	//반복문

	//pritnf("11111111111"); //10번반복할려면?
	//pritnf("11111111111");
	//pritnf("11111111111");
	//pritnf("11111111111");
	//pritnf("11111111111");
	//pritnf("11111111111");
	//pritnf("11111111111");
	//pritnf("11111111111");
	//pritnf("11111111111");
	//pritnf("11111111111"); //노가다... 귀찮음

	//++ 뿔뿔 (1씩 증가) = ++ = a + 1
	//예제 1
	//int a = 10;
	//printf("a는 %d\n", a);
	//a++;
	//printf("a는 %d\n", a);
	//a++;
	//printf("a는 %d\n", a);

	//예제 2 
	//int b = 20;
	//printf("b는 %d\n", ++b); //++을 먼저하고 나서 문장을 끝냄 따라서 이 문장에서 바로 21이됨
	//printf("b는 %d\n", b++); //문장을 먼저 끝내고 다음 문장 넘어갈 때 ++을 함 여기 문장에서는 출력이 그대로 아까 넘어온 21이 됨 
	//printf("b는 %d\n", b); // 넘어온 b++이 1이 더해져서 22가 됨

	//예제 3
	//int i = 1;
	//printf("Hello World %d\n", i++); //1
	//printf("Hello World %d\n", i++); //2
	//printf("Hello World %d\n", i++); //3
	//printf("Hello World %d\n", i++); //4
	//printf("Hello World %d\n", i++); //5
	//printf("Hello World %d\n", i++); //6
	//printf("Hello World %d\n", i++); //7
	//printf("Hello World %d\n", i++); //8
	//printf("Hello World %d\n", i++); //9
	//printf("Hello World %d\n", i++); //10

	////반복문
	//for, while, do while 

	//1. for문((변수)선언, 조건, 증감) { }
	//for (int i = 1; i <= 10; i++)
	//{
	//	printf("Hello World %d\n", i);
	//}

	//2. while문(조건) { }
	//int i = 1;
	//while (i <= 10)
	//{
	//	printf("Hello World %d\n", i++);
	//	//i++ 밑에다가 해도 무방함 
	//}

	//3. do { } while문(조건) 
	//int i = 1;
	//do
	//{
	//	printf("Hello World %d\n", i++);
	//} while (i <= 10);

	////2중 반복문 

	//예제 1
	//for (int i = 1; i <= 3; i++)
	//{
	//	printf("첫 번째 반복문 : %d\n", i);

	//	for (int j = 1; j <= 5; j++)
	//	{
	//		printf("       두 번째 반복문 : %d\n", j);
	//	}
	//}

	//예제2

	//구구단
	//2 x 1 = 2
	//2 x 2 = 4
	//2 x 3 = 6
	//2 x 4 = 8
	//
	//9 x 9 = 81

	//for (int i = 2; i <= 9; i++)
	//{
	//	printf("\n");
	//	printf("%d단 계산\n", i);
	//	printf("\n");

	//	for (int j = 1; j <=9; j++)
	//	{
	//		printf("%d x %d = %d\n", i, j, i*j);
	//	}
	//}

	//별 만들기

	//*
	//**
	//***
	//****
	//*****

	//for (int i = 0; i < 5; i++)
	//{
	//	for (int j = 0; j <= i; j++)
	//	{
	//		printf("*");
	//	}
	//	printf("\n");
	//}

	//    *
	//   **
	//  ***
	// ****
	//*****

	//for (int i = 0; i < 5; i++)
	//{
	//	for (int j = i; j < 5-1; j++)
	//	{
	//		printf("s");
	//	}
	//	for (int k = 0; k <= i; k++)
	//	{
	//		printf("*");
	//	}
	//	printf("\n");
	//}	

	//피라미드를 쌓아라 - 프로젝트
	int floor;
	printf("몇 층으로 쌓겠느냐?");
	scanf("%d", &floor);
	
	//ssss*ssss
	//   ***sss
	//  *****ss
	// *******s
	//*********

	for (int i = 0; i < floor; i++)
	{
		for (int j = i; j < floor - 1; j++)
		{
			printf("s");
		}
		for (int k = 0; k < i*2+1; k++)
		{
			printf("*");
		}
		printf("\n");
	}



	return 0;
}