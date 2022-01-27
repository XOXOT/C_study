#include <stdio.h>

int main(void)
{
	////정수형 변수에 대한 예제 =%d
	//int age = 12; /*int부분은 자료형을 쓰는 부분 age는 변수명, 12는 그 값*/
	//	printf("%d\n", age); 
	//	age = 13;
	//	printf("%d\n", age);

	////실수형 변수에 대한 예제 =%f, %lf
	//float f = 46.5;
	//printf("%.2f\n", f);
	//double d = 4.428;
	//printf("%.2lf\n", d);

	////상수에 대한 예제 = const
	//int YEAR = 2000; 이렇게 하면
	//YEAR = 3000 해버리면 바뀌니까 다음처럼 바꿈 참고로 상수는 보통 대문자 변수명 사용
	//const int YEAR = 2000; /*const를 붙임*/
	//printf("태어난  년도: %d\n", YEAR);

	////printf에 대한 설명
	//연산
	//int add = 3 + 7; /*연산 사용 시 add 변수에 10이 들어감 */
	//printf("3 + 7 = %d\n", add);
	//printf("%d * %d = %d\n", 3, 7, 3*7);

	////scanf에 대한 설명
	//키보드 입력을 받아서 저장

	//숫자를 활용한 예제1
	//int input;
	//printf("값을 입력하세요:");
	//scanf("%d", &input); //input앞에 &은 input이라는 변수가 정의된 곳에 값을 입력 받는다는 의미
	//printf("입력값:%d\n",input);

	//숫자를 활용한 예제2
	//int one, two, three;
	//printf("3개의 정수를 입력하세요 :");
	//scanf("%d %d %d", &one, &two, &three);
	//printf("첫번째 값: %d\n", one);
	//printf("두번째 값: %d\n", two);
	//printf("세번째 값: %d\n", three);

	//문자를 활용한 예제
	//문자(한 글자)=%c, 문자열(한 글자 이상의 여러 글자)=%s
	//char c = 'A';
	//printf("%c\n", c);

	//char str[256]; //대괄호는 배열로써 우선 문자 256개를 쭉만든다는 의미로 나중에 다시 배움
	//scanf("%s", str, sizeof(str)); //scanf에서 문자는 따로 &을 표시를 해주지 않지만 sizeof를 써서 길이 제한을 해줘야함 여기서는 str크기 만큼 제한
	//printf("%s\n", str);

	//프로젝트
	//경찰관이 범죄자의 정보를 입수 (조서 작성)
	//이름? 나이? 몸무게? 키? 범죄명?
	
	//1. 이름
	char name[256];
	printf("당신의 이름은?");
	scanf("%s", name, sizeof(name));

	//2. 나이
	int age;
	printf("당신의 나이는?");
	scanf("%d", &age);

	//3. 몸무게
	float weight;
	printf("당신의 몸무게는?");
	scanf("%f", &weight);

	//4. 키
	double height;
	printf("당신의 키는?");
	scanf("%lf", &height);

	//5. 범죄명
	char what[256];
	printf("당신의 범죄명은?");
	scanf("%s", what,sizeof(what));

	//6. 조서 내용 출력 
	printf("\n\n-----범죄자 정보-----\n\n");
	printf("이름            : %s\n", name);
	printf("나이            : %d\n", age);
	printf("몸무게          : %.2f\n", weight);
	printf("키              : %.2lf\n", height);
	printf("범죄명          : %s\n", what);

	return 0;
}
//자료형이란 정수형 실수형 문자형 등 여러 자료 형태를 나타냄
//변수 변하는 수 
//상수 변하지 않는 수
//정수 -1,0,1,-2 소수점이 없는 수
//실수 -.2.0, 1.3 소수점이 붙은 수