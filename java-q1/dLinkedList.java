
public class dLinkedList {

	// pointers to head and tail
	Node head, tail;
	// tracks if insert is first insert
	boolean firstInsert = true;

	// initiate head and tail pointers as new nodes
	public dLinkedList() {
		this.head = new Node();
		this.tail = new Node();
	}
	
	public void addToStart(int n) {
		// create new node with value n
		Node newNode = new Node();
		newNode.val = n;
		
		// if first insert simply set head and tail to the new node
		if (firstInsert) {
			head = newNode;
			tail = newNode;
			firstInsert = false;
		} else {
		
		// the next pointer points to the tail, the current first item
		newNode.next = tail;
		// tails prev pointer is changed from null to the new first item
		tail.prev = newNode;
		
		// update the tail
		tail = newNode;
		}
	}

	public void removeNode(int n) {
		// get head pointer
		Node node = head;
		// make sure not removed twice, instead first instance is removed
		boolean removed = false;
		// loop from head to tail
		while(node.prev != null) {
			// if the node has the correct val, and hasn't been removed
			if (node.val == n && !removed) {
				// connect the nodes on either side of the removed node
				node.prev.next = node.next;
				node.next.prev = node.prev;
				// set removed to true
				removed = true;
			}
			// update node to check
			node = node.prev;
		}
	}
	
	public int head() {
		// return value of head
		return head.val;
	}
	
	public int tail() {
		// return value of tail
		return tail.val;
	}
	
	public void print() {
		// loop from tail to head
		Node node = tail;
		while(node != null) {
			// print node value
			System.out.println(node.val);
			node = node.next;
		}
	}
	
	
	public void insert(int n) {
		// create new node
		Node newNode = new Node();
		
		// set node value to n, and the prev pointer of the newNode to the current head
		newNode.val = n;
		newNode.prev = head;
		
		// set head next pointer to newNode
		head.next = newNode;
		
		// update head of list as new node becomes the head
		head = newNode;
		
		// if this is the first item being added, set to the tail
		if (firstInsert) {
			tail = newNode;
			firstInsert = false;
		}
	}
	

	
}
