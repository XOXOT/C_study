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
		return 0;  // �� ����Ʈ ������ ����� ��� ������ 0�� ��ȯ
	else if(pos1->xpos == pos2->xpos)
		return 1;  //�� ����Ʈ ������ ��� xpos�� ������ 1�� ��ȯ
	else if(pos1->ypos == pos2->ypos)
		return 2;	// �� ����Ʈ ������ ��� ypos�� ������ 2�� ��ȯ
	else
		return -1; // �� ����Ʈ ������ ����� ��� �ٸ��� -1�� ��ȯ
}