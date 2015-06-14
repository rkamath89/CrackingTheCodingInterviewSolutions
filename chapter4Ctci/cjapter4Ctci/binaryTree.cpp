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
void printInOrder(Node* rootNode)
{

	if (rootNode != NULL)
	{
		printInOrder(rootNode->left);
		cout << " ," << rootNode->value;
		printInOrder(rootNode->right);
	}
	
}
void printPreOrder(Node* rootNode)
{

	if (rootNode != NULL)
	{
		cout << " ," << rootNode->value;
		printPreOrder(rootNode->left);
		printPreOrder(rootNode->right);
		
		
	}
	
}
void printPostOrder(Node* rootNode)
{

	if (rootNode != NULL)
	{
		printPostOrder(rootNode->left);
		printPostOrder(rootNode->right);
		cout << " ," << rootNode->value;
	}
	
}
int heightOfTree(Node* rootNode)
{
	int height = 1;
	if (rootNode == NULL)
		return -1;
	if (rootNode != NULL)
	{
		height = 1 + max(heightOfTree(rootNode->left), heightOfTree(rootNode->right));
	}

	return height;
}
bool isBinarySearchTree(Node* rootNode, int min, int max)
{
	if (rootNode == NULL)
	{
		return true;
	}
	if (rootNode->value > min && rootNode->value < max && isBinarySearchTree(rootNode->left,min,rootNode->value)
		&& isBinarySearchTree(rootNode->right,rootNode->value,max))
	{
		return true;
	}
	else
	{
		return false;
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
		cout << endl << "8: Find Height of the Tree";
		cout << endl << "9: Is Binary Tree a Binary Search Tree" << endl;
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
			cout << endl << "PreOrder Traversal :" << endl;
			printPreOrder(root);
			break;
		case 4:
			cout << endl << "InOrder Traversal :" << endl;
			printInOrder(root);
			break;
		case 5:
			cout << endl << "PostOrder Traversal :" << endl;
			printPostOrder(root);
			break;
		case 6:
			break;
		case 7:
			break;
		case 8:
			cout << endl << " Height of Tree is : " << heightOfTree(root) << endl;
			break;
		case 9:
			cout << endl << "Is Binary Search Tree :: ";
			/*root = getNewNode(10);
			root->left = getNewNode(5);
			root->right = getNewNode(16);
			root->left->left = getNewNode(4);
			root->left->right = getNewNode(7);
			root->left->left->left = getNewNode(1);
			root->left->right->right = getNewNode(11);*/
			bool isValid = isBinarySearchTree(root, -999, 999);
			cout << isValid;
			break;
		}
	}
}