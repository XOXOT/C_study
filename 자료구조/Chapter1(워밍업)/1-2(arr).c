#include <stdio.h>

int main(void)
{
	int num = 0;
	printf("방의 개수를 입력하세요\n");
	scanf("%d", &num);
	printf("\n%d 개의 방을 가지는 배열을 만듭니다.\n\n", num);

	//int room[100];
	int i,j;

	//배열 생성 코드(중간에서 생성하는 것이므로 동적함수를 써야함)
	int *room = (int*)malloc(sizeof(int) * num); //필요한 만큼만 배열 만들기(메모리 누수 방지)

	if (room == NULL)
	{
		return -1;
	}

	for (i = 0; i < num; i++)
	{
		printf("%d번째 방의 값을 입력하세요->",i+1);
		//scanf("%d", &room[i]);
		scanf("%d", room + i);
	}

	printf("\n방의 구성은 다음과 같습니다.\n");
	for (j = 0; j < num; j++)
	{
		//printf("arr[%d] = %d\n",j, room[j]);
		printf("arr[%d] = %d\n", j, *(room + j)); //*(room + j) == room[j]
	}

	free(room);
	return 0;
}