
#include <stdio.h>

void inputFunc(int grade[][8], int* seqNo, int* recordNo);
void outputFunc(int grade[][8], int* recordNo);
void rankCheckFunc(int grade[][8], int* recordNo);
void sortFunc(int grade[][8], int* recordNo);
void deleteFunc(int grade[][8], int* recordNo);

void main()
{
	int selMenu;
	int grade[11][8]={0,};	// 10명, 레코드No┃순번┃국어┃영어┃수학┃과학┃총점┃등수┃,(평균),(등급)
	int seqNo=0;			// 순번
	int recordNo=0;			// record 개수(인덱스로 사용)
	int i;
	
	for(i=0; i<11; i++)	grade[i][7] = 99;	// 등수초기화
	
	while(1)
	{
		system("cls");
		printf("┏━━━━━━━━━━━━━┓\n");
		printf("┃  성적관리 프로그램 v2.0  ┃\n");
		printf("┃                          ┃\n");
		printf("┃       1. 입   력         ┃\n");
		printf("┃       2. 출   력         ┃\n");
		printf("┃       3. 정   렬         ┃\n");
		printf("┃       4. 삭   제         ┃\n");
		printf("┃       0. 종   료         ┃\n");
		printf("┃                          ┃\n");
		printf("┗━━━━━━━━━━━━━┛\n");
		
		printf("선택하세요 > ");	scanf("%d", &selMenu);
		
		switch(selMenu)
		{
		case 1:		// 1.입력
			inputFunc(grade, &seqNo, &recordNo);
			break;
		case 2:		// 2.출력
			outputFunc(grade, &recordNo);			
			break;
		case 3:		// 3.정렬
			sortFunc(grade, &recordNo);
			break;
		case 4:		// 4.삭제
			deleteFunc(grade, &recordNo);
			break;
		case 0:		// 5.종료
			printf("⊙성적관리 프로그램을 종료합니다.⊙\n");
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
            printf("◇10개의 레코드를 초과할 수 없습니다.◇\n");
            system("pause");
            break;
        }
	    
		fflush(stdin);
		
        ++*seqNo;
        ++*recordNo;
		grade[*seqNo][1] = *seqNo;
		grade[*seqNo][0] = *recordNo;
		
		printf(" %d의 국어 성적 > ", *seqNo); scanf("%d", &grade[*seqNo][2]);
		printf(" %d의 영어 성적 > ", *seqNo); scanf("%d", &grade[*seqNo][3]);
		printf(" %d의 수학 성적 > ", *seqNo); scanf("%d", &grade[*seqNo][4]);
		printf(" %d의 과학 성적 > ", *seqNo); scanf("%d", &grade[*seqNo][5]);
		
		grade[*seqNo][6] = grade[*seqNo][2]+grade[*seqNo][3]+grade[*seqNo][4]+grade[*seqNo][5];
		
		fflush(stdin);
		printf("성적을 계속 입력하시겠습니까?('y' or other key) > "); scanf("%c", &yn);
		if(yn=='y' || yn=='Y')	continue;
		else					break;
		
	}			
}

void outputFunc(int grade[][8], int* recordNo)
{
	float tmpAvr;			// 평균
	char tmpGrade[2]="";	// 등급
	int i;

	system("cls");
	// 등수 체크
	rankCheckFunc(grade, recordNo);

	printf("┏━━━━━━━━━━━━━━━━━━━━━━━━━━━┓\n");
	printf("┃순번┃국어┃영어┃수학┃과학┃총점┃ 평균 ┃등수┃등급┃\n");
	printf("┗━━━━━━━━━━━━━━━━━━━━━━━━━━━┛\n");
	for(i=1; i<*recordNo+1; i++)
	{
		tmpAvr = (float)grade[i][6] / 4;
		if		(tmpAvr >= 90)	strcpy(tmpGrade, "수");
		else if	(tmpAvr >= 80)	strcpy(tmpGrade, "우");
		else if	(tmpAvr >= 70)	strcpy(tmpGrade, "미");
		else if	(tmpAvr >= 60)	strcpy(tmpGrade, "양");
		else					strcpy(tmpGrade, "가");

		if(grade[i][1] != 0)
		{
			printf("┃%4d┃%4d┃%4d┃%4d┃%4d┃%4d┃%6.2f┃%4d┃ %s ┃\n", 
				grade[i][1],grade[i][2],grade[i][3],grade[i][4],grade[i][5],grade[i][6],tmpAvr,grade[i][7],tmpGrade);
			printf("┗━━━━━━━━━━━━━━━━━━━━━━━━━━━┛\n");
		}
	}
	system("pause");
}

void rankCheckFunc(int grade[][8], int* recordNo)
{
	int i, j;
	int tmpRank=1;			// 등수	

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
	printf("☆등수에 따라 정렬되었습니다.☆\n");
	system("pause");
}

void deleteFunc(int grade[][8], int* recordNo)
{
	int tmpNo, i, j;
	system("cls");
	printf(" 삭제할 순번을 입력하세요 > ");	scanf("%d", &tmpNo);
	for(i=1; i<*recordNo+1; i++)
	{
		if(grade[i][1] == tmpNo)
		{
			for(j=1; j<8; j++)
				grade[i][j] = 0;
			printf(" %d번이 삭제 되었습니다.\n", tmpNo);
			system("pause");
			return;
		}
	}
	printf(" %d번이 없습니다.\n", tmpNo);
	system("pause");
}
