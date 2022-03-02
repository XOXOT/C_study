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
void get_Info(int max, char(*tmp_name)[10], char*tmp_kor, char* tmp_eng, char* tmp_math, char* tmp_sci)
{
	int i;

	printf("\n======================================\n");

	for (i = 0; i < max; i++) {
		printf("\n%d번째 학생의 정보를 입력해주세요.\n", i + 1);

		// 이름 입력
		printf("이름: ");
		scanf("%s", tmp_name[i]);

		
		//성적 입력

		printf("국어 성적 : ");
		scanf("%d", tmp_kor[i]);

		printf("영어 성적 : ");
		scanf("%d", &tmp_eng[i]);

		printf("수학 성적 : ");
		scanf("%d", &tmp_math[i]);

		printf("과학 성적 : ");
		scanf("%d", &tmp_sci[i]);
	}
}

// 총점을 계산하는 함수
int get_Sum(int max, char* tmp_kor, char* tmp_eng, char* tmp_math, char* tmp_sci, double* sum)
{
	int i;

	for (i = 0; i < max; i++) {
		sum[i] = tmp_kor[i] + tmp_eng[i] + tmp_math[i] + tmp_sci[i];
	}
}

// 평균을 계산하는 함수
double get_Avg(int max, double* sum, double* tmp_avg)
{
	int i;

	for (i = 0; i < max; i++) {
		tmp_avg[i] = sum[i] / 4;
	}
}

// 성적표 출력하는 함수
void get_Result(int max, char(*tmp_name)[10], char*tmp_kor, char* tmp_eng, char* tmp_math, char* tmp_sci, double* sum, double* tmp_avg)
{
	int i;

	for (i = 0; i < max; i++)
	{
		printf("\n============= < %s의 성적표 > =============\n", tmp_name[i]);
		printf("국어 성적: %d\n", tmp_kor[i]);
		printf("\n영어 성적 : %d\n", tmp_eng[i]);
		printf("수학 성적 : %d\n", tmp_math[i]);
		printf("과학 성적 : %d\n", tmp_sci[i]);
		printf("총합 : %.f\n평균 : %.2f\n\n", sum[i], tmp_avg[i]);
	}
}

int main()
{
	int i, count = 0;

	count = get_Count();	// 학생수 입력

	int kor[count], eng[count], math[count], sci[count];
	double sum[count], avg[count];
	char name[count][10]; // 이름, 학번

	get_Info(count, name, kor, eng, math, sci);		// 학생의 정보와 성적 입력 

	// 성적 구하기
	get_Sum(count, kor, eng, math, sci, sum);		// 성적 총점 구하기

	get_Avg(count, sum, avg);		// 성적 평균 구하기

	get_Result(count, name, kor, eng, math, sci, sum, avg);		// 성적표 출력하기

	return 0;
}