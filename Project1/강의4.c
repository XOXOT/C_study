#include <time.h> //��ǻ������ ������ ���ڸ� ������ �� ���� ���̺귯��
#include <stdlib.h> //��ǻ�� ȯ�濡 ���� ��� ������ Ȥ�� ���� ���� ���̺귯��
#include <stdio.h>

int main(void)
{
	////srand(time(NULL));; //���� �ʱ�ȭ ��� 
	////int num = rand() % 3; //0 ~2 ��(�� ����)�� �ϳ��� �̾ƶ� ���� 1���� �̱� ���Ѵٸ� 3+1�� �Է� 

	//printf("���� �ʱ�ȭ ����..\n");
	//for (int i = 0; i < 10; i++)
	//{
	//	printf("%d", rand() % 10);
	//}

	//srand(time(NULL));; //���� �ʱ�ȭ
	//printf("\n���� �ʱ�ȭ ��..\n");
	//for (int i = 0; i < 10; i++)
	//{
	//	printf("%d", rand() % 10);
	//}

	//���� ���� �� 

	////���� ���� ��
	//srand(time(NULL)); //���� �ʱ�ȭ
	//int i = rand() % 3; // 0 ~ 2 ��ȯ

	////�Ϲ� ���
	//if (i == 0)
	//{
	//	printf("����\n");
	//}
	//else if (i == 1)
	//{
	//	printf("����\n");
	//}
	//else if (i == 3)
	//{
	//	printf("��\n");
	//}
	//else
	//	printf("�����\n");

	////switch case �Լ� ��� break �ʼ��� �־���� default�� else�� ���� 
	//switch (i)
	//{
	//case 0: printf("����\n"); break;
	//case 1: printf("����\n"); break;
	//case 2: printf("��\n"); break;
	//default:printf("�����\n"); break;
	//}

	//switch case�� ����
	// 
	//�ʵ��л�(8~13) / ���л�(1~16) / ����л�(17~19)���� ������? ���� 3���� �ô� ���ø� ���� �� switch case 
	
	//int age = 25;
	//switch (age)
	//{
	//case 8:
	//case 9:
	//case 10:
	//case 11:
	//case 12:
	//case 13: printf("�ʵ��л� �Դϴ�\n"); break;
	//case 14:
	//case 15:
	//case 16: printf("���л� �Դϴ�\n"); break;
	//case 17:
	//case 18:
	//case 19: printf("����л� �Դϴ�\n"); break;
	//default: printf("�л��� �ƴѰ�����\n"); break;
	//}
	//���� 8~13 �̷��� ���� �ʵ��л��Դϴٸ� ����ϰ� �ʹٸ� ���� 8~12���� ����Ʈ���� ���� �ʾƵ� �ڵ����� �극��ũ ������ �����´� 

	//UP AND DOWN 
	srand(time(NULL));
	int num = rand() % 100 + 1; //1~100 ������ ����
	printf("����: %d\n",num);
	int answer = 0; //����
	int chance = 5; // ��ȸ�� �� 5��
	while (chance > 0) // while (1)�� �ص� ���� 1�� �� 0�� ���� 
	{
		printf("���� ��ȸ %d ��\n", chance--);
		printf("���ڸ� ����������(1~100) : ");
		scanf("%d", &answer);

		if (answer > num)
		{
			printf("DOWN �� \n\n");
		}
		else if (answer < num)
		{
			printf("UP �� \n\n");
		}
		else if(answer == num)
		{
			printf("�����Դϴ�. \n\n");
			break;
		}
		else
		{
			printf("�� �� ���� ������ �߻��߽��ϴ�. \n\n"); //Ȥ�� �� ���� ���
		}
		if (chance == 0)
		{
			printf("��� ��ȸ�� �� ����ϼ̳׿�. �ƽ��� �����߽��ϴ�. \n\n");
			break;
		}
	}

	return 0;
}
