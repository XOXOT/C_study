#ifndef __POINT_H__
#define __POINT_H__

typedef struct _point
{
	int xpos;   //x좌표 정보
	int ypos;   //y좌표 정보
} Point;

// Point 변수의 xpos, ypos 값 설정
void SetPointPos(Point * ppos, int xpos, int ypos); //값을 저장

// Point 변수의 xpos, ypos 정보 출력 
void ShowPointPos(Point * ppos); //정보 출력

// 두 Point 변수의 비교
int PointComp(Point * pos1, Point * pos2);  //비교

#endif