/*2���� �迭�� �̿��� ���� ó��*/
#include <stdio.h> 


void inputFunc(void);
void sortFunc();




char name[10][8];
int jum[5][4];
int n, m, howmany, tot, total = 0;

void main()
{
	int selMenu;
    char name[10][8];
    int jum[5][4];


	while (1)
	{
		printf("������������������������������\n");
		printf("��     �������� ���α׷�    ��\n");
		printf("��                          ��\n");
		printf("��       1.                 ��\n");
		printf("��       2. ��   ��         ��\n");
		printf("��       3. ��   ��         ��\n");
		printf("��       4. ��   ��         ��\n");
		printf("��       0. ��   ��         ��\n");
		printf("��                          ��\n");
		printf("������������������������������\n");

		printf("�����ϼ��� > ");	scanf("%d", &selMenu);

		switch (selMenu)
		{
		case 1:		// 1.�Է�
            inputFunc();
			break;
		case 2:		// 2.���
			sortFunc();
			break;
		default:
			break;
		}
	}
}


void inputFunc(void)
{
    char name[10][8];
    int jum[5][4];
    int n, m, howmany, tot, total = 0;

    printf("�� ���� ������ ó���ϵ��� �����Ͻðڽ��ϱ�(�ִ� 10��) : ");
    scanf("%d", &howmany);
    if (howmany > 10) 
    {
        printf("10�� �̻��� %d���� �Է��ϼ̽��ϴ�. ó���� �Ұ����մϴ�.", howmany);
        goto exit;
    }
    for (n = 1; n <= howmany; n++) {
        printf("%d��° �л��� �̸� �Է� : ", n);
        scanf("%s", &name[n]);
        printf("%s�� ���� ���� > ",name[n]); 
        scanf("%d", &jum[n][0]);
        printf("%s�� ���� ���� > ",name[n]); 
        scanf("%d", &jum[n][1]);
        printf("%s�� ���� ���� > ",name[n]); 
        scanf("%d", &jum[n][2]);
        printf("%s�� ���� ���� > ",name[n]); 
        scanf("%d", &jum[n][3]);
    }
    printf("\n-----------------------------------------------------");
    printf("\n����\t�̸�\t����\t����\t����\t����\t����\t���\n");
    for (n = 1; n <= howmany; n++) {
        tot = jum[n][0] + jum[n][1] + jum[n][2];
        total += tot;
        printf("%d\t%s\t%d\t%d\t%d\t%d\t%d\t%5.2f\n", n, name[n], jum[n][0], jum[n][1], jum[n][2], jum[n][3], tot, tot / 3.0);
    }
exit:;
}

void sortFunc()
{
	int i, j, k;
	char name[10][8];
	int jum[5][4];
	int howmany, tot, total = 0;

	for (i = 1; i < howmany; i++)
	{
		for (j = i + 1; j < howmany + 1; j++)
		{
			if (jum[i][7] > jum[j][7])
			{
				for (k = 1; k < 8; k++)
				{
					tot[k] = jum[i][k];
				}
				for (k = 1; k < 8; k++)
				{
					jum[i][k] = jum[j][k];
				}
				for (k = 1; k < 8; k++)
				{
					jum[j][k] = tot[k];
				}
			}
		}
	}
	printf("�ٵ���� ���� ���ĵǾ����ϴ�.��\n");
}


