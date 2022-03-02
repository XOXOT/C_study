//이진트리 생성

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

	printf("%c %c %c\n", t1->ch, t2->ch, t3->ch);

	makeTreeNode(t1, t2, t3);
	makeTreeNode(t2, t4, t5);
	makeTreeNode(t3, t6, t7);
	makeTreeNode(t4, t8, NULL);
	makeTreeNode(t5, NULL, t9);

	printf("%c %c %c\n", t1->ch, t1->left->left->ch, t1->right->right->ch);
	return 0;
}