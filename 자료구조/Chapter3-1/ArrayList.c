#include <stdio.h>
#include "ArrayList.h"

void ListInit(List * plist) //List 주소값 전달 - 초기화 함수(init가 있다면 일반적으로 초기화라는 뜻)
{
	(plist->numOfData) = 0; //저장된 데이터 수를 0으로 초기화
	(plist->curPosition) = -1; 
}

void LInsert(List * plist, LData data)
{
	if(plist->numOfData > LIST_LEN) 
	{
		puts("저장이 불가능합니다.");
		return;
	}

	plist->arr[plist->numOfData] = data; //plist의 arr을 불러오고 값은 초기화 시킨 numOfData를 불러오면 그것에 data 값을 넣어라 == arr[0]=11
	(plist->numOfData)++; //==arr[1]
}

int LFirst(List * plist, LData * pdata)
{
	if(plist->numOfData == 0)
		return FALSE;

	(plist->curPosition) = 0;
	*pdata = plist->arr[0];
	return TRUE;
}

int LNext(List * plist, LData * pdata)
{
	if(plist->curPosition >= (plist->numOfData)-1)
		return FALSE;

	(plist->curPosition)++;
	*pdata = plist->arr[plist->curPosition];
	return TRUE;
}

LData LRemove(List * plist)
{
	int rpos = plist->curPosition;
	int num = plist->numOfData;
	int i;
	LData rdata = plist->arr[rpos];

	for(i=rpos; i<num-1; i++)
		plist->arr[i] = plist->arr[i+1];

	(plist->numOfData)--;
	(plist->curPosition)--;
	return rdata;
}

int LCount(List * plist)
{
	return plist->numOfData;
}