//Alphabet_sort.c
//created: 2022.03.03
//Author: 최희태

//연결리스트 사용

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
	//	printf("%d번째 노드 데이터 %c\n", i, curr->alpabet);
	//	curr = curr->next;
	//	i++;
	//}
	//curr = h->head;

	//printf("\n대문자가 들어간 노드 데이터 : ");

	printf("\n대문자 : ");
	while (curr != NULL)
	{
		if (curr->alpabet >= 'A' && curr->alpabet <= 'Z')
			printf("%c ", curr->alpabet);
		curr = curr->next;
	}
	curr = h->head;

	//printf("\n소문자가 들어간 노드 데이터 : ");

	printf("\n소문자 : ");
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
	printf("알파벳 출력 프로그램 입니다.\n\n");
	printf("알파벳 10개 이상 입력해도 정렬 및 출력은 10개만 됩니다.\n");
	printf("===========================================================\n");

	printf("\n알파벳을 한 줄로 입력하세요 ->");

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

				temp = arr[j - 1]; // 비교 대상 한 칸 뒤로 밀기
				arr[j - 1] = arr[j];
				arr[j] = temp;
			}
		}
	}
}