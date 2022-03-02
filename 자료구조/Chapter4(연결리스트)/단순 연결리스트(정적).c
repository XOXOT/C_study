//단순 연결리스트(정적) - 배열을 사용하는 것과 똑같음 따라서 동적으로 해야함

#include <stdio.h>


typedef struct _node
{
	int data;			//데이터를 저장할 멤버변수
	struct _node *next; // 노드주소를 저장할 포인트 멤버 변수
} Node;

int main(void)
{
	
	Node node1, node2;
	node1.data = 10;
	node1.next = NULL;

	node2.data = 20;
	node2.next = NULL;
	node1.next = &node2;

	printf("%d %p\n", node1.data, node1.next);
	printf("%d %p\n", node2.data, node2.next);
	printf("%p\n", &node2);

	return 0;
}