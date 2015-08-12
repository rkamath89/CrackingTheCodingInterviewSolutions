
struct queue
{
	Node *inStack;
	Node *outStack;
};

void addItem(queue **q, int value);
void deleteItem(queue **q);
void printQueue(queue *q);