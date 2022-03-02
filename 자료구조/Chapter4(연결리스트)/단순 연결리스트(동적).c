//�ܼ� ���Ḯ��Ʈ(����)

#include <stdio.h>
#include <stdlib.h>

typedef struct _node
{
	int data;			//�����͸� ������ �������
	struct _node* next; // ����ּҸ� ������ ����Ʈ ��� ����
} Node;

int main(void)
{
	Node* head = (Node*)malloc(sizeof(Node));		//�����Ҵ�

	//���� head�� �Ҵ��� ���������� ����Ͽ� if�� ����
	if (head == NULL)
	{
		return;
	}

	head->next = NULL; //�׻� ó���� ����Ű�� ��� ��带 ����

	Node *node1 = (Node*)malloc(sizeof(Node));       //�����Ҵ�

	//���� node1�� �Ҵ��� ���������� ����Ͽ� if�� ����
	// (��� ��������� ������ �Ǿ����� null�� �� �ִٴ� ��� ��)

	if (node1 == NULL)				
	{
		return;
	}

	head->next = node1; //��� ���� �׻� ù ��° ��带 ����Ű�� �Ѵ�. 
	node1->data = 10;
	node1->next = NULL;

	Node* node2 = (Node*)malloc(sizeof(Node));

	//���� node2�� �Ҵ��� ���������� ����Ͽ� if�� ����
	if (node2 == NULL)		
	{
		return;
	}

	node2->data = 20;
	node2->next = NULL;
	node1->next = node2; //node2 ��ü�� ������(�ּҰ�)�̱� ������ & �ʿ� ����

	Node* node3 = (Node*)malloc(sizeof(Node));

	//���� node3�� �Ҵ��� ���������� ����Ͽ� if�� ����
	if (node3 == NULL)
	{
		return;
	}

	node3->data = 30;
	node3->next = NULL;
	node2->next = node3; //node2 ��ü�� ������(�ּҰ�)�̱� ������ & �ʿ� ����

	Node* node4 = (Node*)malloc(sizeof(Node));

	//���� node4�� �Ҵ��� ���������� ����Ͽ� if�� ����
	if (node4 == NULL)
	{
		return;
	}

	node4->data = 40;
	node4->next = NULL;
	node3->next = node4; //node2 ��ü�� ������(�ּҰ�)�̱� ������ & �ʿ� ����

	//��ȸ�ϴ� ������ ����
	Node* curr = head->next; //��ȸ�ϴ� ������ ���� �׻� ó���� ù��° ��� �ּҰ��� �˾ƾ���(node1�� �ּҰ��� next�� ����)
	
	printf("curr �����͸� �̿��� ������ ��� ��\n\n");

	//printf("%d\n", curr->data);
	//while (curr->next != NULL) //next ��忡 null���� ������ ������ ����� ���� �ǹ�
	//{
	//	curr = curr->next; //�ѹ� �ݺ��ϸ� �� ��° �ڵ带 ����Ű�� ����� ������ ���� ++
	//	printf("%d\n", curr->data);
	//}

	while (curr != NULL)
	{
		printf("%d\n", curr->data);
		curr = curr->next; //�ѹ� �ݺ��ϸ� �� ��° �ڵ带 ����Ű�� ����� ������ ���� ++
	}

	printf("\n�Ϲ������� ����ϴ� ��� ������ �� �� �� ��尡 ����Ű�� �ּҰ�\n\n");
	printf("%p %p\n", head->next, node1); //����� ù��° ��� �ּҰ� �������� üũ
	printf("%d %p\n", node1->data, node1->next);
	printf("%d %p\n", node2->data, node2->next);
	printf("%d %p\n", node3->data, node3->next);
	printf("%d %p\n", node4->data, node4->next);

	//�޸� ��ȯ (�������� �ȶ������� ��ȯ�� ���ص� ���� ����)
	free(head);
	free(node1);
	free(node2);
	free(node3);
	free(node4);
	return 0;
}