#include <stdio.h>
#include <stdlib.h>

typedef struct dnode
{
	int data;			//�����͸� ������ �������
	struct dnode* next; // �ڳ�� ������ ���
	struct dnode* prev;  // �ճ�� ������ ���

} Dnode;

//����
void insertNode(Dnode*, int, Dnode*, char); //������ �Ű����� ��������  
void printNode(Dnode*);
void allDelNode(Dnode*);
Dnode* searchNode(Dnode*, int);
void removeNode(Dnode*, Dnode*);

int main(void)
{
	Dnode* head = (Dnode*)malloc(sizeof(Dnode));
	if (head == NULL)
	{
		exit(1);
	}

	head->next = NULL;
	head->prev = NULL;
	Dnode* pos = NULL;         //���� ���, �˻������ �ּҸ� ����

	//���������� ����
	insertNode(head, 10, pos, 'n');
	pos = searchNode(head, 10);
	insertNode(head, 20, pos, 'n');
	pos = searchNode(head, 20);
	insertNode(head, 30, pos, 'n');
	pos = searchNode(head, 10);

	printNode(head);

	printf("\n������ pos ���� ���� ��\n");

	removeNode(head, pos);

	printNode(head);

	printf("\n��ü �� ����\n");
	allDelNode(head);


	return 0;
}

//������ �� �ʱ�ȭ
void insertNode(Dnode* h, int d, Dnode* p, char opt)
{
	//������
	Dnode* newNode = (Dnode*)malloc(sizeof(Dnode));
	if (newNode == NULL)
	{
		return;
	}
	newNode->data = d;
	newNode->next = NULL;
	newNode->prev = NULL;

	if (p == NULL)				//ù��° ��带 ����
	{
		newNode->next = h->next; //�ι�° ��带 ����Ű�� �Ѵ�. 

		if (h->next != NULL)
		{
			newNode->next->prev = newNode;
		}
		h->next = newNode; //��� ���� �׻� ù ��° ��带 ����Ű�� �Ѵ�. 
	}
	else      //���ϴ� ��ġ�� ����
	{
		Dnode* curr = h->next;
		while (curr != p)
		{
			curr = curr->next;
		}

		if (opt =='p')			//���� ���� (pre)
		{
			newNode->prev = curr->prev;
			newNode->next = curr;
			newNode->prev->next = newNode;
			curr->prev = newNode;
		}

		if(opt == 'n')		//���� ���� (next)
		{
			newNode->prev = curr;
			newNode->next = curr->next;
			if (curr->next != NULL)  //������ ��尡 �ƴ� ���
			{
				curr->next->prev = newNode; //���ο� ���(newnode->next)�� prev
			}
			curr->next = newNode;
			//p->prev = h;
			//p->next = h->next;
			//if (h->next != NULL)
			//{
			//	h->next->prev = p;
			//	h->next = p;
			//}
		}
	}

}
//��ü ��� ����Ʈ
void printNode(Dnode* h)
{
	Dnode* cur = h->next;
	if (cur == NULL)
	{
		printf("����Ʈ�� �����ϴ�.\n");
	}
	else 
	{
		while (cur != NULL)
		{
			printf("%d\n", cur->data);
			cur = cur->next;
		}
	}
}
//��ü ��� ����
void allDelNode(Dnode* h)
{
	//��� 1
	//Dnode* target = h; //������ ����� �ּҸ� �����ϴ� ����
	//Dnode* temp = target; //������ ����� ���� ��� �ּ�
	//while (target != NULL) //
	//{
	//	temp = temp->next; //�����ϱ� �� temp ������ ���� ��� �ּҸ� �̸� ����
	//	printf("\n%d ����\n", temp->data);
	//	free(target);
	//	target = temp;// �����ϱ� ���� ������ temp ������ �ٽ� target�� �����ϰ� �ݺ�
	//}
	//free(h);

	//��� 2
	Dnode* curr = NULL;
	while (h->next != NULL)
	{
		curr = h->next;//head��� ������ �����ع����� ���� ��� �ּҸ� �� �� ���� ������
		h->next = h->next->next;
		printf("\n%d ���� �����Ǿ����ϴ�\n", curr->data);
		free(curr);
		curr = NULL;
	}
	free(h);
	printf("\n��ü ���� �Ϸ�!\n");
}
//��� �˻�
Dnode* searchNode(Dnode* h, int data)
{
	Dnode* curr = h->next;
	while (curr != NULL)
	{
		if (curr->data == data)
		{
			//printf("ã���ô� �� %d�� �ֽ��ϴ�.\n", curr->data);
			return curr;
		}
		else
		{
			curr = curr->next;
		}
	}
	//printf("ã���ô� �� %d�� �����ϴ�.\n", data);
	return NULL;
}
//���� ��� ����
void removeNode(Dnode* h, Dnode* p)
{
	//printf("%d�� �����մϴ�.", p->data);

	Dnode* curr = h->next;
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
	//printNode(h);

	printf("\n�Է��Ͻ� %d�� �����߽��ϴ�.\n",p->data);
	free(p); //������ ��� ����
}