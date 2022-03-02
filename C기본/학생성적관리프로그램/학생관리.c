
#include <stdio.h>

void inputFunc(int grade[][8], int* seqNo, int* recordNo);
void outputFunc(int grade[][8], int* recordNo);
void rankCheckFunc(int grade[][8], int* recordNo);
void sortFunc(int grade[][8], int* recordNo);
void deleteFunc(int grade[][8], int* recordNo);

void main()
{
	int selMenu;
	int grade[11][8]={0,};	// 10��, ���ڵ�No�����������������Ц����Ц������������,(���),(���)
	int seqNo=0;			// ����
	int recordNo=0;			// record ����(�ε����� ���)
	int i;
	
	for(i=0; i<11; i++)	grade[i][7] = 99;	// ����ʱ�ȭ
	
	while(1)
	{
		system("cls");
		printf("������������������������������\n");
		printf("��  �������� ���α׷� v2.0  ��\n");
		printf("��                          ��\n");
		printf("��       1. ��   ��         ��\n");
		printf("��       2. ��   ��         ��\n");
		printf("��       3. ��   ��         ��\n");
		printf("��       4. ��   ��         ��\n");
		printf("��       0. ��   ��         ��\n");
		printf("��                          ��\n");
		printf("������������������������������\n");
		
		printf("�����ϼ��� > ");	scanf("%d", &selMenu);
		
		switch(selMenu)
		{
		case 1:		// 1.�Է�
			inputFunc(grade, &seqNo, &recordNo);
			break;
		case 2:		// 2.���
			outputFunc(grade, &recordNo);			
			break;
		case 3:		// 3.����
			sortFunc(grade, &recordNo);
			break;
		case 4:		// 4.����
			deleteFunc(grade, &recordNo);
			break;
		case 0:		// 5.����
			printf("���������� ���α׷��� �����մϴ�.��\n");
			return;
		default:
			break;
		}
	}
}

void inputFunc(int grade[][8], int* seqNo, int* recordNo)
{
	char yn;
	system("cls");
	while(1)
	{
        if(*recordNo > 9)
        {
            printf("��10���� ���ڵ带 �ʰ��� �� �����ϴ�.��\n");
            system("pause");
            break;
        }
	    
		fflush(stdin);
		
        ++*seqNo;
        ++*recordNo;
		grade[*seqNo][1] = *seqNo;
		grade[*seqNo][0] = *recordNo;
		
		printf(" %d�� ���� ���� > ", *seqNo); scanf("%d", &grade[*seqNo][2]);
		printf(" %d�� ���� ���� > ", *seqNo); scanf("%d", &grade[*seqNo][3]);
		printf(" %d�� ���� ���� > ", *seqNo); scanf("%d", &grade[*seqNo][4]);
		printf(" %d�� ���� ���� > ", *seqNo); scanf("%d", &grade[*seqNo][5]);
		
		grade[*seqNo][6] = grade[*seqNo][2]+grade[*seqNo][3]+grade[*seqNo][4]+grade[*seqNo][5];
		
		fflush(stdin);
		printf("������ ��� �Է��Ͻðڽ��ϱ�?('y' or other key) > "); scanf("%c", &yn);
		if(yn=='y' || yn=='Y')	continue;
		else					break;
		
	}			
}

void outputFunc(int grade[][8], int* recordNo)
{
	float tmpAvr;			// ���
	char tmpGrade[2]="";	// ���
	int i;

	system("cls");
	// ��� üũ
	rankCheckFunc(grade, recordNo);

	printf("����������������������������������������������������������\n");
	printf("�����������������Ц����Ц������� ��� ���������ަ�\n");
	printf("����������������������������������������������������������\n");
	for(i=1; i<*recordNo+1; i++)
	{
		tmpAvr = (float)grade[i][6] / 4;
		if		(tmpAvr >= 90)	strcpy(tmpGrade, "��");
		else if	(tmpAvr >= 80)	strcpy(tmpGrade, "��");
		else if	(tmpAvr >= 70)	strcpy(tmpGrade, "��");
		else if	(tmpAvr >= 60)	strcpy(tmpGrade, "��");
		else					strcpy(tmpGrade, "��");

		if(grade[i][1] != 0)
		{
			printf("��%4d��%4d��%4d��%4d��%4d��%4d��%6.2f��%4d�� %s ��\n", 
				grade[i][1],grade[i][2],grade[i][3],grade[i][4],grade[i][5],grade[i][6],tmpAvr,grade[i][7],tmpGrade);
			printf("����������������������������������������������������������\n");
		}
	}
	system("pause");
}

void rankCheckFunc(int grade[][8], int* recordNo)
{
	int i, j;
	int tmpRank=1;			// ���	

	for(i=1; i<*recordNo+1; i++)
	{
		for(j=1; j<*recordNo+1; j++)
		{
			if(grade[i][6] < grade[j][6]) 
				tmpRank++;
		}
		grade[i][7] = tmpRank;
		tmpRank=1;
	}		
}

void sortFunc(int grade[][8], int* recordNo)
{
	int i, j, k;
	int tmpGrade[8];
	for(i=1; i<*recordNo; i++)
	{
		for(j=i+1; j<*recordNo+1; j++)
		{
			if(grade[i][7] > grade[j][7])
			{
				for(k=1; k<8; k++)	tmpGrade[k] = grade[i][k]; 
				for(k=1; k<8; k++)	grade[i][k] = grade[j][k]; 
				for(k=1; k<8; k++)	grade[j][k] = tmpGrade[k]; 
			}
		}
	}
	printf("�ٵ���� ���� ���ĵǾ����ϴ�.��\n");
	system("pause");
}

void deleteFunc(int grade[][8], int* recordNo)
{
	int tmpNo, i, j;
	system("cls");
	printf(" ������ ������ �Է��ϼ��� > ");	scanf("%d", &tmpNo);
	for(i=1; i<*recordNo+1; i++)
	{
		if(grade[i][1] == tmpNo)
		{
			for(j=1; j<8; j++)
				grade[i][j] = 0;
			printf(" %d���� ���� �Ǿ����ϴ�.\n", tmpNo);
			system("pause");
			return;
		}
	}
	printf(" %d���� �����ϴ�.\n", tmpNo);
	system("pause");
}
