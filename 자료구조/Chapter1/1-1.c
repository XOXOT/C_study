#include <stdio.h>

//5���� ������ �Է¹޾� �ִ� �� ã��
int main(void)
{
	int i=1, num = 0, sum = 0;
	int max;
	int age = 0;
	char name[10] = {NULL};
	char ch;

	//printf("5���� ������ �Է��ϼ���\n");

	//max = num;

	//for (i = 0; i < 5; i++)
	//{
	//	printf("%d��° ���� �Է�->", i + 1);
	//	scanf("%d", &num);

	//	if (max < num)
	//	{
	//		max = num;
	//	}
	//}
	//printf("�ִ� ���� %d �Դϴ�.",max);

	//printf("���̸� �Է��ϼ���\n");
	//scanf("%d", &age);

	////���Ͱ��� scanf���� �ޱ� ������ ���ڿ� ��ȯ�� �ȵ� ���� getchar() �ʿ�(��Ʈ���� �����ִ� ������ ����)
	//getchar();

	//printf("�̸��� �Է��ϼ���\n");
	//scanf("%c", &ch);

	//printf("�̸�:%c\n����:%d\n", ch, age);

	printf("1���� �������� ���� ���ϴ� ���α׷�\n\n");
	printf("������ �Է��ϼ���->");
	scanf("%d", &num);

	//while (i <= num)
	//{
	//	sum += i;
	//	i++;
	//}

	for (i = 1; i <= num; i++)
	{
		sum += i;
	}

	printf("1���� %d������ ���� %d �Դϴ�.\n", num, sum);

	return 0;
}
