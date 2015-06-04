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
	public static void removeCircularity(LinkList collisionPoint,LinkList head)
	{
		LinkList ptr1 =head;
		//Check if ptr2.next == ptr1 , increment it linearly
		LinkList ptr2 = null;
		while(true)
		{
			ptr2 = collisionPoint;
			while(ptr2.nextNode != null && ptr2.nextNode != ptr1 && ptr2.nextNode != collisionPoint)
			{
				ptr2 = ptr2.nextNode;
			}
			if(ptr2.nextNode == ptr1)
			{
				System.out.println(" Start of Loop at value :: " +ptr1.value);
				break;
			}
			else
			{
				ptr1 = ptr1.nextNode;
			}
		}
		ptr2.nextNode = null;
		System.out.println(" LL after removing Circularity");
		printList(head);
	}
	public static void findCircularNode(LinkList node)
	{
		LinkList temp1 = node;
		LinkList temp2 = node;
		while(temp1 != null && temp2 != null && temp2.nextNode!= null)
		{
			temp1 = temp1.nextNode;
			temp2 = temp2.nextNode.nextNode;
			if(temp1 == temp2)
			{
				System.out.println(" LL is circular , circularity found at Value :: "+ temp1.value);
				break;
			}
		}
		if(temp1 == null || temp2 == null)
		{
			System.out.println("LL is not circular");
			return;
		}
		removeCircularity(temp1,node);
		
	}
	public static void reverseLL(LinkList node)
	{
		//1->2->3->4
		LinkList current=null,prev=null,next=null;
		current = node.nextNode;
		prev = node;
		node.nextNode = null;
		while(current != null)
		{
			LinkList temp = current.nextNode;
			current.nextNode = prev;
			prev = current;
			current = temp;
		}
		System.out.println(" Revered Link List :: ");
		printList(prev);
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
			System.out.println("6 : Find the Link that creates the Circular LL");//2.6
			System.out.println("7 : Reverse a Link List");// Own Question from various websites
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
			case 6:
				System.out.println(" Identify the Link that forms a circular LL");
				LinkList n1 = new LinkList(1,null);
				LinkList n2 = new LinkList(2,null);n1.nextNode = n2;
				LinkList n3 = new LinkList(3,null);n2.nextNode = n3;
				LinkList n4 = new LinkList(4,null);n3.nextNode = n4;
				LinkList n5 = new LinkList(5,null);n4.nextNode = n5;
				LinkList n6 = new LinkList(6,null);n5.nextNode = n6;
				LinkList n7 = new LinkList(7,null);n6.nextNode = n7;
				LinkList n8 = new LinkList(8,null);n7.nextNode = n8;
				LinkList n9 = new LinkList(9,null);n8.nextNode = n9;
				LinkList n10 = new LinkList(10,null);n9.nextNode = n10;
				LinkList n11 = new LinkList(11,null);n10.nextNode = n11;
				n11.nextNode =n5; // Circular Link
				// Print the nodes
				int i =14;
				System.out.println(" The nodes in LL Are : ");
				LinkList temp;
				temp =n1;
				while(i-- >=0)
				{
					System.out.print(temp.value +"->" );
					temp = temp.nextNode;
				}
				findCircularNode(n1);
				System.out.println();
				break;	
			case 7:
				LinkList fwdLL = new LinkList(1,new LinkList(2,new LinkList (3, new LinkList(4, new LinkList(5,new LinkList(6,null))))));
				System.out.println("Link List is :: ");printList(fwdLL);
				reverseLL(fwdLL);
				break;
				
				
			}
		}

	}

}
