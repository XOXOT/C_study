#include <stdio.h>
#include <stdlib.h>

typedef struct dnode
{
	int data;			//데이터를 저장할 멤버변수
	struct dnode* next; // 뒤노드 연결할 멤버
	struct dnode* prev;  // 앞노드 연결할 멤버

} Dnode;

//선언
void insertNode(Dnode*, int, Dnode*, char); //선언은 매개변수 생략가능  
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
	Dnode* pos = NULL;         //기준 노드, 검색노드의 주소를 저장

	//순차적으로 대입
	insertNode(head, 10, pos, 'n');
	pos = searchNode(head, 10);
	insertNode(head, 20, pos, 'n');
	pos = searchNode(head, 20);
	insertNode(head, 30, pos, 'n');
	pos = searchNode(head, 10);

	printNode(head);

	printf("\n마지막 pos 값이 삭제 후\n");

	removeNode(head, pos);

	printNode(head);

	printf("\n전체 값 삭제\n");
	allDelNode(head);


	return 0;
}

//노드생성 및 초기화
void insertNode(Dnode* h, int d, Dnode* p, char opt)
{
	//노드생성
	Dnode* newNode = (Dnode*)malloc(sizeof(Dnode));
	if (newNode == NULL)
	{
		return;
	}
	newNode->data = d;
	newNode->next = NULL;
	newNode->prev = NULL;

	if (p == NULL)				//첫번째 노드를 삽입
	{
		newNode->next = h->next; //두번째 노드를 가리키게 한다. 

		if (h->next != NULL)
		{
			newNode->next->prev = newNode;
		}
		h->next = newNode; //헤더 노드는 항상 첫 번째 노드를 가리키게 한다. 
	}
	else      //원하는 위치로 삽입
	{
		Dnode* curr = h->next;
		while (curr != p)
		{
			curr = curr->next;
		}

		if (opt =='p')			//전위 삽입 (pre)
		{
			newNode->prev = curr->prev;
			newNode->next = curr;
			newNode->prev->next = newNode;
			curr->prev = newNode;
		}

		if(opt == 'n')		//후위 삽입 (next)
		{
			newNode->prev = curr;
			newNode->next = curr->next;
			if (curr->next != NULL)  //마지막 노드가 아닌 경우
			{
				curr->next->prev = newNode; //새로운 노드(newnode->next)의 prev
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
//전체 노드 프린트
void printNode(Dnode* h)
{
	Dnode* cur = h->next;
	if (cur == NULL)
	{
		printf("리스트가 없습니다.\n");
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
//전체 노드 삭제
void allDelNode(Dnode* h)
{
	//방법 1
	//Dnode* target = h; //해제할 노드의 주소를 저장하는 변수
	//Dnode* temp = target; //해제할 노드의 다음 노드 주소
	//while (target != NULL) //
	//{
	//	temp = temp->next; //해제하기 전 temp 변수에 다음 노드 주소를 미리 저장
	//	printf("\n%d 삭제\n", temp->data);
	//	free(target);
	//	target = temp;// 해제하기 전에 저장한 temp 변수를 다시 target에 저장하고 반복
	//}
	//free(h);

	//방법 2
	Dnode* curr = NULL;
	while (h->next != NULL)
	{
		curr = h->next;//head노드 공간을 해제해버리면 다음 노드 주소를 알 수 없기 때문에
		h->next = h->next->next;
		printf("\n%d 값이 삭제되었습니다\n", curr->data);
		free(curr);
		curr = NULL;
	}
	free(h);
	printf("\n전체 삭제 완료!\n");
}
//노드 검색
Dnode* searchNode(Dnode* h, int data)
{
	Dnode* curr = h->next;
	while (curr != NULL)
	{
		if (curr->data == data)
		{
			//printf("찾으시는 값 %d이 있습니다.\n", curr->data);
			return curr;
		}
		else
		{
			curr = curr->next;
		}
	}
	//printf("찾으시는 값 %d은 없습니다.\n", data);
	return NULL;
}
//선택 노드 삭제
void removeNode(Dnode* h, Dnode* p)
{
	//printf("%d를 삭제합니다.", p->data);

	Dnode* curr = h->next;
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
	//printNode(h);

	printf("\n입력하신 %d을 삭제했습니다.\n",p->data);
	free(p); //삭제할 노드 해제
}