#include <stdio.h> 
#include <string.h>
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
//���� ��� �߰� - �л� �� ���� ���������� �����ʹ� ��� ����, ���� ���� ������ �ƴ� ���� ����
//���� ������ ��ȸ���� ���ܵǵ��� ��
//- ������ ����� ��.
//���� �� ���������� ����ؼ� ������ ��.


void inputFunc();
void inputscore();
void scorestu(void);
void scoresort(void);


char name[10][7];
int score[5][4];
int len, n, m, howmany, tot, total = 0;

void main()
{
	int selMenu;

	while (1)
	{
		printf("##############################\n");
		printf("       �������� ���α׷�      \n");
		printf("##############################\n");
		printf("         1. �л� �Է�         \n");
		printf("         2. ���� �Է�         \n");
		printf("         3. �л� ���� ���    \n");
		printf("         4. ���� ����         \n");
		printf("         5. ���� ����         \n");
		printf("         6. ���� ����         \n");
		printf("         0. ��   ��           \n");
		printf("                              \n");
		printf("##############################\n");

		printf("�����ϼ��� > ");
		scanf("%d", &selMenu);

		switch (selMenu)
		{
		case 1:		// 1.�Է�
			inputFunc();
			break;
		case 2:		// 2.���� �Է�
			inputscore();
			break;
		case 3:		// 3.�л� ���� ���  
			scorestu();
			break;
			//case 4:		
			//	scorestu(); //4. ���� ���� 
			//	break;
			//case 5:		
			//	scorestu(); //5. ���� ���� 
			//	break;
		case 6:
			scoresort(); //4. ���� ���� (���� ����)
			break;
			//case 0:		// 5.����
			//	printf("�������� ���α׷��� �����մϴ�.\n");
			//	return;
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
		printf("10�� �̻��� %d���� �Է��ϼ̽��ϴ�. ó���� �Ұ����մϴ�.", howmany);
		goto exit;
	}
	for (n = 1; n <= howmany; n++)
	{
		printf("�л��� �̸� �Է� : ");
		scanf("%s", name[n]);
	}
exit:;
}

void inputscore()
{
	printf("��� �л��� ������ �Է� �Ͻðڽ��ϱ�? >\n");
	scanf("%s", name);

	for (n = 1; n <= howmany; n++) 
	{
		printf("%s�� ���� ���� > ", name);
		scanf("%d", &score[n][0]);
		printf("%s�� ���� ���� > ", name);
		scanf("%d", &score[n][1]);
		printf("%s�� ���� ���� > ", name);
		scanf("%d", &score[n][2]);
		printf("%s�� ���� ���� > ", name);
		scanf("%d", &score[n][3]);
	}
	return 0;
}

void scorestu()
{

	int count;

	count = sizeof(name) / sizeof(name[0]);

	printf("��� �л��� ������ ��� �Ͻðڽ��ϱ�? >\n");
	scanf("%s", name[n]);

	printf("\n------------------------------------------");
	printf("\n����\n�̸�\t����\t����\t����\t����\t����\t���\n");

	for (n = 1; n <= count; n++)
	{
		tot = score[n][0] + score[n][1] + score[n][2];
		total += tot;
		printf("%d\%s\t%d\t%d\t%d\t%d\t%d\t%5.2f\n", n, name, score[n][0], score[n][1], score[n][2], score[n][3], tot, tot / 4.0);
	}
	printf("\n\n");

	return 0;
}

void scoresort(void)
{
	printf("\n-----------------------------------------------------");
	printf("\n����\t�̸�\t����\t����\t����\t����\t����\t���\n");

	for (n = 1; n <= howmany; n++)
	{
		tot = score[n][0] + score[n][1] + score[n][2];
		total += tot;
		printf("%d\t%s\t%d\t%d\t%d\t%d\t%d\t%5.2f\n", n, name[n], score[n][0], score[n][1], score[n][2], score[n][3], tot, tot / 4.0);
	}

	return 0;
}

