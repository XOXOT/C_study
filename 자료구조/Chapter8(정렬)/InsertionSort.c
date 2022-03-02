#include <stdio.h>

void InserSort(int arr[], int n)
{
	int i, j;
	int insData;

	for(i=1; i<n; i++)
	{
		insData = arr[i];   // 정렬 대상을 insData에 저장

		for(j=i-1; j>=0 ; j--)
		{
			if(arr[j] > insData) 
				arr[j+1] = arr[j];    // 비교 대상 한 칸 뒤로 밀기
			else
				break;   // 삽입 위치 찾았으니 탈출!
		}

		arr[j+1] = insData;  // 찾은 위치에 정렬 대상 삽입!
	}
}

void InserSort2(int arr[], int n)
{
	int i, j;
	int insData;

	for (i = 1; i < n; i++) //정렬 되어있다고 가정되어 있어 앞 뒤 구분을 위해 1부터 시작
	{
		for (j = i; j > 0; j--)
		{
			if (arr[j - 1] > arr[j])
			{
				insData = arr[j - 1];  // 비교 대상 한 칸 뒤로 밀기
				arr[j - 1] = arr[j];
				arr[j] = insData;
			}
		}
		printf("\n\n%d단계\n\n", i);
		for (int k = 0; k < 5; k++)
			printf("%d ", arr[k]);
	}
}

int main(void)
{
	int arr[5] = {5, 3, 2, 4, 1};
	int i;

	InserSort2(arr, sizeof(arr)/sizeof(int));

	//for(i=0; i<5; i++)
	//	printf("%d ", arr[i]);

	printf("\n");
	return 0;
}