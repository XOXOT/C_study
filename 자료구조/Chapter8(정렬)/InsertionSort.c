#include <stdio.h>

void InserSort(int arr[], int n)
{
	int i, j;
	int insData;

	for(i=1; i<n; i++)
	{
		insData = arr[i];   // ���� ����� insData�� ����

		for(j=i-1; j>=0 ; j--)
		{
			if(arr[j] > insData) 
				arr[j+1] = arr[j];    // �� ��� �� ĭ �ڷ� �б�
			else
				break;   // ���� ��ġ ã������ Ż��!
		}

		arr[j+1] = insData;  // ã�� ��ġ�� ���� ��� ����!
	}
}

void InserSort2(int arr[], int n)
{
	int i, j;
	int insData;

	for (i = 1; i < n; i++) //���� �Ǿ��ִٰ� �����Ǿ� �־� �� �� ������ ���� 1���� ����
	{
		for (j = i; j > 0; j--)
		{
			if (arr[j - 1] > arr[j])
			{
				insData = arr[j - 1];  // �� ��� �� ĭ �ڷ� �б�
				arr[j - 1] = arr[j];
				arr[j] = insData;
			}
		}
		printf("\n\n%d�ܰ�\n\n", i);
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