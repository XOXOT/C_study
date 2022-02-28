//���Ḯ��Ʈ ť

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define SIZE 10

typedef char element;

typedef struct node  //ť��� ����
{
	element data;
	struct node* link;
}Node;

typedef struct  //ť ��ġ
{
	Node* front; //ť ��带 ����Ű�� ���
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
		printf("������ ����ֽ��ϴ�.");
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

	if (isEmpty(apq))	//ù��° ť����
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
		if (apq->front == NULL) //rear���� front���� null�̿��� ��� �ּҰ��� �����Ƿ� �� �۾��� �������
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
	//	if (apq->front == NULL) //rear���� front���� null�̿��� ��� �ּҰ��� �����Ƿ� �� �۾��� �������
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

	enQueue(q, 'E'); //�� �ϳ��� ������ ���ѹݺ��� �Ǵ°�?
	enQueue(q, 'F'); //�ΰ� ������ ���� ���...
	printQ(q);




	return 0;
}