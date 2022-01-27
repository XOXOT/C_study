#include <stdio.h>

// 학생수를 입력 받는 함수
int get_Count()
{
	int cnt;

	printf("성적 계산을 할 학생수를 입력해주세요.\n");
	printf("학생수: ");
	scanf("%d", &cnt);

	return cnt;
}

// 학생의 정보와 성적을 입력 받는 함수
void get_Info(int max, char(*tmp_name)[10], char(*tmp_num)[10], char* tmp_Linux, char* tmp_OS, char* tmp_JPN)
{
	int i, j;

	printf("\n======================================\n");

	for (i = 0; i < max; i++) {
		printf("\n%d번째 학생의 정보를 입력해주세요.\n", i + 1);

		// 이름 입력
		printf("이름: ");
		scanf("%s", tmp_name[i]);

		// 학번 입력
		printf("학번 : ");
		scanf("%s", tmp_num[i]);

		// 성적 입력
		printf("리눅스 성적 : ");
		scanf("%d", &tmp_Linux[i]);

		printf("운영체제 성적 : ");
		scanf("%d", &tmp_OS[i]);

		printf("일본어 성적 : ");
		scanf("%d", &tmp_JPN[i]);
	}
}

// 총점을 계산하는 함수
int get_Sum(int max, char* tmp_Linux, char* tmp_OS, char* tmp_JPN, double* sum)
{
	int i;

	for (i = 0; i < max; i++) {
		sum[i] = tmp_Linux[i] + tmp_OS[i] + tmp_JPN[i];
	}
}

// 평균을 계산하는 함수
double get_Avg(int max, double* sum, double* tmp_avg)
{
	int i;

	for (i = 0; i < max; i++) {
		tmp_avg[i] = sum[i] / 3;
	}
}

// 성적표 출력하는 함수
void get_Result(int max, char(*tmp_name)[10], char(*tmp_num)[10], char* tmp_Linux, char* tmp_OS, char* tmp_JPN, double* sum, double* tmp_avg)
{
	int i;

	for (i = 0; i < max; i++)
	{
		printf("\n============= < %s의 성적표 > =============\n", tmp_name[i]);
		printf("\n리눅스 성적 : %d\n", tmp_Linux[i]);
		printf("운영체제 성적 : %d\n", tmp_OS[i]);
		printf("일본어 성적 : %d\n", tmp_JPN[i]);
		printf("총합 : %.f\n평균 : %.2f\n\n", sum[i], tmp_avg[i]);
	}
}

int main()
{
	int i, count = 0;

	count = get_Count();	// 학생수 입력

	int Linux[count], OS[count], JPN[count];	// 리눅스, 운영체제, 일본어
	double sum[count], avg[count];
	char name[count][10], number[count][10];	// 이름, 학번

	get_Info(count, name, number, Linux, OS, JPN);		// 학생의 정보와 성적 입력 

	// 성적 구하기
	get_Sum(count, Linux, OS, JPN, sum);		// 성적 총점 구하기

	get_Avg(count, sum, avg);		// 성적 평균 구하기

	get_Result(count, name, number, Linux, OS, JPN, sum, avg);		// 성적표 출력하기

	return 0;
}