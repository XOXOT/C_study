#include<stdio.h>

//int Fibo(int n)  // (int n)�Է�
//{
//	if (n == 1)
//		return 0; // �Ǻ���ġ ������ ó�� ���� 0
//	else if (n == 2)
//		return 1; // �ι�° ���� 1�� ���۵Ǳ� ������ ���� ���ϰ��� 0�� 1�� ����
//	else
//		return Fibo(n - 1) + Fibo(n - 2);    // �Ǻ����ü��� ����  n=(n-1)+(n-2) , (n-1)=(n-2)+(n-3)
//}
//
//int main(void)
//{
//	int i;
//	for (i = 1; i < 15; i++)
//		printf("%d ", Fibo(i));
//
//	return 0;
//}


//int Fibo(int n)  // (int n)�Է�
//{
//	if (n == 1)
//		return 0;
//	else if (n == 2)
//		return 1;
//	else
//		return Fibo(n - 1) + Fibo(n - 2);    // �Ǻ����ü��� ����  n=(n-1)+(n-2) , (n-1)=(n-2)+(n-3)
//}
//
//int main(void)
//{
//	int i,res;
//	for (i = 1; i < 15; i++) {
//		res = Fibo(i);
//		printf("%3d", res);
//	}
//	return 0;
//}


//int Fibo(int n)
//{
//	printf("func call param param %d\n", n);
//
//	if (n == 1)
//		return 0;
//	else if (n == 2)
//		return 1;
//	else
//		return Fibo(n - 1) + Fibo(n - 2);
//}
//
//int main(void)
//{
//	Fibo(7);
//	return 0;
//}

typedef struct profile {
    char name[10];
    int num;
    int money;

} Profile;

int main() {

    Profile new[5];
    int add = 0;
    double avg;

    for (int i = 0; i < 5; ++i) {
        printf("[%d �������]\n", i + 1);
        printf("�̸� : ");
        scanf("%s", &new[i].name);
        printf("�����ȣ : ");
        scanf("%d", &new[i].num);
        printf("�޿� : ");
        scanf("%d", &new[i].money);
        
        add += new[i].money;
    }
    avg = add / 5;
    printf("\n== ��� ��� ==\n");
    for (int i = 0; i < 5; ++i) {
        printf("�̸�: %s  �����ȣ : %d  �޿� : %d\n", new[i].name, new[i].num, new[i].money);
    }
    printf("�ѱ޿��� : %d��\n", add);
    printf("��� �޿��� : %.1lf��\n", avg);

    return 0;
}