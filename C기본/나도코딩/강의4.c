#include <time.h> //컴퓨터한테 랜덤한 숫자를 가져올 때 쓰는 라이브러리
#include <stdlib.h> //컴퓨터 환경에 따라 없어도 되지만 혹시 몰라 쓰는 라이브러리
#include <stdio.h>

int main(void)
{
	////srand(time(NULL));; //난수 초기화 방법 
	////int num = rand() % 3; //0 ~2 중(세 가지)에 하나를 뽑아라 만약 1부터 뽑길 원한다면 3+1로 입력 

	//printf("난수 초기화 이전..\n");
	//for (int i = 0; i < 10; i++)
	//{
	//	printf("%d", rand() % 10);
	//}

	//srand(time(NULL));; //난수 초기화
	//printf("\n난수 초기화 후..\n");
	//for (int i = 0; i < 10; i++)
	//{
	//	printf("%d", rand() % 10);
	//}

	//가위 바위 보 

	////가위 바위 보
	//srand(time(NULL)); //난수 초기화
	//int i = rand() % 3; // 0 ~ 2 반환

	////일반 방식
	//if (i == 0)
	//{
	//	printf("가위\n");
	//}
	//else if (i == 1)
	//{
	//	printf("바위\n");
	//}
	//else if (i == 3)
	//{
	//	printf("보\n");
	//}
	//else
	//	printf("몰라요\n");

	////switch case 함수 방식 break 필수로 넣어야함 default는 else와 같음 
	//switch (i)
	//{
	//case 0: printf("가위\n"); break;
	//case 1: printf("바위\n"); break;
	//case 2: printf("보\n"); break;
	//default:printf("몰라요\n"); break;
	//}

	//switch case의 원리
	// 
	//초등학생(8~13) / 중학생(1~16) / 고등학생(17~19)으로 나누면? 강의 3에서 봤던 예시를 통해 본 switch case 
	
	//int age = 25;
	//switch (age)
	//{
	//case 8:
	//case 9:
	//case 10:
	//case 11:
	//case 12:
	//case 13: printf("초등학생 입니다\n"); break;
	//case 14:
	//case 15:
	//case 16: printf("중학생 입니다\n"); break;
	//case 17:
	//case 18:
	//case 19: printf("고등학생 입니다\n"); break;
	//default: printf("학생이 아닌가봐요\n"); break;
	//}
	//만약 8~13 이렇게 같이 초등학생입니다를 출력하고 싶다면 굳이 8~12까지 프린트문을 적지 않아도 자동으로 브레이크 문까지 내려온다 

	//UP AND DOWN 
	srand(time(NULL));
	int num = rand() % 100 + 1; //1~100 사이의 숫자
	printf("숫자: %d\n",num);
	int answer = 0; //정답
	int chance = 5; // 기회는 총 5번
	while (chance > 0) // while (1)로 해도 무방 1은 참 0은 거짓 
	{
		printf("남은 기회 %d 번\n", chance--);
		printf("숫자를 맞혀보세요(1~100) : ");
		scanf("%d", &answer);

		if (answer > num)
		{
			printf("DOWN ↓ \n\n");
		}
		else if (answer < num)
		{
			printf("UP ↑ \n\n");
		}
		else if(answer == num)
		{
			printf("정답입니다. \n\n");
			break;
		}
		else
		{
			printf("알 수 없는 오류가 발생했습니다. \n\n"); //혹시 모를 오류 대비
		}
		if (chance == 0)
		{
			printf("모든 기회를 다 사용하셨네요. 아쉽게 실패했습니다. \n\n");
			break;
		}
	}

	return 0;
}
