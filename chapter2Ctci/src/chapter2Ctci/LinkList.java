package chapter2Ctci;

public class LinkList 
{
	int value;
	LinkList nextNode;
	LinkList(int val,LinkList node)
	{
		this.value = val;
		this.nextNode = node;
	}
	public LinkList() {
		// TODO Auto-generated constructor stub
	}
	public void setNextNode(LinkList node) 
	{
		this.nextNode = node;
		
	}
}
