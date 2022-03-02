//순차자료구조의 큐

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
		printf("큐가 없습니다.");
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
		printf("큐가 꽉찼습니다.");
		return true;
	}
	else
	{
		return false;
	}
}

void enQueue(Queue* apq, element adata) //삽입
{
	if (isFull(apq))
	{
		return;
	}
	apq->que[++(apq->rear)] = adata; //초기값이 -1이므로 
}

element deQueue(Queue* apq) //삭제
{
	if (isEmpty(apq))
	{
		printf("스택이 비어있습니다.");
		exit(1);
	}
	else
	{
		apq->front = (apq->front + 1);
		return apq->que[apq->front];
	}
}

element peek(Queue* apq) //deQueue 했을 때 원소가 무엇인가?
{
	if (isEmpty(apq)) //비워져있으면 출력 불가능
	{
		printf("스택이 비어있습니다.");
		exit(1);
	}
	else
	{
		return apq->que[apq->front+1];
	}
}

void printQ(Queue* apq) //출력
{
	//while문
	int i, first, last;
	first = apq->front + 1;
	last = apq->rear + 1;
	printf("출력\n");
	i = first;
	while (i != last)
	{
		printf("%c\n", apq->que[i]);
		i++;
	}
	printf("\n");

	////for문?
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
	printf("출력\n");
	printQ(Q);
	

	return 0;
}