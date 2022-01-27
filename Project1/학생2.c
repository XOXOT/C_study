#include <stdio.h>

// �л����� �Է� �޴� �Լ�
int get_Count()
{
	int cnt;

	printf("���� ����� �� �л����� �Է����ּ���.\n");
	printf("�л���: ");
	scanf("%d", &cnt);

	return cnt;
}

// �л��� ������ ������ �Է� �޴� �Լ�
void get_Info(int max, char(*tmp_name)[10], char*tmp_kor, char* tmp_eng, char* tmp_math, char* tmp_sci)
{
	int i;

	printf("\n======================================\n");

	for (i = 0; i < max; i++) {
		printf("\n%d��° �л��� ������ �Է����ּ���.\n", i + 1);

		// �̸� �Է�
		printf("�̸�: ");
		scanf("%s", tmp_name[i]);

		
		//���� �Է�

		printf("���� ���� : ");
		scanf("%d", tmp_kor[i]);

		printf("���� ���� : ");
		scanf("%d", &tmp_eng[i]);

		printf("���� ���� : ");
		scanf("%d", &tmp_math[i]);

		printf("���� ���� : ");
		scanf("%d", &tmp_sci[i]);
	}
}

// ������ ����ϴ� �Լ�
int get_Sum(int max, char* tmp_kor, char* tmp_eng, char* tmp_math, char* tmp_sci, double* sum)
{
	int i;

	for (i = 0; i < max; i++) {
		sum[i] = tmp_kor[i] + tmp_eng[i] + tmp_math[i] + tmp_sci[i];
	}
}

// ����� ����ϴ� �Լ�
double get_Avg(int max, double* sum, double* tmp_avg)
{
	int i;

	for (i = 0; i < max; i++) {
		tmp_avg[i] = sum[i] / 4;
	}
}

// ����ǥ ����ϴ� �Լ�
void get_Result(int max, char(*tmp_name)[10], char*tmp_kor, char* tmp_eng, char* tmp_math, char* tmp_sci, double* sum, double* tmp_avg)
{
	int i;

	for (i = 0; i < max; i++)
	{
		printf("\n============= < %s�� ����ǥ > =============\n", tmp_name[i]);
		printf("���� ����: %d\n", tmp_kor[i]);
		printf("\n���� ���� : %d\n", tmp_eng[i]);
		printf("���� ���� : %d\n", tmp_math[i]);
		printf("���� ���� : %d\n", tmp_sci[i]);
		printf("���� : %.f\n��� : %.2f\n\n", sum[i], tmp_avg[i]);
	}
}

int main()
{
	int i, count = 0;

	count = get_Count();	// �л��� �Է�

	int kor[count], eng[count], math[count], sci[count];
	double sum[count], avg[count];
	char name[count][10]; // �̸�, �й�

	get_Info(count, name, kor, eng, math, sci);		// �л��� ������ ���� �Է� 

	// ���� ���ϱ�
	get_Sum(count, kor, eng, math, sci, sum);		// ���� ���� ���ϱ�

	get_Avg(count, sum, avg);		// ���� ��� ���ϱ�

	get_Result(count, name, kor, eng, math, sci, sum, avg);		// ����ǥ ����ϱ�

	return 0;
}