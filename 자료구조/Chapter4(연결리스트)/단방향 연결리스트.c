#include <stdio.h>
#include <stdlib.h>


typedef struct _node
{
	int data;			//데이터를 저장할 멤버변수
	struct _node* next; // 노드주소를 저장할 포인트 멤버 변수
} Node;

//선언
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

	Node* search = (Node*)malloc(sizeof(Node));
	if (head != NULL)
	{
		head->next = NULL; //head->next 값 초기화;
	}

	pre_insertNode(head,10);
	//rear_insertNode(head,10);
	rear_insertNode(head, 20);
	rear_insertNode(head, 30);

	printNode(head);
	searchNode(head, 20);
	searchNode(head, 30);

	printf("\n삭제 후\n");
	search = searchNode(head, 20);
	deleteNode(head, search);

	freeNode(head);


	return 0;
}

//항상 첫번째 노드를 추가하는 함수 (전위삽입노드)
void pre_insertNode(Node* h, int d)
{
	Node* newNode = (Node*)malloc(sizeof(Node));
	if (newNode == NULL)
	{
		return;
	}
	newNode->data = d; //정수형 데이터를 집어넣는다.
	newNode->next = h->next; //두번째 노드를 가리키게 한다. 
	h->next = newNode; //헤더 노드는 항상 첫 번째 노드를 가리키게 한다. 
}

//첫번째 이후 노드를 추가하는 함수 (후위삽입노드)
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
		h->next = newNode; //만약 연결되지 않았을 경우
	}
	else
	{
		while (cur->next != NULL)
		{
			cur = cur->next;
		} //이 반복문을 끝내면 마지막 노드를 찾고 나면
		cur->next = newNode; //그 마지막 널 값에 새로운 노드를 생성
	}
}

//데이터 출력 함수
void printNode(Node* h)
{
	Node* cur = h->next;
	while (cur != NULL)
	{
		printf("%d\n", cur->data);
		cur = cur->next;
	}
}

//데이터 프리 (동적해제함수)
void freeNode(Node* h)
{
	Node* curr;

	////방법 1
	//curr = h; //head노드 공간을 해제해버리면 다음 노드 주소를 알 수 없기 때문에 변수 저장 
	//while (curr != NULL)
	//{
	//	Node* nc;
	//	nc = curr->next;
	//	free(curr);
	//	curr = nc;
	//}
	//방법 2
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

	////방법 3
	//Node* target = h; //해제할 노드의 주소를 저장하는 변수
	//Node* temp = target; //해제할 노드의 다음 노드 주소
	//while (target != NULL) //
	//{
	//	temp = temp->next; //해제하기 전 temp 변수에 다음 노드 주소를 미리 저장
	//	printf("\n%d 삭제", temp->data);
	//	free(target);
	//	target = temp;// 해제하기 전에 저장한 temp 변수를 다시 target에 저장하고 반복
	//}
	
}

Node* searchNode(Node* h, int data)
{
	Node* curr = h->next;
	while (curr!=NULL)
	{
		if (curr->data == data)
		{
			printf("찾으시는 값 %d이 있습니다.\n", curr->data);
			return curr;
		}
		curr = curr->next;
	}
	printf("찾으시는 값은 없습니다.\n");
	return NULL;
}

void deleteNode(Node* h, Node *p)
{
	//printf("%d를 삭제합니다.", p->data);

	Node* curr = h->next;
	if (curr == p) //첫번째 노드인 경우
	{
		h->next = p->next; //두번째 노드를 첫번째 노드로 연결
	}
	else //두번째 노드인 경우
	{
		while (curr->next != p) 
		{
			curr = curr->next; // 현 노드의 next 필드가 삭제 노드인지를 찾는다.
		}
		curr->next = p->next; // 삭제할 노드의 다음노드를 현재 노드의 next에 연결
 	}
	printNode(h);

	printf("찾으시는 값을 삭제했습니다.\n");
	free(p); //삭제할 노드 해제

}

//중간노드 삽입
void insertNode(Node* h, Node* p)
{
	h->next = p;
	p->next = h->next;
}