#ifndef __ARRAY_LIST_H__  //중복으로 헤더를 집어넣어도 상관없게 해주는 코드(컴파일이 똑똑해져서 없어도 중복 처리 안됨)  #ifdef 해더명 \n #define 헤더명 ~ #endif 사이의 헤더값을 집어 넣게 해줌
#define __ARRAY_LIST_H__

#define TRUE	1 // '참'을 표현하기 위한 매크로 정의
#define FALSE	0 //'거짓'을 표현하기 위한 매크로 정의

/*** ArrayList의 정의 ****/
#define LIST_LEN	100 //배열의 길이 고정
typedef int LData; //LData에 대한 typedef 선언 (int 자체를 LData로 선언한 것)

typedef struct __ArrayList  //배열기반 리스트를 정의한 구조체
{
	LData arr[LIST_LEN];    //리스트의 저장소인 배열  == int arr[100]
	int numOfData;			// 저장된 데이터의 수
	int curPosition;		// 데이터 참조위치를 기록
} ArrayList;


/*** ArrayList와 관련된 연산들 ****/
typedef ArrayList List;	// ArrayList 구조체를 한번 더 List로 정의

void ListInit(List * plist);						// 초기화
void LInsert(List * plist, LData data);				// 데이터 저장

int LFirst(List * plist, LData * pdata);			// 첫 데이터 참조
int LNext(List * plist, LData * pdata);				// 두 번째 이후 데이터 참조

LData LRemove(List * plist);						// 참조한 데이터 삭제
int LCount(List * plist);							// 저장된 데이터의 수 반환

#endif