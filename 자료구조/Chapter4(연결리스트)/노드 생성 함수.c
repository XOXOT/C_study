#include <stdio.h>
#include <stdlib.h>


typedef struct _node
{
	int data;			//�����͸� ������ �������
	struct _node* next; // ����ּҸ� ������ ����Ʈ ��� ����
} Node;

void addNode(Node *p, int d);
void printNode(Node *h);

int main(void)
{
	Node* head = (Node*)malloc(sizeof(Node));		//�����Ҵ�

	//���� head�� �Ҵ��� ���������� ����Ͽ� if�� ����
	if (head == NULL)
	{
		return;
	}

	head->next = NULL; //�׻� ó���� ����Ű�� ��� ��带 ����

	addNode(head, 10);
	addNode(head, 20);
	printNode(head);

	return 0;
}

//��� �߰� �Լ�
void addNode(Node* h, int d) //�׻� ù��° ��带 �߰��ϴ� �Լ�
{
	Node* newNode = (Node*)malloc(sizeof(Node));

	if (newNode == NULL)
	{
		return;
	}
	newNode->data = d;	//������ �����͸� ����ִ´�.
	newNode->next = h->next; //�ι�° ��带 ����Ű�� �Ѵ�. 
	h->next = newNode; //��� ���� �׻� ù ��° ��带 ����Ű�� �Ѵ�. 
}

//������ ��� �Լ�
void printNode(Node* h)
{
	Node* cur = h->next;
	while (cur!=NULL)
	{
		printf("%d\n",cur->data);
		cur = cur->next;
	}
}