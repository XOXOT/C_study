#include <stdio.h>

int main(void)
{
	int inkey = 0;
	int ary[] = {1,5,9,3,8,7,4,2};
	int size = sizeof(ary) / sizeof(ary[0]);

	printf("찾을 숫자를 입력하세요.", inkey);
	scanf("%d", &inkey);

	LSearch(ary, inkey, size);

	return 0;
}

int LSearch(int* pary, int num, int sz)
{
	int i = 0;

	for (i = 0; i < sz; i++)
	{
		if (pary[i] == num)
		{
			printf("%d 숫자를 찾았습니다.", num);
			return pary[i];
		}
	}
	printf("%d 숫자는 없습니다.", num);
	return -1;
}