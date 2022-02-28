#include <stdio.h>
#include <stdbool.h> //bool 자료형을 쓰기 위한 헤더

#define STACK_SZ 10
typedef int element; //스택자료형

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
	Stack stack; //initStack 함수를 쓰기 위한 구조체 변수 생성
	initStack(&stack);

	push(&stack, 5);
	push(&stack, 3);
	push(&stack, 4);
	push(&stack, 2);
	printf("%d\n", pop(&stack));
	printf("%d\n", pop(&stack)); //마지막 값부터 출력

	return 0;
}

void initStack(Stack* pstack) //스택 초기화 
{
	pstack->top = -1;
}

bool isEmpty(Stack* pstack) //비워져있는지 확인
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

bool isFull(Stack* pstack) //스택의 포화상태 확인
{
	if (pstack->top >= STACK_SZ - 1) //index는 -1값이니
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
	if (isFull(pstack))	//가득 찼을 경우 못만듬
	{
		printf("스택이 가득 찼습니다.");
		return; //출력이 없어서 리턴만
	}
	else
	{
		pstack->stack[++pstack->top] = value; //배열의 시작은 0이므로 -1에서 ++해준 후 값을 넣음
	}
}

element pop(Stack* pstack)		//스택 원소 출력
{
	if (isEmpty(pstack)) //비워져있으면 출력 불가능
	{
		printf("스택이 비어있습니다.");
		return 0; //출력이 있으니 0을 리턴
	}
	else
	{
		return pstack->stack[pstack->top--]; //맨 마지막에 들어오는 원소를 출력 후에 다음 원소를 출력시켜야 하니 --해야함
	}
}

element peek(Stack* pstack) //가장 최근에 들어온 값을 반환
{
	if (isEmpty(pstack)) //비워져있으면 출력 불가능
	{
		printf("스택이 비어있습니다.");
		exit(1);
	}
	else
	{
		return pstack->stack[pstack->top]; //맨 마지막에 들어오는 원소를 출력만 하면 되니 연산은 필요없음
	}
}