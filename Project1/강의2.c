#include <stdio.h>

int main(void)
{
	//�ݺ���

	//pritnf("11111111111"); //10���ݺ��ҷ���?
	//pritnf("11111111111");
	//pritnf("11111111111");
	//pritnf("11111111111");
	//pritnf("11111111111");
	//pritnf("11111111111");
	//pritnf("11111111111");
	//pritnf("11111111111");
	//pritnf("11111111111");
	//pritnf("11111111111"); //�밡��... ������

	//++ �Ի� (1�� ����) = ++ = a + 1
	//���� 1
	//int a = 10;
	//printf("a�� %d\n", a);
	//a++;
	//printf("a�� %d\n", a);
	//a++;
	//printf("a�� %d\n", a);

	//���� 2 
	//int b = 20;
	//printf("b�� %d\n", ++b); //++�� �����ϰ� ���� ������ ���� ���� �� ���忡�� �ٷ� 21�̵�
	//printf("b�� %d\n", b++); //������ ���� ������ ���� ���� �Ѿ �� ++�� �� ���� ���忡���� ����� �״�� �Ʊ� �Ѿ�� 21�� �� 
	//printf("b�� %d\n", b); // �Ѿ�� b++�� 1�� �������� 22�� ��

	//���� 3
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

	////�ݺ���
	//for, while, do while 

	//1. for��((����)����, ����, ����) { }
	//for (int i = 1; i <= 10; i++)
	//{
	//	printf("Hello World %d\n", i);
	//}

	//2. while��(����) { }
	//int i = 1;
	//while (i <= 10)
	//{
	//	printf("Hello World %d\n", i++);
	//	//i++ �ؿ��ٰ� �ص� ������ 
	//}

	//3. do { } while��(����) 
	//int i = 1;
	//do
	//{
	//	printf("Hello World %d\n", i++);
	//} while (i <= 10);

	////2�� �ݺ��� 

	//���� 1
	//for (int i = 1; i <= 3; i++)
	//{
	//	printf("ù ��° �ݺ��� : %d\n", i);

	//	for (int j = 1; j <= 5; j++)
	//	{
	//		printf("       �� ��° �ݺ��� : %d\n", j);
	//	}
	//}

	//����2

	//������
	//2 x 1 = 2
	//2 x 2 = 4
	//2 x 3 = 6
	//2 x 4 = 8
	//
	//9 x 9 = 81

	//for (int i = 2; i <= 9; i++)
	//{
	//	printf("\n");
	//	printf("%d�� ���\n", i);
	//	printf("\n");

	//	for (int j = 1; j <=9; j++)
	//	{
	//		printf("%d x %d = %d\n", i, j, i*j);
	//	}
	//}

	//�� �����

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

	//�Ƕ�̵带 �׾ƶ� - ������Ʈ
	int floor;
	printf("�� ������ �װڴ���?");
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