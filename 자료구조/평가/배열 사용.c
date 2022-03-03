//Alphabet_sort.c
//created: 2022.03.03
//Author: ������

//�迭 ���

#include <stdio.h>
#include <string.h>
#define MAX_LENGTH 10

void insertionSort(char*, int); //��������
void printUL(char*, int); //������ �迭 ��ü �� ���

int main(void)
{
	char input_ary[MAX_LENGTH];
	char lower_ary[MAX_LENGTH];
	char upper_ary[MAX_LENGTH];

	int UPcount = 0; //�빮�� ī��Ʈ
	int LOWcount = 0; //�ҹ��� ī��Ʈ

	printf("============================================\n");
	printf("\t���ĺ� ��� ���α׷� �Դϴ�.\n\n");
	printf("  ���ĺ� 10���� �Է��ϸ� �ڵ� ��� �˴ϴ�.");
	printf("\n============================================\n");

	for (int i = 0; i < MAX_LENGTH; i++)
	{
		printf("\n���ĺ��� �ϳ��� �Է��ϼ��� ->");
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
	printf("��¿Ϸ�!\n");
	printf("\n�빮�� : ");
	printUL(upper_ary, UPcount);
	printf("\n�ҹ��� : ");
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
				charData = arr[j - 1]; // �� ��� �� ĭ �ڷ� �б�
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