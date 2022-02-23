#include <stdio.h>
#include "Point.h"

void SetPointPos(Point * ppos, int xpos, int ypos)
{
	ppos->xpos = xpos;
	ppos->ypos = ypos;
}

void ShowPointPos(Point * ppos)
{
	printf("[%d, %d] \n", ppos->xpos, ppos->ypos);
}

int PointComp(Point * pos1, Point * pos2)
{
	if(pos1->xpos == pos2->xpos && pos1->ypos == pos2->ypos)
		return 0;  // 두 포인트 변수의 멤버가 모두 같으면 0을 반환
	else if(pos1->xpos == pos2->xpos)
		return 1;  //두 포인트 변수의 멤버 xpos만 같으면 1을 반환
	else if(pos1->ypos == pos2->ypos)
		return 2;	// 두 포인트 변수의 멤버 ypos만 같으면 2를 반환
	else
		return -1; // 두 포인트 변수의 멤버가 모두 다르면 -1을 반환
}