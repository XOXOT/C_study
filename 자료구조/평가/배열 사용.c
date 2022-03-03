//Alphabet_sort.c
//created: 2022.03.03
//Author: 최희태

//배열 사용

#include <stdio.h>
#include <string.h>
#define MAX_LENGTH 10

void insertionSort(char*, int); //삽입정렬
void printUL(char*, int); //포인터 배열 전체 값 출력

int main(void)
{
	char input_ary[MAX_LENGTH];
	char lower_ary[MAX_LENGTH];
	char upper_ary[MAX_LENGTH];

	int UPcount = 0; //대문자 카운트
	int LOWcount = 0; //소문자 카운트

	printf("============================================\n");
	printf("\t알파벳 출력 프로그램 입니다.\n\n");
	printf("  알파벳 10개를 입력하면 자동 출력 됩니다.");
	printf("\n============================================\n");

	for (int i = 0; i < MAX_LENGTH; i++)
	{
		printf("\n알파벳을 하나씩 입력하세요 ->");
		scanf(" %c", &input_ary[i]);
	}

	for (int i = 0; i < MAX_LENGTH; i++)
	{
		if (input_ary[i] >= 'A' && input_ary[i] <= 'Z')
		{
			upper_ary[UPcount] = input_ary[i];
			UPcount++;
		}
		else if (input_ary[i] >= 'a' && input_ary[i] <= 'z')
		{
			lower_ary[LOWcount] = input_ary[i];
			LOWcount++;
		}
	}

	insertionSort(upper_ary, UPcount);
	insertionSort(lower_ary, LOWcount);
	printf("\n\n============================================\n");
	printf("출력완료!\n");
	printf("\n대문자 : ");
	printUL(upper_ary, UPcount);
	printf("\n소문자 : ");
	printUL(lower_ary, LOWcount);
	printf("\n============================================\n");

	return 0;
}

void insertionSort(char* arr, int count)
{
	char charData;
	for (int i = 1; i < count; i++)
	{
		for (int j = i; j > 0; j--)
		{
			if (arr[j - 1] > arr[j])
			{
				charData = arr[j - 1]; // 비교 대상 한 칸 뒤로 밀기
				arr[j - 1] = arr[j];
				arr[j] = charData;
			}
		}
	}
}

void printUL(char* arr, int count)
{
	for (int i = 0; i < count; i++)
	{
		printf("%c ", arr[i]);
	}
}