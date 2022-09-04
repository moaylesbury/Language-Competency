
public class testing {

	public static void main(String args[]) {
		dLinkedList dll = new dLinkedList();
		
		dll.insert(1);
		dll.insert(2);
		dll.insert(3);
		dll.insert(4);
		dll.insert(5);
		
		dll.removeNode(3);
		
		dll.addToStart(10);
		
		System.out.print("head: ");
		System.out.println(dll.head());
		System.out.print("tail: ");
		System.out.println(dll.tail());
		
		System.out.println("~~~~Printing~~~~~");
		
		dll.print();
		
		System.out.println("~~~~Printing~~~~~");
	}
	
	
}
