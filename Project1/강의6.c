#include <stdio.h>
#include<time.h>

int main(void)
{
	////배열
	//int subway_1 = 30; // 지하철 1호차에 30명이 타고 있다. 
	//int subway_2 = 40;
	//int subway_3 = 50;
	////만약 지하철 호수가 100호수(칸)까지 있다면 하나하나 하기 어렵다 따라서 배열을 이용한다. (배열은 연속해서 만들 수 있는 자료형)
	//printf("지하철 1호차에 %d 명이 타고 있습니다\n", subway_1);
	//printf("지하철 2호차에 %d 명이 타고 있습니다\n", subway_2);
	//printf("지하철 3호차에 %d 명이 타고 있습니다\n", subway_3);

	////위와 같은 3줄을 밑에처럼 한 줄로 표현 (여러 개의 변수를 함께, 동시에 생성
	//int subway_array[3]; //[0],[1],[2]
	//subway_array[0] = 30;
	//subway_array[1] = 40;
	//subway_array[2] = 50;

	//for (int i = 0; i < 3; i++)
	//{
	//	printf("지하철 %d호차에 %d 명이 타고 있습니다\n", i+1, subway_array[i]);
	//}

	// 값 설정 방법 
	/*int arr[10] = {1,2,3,4,5,6,7,8,9,10}; //초기화를 안하면 더미값이 나옴
	for (int i = 0; i < 10; i++)
	{
		printf("%d\n", arr[i]);
	}*/

	//배열크기는 항상 상수로 선언
	/*int size = 10;
	int arr[10];*/

	//int arr[10] = { 1,2 }; //3번째 값부터는 자동으로 0으로 초기화 됨
	//for (int i = 0; i < 10; i++)
	//{
		//printf("%d\n", arr[i]);
	//}

	//int arr[] = { 1, 2 }; // arr[2]와 동일한 입력값

	//float arr_f[5] = { 1.0f, 2.0f,3.0f }; //float또한 자동으로 0으로 초기화 됨 
	//for (int i = 0; i < 5; i++)
	//{
		//printf("%.2f\n", arr_f[i]);
	//}

	//문자 vs 문자열
	//char c = 'A';
	//printf("%c\n", c);

	//문자열 끝에는 '끝'을 의미하는 NULL 문자 \0 가 포함되어야 함 
	//char str[6] = "coding"; //[c] [o] [d] [i] [n] [g]
	//char str[7] = "coding";
	//printf("%s\n", str);

	//char str[] = "coding";
	//printf("%s\n", str);
	//printf("%d\n", sizeof(str));

	//for (int i = 0; i < sizeof(str); i++)
	//{
		//printf("%c\n", str[i]);
	//}

	//char kor[] = "나도코딩";
	//printf("%s\n", kor);
	//printf("%d\n", sizeof(kor));
	//영어 1글자 : 1byte
	//한글 1글자 : 2byte
	//한 글
	//En gl ish
	//char 크기: 1byte 

	//char c_array[7] = { 'c','o','d','i','n','g','\0'};
	//char c_array[6] = { 'c','o','d','i','n','g'}; //역시 마찬가지로 알수없는 문자가 나옴
	//printf("%s\n", c_array);

	//char c_array[10] = { 'c','o','d','i','n','g'};
	//printf("%s\n", c_array);
	//for (int i = 0; i < sizeof(c_array); i++)
	//{
		//printf("%c\n", c_array[i]);
	//}

	//for (int i = 0; i < sizeof(c_array); i++)
	//{
		//printf("%d\n", c_array[i]); //정수로 나타내면 아스키코드 값이 나옴 
	//}
	
	//문자열 입력받기: 경찰서 조서 쓰기 예제  
	//char name[256];
	//printf("당신의 이름은?");
	//scanf("%s", name, sizeof(name));
	//printf("%s\n", name);

	//참고 ASCII코드? ANSI (미국표준협회)에서 제시한 표준 코드 체계
	//7bit, 총 126 개 코드(0~127)
	//a 97 (문자 a의 아스키코드 정수값)
	//A 65
	//0 48
	//printf("%c\n", 'a');
	//printf("%d\n", 'a');

	//printf("%c\n", '\0');
	//printf("%d\n", '\0'); // 널은 아스키 코드값 0 

	//printf("%c\n", '0');
	//printf("%d\n", '0');

	//참고2 0~127사이의 아스키코드 정수값에 해당하는 문자 확인 
	//for (int i = 0; i <128; i++)
	//{
	//	printf("아스키코드 정수 %d : %c\n ", i, i);
	//}
	

	//아빠는 대머리 게임

	srand(time(NULL));
	printf("\n\n === 아빠는 대머리 게임 ===\n\n");
	int answer; // 사용자 입력값
	int treatment = rand() % 4; //발모제 선택(0~3)

	int cntShowBottle = 0; //이번 게임에 보여줄 병 갯수 
	int prevCntShowBottle = 0; //앞 게임에 보여준 병 갯수
	// 서로 보여주는 병 갯수를 다르게 하여 정답률 향상 (처음에 2개 -> 다음엔 3개...)

	//3번의 기회 (3번의 발모제 투여 시도)
	for (int i = 0; i <= 3; i++)
	{
		int bottle[4] = { 0,0,0,0 }; //4개의 병
		do {
			cntShowBottle = rand() % 2 + 2; //보여줄 병 갯수 (0~1, +2 -> 2, 3) 2개에서 3개를 보여줌
		} while (cntShowBottle == prevCntShowBottle); // 이번에 보여준 병 갯수와 앞에서 보여준 병 갯수가 같으면 반복
		prevCntShowBottle = cntShowBottle; //pre가 0으로 설정되어있어 비교가 0이랑 되고 있어 다음과 같이 설정

		int islncluded = 0; //보여줄 병 중에 발모제가 포함되었는지 여부 (1이면 포함)
		printf("> %d 번째 시도 : ", i);

		//보여줄 병 종류를 선택
		for (int j = 0; j < cntShowBottle; j++)
		{
			int randBottle = rand() % 4; // 0~3

			//아직 선택되지 않은 병이면, 선택 처리
			if (bottle[randBottle]==0)
			{
				bottle[randBottle] = 1;
				if (randBottle == treatment)
				{
					islncluded = 1;
				}
			}
			//이미 선택된 병이면, 중복이므로 다시 선택
			else
			{
				j--; //하지 않으면 바로 끝나버림
			}
		}
		//사용자에게 문제 표시
		for (int k = 0; k < 4; k++)
		{
			if (bottle[k] == 1)
			{
				printf("%d", k + 1); //k가 0부터 시작하기 떄문에 +1 사람들에게 표시되는건 1번째가 나아서
			}
		}
		printf("물약을 머리에 바릅니다\n\n");

		if (islncluded ==1)
		{
			printf(">>성공! 머리가 났어요 !!\n");
		}
		else
		{
			printf(">>실패! 머리가 나지 않았어요... !!\n");
		}

		printf("\n... 계속 하려면 아무키나 누르세요...");
		getchar(); // 사용자가 키를 입력할때까지 대기
	}

	printf("\n\n발모제는 몇 번일까요?");
	scanf("%d", &answer);

	if (answer == treatment + 1)
	{
		printf("\n >> 정답입니다");
	}
	else
	{
		printf("\n >> 땡! 틀렸습니다. 정답은 %d 입니다\n", treatment + 1);
	}


	return 0;
}