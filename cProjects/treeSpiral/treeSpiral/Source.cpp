#include <iostream>
#include "Header.h"
#include <queue>
#include <stack>
using namespace std;


void findPositionToAddNode(Node *rootNode, Node *temp)
{
	Node *tempRoot = rootNode;
	while (1)
	{
		if (temp->value < tempRoot->value)
		{
			if (tempRoot->leftNode != NULL)
			{
				tempRoot = tempRoot->leftNode;
			}
			else
			{
				tempRoot->leftNode = temp;
				break;
			}
			
		}
		else
		{
			if (tempRoot->rightNode != NULL)
			{
				tempRoot = tempRoot->rightNode;
			}
			else
			{
				tempRoot->rightNode = temp;
				break;
			}
		}
	}
}
void addNode(Node **rootNode, int value)
{
	Node *temp = new Node();
	temp->value = value;
	temp->leftNode = NULL;
	temp->rightNode = NULL;

	if (*rootNode == NULL)
	{
		*rootNode = temp;
	}
	else
	{
		findPositionToAddNode(*rootNode, temp);
	}

}
void printLevelOrder(Node *rootNode,queue<Node*> nodes)
{
	cout << endl;
	nodes.push(rootNode);
	while (!nodes.empty())
	{
		Node *temp = nodes.front();
		nodes.pop();
		cout << temp->value << ",";
		if (temp->leftNode != NULL)
			nodes.push(temp->leftNode);
		if (temp->rightNode != NULL)
			nodes.push(temp->rightNode);
	}
}
int getHeight(Node *root)
{
	if (root == NULL)
		return 0;
	int lHeight = 1 + getHeight(root->leftNode);
	int rHeight = 1 + getHeight(root->rightNode);
	if (lHeight >= rHeight)
		return lHeight;
	else
		return rHeight;
}

void printNode(Node *rootNode, int level, bool alt)
{
	if (rootNode == NULL)
		return;
	if (level == 1)
		cout << rootNode->value << ", ";
	if (alt)
	{
		printNode(rootNode->leftNode, level - 1, alt);
		printNode(rootNode->rightNode, level - 1, alt);
	}
	else
	{

		printNode(rootNode->rightNode, level - 1, alt);
		printNode(rootNode->leftNode, level - 1, alt);
	}
}
void spiralUsingQueue(Node *rootNode)
{
	vector<Node*> first;
	vector<Node*> second;
	first.push_back(rootNode);
	bool printRev = false;
	cout << endl;
	while (!first.empty() || !second.empty())
	{
		if (!first.empty())
		{
			for (int i = 0; i < first.size(); i++)
			{
				Node* temp = first[i];
				cout  << temp->value << ", ";
				if (temp->leftNode != NULL)
					second.push_back(temp->leftNode);

				if (temp->rightNode != NULL)
					second.push_back(temp->rightNode);
			}
			first.clear();
		}
		if (!second.empty())
		{
			for (int i = 0; i < second.size(); i++)
			{
				Node* temp = second[i];
				if (temp->leftNode != NULL)
					first.push_back(temp->leftNode);

				if (temp->rightNode != NULL)
					first.push_back(temp->rightNode);
			}
			for (int i = second.size()-1; i >= 0 ; i--)
			{
				Node* temp = second[i];
				cout << temp->value << ", ";
			}
			second.clear();
		}
	}
}
void printSpiral(Node *rootNode)
{
	bool alternate = true;
	int height = getHeight(rootNode);
	cout << endl;
	for (int level = 1; level <= height; level++)
	{
		printNode(rootNode, level, alternate);
		alternate = !alternate;
	}
}
Node* newNode(int data)
{
	struct Node* node = new Node();
	node->value = data;
	node->leftNode = NULL;
	node->rightNode = NULL;

	return(node);
}
void main()
{
	char *exit = "N";
	int val;
	Node *rootNode = NULL;
	queue<Node*> nodes;
	int height = 0;
	int choice;
	while (exit != "Y")
	{
		cout << endl << "1 : Create New Node";
		cout << endl << "2: Print Level Order";
		cout << endl << "3: Get Height Of Tree";
		cout << endl << "4: Print Tree in Spiral Form";
		cout << endl;
		cin >> choice;
		
		switch (choice)
		{
		case 1:
			cout << endl << "Enter Value of New Node: ";
			cin >> val;
			addNode(&rootNode, val);
			break;
		case 2:
			cout << endl << "Elements of tree as Per Level are ";
			printLevelOrder(rootNode, nodes);
			break;
		case 3:
			height = getHeight(rootNode);
			cout << endl << " Height Of Tree is : " << height;
			break;
		case 4:
			cout << " Tree In Spiral Form " << endl;
			/*rootNode = newNode(10);
			rootNode->leftNode = newNode(5);
			rootNode->rightNode = newNode(15);
			rootNode->leftNode->leftNode = newNode(1);
			rootNode->leftNode->rightNode = newNode(6);
			rootNode->rightNode->leftNode = newNode(11);
			rootNode->rightNode->rightNode = newNode(17);*/
			spiralUsingQueue(rootNode);
			break;
			


		}
	}
}