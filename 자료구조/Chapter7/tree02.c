//이진트리 순회

#include <stdio.h>
#include <stdlib.h>

typedef struct tnode
{
	char ch;
	struct tnode* left;
	struct tnode* right;
}Tnode;

Tnode* creatNode(char ach)
{
	Tnode* newNode = (Tnode*)malloc(sizeof(Tnode));
	if (newNode == NULL)
	{
		return;
	}
	newNode->ch = ach;
	newNode->left = NULL;
	newNode->right = NULL;
	return newNode;
}

void makeTreeNode(Tnode* aroot, Tnode* al, Tnode* ar)
{
	aroot->left = al;
	aroot->right = ar;
}

void preorederTree(Tnode* aroot) //전위순회
{
	if (aroot == NULL)
	{
		return;
	}
	printf("%c ", aroot->ch);
	preorederTree(aroot->left);
	preorederTree(aroot->right);
}

void inorederTree(Tnode* aroot) //중위순회
{
	if (aroot == NULL)
	{
		return;
	}
	inorederTree(aroot->left);
	printf("%c ", aroot->ch);
	inorederTree(aroot->right);
}

void postorederTree(Tnode* aroot) //후위순회
{
	if (aroot == NULL)
	{
		return;
	}
	postorederTree(aroot->left);
	postorederTree(aroot->right);
	printf("%c ", aroot->ch);
}

int main(void)
{

	Tnode* t1 = creatNode('a');
	Tnode* t2 = creatNode('b');
	Tnode* t3 = creatNode('c');
	Tnode* t4 = creatNode('d');
	Tnode* t5 = creatNode('e');
	Tnode* t6 = creatNode('f');
	Tnode* t7 = creatNode('g');
	Tnode* t8 = creatNode('h');
	Tnode* t9 = creatNode('i');

	makeTreeNode(t1, t2, t3);
	makeTreeNode(t2, t4, t5);
	makeTreeNode(t3, t6, t7);
	makeTreeNode(t4, t8, NULL);
	makeTreeNode(t5, NULL, t9);

	printf("전위순회\n");
	preorederTree(t1);
	printf("\n중위순회\n");
	inorederTree(t1);
	printf("\n후위순회\n");
	postorederTree(t1);



	return 0;
}