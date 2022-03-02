#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
	int data;			//�����͸� ������ �������
	struct node* next; // �ڳ�� ������ ���
} Node;

//���� 

Node* insertFirstNode(Node*, int);
Node* insertLastNode(Node*, int);
Node* searchNode(Node*, int);
void printNode(Node*);
void allDelNode(Node*);
void removeNode(Node*, Node*);
//void insertNode(Node*, int, Node*, char); //������ �Ű����� �������� 

int main(void)
{
	//head->next(���������);
	//head->next->next(ù��° ���);
	//head->next = newnode->prev ?(���ο� ��带 ������ ���� �������?)

	Node* tail = NULL;

	tail = insertFirstNode(tail,10);
	tail = insertLastNode(tail, 20);
	tail = insertLastNode(tail, 30);
	tail = insertLastNode(tail, 40);
	
	printNode(tail);

	allDelNode(tail);

	return 0;
}

Node* insertFirstNode(Node* t, int d) //ù��° ��� ����
{
	//������
	Node* newNode = (Node*)malloc(sizeof(Node));
	if (newNode == NULL)
	{
		return;
	}
	newNode->data = d;
	newNode->next = NULL;

	//������ ��尡 ���� ��� (ù��° ���鼭 ������ ���)
	if (t == NULL)
	{
		t = newNode;
		newNode->next = newNode;
	}
	//ù��° ���� ���� (������ ��尡 ���� ��)
	else
	{
		newNode->next = t->next;
		t->next = newNode;
	}
	return t;
}

Node* insertLastNode(Node* t, int d)
{
	//������
	Node* newNode = (Node*)malloc(sizeof(Node));
	if (newNode == NULL)
	{
		return;
	}
	newNode->data = d;
	newNode->next = NULL;

	if (t == NULL)
	{
		t = newNode;
		newNode->next = newNode;
	}
	else
	{
		newNode->next = t->next;
		t->next = newNode;
		t = newNode;
	}
	return t;
}

void printNode(Node* t)
{
	//��� 2
	if (t == NULL)
	{
		printf("����Ʈ�� �����ϴ�.\n");
		return;
	}

	Node* cur = t->next;
	do
	{
		printf("%d\n", cur->data);
		cur = cur->next;
	} while (cur != t);
	printf("%d", cur->data); //������ ��� �� ���

}

//��ü ��� ���� (�����ؾ���)
void allDelNode(Node* h)
{
	//Node* curr = NULL;
	//while (h->next != NULL)
	//{
	//	curr = h->next;//head��� ������ �����ع����� ���� ��� �ּҸ� �� �� ���� ������
	//	h->next = NULL;

	//	printf("\n\n%d ���� �����Ǿ����ϴ�\n", curr->data);
	//	free(curr);
	//	curr = NULL;
	//}
	//printf("\n��ü ���� �Ϸ�!\n");
	//free(h);

	Node* curr = h->next;
	if (curr == h->next)
	{
		if (h->next == h->next->next)
		{
			h->next = NULL;
		}
	}
	while (h->next == NULL)
	{
		curr = h->next;//head��� ������ �����ع����� ���� ��� �ּҸ� �� �� ���� ������
		h->next = h->next->next;
		printf("\n%d ����", curr->data);
		free(curr);
		curr = NULL;
	}
	free(h);
	printf("\n��ü ���� �Ϸ�!\n");
}
