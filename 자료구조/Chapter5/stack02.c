#include <stdio.h>
#include <stdbool.h> //bool �ڷ����� ���� ���� ���

#define STACK_SZ 10
typedef int element; //�����ڷ���

typedef struct
{
	int top;
	element stack[STACK_SZ];
}Stack;

void initStack(Stack* pstack);
bool isEmpty(Stack*);
bool isFull(Stack*);
void push(Stack* ,element);
element pop(Stack*);
element peek(Stack*);

int main(void)
{
	Stack stack; //initStack �Լ��� ���� ���� ����ü ���� ����
	initStack(&stack);

	push(&stack, 5);
	push(&stack, 3);
	push(&stack, 4);
	push(&stack, 2);
	printf("%d\n", pop(&stack));
	printf("%d\n", pop(&stack)); //������ ������ ���

	return 0;
}

void initStack(Stack* pstack) //���� �ʱ�ȭ 
{
	pstack->top = -1;
}

bool isEmpty(Stack* pstack) //������ִ��� Ȯ��
{
	if (pstack->top <= -1)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool isFull(Stack* pstack) //������ ��ȭ���� Ȯ��
{
	if (pstack->top >= STACK_SZ - 1) //index�� -1���̴�
	{
		return true;
	}
	else
	{
		return false;
	}
}

void push(Stack* pstack, element value)
{
	if (isFull(pstack))	//���� á�� ��� ������
	{
		printf("������ ���� á���ϴ�.");
		return; //����� ��� ���ϸ�
	}
	else
	{
		pstack->stack[++pstack->top] = value; //�迭�� ������ 0�̹Ƿ� -1���� ++���� �� ���� ����
	}
}

element pop(Stack* pstack)		//���� ���� ���
{
	if (isEmpty(pstack)) //����������� ��� �Ұ���
	{
		printf("������ ����ֽ��ϴ�.");
		return 0; //����� ������ 0�� ����
	}
	else
	{
		return pstack->stack[pstack->top--]; //�� �������� ������ ���Ҹ� ��� �Ŀ� ���� ���Ҹ� ��½��Ѿ� �ϴ� --�ؾ���
	}
}

element peek(Stack* pstack) //���� �ֱٿ� ���� ���� ��ȯ
{
	if (isEmpty(pstack)) //����������� ��� �Ұ���
	{
		printf("������ ����ֽ��ϴ�.");
		exit(1);
	}
	else
	{
		return pstack->stack[pstack->top]; //�� �������� ������ ���Ҹ� ��¸� �ϸ� �Ǵ� ������ �ʿ����
	}
}