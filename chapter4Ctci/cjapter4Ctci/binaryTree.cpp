#include <iostream>
#include <queue>
#include <vector>
#include <stack>
using namespace std;


struct Node
{
	int value;
	Node* left;
	Node* right;
};
vector<vector<Node*>> levelList;
int levelNumber=0;
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
int checkHeightAndBalance(Node* rootNode)
{
	if (rootNode == NULL)
	{
		return -1;
	}
	int heightOfLeft = checkHeightAndBalance(rootNode->left);
	if (heightOfLeft == -2)
	{
		return -2;
	}
	int heightOfRight = checkHeightAndBalance(rootNode->right);
	if (heightOfRight == -2)
	{
		return -2;
	}
	
	if (abs(heightOfLeft - heightOfRight) > 1)
	{
		return -2;
	}
	else
	{
		return max(heightOfLeft,heightOfRight) + 1;
	}

	
}
Node* createTreeFromArray(int *sortedArray, int low, int high)
{
	Node *newNode = new Node();
	if (high < low)
	{
		return NULL;
	}
	int mid = (low + high) / 2;

	newNode->value = sortedArray[mid];
	newNode->left = createTreeFromArray(sortedArray, low, mid-1);
	newNode->right = createTreeFromArray(sortedArray, mid+1, high);
	return newNode;

}

void createLinkListOfNodes(Node *rootNode)
{
	while (levelList[levelNumber].size() != 0)
	{
		int nextLevel = levelNumber + 1;
		vector<Node*> tempVector = levelList[levelNumber];
		vector<Node*> newVector;
		for (int i = 0; i < tempVector.size(); i++)
		{
			Node *tempNode = tempVector[i];
			if (tempNode->left != NULL)
			{
				newVector.push_back(tempNode->left);
			}
			if (tempNode->right != NULL)
			{
				newVector.push_back(tempNode->right);
			}
		}
		levelList.push_back(newVector);
		levelNumber++;
	}
	
	
}
void printLinkListLevelByLevel()
{
	vector<vector<Node*>> newlevelList;
	vector<Node*> tempVector = levelList[0];
	cout << endl << " Contents Of Level " << 0 << endl;
	cout << " ," << tempVector[0]->value;
	newlevelList.push_back(tempVector);
	
	for (int i = 1; i < levelNumber; i++)
	{
		int prevLevel = i - 1;
		vector<Node*> prevVector = newlevelList[prevLevel];
		vector<Node*> tempVector = levelList[i];
		for (int j = 0; j < tempVector.size(); j++)
		{
			prevVector.push_back(tempVector[j]);
		}
		newlevelList.push_back(prevVector);
	}
	for (int i = 1; i < levelNumber; i++)
	{
		cout << endl << " Contents Of Level " << i << endl;
		vector<Node*> tempVector = newlevelList[i];
		for (int j = 0; j < tempVector.size(); j++)
		{
			cout << " ," << tempVector[j]->value;
		}
	}
}
void commmonAncestor(int number1, int number2,Node * rootNode)
{
	Node *temp,prev;
	temp = rootNode;
	queue<Node> pathTravered;
	while (temp != NULL)
	{
		pathTravered.push(*temp);
		if (temp->value == number1)
		{
			break;
		}
		if (number1 < temp->value)
		{
			temp = temp->left;
		}
		else
		{
			temp = temp->right;
		}
	}
	temp = rootNode;
	while (temp != NULL)
	{
		
		if (temp->value != pathTravered.front()                                                                   .value)
		{
			cout << endl << " Common Node is :: " << prev.value << endl;
			break;
		}
		if (number2 < temp->value)
		{
			temp = temp->left;
		}
		else
		{
			temp = temp->right;
		}
		prev = pathTravered.front();
		pathTravered.pop();
	}
}
void findPathToLeafNodes(Node* rootNode, queue<Node> pathTillNow,int sum)
{
	sum = sum - rootNode->value;
	if (rootNode->right == NULL && rootNode->left == NULL)
	{
		pathTillNow.push(*rootNode);
		
		if (pathTillNow.size() > 0 && sum == 0)
		{
			cout << endl << " Path to Leaf Node :" << pathTillNow.back().value << " From Root : " << pathTillNow.front().value << " Is :" << endl;
			while (pathTillNow.size() > 0)
			{
				cout << " ," << pathTillNow.front().value;
				pathTillNow.pop();
			}
		}
	}
	else
	{
		pathTillNow.push(*rootNode);
		findPathToLeafNodes(rootNode->left, pathTillNow, sum);
		findPathToLeafNodes(rootNode->right, pathTillNow, sum);
	}
}
void main()
{
	
	bool isExit = false;
	while (!isExit)
	{
		int choice = 0,sum=0;
		int height = -1;
		int number1 = 0, number2 = 0;
		vector<Node*> tempNode;
		queue<Node> pathTillNow;
		int sortedArray[] = { 20, 25, 30, 50, 75, 100, 125 };
		int sortedArray2[] = { 10, 15, 17, 20, 23, 25, 26, 30, 31, 50, 75, 100, 125 };
		cout << endl << "1: Add a New Node to tree";
		cout << endl << "2: Print Level Order Traversal";
		cout << endl << "3: Print PreOrder Traversal";
		cout << endl << "4: Print InOrder Traversal";
		cout << endl << "5: Print PostOrder Traversal";
		cout << endl << "6: Delete a Node";
		cout << endl << "7: Find Min and Max";
		cout << endl << "8: Find Height of the Tree";
		cout << endl << "9: Is Binary Tree a Binary Search Tree" ; // Means Left side is smaller values and Right is Bigger Values
		cout << endl << "10: Is Tree a Balanced Tree";// Difference of Height of the Left and Right Tree is not more than 1.
		cout << endl << "11: Create Tree from Sorted Array ";
		cout << endl << "12: Create Link List of All Node every Level";
		cout << endl << "13: Find the Common Ancestor Queue Implementation";
		cout << endl << "14: Find Path to Leaf Node, given a sum" << endl;
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
			cout << endl << "Is Binary Search Tree :: " << isBinarySearchTree(root, -999, 999);
			/*root = getNewNode(10);
			root->left = getNewNode(5);
			root->right = getNewNode(16);
			root->left->left = getNewNode(4);
			root->left->right = getNewNode(7);
			root->left->left->left = getNewNode(1);
			root->left->right->right = getNewNode(11);*/
			//bool isValid = isBinarySearchTree(root, -999, 999);
			//cout << isValid;
			break;
		case 10:
			cout << "Is the Tree a Balanced Tree :: ";
			height = checkHeightAndBalance(root);
			if (height == -2)
			{
				cout << "NO" << endl;
			}
			else
			{
				cout << "YEs" << endl;
			}
				
			break;
		case 11:
			cout << endl << " Creating a Tree from Sorted Array";
			//int sortedArray[] = { 20,25,30,50,75,100,125 };
			root = createTreeFromArray(sortedArray, 0, 6);
			cout << endl << "Contents Of Tree " << endl;
			printInOrder(root);
			break;
		case 12:
			//int sortedArray[] = { 20,25,30,50,75,100,125 };
			root = createTreeFromArray(sortedArray, 0, 6);
			tempNode.push_back(root);
			levelList.push_back(tempNode);
			createLinkListOfNodes(root);
			printLinkListLevelByLevel();
			break;
		case 13:
			//root = NULL;
			//root = createTreeFromArray(sortedArray2, 0, 12);
			cout << endl << " Enter the Node1 " << endl;
			cin >> number1;
			cout << endl << " Enter the Node2 " << endl;
			cin >> number2;
			commmonAncestor(number1, number2, root);
			break;
		case 14:
			cout << endl << " Find path with SUM : ";
			cin >> sum;
			if (root == NULL)
				root = createTreeFromArray(sortedArray, 0, 6);
			findPathToLeafNodes(root, pathTillNow,sum);
			break;
		}
	}
}