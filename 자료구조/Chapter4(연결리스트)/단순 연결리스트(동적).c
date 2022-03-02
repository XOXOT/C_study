//단순 연결리스트(동적)

#include <stdio.h>
#include <stdlib.h>

typedef struct _node
{
	int data;			//데이터를 저장할 멤버변수
	struct _node* next; // 노드주소를 저장할 포인트 멤버 변수
} Node;

int main(void)
{
	Node* head = (Node*)malloc(sizeof(Node));		//동적할당

	//만약 head가 할당을 못받을때를 대비하여 if문 생성
	if (head == NULL)
	{
		return;
	}

	head->next = NULL; //항상 처음을 가르키는 헤더 노드를 생성

	Node *node1 = (Node*)malloc(sizeof(Node));       //동적할당

	//만약 node1이 할당을 못받을때를 대비하여 if문 생성
	// (없어도 실행되지만 역참조 되었지만 null일 수 있다는 경고가 뜸)

	if (node1 == NULL)				
	{
		return;
	}

	head->next = node1; //헤더 노드는 항상 첫 번째 노드를 가리키게 한다. 
	node1->data = 10;
	node1->next = NULL;

	Node* node2 = (Node*)malloc(sizeof(Node));

	//만약 node2가 할당을 못받을때를 대비하여 if문 생성
	if (node2 == NULL)		
	{
		return;
	}

	node2->data = 20;
	node2->next = NULL;
	node1->next = node2; //node2 자체가 포인터(주소값)이기 때문에 & 필요 없음

	Node* node3 = (Node*)malloc(sizeof(Node));

	//만약 node3가 할당을 못받을때를 대비하여 if문 생성
	if (node3 == NULL)
	{
		return;
	}

	node3->data = 30;
	node3->next = NULL;
	node2->next = node3; //node2 자체가 포인터(주소값)이기 때문에 & 필요 없음

	Node* node4 = (Node*)malloc(sizeof(Node));

	//만약 node4가 할당을 못받을때를 대비하여 if문 생성
	if (node4 == NULL)
	{
		return;
	}

	node4->data = 40;
	node4->next = NULL;
	node3->next = node4; //node2 자체가 포인터(주소값)이기 때문에 & 필요 없음

	//순회하는 포인터 생성
	Node* curr = head->next; //순회하는 포인터 노드로 항상 처음은 첫번째 노드 주소값을 알아야함(node1의 주소값은 next가 가짐)
	
	printf("curr 포인터를 이용한 데이터 출력 값\n\n");

	//printf("%d\n", curr->data);
	//while (curr->next != NULL) //next 노드에 null값이 있으면 마지막 노드라는 것을 의미
	//{
	//	curr = curr->next; //한번 반복하면 두 번째 코드를 가르키게 만드는 변수를 생성 ++
	//	printf("%d\n", curr->data);
	//}

	while (curr != NULL)
	{
		printf("%d\n", curr->data);
		curr = curr->next; //한번 반복하면 두 번째 코드를 가르키게 만드는 변수를 생성 ++
	}

	printf("\n일반적으로 출력하는 노드 데이터 값 및 각 노드가 가르키는 주소값\n\n");
	printf("%p %p\n", head->next, node1); //헤더와 첫번째 노드 주소가 동일한지 체크
	printf("%d %p\n", node1->data, node1->next);
	printf("%d %p\n", node2->data, node2->next);
	printf("%d %p\n", node3->data, node3->next);
	printf("%d %p\n", node4->data, node4->next);

	//메모리 반환 (컴파일이 똑똑해져서 반환을 안해도 실행 가능)
	free(head);
	free(node1);
	free(node2);
	free(node3);
	free(node4);
	return 0;
}