#include <stdio.h>
#include <stdio.h> 
#include <string.h>
#include <stdlib.h>

//- ������ �л� ��
//10��
//
//- ������ �л��� ������
//�̸�(����), 4 ����(����, ����, ����, ����)�� ���� ����(����)
//
//- ���
//�л� ��� �� ����,
//���� ��� �� ����,
//�л� �̸����� ���� ��ȸ �� ���,
//��ü �л��� ���������� ���,
//���� ��½� �������� �̸�, �����, ����, ���, ���� �� ���� ����� ��,
//�л� �� ���� ����� ����� �ǵ��� �� ��.
//
//- ������ ������ ��.
//���� �� ���������� �����ؼ� ������ ��.
//�̴�������Ʈ �ÿ� �������� ������ ��.


void inputFunc();
void scorestu(void);
void scoresort(void);
void scoreedit(void);
void studel(void);
void pexit();


char name[10][7];
int score[10][5];   // [4]: ����
//int len, n, m, howmany, tot, total = 0;
int n, m, howmany, total = 0;

void main()
{
	int selMenu;

	while (1)
	{
		printf("##############################\n");
		printf("       �������� ���α׷�      \n");
		printf("##############################\n");
		printf("                              \n");
		printf("  1. �л� �̸� �� ���� �Է�   \n");
		printf("      2. �л� ���� ���       \n");
		printf("      3. �л� ���� ����       \n");
		printf("      4. �л� ���� ����       \n");
		printf("      5. �л� ���� ����       \n");
		printf("         0. ��   ��           \n");
		printf("                              \n");
		printf("##############################\n");

		printf("�����ϼ��� > ");
		scanf("%d", &selMenu);

		switch (selMenu)
		{
		case 1:		// 1.�л� �̸� �� ���� �Է�
			inputFunc();
			break;
		case 2:		// 2.�л� ���� ���
			scorestu();
			break;
		case 3:		// 3.�л� ���� ���� 			
			scoreedit();
			break;
		case 4:
			scoresort(); //4. ���� ���� (���� ����)
			break;
		case 5:		
			studel(); //5. �л� ���� ����
			break;
		case 0:		
			pexit(); // 0.����
			break;
		default:
			break;
		}
	}
}
void inputFunc()
{
	printf("�� ���� ������ ó���ϵ��� �����Ͻðڽ��ϱ�(�ִ� 10��) : ");
	scanf("%d", &howmany);
	if (howmany > 10)
	{
		printf("10�� �̻��� %d���� �Է��ϼ̽��ϴ�. ó���� �Ұ����մϴ�.\n", howmany);
		return 0;
	}
	for (n = 0; n < howmany; n++)
	{
		printf("�л��� �̸� �Է� : ");
		scanf("%s", name[n]);

		printf("%s�� ���� ���� > ", name[n]);
		scanf("%d", &score[n][0]);
		printf("%s�� ���� ���� > ", name[n]);
		scanf("%d", &score[n][1]);
		printf("%s�� ���� ���� > ", name[n]);
		scanf("%d", &score[n][2]);
		printf("%s�� ���� ���� > ", name[n]);
		scanf("%d", &score[n][3]);
	}
}

void scorestu()
{
	char temp[7];

	printf("��� �л��� ������ ��� �Ͻðڽ��ϱ�? >\n");
	scanf("%s", temp);

	printf("\n------------------------------------------\n");
	printf("\n����\t�̸�\t����\t����\t����\t����\t����\t���\n");

	for (n = 0; n < howmany; n++)   ////// ����
	{
		if (strcmp(temp, name[n]) == 0)
		{
			score[n][4] = score[n][0] + score[n][1] + score[n][2] + score[n][3];   ///   ���� 
			total += score[n][4];
			printf("%d\t%s\t%d\t%d\t%d\t%d\t%d\t%5.2f\n", n + 1, name[n], score[n][0], score[n][1], score[n][2], score[n][3], score[n][4], score[n][4] / 4.0);
		}
	}
	printf("\n\n");

	return 0;
}

void scoresort(void)
{
	printf("\n-----------------------------------------------------");
	printf("\n����\t�̸�\t����\t����\t����\t����\t����\t���\n");

	// ���� �� ����: ���� ����
	int k, m, temp;
	char tname[7];

	for (n = 0; n < howmany - 1; n++)
	{
		for (k = 0; k < howmany - 1; k++)
		{
			if (score[k][4] < score[k + 1][4]) // Descending sort(�������� ����)
			{
				strcpy(tname, name[k]);
				strcpy(name[k], name[k + 1]);
				strcpy(name[k + 1], tname);

				for (m = 0; m < 5; m++)
				{
					temp = score[k][m];
					score[k][m] = score[k + 1][m];
					score[k + 1][m] = temp;
				}
			}
		}
	}

	// ���
	for (n = 0; n < howmany; n++)
	{
		score[n][4] = score[n][0] + score[n][1] + score[n][2] + score[n][3];    
		total += score[n][4];
		printf("%d\t%s\t%d\t%d\t%d\t%d\t%d\t%5.2f\n", n + 1, name[n], score[n][0], score[n][1], score[n][2], score[n][3], score[n][4], score[n][4] / 4.0);
	}

	return 0;
}

void scoreedit(void)
{
	char temp[7];
	int i, j;

	printf("���� ������ �л� �̸� �Է�:");
	scanf("%s", temp);

	for (n = 0; n < howmany; n++)   ////// ����
	{
		if (strcmp(temp, name[n]) == 0)
		{
			printf("%s�� ���� ���� > ", name[n]);
			scanf("%d", &score[n][0]);
			printf("%s�� ���� ���� > ", name[n]);
			scanf("%d", &score[n][1]);
			printf("%s�� ���� ���� > ", name[n]);
			scanf("%d", &score[n][2]);
			printf("%s�� ���� ���� > ", name[n]);
			scanf("%d", &score[n][3]);
		}
	}
	printf("������ �Ϸ�Ǿ����ϴ�.\n");
	printf("\n\n");
	
	return 0;
}

void studel(void)
{
	char temp[7];
	int i, j;

	printf("���� �� �л� �̸� �Է�:");
	scanf("%s", &temp);

	for (i = 0; i < howmany; i++)
	{
		if (strcmp(temp, name[i]) == 0)
		{
			for (j = i + 1; j < howmany; j++)
			{
				name[i][j] = "del";
			}
		}
	}
	howmany--;

	printf("������ �Ϸ�Ǿ����ϴ�.\n");
	printf("\n\n");
}



void pexit()
{
	int n;
	printf("0�� �ѹ� �� ������ ���� �˴ϴ�.\n");
	scanf("%d", &n);
	if (n == 0)
	{
		printf("�������� ���α׷��� �����մϴ�.");
		exit(0);
	}
	else
	{
		printf("�� �� ���� ���� �߻�.");
	}
}