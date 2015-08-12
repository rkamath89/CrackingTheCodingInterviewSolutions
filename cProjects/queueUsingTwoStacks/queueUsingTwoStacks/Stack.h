struct Node
{
	int value;
	Node *nextNode;
	Node *topOfStack;
	Node *bottomOfStack;
};

void addNode(Node **stack, int value);
Node *getStackTop(Node *stack);
void popNode(Node **stack,bool print=true);
void printStack(Node *stack);