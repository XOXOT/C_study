#include <stdio.h>
#include <stdbool.h> //bool �ڷ����� ���� ���� ���

#define STACK_SZ 5

typedef int element; //�����ڷ���

bool isEmpty();
bool isFull();
void push(element value);
element pop();
element peek();

element stack[STACK_SZ];  //���� ����

int top = -1;			// ����ִ��� �Ⱥ���ִ��� ���¸� Ȯ���ϱ� ���� �׻� �ʱⰪ�� -1;
						// -1�̸� ������ִٴ� ���� �ǹ�

int main(void)
{

	push(2);
	push(3);
	push(4);
	push(2);
	push(3);
	printf("%d\n", pop());//������ ������ ���
	printf("%d\n", pop());

	return 0;
}

bool isEmpty() //������ִ��� Ȯ��
{
	if (top<= -1)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool isFull() //������ ��ȭ���� Ȯ��
{
	if (top >= STACK_SZ - 1) //index�� -1���̴�
	{
		return true;
	}
	else
	{
		return false;
	}
}

void push(element value) //���ÿ� ���� ����
{
	if (isFull())	//���� á�� ��� ������
	{
		printf("������ ���� á���ϴ�.");
		return; //����� ��� ���ϸ�
	}
	else
	{
		stack[++top] = value; //�迭�� ������ 0�̹Ƿ� -1���� ++���� �� ���� ����
	}
}

element pop()		//���� ���� ���
{
	if (isEmpty()) //����������� ��� �Ұ���
	{
		printf("������ ����ֽ��ϴ�.");
		return 0; //����� ������ 0�� ����
	}
	else
	{
		return stack[top--]; //�� �������� ������ ���Ҹ� ��� �Ŀ� ���� ���Ҹ� ��½��Ѿ� �ϴ� --�ؾ���
	}
}

element peek() //���� �ֱٿ� ���� ���� ��ȯ
{
	if (isEmpty()) //����������� ��� �Ұ���
	{
		printf("������ ����ֽ��ϴ�.");
		exit(1);
	}
	else
	{
		return stack[top]; //�� �������� ������ ���Ҹ� ��¸� �ϸ� �Ǵ� ������ �ʿ����
	}
}
