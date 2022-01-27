//문제9.문자열을 입력 받으세요.그리고 입력 받은 문자열 중에서 알파벳 대문자는 소문자로,
//소문자는 대문자로 각각 변경하여 출력하는 프로그램을 작성하세요.
//단 알파벳 이외의 문자가 존재하면 특별한 변경 없이 출력하는 것으로 합니다.
//
//문제9 실행의 예
//
//문자열 입력 : What Is Your Name ?
//wHAT iS yOUR nAME ?


#include <stdio.h>
#define len 50  //배열의 길이를 설정

int main()
{
	char str[len];
	int i;

	printf("문자열 입력 : ");
	gets(str);

	for (i = 0; i < len; i++)
	{
		if (str[i] >= 'A' && str[i] <= 'Z')  //해당 알파벳이 대문자(65~90)면 소문자로 변환
		{
			str[i] = str[i] + 32;
		}
		else if (str[i] >= 'a' && str[i] <= 'z') //해당 알파벳이 소문자(97~122)면 대문자로 변환
		{
			str[i] = str[i] - 32;
		}
	}
	printf("대소문자 변경 결과 : %s\n", str);

	return 0;
}