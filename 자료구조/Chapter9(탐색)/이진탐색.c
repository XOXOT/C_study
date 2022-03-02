#include <stdio.h>

int main(void)
{
	int ary[] = {1,3,4,5,7,8,9,12};
	int len = sizeof(ary) / sizeof(ary[0]);
	int key = 0, idx;

	printf("ã�� ���ڸ� �Է��ϼ���.", key);
	scanf("%d", &key);

	idx = BSearch(ary, len, key);

	printf("ã�� �ε���-> %d\n", idx);
	printf("ã�� ��-> %d\n", ary[idx]);

	return 0;
}


int BSearch(int* pary, int n, int key)
{
	int low, middle, high;
	low = 0;
	high = n - 1;
	while (low <= high)
	{
		printf("[%d, %d]\n", low, high);
		middle = (low + high) / 2;
		if (key == pary[middle])
		{
			return middle;
		}
		else if (key > pary[middle])
		{
			low = middle + 1;
		}
		else if (key < pary[middle])
		{
			high = middle - 1;
		}
	}
	if (key != pary[middle])
	{
		printf("ã���ô� ���� �����ϴ�.\n"); //????? �ȵǴ� �ǰ�
	}
	return -1;
}