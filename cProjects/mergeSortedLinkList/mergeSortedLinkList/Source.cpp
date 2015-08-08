#include <iostream>
using namespace std;

struct Node
{
	int value;
	Node *nextNode;
};

void addNode(Node **headNode,int value)
{
	Node *newNode = new Node();
	newNode->value = value;
	newNode->nextNode = nullptr;
	if (*headNode == nullptr)
	{
		*headNode = newNode;
	}
	else
	{
		newNode->nextNode = *headNode;
		*headNode = newNode;
	}
}
void printNodes(Node *headNode)
{
	Node *temp = headNode;
	while (temp != nullptr)
	{
		cout << " " << temp->value;
		temp = temp->nextNode;
	}
}
void splitNode(Node *src, Node **front, Node ** mid)
{
	Node * slow = src;
	Node * fast = src->nextNode;
	while (fast != NULL)
	{
		fast = fast->nextNode;
		if (fast != NULL)
		{
			slow = slow->nextNode;
			fast = fast->nextNode;
		}
	}
	*front = src;
	*mid = slow->nextNode;
	slow->nextNode = NULL;

}
void sortLinkLists(Node *a, Node *b, Node **c)
{
	Node *headC = nullptr;
	
	while (a != nullptr && b != nullptr)
	{
		if (a->value < b->value)
		{
			if (*c == nullptr)
			{
				headC = a;
				*c = headC;
			}	
			else
			{
				(*c)->nextNode = a;
				*c = (*c)->nextNode;
			}
			a = a->nextNode;
				
		}
		else
		{
			
			if (*c == nullptr)
			{
				headC = b;
				*c = headC;
			}
			else
			{
				(*c)->nextNode = b;
				*c = (*c)->nextNode;
			}
			b = b->nextNode;

		}
	}
	if (a != nullptr)
	{
		(*c)->nextNode = a;
	}
	if (b != nullptr)
	{
		(*c)->nextNode = b;
	}
	*c = headC;
}
void mergeSort(Node **src)
{
	Node *head = nullptr;
	Node *start, *mid;
	if (*src == NULL || (*src)->nextNode == NULL)
		return;
	splitNode(*src, &start, &mid);
	mergeSort(&start);
	mergeSort(&mid);
	sortLinkLists(start, mid, &head);


}
void main()
{
	int choice=0;
	Node *headNode = nullptr;
	while (1)
	{
		cout << endl << "1 : Enter New Node ";
		cout << endl << "2 : Print Nodes" ;
		cout << endl << "3 : Merge Sorted LL";
		cout << endl << "4: Split LL" << endl;
		cout << endl << "5: Perform Merge Sort" << endl;
		cin >>  choice;
		
		switch (choice)
		{
		case 1:
			cout << endl << "Enter the Value of New Node :";
			int val;
			cin >> val;
			addNode(&headNode, val);
			break;
		case 2:
			cout << endl << "Contents are : ";
			printNodes(headNode);
			break;
		
		/*case 3:
			Node *a = nullptr; Node *b = nullptr;
			addNode(&a, 10); addNode(&a, 8); addNode(&a, 6); addNode(&a, 2); addNode(&a,1);
			addNode(&b, 9); addNode(&b, 7); addNode(&b, 5); addNode(&b, 4); addNode(&b, 3);
			cout << endl << "Contents of A are : ";
			printNodes(a);
			cout << endl << "Contents of B are : ";
			printNodes(b);
			Node *c = nullptr;
			sortLinkLists(a,b,&c);
			cout << endl << "Contents of C are : ";
			printNodes(c);
			break;
			case 4:
			Node *a = nullptr;
			cout << endl << "Contents of A : ";
			addNode(&a, 6); addNode(&a, 5); addNode(&a, 4); addNode(&a, 3); addNode(&a, 2); addNode(&a, 1);
			printNodes(a);
			Node *front = nullptr; Node *mid = nullptr;
			splitNode(a, &front, &mid);
			cout << endl << "Contents of Front : ";
			printNodes(front);
			cout << endl << "Contents of Mid :";
			printNodes(mid);
			break;
			*/
		case 5:
			Node *a = nullptr; Node *b = nullptr;
			addNode(&a, 4); addNode(&a, 2); addNode(&a, 6); addNode(&a, 12); addNode(&a, 1);
			cout << endl << "Contents of A are : ";
			printNodes(a);
			mergeSort(&a);
			cout << endl << "Contents of A after merge are : ";
			printNodes(a);
		
		}
	}
}