#include <stdio.h>

int main(void)
{
	int a;

	scanf("%d", &a);
	printf("�Է°�:%d\n", a);

	getchar(); /*�� �ʱ�ȭ*/

	int age;
	double height;

	printf("���̿� Ű�� �Է��ϼ���:");
	scanf("%d%lf", &age, &height);
	printf("���̴� %d��\nŰ�� %.1lfcm�Դϴ�\n", age, height);

	char grade;
	char name[20];

	getchar(); /*�� �ʱ�ȭ*/

	printf("���� �Է�:");
	scanf("%c", &grade);
	printf("�̸� �Է�:");
	scanf("%s", &name);
	printf("%s�� ������%c�Դϴ�.\n",name,grade);

	return 0;
}