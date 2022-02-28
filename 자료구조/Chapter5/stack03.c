//연결리스트로 구현된 스택
//스택은?
//(실행취소 및 되돌아가기 같은 기능)

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h> //bool 자료형을 쓰기 위한 헤더

#define STACK_SZ 10

typedef int element; //스택자료형

typedef struct node //리스트 구조체
{
	int data;
	struct node* link;
}Node;

typedef struct  //헤드 구조체
{
	Node* head;
}HStack;

HStack* createHead();
bool isEmpty(HStack*);
//bool isFull(HStack*); //연결리스트는 필요할때마다 연결을 해주면 돼서 필요가 없다.
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
	printf("삭제한 값\n");
	printf("%d\n", pop(H));
	printf("삭제 후 값들\n");
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
		printf("스택이 비어있습니다.");
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
	//방법1
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
	
	//////방법2
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
		printf("\n출력완료");
	}
	else
	{
		printf("출력 값이 없습니다.");
	}
}