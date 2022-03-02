/*2차원 배열을 이용한 성적 처리*/
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
		printf("┏━━━━━━━━━━━━━┓\n");
		printf("┃     성적관리 프로그램    ┃\n");
		printf("┃                          ┃\n");
		printf("┃       1.                 ┃\n");
		printf("┃       2. 출   력         ┃\n");
		printf("┃       3. 정   렬         ┃\n");
		printf("┃       4. 삭   제         ┃\n");
		printf("┃       0. 종   료         ┃\n");
		printf("┃                          ┃\n");
		printf("┗━━━━━━━━━━━━━┛\n");

		printf("선택하세요 > ");	scanf("%d", &selMenu);

		switch (selMenu)
		{
		case 1:		// 1.입력
            inputFunc();
			break;
		case 2:		// 2.출력
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

    printf("몇 명의 성적을 처리하도록 설정하시겠습니까(최대 10명) : ");
    scanf("%d", &howmany);
    if (howmany > 10) 
    {
        printf("10명 이상인 %d명을 입력하셨습니다. 처리가 불가능합니다.", howmany);
        goto exit;
    }
    for (n = 1; n <= howmany; n++) {
        printf("%d번째 학생의 이름 입력 : ", n);
        scanf("%s", &name[n]);
        printf("%s의 국어 성적 > ",name[n]); 
        scanf("%d", &jum[n][0]);
        printf("%s의 영어 성적 > ",name[n]); 
        scanf("%d", &jum[n][1]);
        printf("%s의 수학 성적 > ",name[n]); 
        scanf("%d", &jum[n][2]);
        printf("%s의 과학 성적 > ",name[n]); 
        scanf("%d", &jum[n][3]);
    }
    printf("\n-----------------------------------------------------");
    printf("\n순번\t이름\t국어\t영어\t수학\t과학\t총점\t평균\n");
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
	printf("☆등수에 따라 정렬되었습니다.☆\n");
}


