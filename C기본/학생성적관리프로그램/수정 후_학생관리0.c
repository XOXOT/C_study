#include <stdio.h>
#include <stdio.h> 
#include <string.h>
#include <stdlib.h>

//- 관리할 학생 수
//10명
//
//- 관리할 학생의 데이터
//이름(문자), 4 과목(국어, 영어, 수학, 과학)의 성적 점수(숫자)
//
//- 기능
//학생 등록 및 수정,
//성적 등록 및 수정,
//학생 이름으로 성적 조회 후 출력,
//전체 학생을 성적순으로 출력,
//성적 출력시 제목으로 이름, 과목명, 총점, 평균, 석차 를 먼저 출력한 후,
//학생 별 성적 결과가 출력이 되도록 할 것.
//
//- 구현시 고려할 점.
//재사용 및 유지보수를 고려해서 구현할 것.
//미니프로젝트 시연 동영상을 참고할 것.


void inputFunc();
void scorestu(void);
void scoresort(void);
void scoreedit(void);
void studel(void);
void pexit();


char name[10][7];
int score[10][5];   // [4]: 총점
//int len, n, m, howmany, tot, total = 0;
int n, m, howmany, total = 0;

void main()
{
	int selMenu;

	while (1)
	{
		printf("##############################\n");
		printf("       성적관리 프로그램      \n");
		printf("##############################\n");
		printf("                              \n");
		printf("  1. 학생 이름 및 성적 입력   \n");
		printf("      2. 학생 성적 출력       \n");
		printf("      3. 학생 성적 수정       \n");
		printf("      4. 학생 성적 정렬       \n");
		printf("      5. 학생 정보 삭제       \n");
		printf("         0. 종   료           \n");
		printf("                              \n");
		printf("##############################\n");

		printf("선택하세요 > ");
		scanf("%d", &selMenu);

		switch (selMenu)
		{
		case 1:		// 1.학생 이름 및 성적 입력
			inputFunc();
			break;
		case 2:		// 2.학생 성적 출력
			scorestu();
			break;
		case 3:		// 3.학생 성적 수정 			
			scoreedit();
			break;
		case 4:
			scoresort(); //4. 성적 정렬 (총점 기준)
			break;
		case 5:		
			studel(); //5. 학생 정보 삭제
			break;
		case 0:		
			pexit(); // 0.종료
			break;
		default:
			break;
		}
	}
}
void inputFunc()
{
	printf("몇 명의 성적을 처리하도록 설정하시겠습니까(최대 10명) : ");
	scanf("%d", &howmany);
	if (howmany > 10)
	{
		printf("10명 이상인 %d명을 입력하셨습니다. 처리가 불가능합니다.\n", howmany);
		return 0;
	}
	for (n = 0; n < howmany; n++)
	{
		printf("학생의 이름 입력 : ");
		scanf("%s", name[n]);

		printf("%s의 국어 성적 > ", name[n]);
		scanf("%d", &score[n][0]);
		printf("%s의 영어 성적 > ", name[n]);
		scanf("%d", &score[n][1]);
		printf("%s의 수학 성적 > ", name[n]);
		scanf("%d", &score[n][2]);
		printf("%s의 과학 성적 > ", name[n]);
		scanf("%d", &score[n][3]);
	}
}

void scorestu()
{
	char temp[7];

	printf("어느 학생의 성적을 출력 하시겠습니까? >\n");
	scanf("%s", temp);

	printf("\n------------------------------------------\n");
	printf("\n순번\t이름\t국어\t영어\t수학\t과학\t총점\t평균\n");

	for (n = 0; n < howmany; n++)   ////// 수정
	{
		if (strcmp(temp, name[n]) == 0)
		{
			score[n][4] = score[n][0] + score[n][1] + score[n][2] + score[n][3];   ///   수정 
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
	printf("\n순번\t이름\t국어\t영어\t수학\t과학\t총점\t평균\n");

	// 총점 순 정렬: 선택 정렬
	int k, m, temp;
	char tname[7];

	for (n = 0; n < howmany - 1; n++)
	{
		for (k = 0; k < howmany - 1; k++)
		{
			if (score[k][4] < score[k + 1][4]) // Descending sort(내림차순 정렬)
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

	// 출력
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

	printf("성적 수정할 학생 이름 입력:");
	scanf("%s", temp);

	for (n = 0; n < howmany; n++)   ////// 수정
	{
		if (strcmp(temp, name[n]) == 0)
		{
			printf("%s의 국어 성적 > ", name[n]);
			scanf("%d", &score[n][0]);
			printf("%s의 영어 성적 > ", name[n]);
			scanf("%d", &score[n][1]);
			printf("%s의 수학 성적 > ", name[n]);
			scanf("%d", &score[n][2]);
			printf("%s의 과학 성적 > ", name[n]);
			scanf("%d", &score[n][3]);
		}
	}
	printf("변경이 완료되었습니다.\n");
	printf("\n\n");
	
	return 0;
}

void studel(void)
{
	char temp[10][7];
	int i, j;

	printf("삭제 할 학생 이름 입력:");
	scanf("%s", temp);

	for (i = 0; i < howmany; i++)
	{
		if (strcmp(temp, name[n]) == 0)
		{
			for (j = 0; j < howmany; j++)
			{
				temp[i][j] = temp[i + 1][j];
			}
		}
	}
	howmany--;

	printf("삭제가 완료되었습니다.\n");
	printf("\n\n");
}



void pexit()
{
	int n;
	printf("0을 한번 더 누르면 종료 됩니다.\n");
	scanf("%d", &n);
	if (n == 0)
	{
		printf("성적관리 프로그램을 종료합니다.");
		exit(0);
	}
	else
	{
		printf("알 수 없는 오류 발생.");
	}
}