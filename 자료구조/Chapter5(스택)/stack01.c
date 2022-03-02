#include <stdio.h>
#include <stdbool.h> //bool 자료형을 쓰기 위한 헤더

#define STACK_SZ 5

typedef int element; //스택자료형

bool isEmpty();
bool isFull();
void push(element value);
element pop();
element peek();

element stack[STACK_SZ];  //스택 생성

int top = -1;			// 비어있는지 안비어있는지 상태를 확인하기 위해 항상 초기값은 -1;
						// -1이면 비워져있다는 것을 의미

int main(void)
{

	push(2);
	push(3);
	push(4);
	push(2);
	push(3);
	printf("%d\n", pop());//마지막 값부터 출력
	printf("%d\n", pop());

	return 0;
}

bool isEmpty() //비워져있는지 확인
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

bool isFull() //스택의 포화상태 확인
{
	if (top >= STACK_SZ - 1) //index는 -1값이니
	{
		return true;
	}
	else
	{
		return false;
	}
}

void push(element value) //스택에 원소 삽입
{
	if (isFull())	//가득 찼을 경우 못만듬
	{
		printf("스택이 가득 찼습니다.");
		return; //출력이 없어서 리턴만
	}
	else
	{
		stack[++top] = value; //배열의 시작은 0이므로 -1에서 ++해준 후 값을 넣음
	}
}

element pop()		//스택 원소 출력
{
	if (isEmpty()) //비워져있으면 출력 불가능
	{
		printf("스택이 비어있습니다.");
		return 0; //출력이 있으니 0을 리턴
	}
	else
	{
		return stack[top--]; //맨 마지막에 들어오는 원소를 출력 후에 다음 원소를 출력시켜야 하니 --해야함
	}
}

element peek() //가장 최근에 들어온 값을 반환
{
	if (isEmpty()) //비워져있으면 출력 불가능
	{
		printf("스택이 비어있습니다.");
		exit(1);
	}
	else
	{
		return stack[top]; //맨 마지막에 들어오는 원소를 출력만 하면 되니 연산은 필요없음
	}
}
