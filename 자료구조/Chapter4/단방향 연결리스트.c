#include <stdio.h>
#include <stdlib.h>


typedef struct _node
{
	int data;			//�����͸� ������ �������
	struct _node* next; // ����ּҸ� ������ ����Ʈ ��� ����
} Node;

//����
void pre_insertNode(Node* h, int d);
void rear_insertNode(Node* h, int d);
void printNode(Node* h);
void freeNode(Node* h);
Node *searchNode(Node* h, int data);
void deleteNode(Node* h, Node*p);

int main(void)
{
	Node* head = (Node*)malloc(sizeof(Node));
	if (head == NULL)
	{
		return;
	}

	head->next = NULL; //head->next �� �ʱ�ȭ
	pre_insertNode(head,10);
	rear_insertNode(head,30);

	printNode(head);
	searchNode(head, 20);
	searchNode(head, 30);

	deleteNode(head, 30);

	freeNode(head);


	return 0;
}

//�׻� ù��° ��带 �߰��ϴ� �Լ� (�������Գ��)
void pre_insertNode(Node* h, int d)
{
	Node* newNode = (Node*)malloc(sizeof(Node));
	if (newNode == NULL)
	{
		return;
	}
	newNode->data = d; //������ �����͸� ����ִ´�.
	newNode->next = h->next; //�ι�° ��带 ����Ű�� �Ѵ�. 
	h->next = newNode; //��� ���� �׻� ù ��° ��带 ����Ű�� �Ѵ�. 
}

//ù��° ���� ��带 �߰��ϴ� �Լ� (�������Գ��)
void rear_insertNode(Node* h, int d)
{
	Node* newNode = (Node*)malloc(sizeof(Node));
	Node* cur = h->next;
	if (newNode == NULL)
	{
		return;
	}
	newNode->data = d;
	newNode->next = NULL;
	//printf("%d", newNode->data);
	if (cur == NULL) 
	{
		h->next = newNode; //���� ������� �ʾ��� ���
	}
	else
	{
		while (cur->next != NULL)
		{
			cur = cur->next;
		} //�� �ݺ����� ������ ������ ��带 ã�� ����
		cur->next = newNode; //�� ������ �� ���� ���ο� ��带 ����
	}
}

//������ ��� �Լ�
void printNode(Node* h)
{
	Node* cur = h->next;
	while (cur != NULL)
	{
		printf("%d\n", cur->data);
		cur = cur->next;
	}
}

//������ ���� (���������Լ�)
void freeNode(Node* h)
{
	//Node* curr;
	////��� 1
	//curr = h; //head��� ������ �����ع����� ���� ��� �ּҸ� �� �� ���� ������ ���� ���� 
	//while (curr != NULL)
	//{
	//	Node* nc;
	//	nc = curr->next;
	//	free(curr);
	//	curr = nc;
	//}
	////��� 2
	//while (h->next == NULL)
	//{
	//	curr = h->next;//head��� ������ �����ع����� ���� ��� �ּҸ� �� �� ���� ������
	//	h->next = h->next->next;
	//	free(curr);
	//	curr = NULL;
	//}
	//free(h);

	//��� 3
	Node* target = h; //������ ����� �ּҸ� �����ϴ� ����
	Node* temp = target; //������ ����� ���� ��� �ּ�
	while (target != NULL) //
	{
		temp = temp->next; //�����ϱ� �� temp ������ ���� ��� �ּҸ� �̸� ����
		free(target);
		target = temp;// �����ϱ� ���� ������ temp ������ �ٽ� target�� �����ϰ� �ݺ�
	}
	
}

Node* searchNode(Node* h, int data)
{
	Node* curr = h->next;
	while (curr!=NULL)
	{
		if (curr->data == data)
		{
			printf("ã���ô� �� %d�� �ֽ��ϴ�.\n", curr->data);
			return curr;
		}
		curr = curr->next;
	}
	printf("ã���ô� ���� �����ϴ�.\n");
	return NULL;
}

void deleteNode(Node* h, Node *p)
{
	//printf("%d�� �����մϴ�.", p->data);

	Node* curr = h->next;
	if (curr == p) //ù��° ����� ���
	{
		h->next = p->next; //�ι�° ��带 ù��° ���� ����
	}
	else //�ι�° ����� ���
	{
		while (curr->next != p) 
		{
			curr = curr->next; // �� ����� next �ʵ尡 ���� ��������� ã�´�.
		}
		curr->next = p->next; // ������ ����� ������带 ���� ����� next�� ����
 	}
	free(p); //������ ��� ����

	printNode(h);

	printf("ã���ô� ���� �����߽��ϴ�.\n");

}

//�߰���� ����
void insertNode(Node* h, Node* p)
{
	h->next = p;
	p->next = h->next;
}