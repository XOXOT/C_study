//���Ḯ��Ʈ�� ������ ����
//������?
//(������� �� �ǵ��ư��� ���� ���)

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h> //bool �ڷ����� ���� ���� ���

#define STACK_SZ 10

typedef int element; //�����ڷ���

typedef struct node //����Ʈ ����ü
{
	int data;
	struct node* link;
}Node;

typedef struct  //��� ����ü
{
	Node* head;
}HStack;

HStack* createHead();
bool isEmpty(HStack*);
//bool isFull(HStack*); //���Ḯ��Ʈ�� �ʿ��Ҷ����� ������ ���ָ� �ż� �ʿ䰡 ����.
void push(HStack*, element);
element pop(HStack*);
element peek(HStack*);
void printstack(HStack* ahead);

int main(void)
{
	HStack* H = createHead();
	push(H, 10);
	push(H, 20);
	push(H, 30);
	push(H, 40);
	printf("������ ��\n");
	printf("%d\n", pop(H));
	printf("���� �� ����\n");
	printstack(H);

	return 0;
}

HStack* createHead()
{
	HStack* h = (HStack*)malloc(sizeof(HStack));
	if (h == NULL)
	{
		exit(1);
	}
	h->head = NULL;
	return h;
}

bool isEmpty(HStack* ahead)
{
	if (ahead->head == NULL)
	{
		printf("������ ����ֽ��ϴ�.");
		return true;
	}
	else
	{
		return false;
	}
}

void push(HStack* ahead, element value)
{
	Node* newNode = (Node*)malloc(sizeof(Node));

	if (newNode == NULL)
	{
		return;
	}

	newNode->data = value;	
	newNode->link = ahead->head;
	ahead->head = newNode;
}

element pop(HStack* ahead)
{
	//���1
	if (!isEmpty(ahead))
	{
		Node* temp = ahead->head;
		char data = temp->data;
		ahead->head = temp->link;
		free(temp);
		return data;
	}
	else
	{
		printf("underflow!!");
		exit(1);
	}
	
	//////���2
	//element d;
	//Node* curr;
	//if (isEmpty(ahead))
	//{
	//	printf("underflow!!");
	//	exit(1);
	//}
	//else
	//{
	//	d = ahead->head->data;
	//	curr = ahead->head;
	//	ahead->head = ahead->head->link;
	//	free(curr);
	//	return d;
	//}

}

element peek(HStack* ahead)
{
	if (!isEmpty(ahead))
	{
		return ahead->head->data;
	}
}

void printstack(HStack* ahead)
{
	if (!isEmpty(ahead))
	{
		Node* temp = ahead->head;
		while (temp)
		{
			printf("%d\n", temp->data);
			temp = temp->link;
		}
		printf("\n��¿Ϸ�");
	}
	else
	{
		printf("��� ���� �����ϴ�.");
	}
}