//연결리스트 큐

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define SIZE 10

typedef char element;

typedef struct node  //큐노드 생성
{
	element data;
	struct node* link;
}Node;

typedef struct  //큐 위치
{
	Node* front; //큐 노드를 가리키는 멤버
	Node* rear;

}Qlink;

//Node* front = NULL;
//Node* rear = NULL;

Qlink* createQ()
{
	Qlink* ql = (Qlink*)malloc(sizeof(Qlink));
	if (ql == NULL)
	{
		exit(1);
	}
	ql->rear = NULL;
	ql->front = NULL;

	return ql;
}

bool isEmpty(Qlink* apq)
{
	if (apq->front == NULL)
	{
		printf("스택이 비어있습니다.");
		return true;
	}
	else
	{
		return false;
	}
}

void enQueue(Qlink* apq, element adata)
{
	Node* newNode = (Node*)malloc(sizeof(Node));

	if (newNode == NULL)
	{
		return 0;
	}

	newNode->data = adata;
	newNode->link = NULL;

	if (isEmpty(apq))	//첫번째 큐연결
	{
		apq->front = newNode;
		apq->rear = newNode;
	}

	apq->rear->link = newNode;
	apq->rear = newNode;

	return;
}

element deQueue(Qlink* apq)
{
	Node* oldNode = apq->front;
	if (isEmpty(apq))
	{
		return 0;
	}
	else
	{
		element adata = apq->front->data;
		apq->front = apq->front->link;
		if (apq->front == NULL) //rear값이 front값이 null이여도 어떠한 주소값을 가지므로 이 작업을 해줘야함
		{
			apq->rear = NULL;
		}
		free(oldNode);
		return adata;
	}

	//Node* del = apq->front;
	//element d;
	//if (isEmpty(apq))
	//{
	//	return 0;
	//}
	//else
	//{
	//	d = del->data;
	//	apq->front = apq->front->link;
	//	if (apq->front == NULL) //rear값이 front값이 null이여도 어떠한 주소값을 가지므로 이 작업을 해줘야함
	//	{
	//		apq->rear = NULL;
	//	}
	//	free(del);
	//	return d;
	//}
}

void printQ(Qlink* apq)
{
	Node* curr = apq->front;
	while (curr)
	{
		printf("%c ", curr->data);
		curr = curr->link;
	}
}

int main(void)
{
	Qlink* q = createQ();

	enQueue(q, 'A');
	enQueue(q, 'B');
	enQueue(q, 'C');
	enQueue(q, 'D');
	printQ(q);

	deQueue(q);
	deQueue(q);
	deQueue(q);
	deQueue(q);


	printQ(q);

	enQueue(q, 'E'); //왜 하나만 넣으면 무한반복이 되는가?
	enQueue(q, 'F'); //두개 넣으면 정상 출력...
	printQ(q);




	return 0;
}