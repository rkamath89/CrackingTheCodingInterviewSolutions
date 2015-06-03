package chapter2Ctci;

import java.util.HashMap;
import java.util.LinkedHashSet;
import java.util.Scanner;

public class removeDuplicates {

	static LinkList head = null;
	static LinkList tail = null;
	static int element=0;
	public static void createNode(int val)
	{
		if(head == null)
		{
			head = new LinkList();
			head.value = val;
			head.nextNode = null;
			tail= head;
		}
		else
		{
			LinkList tempNode = new LinkList();
			tempNode.value = val;
			tempNode.nextNode = null;
			tail.nextNode = tempNode;
			tail = tempNode;
		}
	}
	public static void printList(LinkList headNode)
	{
		LinkList temp = headNode;
		while(temp != null)
		{
			System.out.print(" "+temp.value+"->");
			temp = temp.nextNode;
		}
		System.out.println();
	}
	public static void removeDuplicates()
	{
		LinkedHashSet<Integer> map = new LinkedHashSet<Integer>();
		LinkList temp = head;
		LinkList prev  = head;;
		while(temp != null)
		{
			if(!map.contains(temp.value))
			{
				map.add(temp.value);
				prev = temp;
				temp = temp.nextNode;
			}
			else
			{
				prev.nextNode = temp.nextNode;
				temp = temp.nextNode;
			}
			
		}
	}
	public static LinkList findKtoLastElement(int elem,LinkList node)
	{
		
		if(node == null)
		{
			return null;
		}
		else
		{
			
			LinkList foundNode = findKtoLastElement(elem,node.nextNode);
			element++;
			if(elem == element)
			{
				return node;
			}
			else if(foundNode != null)
			{
				return foundNode;
			}
		}
		return null;
	}
	public static void addNodes(LinkList node1,LinkList node2)
	{
		int sum=0;
		int carry=0;
		int node1Val=0,node2Val = 0;
		LinkList tempN1,tempN2,result=null,resultHead=null;
		tempN1 = node1;
		tempN2 = node2;
		while(tempN1 != null || tempN2 != null)
		{
			if(tempN1 != null)
			{
				node1Val = tempN1.value;
				tempN1 = tempN1.nextNode;
			}
			if(tempN2 != null)
			{
				node2Val = tempN2.value;
				tempN2 =tempN2.nextNode;
			}
			sum = carry+node1Val+node2Val; // 9 + 2 = 11
			carry =0;
			// Using Mod operaor we can get remainder as new node , if sum > 10 else just use the sum as new node
			if(sum >= 10)
			{
				int rem = sum % 10;
				carry = 1;
				if(result == null)
				{
					resultHead = result = new LinkList(rem,null);
				}
				else
				{
					result.nextNode = new LinkList(rem,null);
					result = result.nextNode;
				}
			}
			else
			{
				if(result == null)
				{
					resultHead = result = new LinkList(sum,null);
				}
				else
				{
					result.nextNode = new LinkList(sum,null);
					result = result.nextNode;
				}
			}
			sum = node1Val = node2Val =0;
		}
		System.out.println("Sum Of Node is ");
		printList(resultHead);
	}
	public static void main(String[] args) 
	{
		Scanner input = new Scanner(System.in);
		String cont = "Y";
		int choice =-1;
		while(cont.equalsIgnoreCase("Y"))
		{
			
			System.out.println("1 : Create LL");
			System.out.println("2 : Print LL");
			System.out.println("3 : Remove Duplicates"); // 2.1
			System.out.println("4 : Finding K to Last element"); //2.2
			System.out.println("5 : Adding 2 Number Stored as reverse"); //2.5
			choice = input.nextInt();
			switch(choice)
			{
			case 1:
				System.out.println(" Enter the Number");
				int val = input.nextInt();
				createNode(val);
				break;
			case 2:
				printList(head);
				break;
			case 3:
				removeDuplicates();
				System.out.println(" List after Removing duplicates");
				printList(head);
				break;
			case 4:
				//1->2->3->4->5->6
				/*head = new LinkList(1,null);
				head.nextNode = new LinkList(2,new LinkList(3,new LinkList (4, new LinkList(5,new LinkList(6,null)))));*/
				element =0;
				System.out.println(" Enter the Elemment to find from the End ");
				int elem = input.nextInt();
				LinkList foundNode = findKtoLastElement(elem,head);
				if(foundNode != null)
				System.out.println(elem+" From end is :: "+foundNode.value);
				break;
			case 5:
				System.out.println("The 1st Node is :: 7->1->6->5->5 and 2nd is 3->5->4->4");
				// 5617 + 1453 = 7070
				LinkList node1 = new LinkList(7,new LinkList(1,new LinkList (6, new LinkList(5, new LinkList(5,null)))));
				LinkList node2 = new LinkList(3,new LinkList(5,new LinkList (4, new LinkList(4,null))));
				addNodes(node1,node2);
				break;
				
			}
		}

	}

}
