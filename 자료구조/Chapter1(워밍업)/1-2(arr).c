#include <stdio.h>

int main(void)
{
	int num = 0;
	printf("���� ������ �Է��ϼ���\n");
	scanf("%d", &num);
	printf("\n%d ���� ���� ������ �迭�� ����ϴ�.\n\n", num);

	//int room[100];
	int i,j;

	//�迭 ���� �ڵ�(�߰����� �����ϴ� ���̹Ƿ� �����Լ��� �����)
	int *room = (int*)malloc(sizeof(int) * num); //�ʿ��� ��ŭ�� �迭 �����(�޸� ���� ����)

	if (room == NULL)
	{
		return -1;
	}

	for (i = 0; i < num; i++)
	{
		printf("%d��° ���� ���� �Է��ϼ���->",i+1);
		//scanf("%d", &room[i]);
		scanf("%d", room + i);
	}

	printf("\n���� ������ ������ �����ϴ�.\n");
	for (j = 0; j < num; j++)
	{
		//printf("arr[%d] = %d\n",j, room[j]);
		printf("arr[%d] = %d\n", j, *(room + j)); //*(room + j) == room[j]
	}

	free(room);
	return 0;
}