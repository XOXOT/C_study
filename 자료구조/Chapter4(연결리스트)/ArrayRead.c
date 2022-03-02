#include <stdio.h>

int main(void)
{
	int arr[10];
	int readCount = 0;
	int readData;
	int i;
	printf("자연수를 입력하면 출력하고 1보다 작은 값을 입력하면\n\t입력된 값을 출력하는 프로그램\n\n ");
	while(1)
	{
		printf("자연수 입력: ");
		scanf("%d", &readData);
		if(readData < 1)
			break;

		arr[readCount++] = readData;
	}

	for(i=0; i<readCount; i++)
		printf("%d  ", arr[i]);

	return 0;
}