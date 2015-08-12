#include "Stack.h";
#include <iostream>
using namespace std;

void addNode(Node **stack, int value)
{
	Node *newNode = new Node();
	newNode->value = value;
	newNode->nextNode = NULL;
	newNode->topOfStack = NULL;
	if (*stack == NULL)
	{
		*stack = newNode;
		(*stack)->topOfStack = *stack;

	}
	else
	{
		Node *temp = (*stack)->topOfStack;
		newNode->nextNode = temp;
		(*stack)->topOfStack = newNode;

	}
}
void printStack(Node *stack)
{
	if (stack == NULL)
		return;
	Node * temp = stack->topOfStack;
	cout << endl;
	while (temp != NULL)
	{
		cout << temp->value << ", ";
		temp = temp->nextNode;
	}
	cout << endl;
}
Node *getStackTop(Node *stack)
{
	return stack->topOfStack;
}
void popNode(Node **topOfStack,bool print)
{
	Node *stackTop = (*topOfStack)->topOfStack;
	if (stackTop == NULL)
	{
		cout << endl << " Stack is empty" << endl;
		return;
	}
	if (print)
		cout << endl << " Value Poped is : " << stackTop->value << endl;
	(*topOfStack)->topOfStack = stackTop->nextNode;
	//delete(stackTop);
	

}
//
//void main()
//{
//	int choice;
//	bool exit = false;
//	int value;
//	Node *stack = NULL,*top = NULL;
//	while (!exit)
//	{
//		cout << endl << "1: Create New Node";
//		cout << endl << "2: Print Nodes";
//		cout << endl << "3:Pop Node";
//		cout << endl << "4:Value at Top";
//		cout << endl;
//		cin >> choice;
//		switch (choice)
//		{
//		case 1:
//			cout << endl << "Enter value of new Node :";
//			cin >> value;
//			addNode(&stack, value);
//			break;
//		case 2:
//			cout << endl << "Contents of Stack are :";
//			printStack(stack);
//			break;
//		case 3:
//			popNode(&stack);
//			break;
//		case 4:
//			top = getStackTop(stack);
//			cout << endl << "Element at top is : " << top->value << endl;
//			break;
//
//
//		}
//	}
//}