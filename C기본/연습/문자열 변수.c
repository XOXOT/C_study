#include <stdio.h>
#include <string.h> /*���ڿ� ���� �ҽ��ڵ�*/

int main(void)
{
	char fruit[20] = "strawberry";

	printf("����: %s\n", fruit);
	printf("����´: %s %s\n", fruit, "jam");
	printf("�����ϴ� ����: %s\n", fruit);
	strcpy(fruit, "banana");
	printf("%s\n", fruit);

	return 0;
}