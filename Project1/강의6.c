#include <stdio.h>
#include<time.h>

int main(void)
{
	////�迭
	//int subway_1 = 30; // ����ö 1ȣ���� 30���� Ÿ�� �ִ�. 
	//int subway_2 = 40;
	//int subway_3 = 50;
	////���� ����ö ȣ���� 100ȣ��(ĭ)���� �ִٸ� �ϳ��ϳ� �ϱ� ��ƴ� ���� �迭�� �̿��Ѵ�. (�迭�� �����ؼ� ���� �� �ִ� �ڷ���)
	//printf("����ö 1ȣ���� %d ���� Ÿ�� �ֽ��ϴ�\n", subway_1);
	//printf("����ö 2ȣ���� %d ���� Ÿ�� �ֽ��ϴ�\n", subway_2);
	//printf("����ö 3ȣ���� %d ���� Ÿ�� �ֽ��ϴ�\n", subway_3);

	////���� ���� 3���� �ؿ�ó�� �� �ٷ� ǥ�� (���� ���� ������ �Բ�, ���ÿ� ����
	//int subway_array[3]; //[0],[1],[2]
	//subway_array[0] = 30;
	//subway_array[1] = 40;
	//subway_array[2] = 50;

	//for (int i = 0; i < 3; i++)
	//{
	//	printf("����ö %dȣ���� %d ���� Ÿ�� �ֽ��ϴ�\n", i+1, subway_array[i]);
	//}

	// �� ���� ��� 
	/*int arr[10] = {1,2,3,4,5,6,7,8,9,10}; //�ʱ�ȭ�� ���ϸ� ���̰��� ����
	for (int i = 0; i < 10; i++)
	{
		printf("%d\n", arr[i]);
	}*/

	//�迭ũ��� �׻� ����� ����
	/*int size = 10;
	int arr[10];*/

	//int arr[10] = { 1,2 }; //3��° �����ʹ� �ڵ����� 0���� �ʱ�ȭ ��
	//for (int i = 0; i < 10; i++)
	//{
		//printf("%d\n", arr[i]);
	//}

	//int arr[] = { 1, 2 }; // arr[2]�� ������ �Է°�

	//float arr_f[5] = { 1.0f, 2.0f,3.0f }; //float���� �ڵ����� 0���� �ʱ�ȭ �� 
	//for (int i = 0; i < 5; i++)
	//{
		//printf("%.2f\n", arr_f[i]);
	//}

	//���� vs ���ڿ�
	//char c = 'A';
	//printf("%c\n", c);

	//���ڿ� ������ '��'�� �ǹ��ϴ� NULL ���� \0 �� ���ԵǾ�� �� 
	//char str[6] = "coding"; //[c] [o] [d] [i] [n] [g]
	//char str[7] = "coding";
	//printf("%s\n", str);

	//char str[] = "coding";
	//printf("%s\n", str);
	//printf("%d\n", sizeof(str));

	//for (int i = 0; i < sizeof(str); i++)
	//{
		//printf("%c\n", str[i]);
	//}

	//char kor[] = "�����ڵ�";
	//printf("%s\n", kor);
	//printf("%d\n", sizeof(kor));
	//���� 1���� : 1byte
	//�ѱ� 1���� : 2byte
	//�� ��
	//En gl ish
	//char ũ��: 1byte 

	//char c_array[7] = { 'c','o','d','i','n','g','\0'};
	//char c_array[6] = { 'c','o','d','i','n','g'}; //���� ���������� �˼����� ���ڰ� ����
	//printf("%s\n", c_array);

	//char c_array[10] = { 'c','o','d','i','n','g'};
	//printf("%s\n", c_array);
	//for (int i = 0; i < sizeof(c_array); i++)
	//{
		//printf("%c\n", c_array[i]);
	//}

	//for (int i = 0; i < sizeof(c_array); i++)
	//{
		//printf("%d\n", c_array[i]); //������ ��Ÿ���� �ƽ�Ű�ڵ� ���� ���� 
	//}
	
	//���ڿ� �Է¹ޱ�: ������ ���� ���� ����  
	//char name[256];
	//printf("����� �̸���?");
	//scanf("%s", name, sizeof(name));
	//printf("%s\n", name);

	//���� ASCII�ڵ�? ANSI (�̱�ǥ����ȸ)���� ������ ǥ�� �ڵ� ü��
	//7bit, �� 126 �� �ڵ�(0~127)
	//a 97 (���� a�� �ƽ�Ű�ڵ� ������)
	//A 65
	//0 48
	//printf("%c\n", 'a');
	//printf("%d\n", 'a');

	//printf("%c\n", '\0');
	//printf("%d\n", '\0'); // ���� �ƽ�Ű �ڵ尪 0 

	//printf("%c\n", '0');
	//printf("%d\n", '0');

	//����2 0~127������ �ƽ�Ű�ڵ� �������� �ش��ϴ� ���� Ȯ�� 
	//for (int i = 0; i <128; i++)
	//{
	//	printf("�ƽ�Ű�ڵ� ���� %d : %c\n ", i, i);
	//}
	

	//�ƺ��� ��Ӹ� ����

	srand(time(NULL));
	printf("\n\n === �ƺ��� ��Ӹ� ���� ===\n\n");
	int answer; // ����� �Է°�
	int treatment = rand() % 4; //�߸��� ����(0~3)

	int cntShowBottle = 0; //�̹� ���ӿ� ������ �� ���� 
	int prevCntShowBottle = 0; //�� ���ӿ� ������ �� ����
	// ���� �����ִ� �� ������ �ٸ��� �Ͽ� ����� ��� (ó���� 2�� -> ������ 3��...)

	//3���� ��ȸ (3���� �߸��� ���� �õ�)
	for (int i = 0; i <= 3; i++)
	{
		int bottle[4] = { 0,0,0,0 }; //4���� ��
		do {
			cntShowBottle = rand() % 2 + 2; //������ �� ���� (0~1, +2 -> 2, 3) 2������ 3���� ������
		} while (cntShowBottle == prevCntShowBottle); // �̹��� ������ �� ������ �տ��� ������ �� ������ ������ �ݺ�
		prevCntShowBottle = cntShowBottle; //pre�� 0���� �����Ǿ��־� �񱳰� 0�̶� �ǰ� �־� ������ ���� ����

		int islncluded = 0; //������ �� �߿� �߸����� ���ԵǾ����� ���� (1�̸� ����)
		printf("> %d ��° �õ� : ", i);

		//������ �� ������ ����
		for (int j = 0; j < cntShowBottle; j++)
		{
			int randBottle = rand() % 4; // 0~3

			//���� ���õ��� ���� ���̸�, ���� ó��
			if (bottle[randBottle]==0)
			{
				bottle[randBottle] = 1;
				if (randBottle == treatment)
				{
					islncluded = 1;
				}
			}
			//�̹� ���õ� ���̸�, �ߺ��̹Ƿ� �ٽ� ����
			else
			{
				j--; //���� ������ �ٷ� ��������
			}
		}
		//����ڿ��� ���� ǥ��
		for (int k = 0; k < 4; k++)
		{
			if (bottle[k] == 1)
			{
				printf("%d", k + 1); //k�� 0���� �����ϱ� ������ +1 ����鿡�� ǥ�õǴ°� 1��°�� ���Ƽ�
			}
		}
		printf("������ �Ӹ��� �ٸ��ϴ�\n\n");

		if (islncluded ==1)
		{
			printf(">>����! �Ӹ��� ����� !!\n");
		}
		else
		{
			printf(">>����! �Ӹ��� ���� �ʾҾ��... !!\n");
		}

		printf("\n... ��� �Ϸ��� �ƹ�Ű�� ��������...");
		getchar(); // ����ڰ� Ű�� �Է��Ҷ����� ���
	}

	printf("\n\n�߸����� �� ���ϱ��?");
	scanf("%d", &answer);

	if (answer == treatment + 1)
	{
		printf("\n >> �����Դϴ�");
	}
	else
	{
		printf("\n >> ��! Ʋ�Ƚ��ϴ�. ������ %d �Դϴ�\n", treatment + 1);
	}


	return 0;
}