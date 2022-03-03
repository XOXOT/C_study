//Alphabet_sort.c
//created: 2022.03.03
//Author: ������

//���Ḯ��Ʈ ���

#include <stdio.h>
#include <stdlib.h>
#define MAX_LENGTH 10

void insertionSort(char*, int);

typedef struct node 
{
	char alpabet;
	struct node* next;
} Node;

typedef struct {

	Node* head;

}HeadNode;

HeadNode* createHead()
{
	HeadNode* h = (HeadNode*)malloc(sizeof(HeadNode));
	if (h == NULL)
	{
		return;
	}
	if (h != NULL)
	{
		h->head = NULL;
	}
	return h;
}

void insertNode(HeadNode* h, char alpa)
{
	Node* newNode = (Node*)malloc(sizeof(Node));
	if (newNode == NULL)
	{
		return;
	}
	if (newNode != NULL) 
	{
		newNode->alpabet = alpa;
		newNode->next = NULL;

		if (h->head == NULL)
		{
			h->head = newNode;
		}

		else if (h->head != NULL)
		{
			Node* curr = h->head;
			while (curr->next != NULL) curr = curr->next;
			curr->next = newNode;
		}
	}

}

void printNode(HeadNode* h)
{
	Node* curr = h->head;
	int i = 1;

	//while (curr != NULL)
	//{
	//	printf("%d��° ��� ������ %c\n", i, curr->alpabet);
	//	curr = curr->next;
	//	i++;
	//}
	//curr = h->head;

	//printf("\n�빮�ڰ� �� ��� ������ : ");

	printf("\n�빮�� : ");
	while (curr != NULL)
	{
		if (curr->alpabet >= 'A' && curr->alpabet <= 'Z')
			printf("%c ", curr->alpabet);
		curr = curr->next;
	}
	curr = h->head;

	//printf("\n�ҹ��ڰ� �� ��� ������ : ");

	printf("\n�ҹ��� : ");
	while (curr != NULL)
	{
		if (curr->alpabet >= 'a' && curr->alpabet <= 'z')
			printf("%c ", curr->alpabet);
		curr = curr->next;
	}
	printf("\n");
}

int main()
{
	HeadNode* h = createHead();

	char input_ary[10];
	int j = 0, k = 0;

	printf("===========================================================\n");
	printf("���ĺ� ��� ���α׷� �Դϴ�.\n\n");
	printf("���ĺ� 10�� �̻� �Է��ص� ���� �� ����� 10���� �˴ϴ�.\n");
	printf("===========================================================\n");

	printf("\n���ĺ��� �� �ٷ� �Է��ϼ��� ->");

	for (int i = 0; i < 10; i++)
	{
		scanf("%c", &input_ary[i]);
	}

	insertionSort(input_ary, 10);

	for (int i = 0; i < 10; i++)
	{
		insertNode(h, input_ary[i]);
	}

	printNode(h);

}

void insertionSort(char* arr, int count)
{
	char temp;
	for (int i = 1; i < count; i++)
	{
		for (int j = i; j > 0; j--)
		{
			if (arr[j - 1] > arr[j])
			{

				temp = arr[j - 1]; // �� ��� �� ĭ �ڷ� �б�
				arr[j - 1] = arr[j];
				arr[j] = temp;
			}
		}
	}
}