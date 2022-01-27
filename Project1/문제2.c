//7개의 숫자를 정수 형태로(반드시 정수 형태로 입력 받는다) 입력 받아서
//입력 받은 수들의 최대값, 최소값, 전체 합, 그리고 평균을 구하는 프로그램을 작성하세요.
//단 평균은 정확히 계산하여 소수점 이하까지 출력합니다.
//
//문제 2 실행의 예
//
//정수형 데이터 입력 : 3
//정수형 데이터 입력 : 4
//정수형 데이터 입력 : 2
//정수형 데이터 입력 : 3
//정수형 데이터 입력 : 5
//정수형 데이터 입력 : 7
//정수형 데이터 입력 : -12
//
//최대값 : 7
//	최소값 : -12
//	전체합 : 12
//	평 균 : 1.714286

#include <stdio.h>

int main(void)
{
	int arr[7];
	int max, min;
	int i, sum = 0;

	for (i = 0; i < 7; i++)
	{
		printf("정수형 데이터 입력 : ");
		scanf("%d", &arr[i]);
	}

	max = arr[0]; 
	min = arr[0];
	sum = arr[0];

	for (i = 1; i < 7; i++)
	{
		if (arr[i] > max)
		{
			max = arr[i];
		}
		if (arr[i] < min)
		{
			min = arr[i];
		}

		sum += arr[i];
	}

	printf("                           \n");
	printf("입력한 정수의 최댓값 : %d \n", max);
	printf("입력한 정수의 최솟값 : %d \n", min);
	printf("입력한 정수의 합 : %d \n", sum);
	printf("입력한 정수의 평균 : %f \n", (float)sum / i);

	return 0;
}