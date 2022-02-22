#include <stdio.h>

int main(void)
{
	int i, num = 0;
	int res = 1;

	//4 x 3 x 2 x 1
	//for (i = 4; i >= 1; i--)
	//{
	//	res = i * res;
	//}
	//printf("%d\n", res);

	printf("%d\n", factorial(4));

	return 0;
}

int factorial(int a)
{
	if (a == 0)
	{
		return 1; //0의 펙토리얼은 1이기 때문
	}
	else
	{
		return a * factorial(a - 1);
	}
}