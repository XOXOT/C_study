#include<stdio.h>

//int Fibo(int n)  // (int n)입력
//{
//	if (n == 1)
//		return 0; // 피보나치 수열은 처음 값은 0
//	else if (n == 2)
//		return 1; // 두번째 값은 1로 시작되기 때문에 각각 리턴값을 0과 1로 지정
//	else
//		return Fibo(n - 1) + Fibo(n - 2);    // 피보나시수열 공식  n=(n-1)+(n-2) , (n-1)=(n-2)+(n-3)
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


//int Fibo(int n)  // (int n)입력
//{
//	if (n == 1)
//		return 0;
//	else if (n == 2)
//		return 1;
//	else
//		return Fibo(n - 1) + Fibo(n - 2);    // 피보나시수열 공식  n=(n-1)+(n-2) , (n-1)=(n-2)+(n-3)
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
        printf("[%d 사원정보]\n", i + 1);
        printf("이름 : ");
        scanf("%s", &new[i].name);
        printf("사원번호 : ");
        scanf("%d", &new[i].num);
        printf("급여 : ");
        scanf("%d", &new[i].money);
        
        add += new[i].money;
    }
    avg = add / 5;
    printf("\n== 사원 명단 ==\n");
    for (int i = 0; i < 5; ++i) {
        printf("이름: %s  사원번호 : %d  급여 : %d\n", new[i].name, new[i].num, new[i].money);
    }
    printf("총급여액 : %d원\n", add);
    printf("평균 급여액 : %.1lf원\n", avg);

    return 0;
}