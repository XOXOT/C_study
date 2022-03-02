#include <stdio.h>
#include <time.h>

//선언(함수를 만들려면 선언을 해야함 void)
void p(int num);
void function_without_return();
int function_with_return();
void function_without_params();
void function_with_params(int num1, int num2, int num3);
int apple(int total, int ate); // 전체 total 개에서 ate 개를 먹고 남은 수를 반환 
int add(int num1, int num2);
int sub(int num1, int num2);
int mul(int num1, int num2);
int div(int num1, int num2);
int getRandomNumber(int level);
void showQuestion(int level, int num1, int num2);
void success();
void fail();

int main(void)
{
	////function (함수) 
	////계산기

	//int num = 2;
	////printf("num은 %d 입니다 \n", num);
	//p(num);

	////2+3은? 
	//num = num + 3; //num +=3;
	////printf("num은 %d 입니다 \n", num); //5
	//p(num);

	////5-1은?
	//num -= 1; // num -1
	////printf("num은 %d 입니다 \n", num); //4
	//p(num);

	////4 x 3은?
	//num *= 3;
	////printf("num은 %d 입니다 \n", num); //12
	//p(num);

	//// 12 / 6은?
	//num /= 6;
	////printf("num은 %d 입니다 \n", num); //2
	//p(num);

	////함수 종류 
	////반환값이 없는 함수 (void 함수)
	//function_without_return();

	////반환값이 있는 함수 
	//int ret = function_with_return();
	//p(ret);

	////파라미터(전달값)가 없는 함수
	//function_without_params();

	////파라미터(전달값)가 있는 함수
	//function_with_params(1,2,3);

	//파라미터(전달값)도 받고, 반환값이 있는 함수
	//int ret = apple(5, 2); //5개의 사과 중 2개를 먹음 
	//printf("사과 5개 중 2개를 먹으면? %d 개가 남아요\n", ret);
	//printf("사과 %d 개 중에 %d 개를 먹으면? %d개가 남아요\n", 10, 4, apple(10, 4));

	////계산기 함수
	//int num = 2;
	//num = add(num, 3);
	//p(num);

	//num = sub(num, 1);
	//p(num);

	//num = mul(num, 3);
	//p(num);

	//num = div(num, 6);
	//p(num);

	//프로젝트 
	//문이 5개가 있고, 각 문마다 점점 어려운 수식 퀴즈가 출제, 맞히면 통과 틀리면 실패 (랜덤)

	srand(time(NULL));
	int count = 0;
	for (int i = 1; i <= 5; i++)
	{
		//x * y = ?
		int num1 = getRandomNumber(i);
		int num2 = getRandomNumber(i);
		//printf("%d x %d ?", num1, num2);
		showQuestion(i, num1, num2);

		int answer = -1;
		scanf("%d", &answer);
		if (answer == -1)
		{
			printf("프로그램을 종료합니다\n");
			exit(0); // 프로그램을 바로 끝내는 함수 
		}
		else if (answer == num1 * num2)
		{
			//성공
			success();
			count++;
		}
		else
		{
			//실패
			fail();
		}

	}

	printf("\n\n 당신은 5개의 비밀번호 중 %d 개를 맞혔습니다 \n ", count);

	return 0;
}




//정의 
void p(int num)
{
	printf("num은 %d 입니다 \n", num);
}

void function_without_return()
{
	printf("반환값이 없는 함수입니다.\n");
}

int function_with_return()
{
	printf("반환값이 있는 함수입니다.\n");
	return 10;
}

void function_without_params()
{
	printf("전달값이 없는 함수입니다.\n");
}

void function_with_params(int num1, int num2, int num3)
{
	printf("전달값이 있는 함수이며, 전달받은 값은 %d, %d, %d 입니다.\n", num1, num2, num3);
}

int apple(int total, int ate)
{
	printf("전달값과 반환값이 있는 함수입니다.\n");
	return total - ate;
}

int add(int num1, int num2)
{
	return num1 + num2;
}

int sub(int num1, int num2)
{
	return num1 - num2;
}
int mul(int num1, int num2)
{
	return num1 * num2;
}
int div(int num1, int num2)
{
	return num1 / num2;
}

int getRandomNumber(int level)
{
	return rand() % (level * 7) + 1;
}
void showQuestion(int level, int num1, int num2)
{
	printf("\n\n\n####### %d 번째 비밀번호 ######\n", level);
	printf("\n\t%d x %d 는?\n\n", num1, num2);
	printf("###############################\n");
	printf("비밀번호를 입력하세요 (종료 : -1) >>");
}
void success()
{
	printf("\n>>> Good !: 정답입니다");
}
void fail()
{
	printf("\n>>> Good !: 틀렸습니다");
}

////전달값 : 36
////함수: a + 4 
////반환형: ?
//반환형(전달값의 형태에 알맞게 적어줌 ex.int, void(아무것도 없다는 의미), double, char 등등...) 함수이름(전달값) - 전달값 앞에도 형태 변경 가능(int 전달값, float 전달값 등..)
//{
//	return(반환한다는 의미를 써서 return을 전달값 앞에 적어줌  전달값 + 4 
//}