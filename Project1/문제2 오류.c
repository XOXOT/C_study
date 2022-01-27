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

#include<stdio.h>

#include <stdio.h>

int main(void) {
	int x; // 데이터 입력
	int count = 0; // while문 횟수
	int max, min; // 최댓값, 최솟값
	int sum = 0; // 평균을 구하기 위한 총합
	double average; // 평균

	while (1) { //무한반복

		printf("정수형 데이터 입력 : ");
		scanf("%d", &x);

		if (x < 0)
			break; // 음수 입력시 while문 벗어나기

		count++;

		if (count == 1) { // 처음으로 받은 x의 값을 max와 min 초기화
			max = x;
			min = x;
		}

		if (x > max)
			max = x;

		if (x < min)
			min = x;

		sum += x;
	}

	average = sum / count;

	printf("최대값 = %d\n", max);
	printf("최소값 = %d\n", min);
	printf("전체합 : %d\n", sum);
	printf("평 균 : %d\n", average);

	return 0;
}