#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
	int data;			//데이터를 저장할 멤버변수
	struct node* next; // 뒤노드 연결할 멤버
} Node;

//선언 

Node* insertFirstNode(Node*, int);
Node* insertLastNode(Node*, int);
Node* searchNode(Node*, int);
void printNode(Node*);
void allDelNode(Node*);
void removeNode(Node*, Node*);
//void insertNode(Node*, int, Node*, char); //선언은 매개변수 생략가능 

int main(void)
{
	//head->next(마지막노드);
	//head->next->next(첫번째 노드);
	//head->next = newnode->prev ?(새로운 노드를 마지막 노드로 만들려면?)

	Node* tail = NULL;

	tail = insertFirstNode(tail,10);
	tail = insertLastNode(tail, 20);
	tail = insertLastNode(tail, 30);
	tail = insertLastNode(tail, 40);
	
	printNode(tail);

	allDelNode(tail);

	return 0;
}

Node* insertFirstNode(Node* t, int d) //첫번째 노드 생성
{
	//노드생성
	Node* newNode = (Node*)malloc(sizeof(Node));
	if (newNode == NULL)
	{
		return;
	}
	newNode->data = d;
	newNode->next = NULL;

	//생성된 노드가 없는 경우 (첫번째 노드면서 마지막 노드)
	if (t == NULL)
	{
		t = newNode;
		newNode->next = newNode;
	}
	//첫번째 노드로 생성 (생성된 노드가 있을 때)
	else
	{
		newNode->next = t->next;
		t->next = newNode;
	}
	return t;
}

Node* insertLastNode(Node* t, int d)
{
	//노드생성
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
	//방법 2
	if (t == NULL)
	{
		printf("리스트가 없습니다.\n");
		return;
	}

	Node* cur = t->next;
	do
	{
		printf("%d\n", cur->data);
		cur = cur->next;
	} while (cur != t);
	printf("%d", cur->data); //마지막 노드 값 출력

}

//전체 노드 삭제 (수정해야함)
void allDelNode(Node* h)
{
	//Node* curr = NULL;
	//while (h->next != NULL)
	//{
	//	curr = h->next;//head노드 공간을 해제해버리면 다음 노드 주소를 알 수 없기 때문에
	//	h->next = NULL;

	//	printf("\n\n%d 값이 삭제되었습니다\n", curr->data);
	//	free(curr);
	//	curr = NULL;
	//}
	//printf("\n전체 삭제 완료!\n");
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
		curr = h->next;//head노드 공간을 해제해버리면 다음 노드 주소를 알 수 없기 때문에
		h->next = h->next->next;
		printf("\n%d 삭제", curr->data);
		free(curr);
		curr = NULL;
	}
	free(h);
	printf("\n전체 삭제 완료!\n");
}
