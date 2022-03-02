#include <stdio.h>

int main(void)
{
	int ary[] = {1,3,4,5,7,8,9,12};
	int len = sizeof(ary) / sizeof(ary[0]);
	int key = 0, idx;

	printf("찾을 숫자를 입력하세요.", key);
	scanf("%d", &key);

	idx = BSearch(ary, len, key);

	printf("찾은 인덱스-> %d\n", idx);
	printf("찾은 값-> %d\n", ary[idx]);

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
		printf("찾으시는 값은 없습니다.\n"); //????? 안되는 건가
	}
	return -1;
}