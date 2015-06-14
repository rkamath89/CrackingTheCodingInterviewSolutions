#include <iostream>
#include <queue>
using namespace std;


struct Node
{
	int value;
	Node* left;
	Node* right;
};
Node *root = NULL;
Node* getNewNode(int value)
{
	Node *newNode = new Node();
	newNode->left = NULL;
	newNode->right = NULL;
	newNode->value = value;
	return newNode;
}
void addNodeToTree(int value,Node* rootNode)
{
	if (rootNode == NULL)
	{
		root = getNewNode(value);
	}
	else
	{
		Node* temp = rootNode;
		while (temp != NULL)
		{
			if (value < temp->value)
			{
				if (temp->left == NULL)
				{
					temp->left = getNewNode(value);
					break;
				}
				else
				{
					temp = temp->left;
				}
			}
			else if (value > temp->value)
			{
				if (temp->right == NULL)
				{
					temp->right = getNewNode(value);
					break;
				}
				else
				{
					temp = temp->right;
				}
			}
		}
		
	}
}
void  printLevelOrder(Node *nodeVal)
{
	queue<Node> nodeQueue;
	nodeQueue.push(*nodeVal);
	cout << endl;
	while (!nodeQueue.empty())
	{
		Node poppedNode = nodeQueue.front();
		cout << " ," << poppedNode.value;
		nodeQueue.pop();
		if (poppedNode.left != NULL)
		{
			nodeQueue.push(*poppedNode.left);
		}
		if (poppedNode.right != NULL)
		{
			nodeQueue.push(*poppedNode.right);
		}
		
	}
}
void main()
{
	
	bool isExit = false;
	while (!isExit)
	{
		int choice = 0;
		cout << endl << "1: Add a New Node to tree";
		cout << endl << "2: Print Level Order Traversal";
		cout << endl << "3: Print PreOrder Traversal";
		cout << endl << "4: Print InOrder Traversal";
		cout << endl << "5: Print PostOrder Traversal";
		cout << endl << "6: Delete a Node";
		cout << endl << "7: Find Min and Max";
		cout << endl << "8: Find Height of the Tree" << endl;
		cin >> choice;
		switch (choice)
		{
		case 1:
			int val;
			cout << endl << " Enter the Value Of New Node ::";
			cin >> val;
			addNodeToTree(val,root);
			break;
		case 2:
			cout << endl << " Printing in Level Order";
			printLevelOrder(root);
			break;

		case 3:
			break;
		case 4:
			break;

		case 5:
			break;
		case 6:
			break;

		case 7:
			break;
		case 8:
			break;
		}
	}
}