//�ܼ� ���Ḯ��Ʈ(����) - �迭�� ����ϴ� �Ͱ� �Ȱ��� ���� �������� �ؾ���

#include <stdio.h>


typedef struct _node
{
	int data;			//�����͸� ������ �������
	struct _node *next; // ����ּҸ� ������ ����Ʈ ��� ����
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