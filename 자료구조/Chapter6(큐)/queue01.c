//�����ڷᱸ���� ť

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define SIZE 10

typedef char element;

typedef struct
{
	element que[SIZE];
	int front, rear;
}Queue;

Queue* createQ()
{
	Queue* q = (Queue*)malloc(sizeof(Queue));
	if (q == NULL)
	{
		exit(1);
	}
	q->front = -1;
	q->rear = -1;
	return q;
	
}

bool isEmpty(Queue* apq)
{
	if (apq->front == apq->rear)
	{
		printf("ť�� �����ϴ�.");
		return true;
	}
	else
	{
		return false;
	}
}

bool isFull(Queue* apq)
{
	if (apq->rear >= SIZE - 1)
	{
		printf("ť�� ��á���ϴ�.");
		return true;
	}
	else
	{
		return false;
	}
}

void enQueue(Queue* apq, element adata) //����
{
	if (isFull(apq))
	{
		return;
	}
	apq->que[++(apq->rear)] = adata; //�ʱⰪ�� -1�̹Ƿ� 
}

element deQueue(Queue* apq) //����
{
	if (isEmpty(apq))
	{
		printf("������ ����ֽ��ϴ�.");
		exit(1);
	}
	else
	{
		apq->front = (apq->front + 1);
		return apq->que[apq->front];
	}
}

element peek(Queue* apq) //deQueue ���� �� ���Ұ� �����ΰ�?
{
	if (isEmpty(apq)) //����������� ��� �Ұ���
	{
		printf("������ ����ֽ��ϴ�.");
		exit(1);
	}
	else
	{
		return apq->que[apq->front+1];
	}
}

void printQ(Queue* apq) //���
{
	//while��
	int i, first, last;
	first = apq->front + 1;
	last = apq->rear + 1;
	printf("���\n");
	i = first;
	while (i != last)
	{
		printf("%c\n", apq->que[i]);
		i++;
	}
	printf("\n");

	////for��?
	//int i, j, count = 0;
	//if (apq->front <= apq->rear)
	//{
	//	for (i = apq->front+1; i < apq->rear; i++)
	//	{
	//		printf("%c\n", apq->que[i]);
	//		count++;
	//	}
	//}
	//if (apq->front <= apq->rear)
	//{
	//	for (i = apq->front+1; i < SIZE; i++)
	//	{
	//		printf("%c\n", apq->que[i]);
	//		count++;
	//	}
	//	for (j = 0; j < apq->rear; j++)
	//	{
	//		printf("%c\n", apq->que[i]);
	//		count++;
	//	}
	//}
	//printf("\n");
}

int main()
{

	Queue* Q = createQ();
	enQueue(Q, 'A');
	enQueue(Q, 'B');
	enQueue(Q, 'C');
	enQueue(Q, 'D');

	printf("%c\n", peek(Q));
	printf("%c\n", deQueue(Q));
	printf("%c\n", deQueue(Q));
	printf("���\n");
	printQ(Q);
	

	return 0;
}