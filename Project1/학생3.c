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
void get_Info(int max, char(*tmp_name)[10], char(*tmp_num)[10], char* tmp_Linux, char* tmp_OS, char* tmp_JPN)
{
	int i, j;

	printf("\n======================================\n");

	for (i = 0; i < max; i++) {
		printf("\n%d��° �л��� ������ �Է����ּ���.\n", i + 1);

		// �̸� �Է�
		printf("�̸�: ");
		scanf("%s", tmp_name[i]);

		// �й� �Է�
		printf("�й� : ");
		scanf("%s", tmp_num[i]);

		// ���� �Է�
		printf("������ ���� : ");
		scanf("%d", &tmp_Linux[i]);

		printf("�ü�� ���� : ");
		scanf("%d", &tmp_OS[i]);

		printf("�Ϻ��� ���� : ");
		scanf("%d", &tmp_JPN[i]);
	}
}

// ������ ����ϴ� �Լ�
int get_Sum(int max, char* tmp_Linux, char* tmp_OS, char* tmp_JPN, double* sum)
{
	int i;

	for (i = 0; i < max; i++) {
		sum[i] = tmp_Linux[i] + tmp_OS[i] + tmp_JPN[i];
	}
}

// ����� ����ϴ� �Լ�
double get_Avg(int max, double* sum, double* tmp_avg)
{
	int i;

	for (i = 0; i < max; i++) {
		tmp_avg[i] = sum[i] / 3;
	}
}

// ����ǥ ����ϴ� �Լ�
void get_Result(int max, char(*tmp_name)[10], char(*tmp_num)[10], char* tmp_Linux, char* tmp_OS, char* tmp_JPN, double* sum, double* tmp_avg)
{
	int i;

	for (i = 0; i < max; i++)
	{
		printf("\n============= < %s�� ����ǥ > =============\n", tmp_name[i]);
		printf("\n������ ���� : %d\n", tmp_Linux[i]);
		printf("�ü�� ���� : %d\n", tmp_OS[i]);
		printf("�Ϻ��� ���� : %d\n", tmp_JPN[i]);
		printf("���� : %.f\n��� : %.2f\n\n", sum[i], tmp_avg[i]);
	}
}

int main()
{
	int i, count = 0;

	count = get_Count();	// �л��� �Է�

	int Linux[count], OS[count], JPN[count];	// ������, �ü��, �Ϻ���
	double sum[count], avg[count];
	char name[count][10], number[count][10];	// �̸�, �й�

	get_Info(count, name, number, Linux, OS, JPN);		// �л��� ������ ���� �Է� 

	// ���� ���ϱ�
	get_Sum(count, Linux, OS, JPN, sum);		// ���� ���� ���ϱ�

	get_Avg(count, sum, avg);		// ���� ��� ���ϱ�

	get_Result(count, name, number, Linux, OS, JPN, sum, avg);		// ����ǥ ����ϱ�

	return 0;
}