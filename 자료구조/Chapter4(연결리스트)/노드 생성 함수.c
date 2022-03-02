#include <stdio.h>
#include <stdlib.h>


typedef struct _node
{
	int data;			//데이터를 저장할 멤버변수
	struct _node* next; // 노드주소를 저장할 포인트 멤버 변수
} Node;

void addNode(Node *p, int d);
void printNode(Node *h);

int main(void)
{
	Node* head = (Node*)malloc(sizeof(Node));		//동적할당

	//만약 head가 할당을 못받을때를 대비하여 if문 생성
	if (head == NULL)
	{
		return;
	}

	head->next = NULL; //항상 처음을 가르키는 헤더 노드를 생성

	addNode(head, 10);
	addNode(head, 20);
	printNode(head);

	return 0;
}

//노드 추가 함수
void addNode(Node* h, int d) //항상 첫번째 노드를 추가하는 함수
{
	Node* newNode = (Node*)malloc(sizeof(Node));

	if (newNode == NULL)
	{
		return;
	}
	newNode->data = d;	//정수형 데이터를 집어넣는다.
	newNode->next = h->next; //두번째 노드를 가리키게 한다. 
	h->next = newNode; //헤더 노드는 항상 첫 번째 노드를 가리키게 한다. 
}

//데이터 출력 함수
void printNode(Node* h)
{
	Node* cur = h->next;
	while (cur!=NULL)
	{
		printf("%d\n",cur->data);
		cur = cur->next;
	}
}