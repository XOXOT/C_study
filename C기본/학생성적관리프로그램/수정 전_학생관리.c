#include <stdio.h> 
#include <string.h>
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
//삭제 기능 추가 - 학생 및 성적 정보임으로 데이터는 계속 유지, 따라서 실제 삭제가 아닌 논리적 삭제
//논리적 삭제는 조회에서 제외되도록 함
//- 구현시 고려할 점.
//재사용 및 유지보수를 고려해서 구현할 것.


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
		printf("       성적관리 프로그램      \n");
		printf("##############################\n");
		printf("         1. 학생 입력         \n");
		printf("         2. 성적 입력         \n");
		printf("         3. 학생 성적 출력    \n");
		printf("         4. 성적 수정         \n");
		printf("         5. 정보 삭제         \n");
		printf("         6. 성적 정렬         \n");
		printf("         0. 종   료           \n");
		printf("                              \n");
		printf("##############################\n");

		printf("선택하세요 > ");
		scanf("%d", &selMenu);

		switch (selMenu)
		{
		case 1:		// 1.입력
			inputFunc();
			break;
		case 2:		// 2.성적 입력
			inputscore();
			break;
		case 3:		// 3.학생 성적 출력  
			scorestu();
			break;
			//case 4:		
			//	scorestu(); //4. 성적 수정 
			//	break;
			//case 5:		
			//	scorestu(); //5. 정보 삭제 
			//	break;
		case 6:
			scoresort(); //4. 성적 정렬 (총점 기준)
			break;
			//case 0:		// 5.종료
			//	printf("성적관리 프로그램을 종료합니다.\n");
			//	return;
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
		printf("10명 이상인 %d명을 입력하셨습니다. 처리가 불가능합니다.", howmany);
		goto exit;
	}
	for (n = 1; n <= howmany; n++)
	{
		printf("학생의 이름 입력 : ");
		scanf("%s", name[n]);
	}
exit:;
}

void inputscore()
{
	printf("어느 학생의 성적을 입력 하시겠습니까? >\n");
	scanf("%s", name);

	for (n = 1; n <= howmany; n++) 
	{
		printf("%s의 국어 성적 > ", name);
		scanf("%d", &score[n][0]);
		printf("%s의 영어 성적 > ", name);
		scanf("%d", &score[n][1]);
		printf("%s의 수학 성적 > ", name);
		scanf("%d", &score[n][2]);
		printf("%s의 과학 성적 > ", name);
		scanf("%d", &score[n][3]);
	}
	return 0;
}

void scorestu()
{

	int count;

	count = sizeof(name) / sizeof(name[0]);

	printf("어느 학생의 성적을 출력 하시겠습니까? >\n");
	scanf("%s", name[n]);

	printf("\n------------------------------------------");
	printf("\n순번\n이름\t국어\t영어\t수학\t과학\t총점\t평균\n");

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
	printf("\n순번\t이름\t국어\t영어\t수학\t과학\t총점\t평균\n");

	for (n = 1; n <= howmany; n++)
	{
		tot = score[n][0] + score[n][1] + score[n][2];
		total += tot;
		printf("%d\t%s\t%d\t%d\t%d\t%d\t%d\t%5.2f\n", n, name[n], score[n][0], score[n][1], score[n][2], score[n][3], tot, tot / 4.0);
	}

	return 0;
}

