#include "Stack.h"
#include "Queue.h"
#include <iostream>
using namespace std;


void addItem(queue **q, int value)
{
	if (*q == NULL)
	{
		*q = new queue();
		(*q)->inStack = NULL;
		(*q)->outStack = NULL;
	}
	addNode(&(*q)->inStack, value);
}
void deleteItem(queue **q)
{
	
	if ((*q)->outStack != NULL)
	{
		popNode(&(*q)->outStack);
	}
	else
	{
		Node *temp = NULL;
		while ((*q)->inStack->topOfStack != NULL)
		{
			temp = getStackTop((*q)->inStack);
			popNode(&(*q)->inStack, false);
			addNode(&(*q)->outStack, temp->value);
		}
		temp = getStackTop((*q)->outStack);
		cout << endl << "Value PopeD : " << temp->value << endl;
		popNode(&(*q)->outStack,false);
	}
}
void printNode(Node *node)
{
	if (node == NULL)
		return;
	else
	{
		printNode(node->nextNode);
		cout << node->value << ", ";
	}
	
		
	
}
void printQueue(queue *q)
{
	Node *in = q->inStack;
	Node *qout = q->outStack;
	cout << endl;
	if (qout != NULL)
	{
		printStack(qout);
	}
	if (in != NULL)
	{
		printNode(in->topOfStack);
	}
	cout << endl;
}
void main()
{
	int choice;
	bool exit = false,done=false;
	int value;
	queue *q = NULL, *top = NULL;
	while (!exit)
	{
		cout << endl << "1:Inset into Queue";
		cout << endl << "2: Print Queue";
		cout << endl << "3:Remove from Front";
		
		cout << endl;
		cin >> choice;
		switch (choice)
		{
		case 1:
			cout << endl << "Enter value of new Node :";
			cin >> value;
			addItem(&q, value);
			break;
		case 2:
			cout << endl << "Contents of Queue are :";
			printQueue(q);
			break;
		case 3:
			if (!done)
			{
				addItem(&q, 1); addItem(&q, 2); addItem(&q, 3); addItem(&q, 4); addItem(&q, 5); addItem(&q, 6);
				done = true;
			}
				
			deleteItem(&q);
			break;
		


		}
	}
}