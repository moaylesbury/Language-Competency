#include <stdio.h>
#include <string.h>

#include <iostream>
#include <stddef.h>

#include <stdlib.h>

 struct node_t
 {
     unsigned v;
     struct node_t* next;
 };




struct node_t* add_node(struct node_t** head, int val){
	// adds new node to the front of the linked list

	// if the node is nullptr simply change its value
	if (!(*head)){
		(*head)->v = val;
		return (*head);
	}

	// otherwise create a new node
 	struct node_t* new_node = new node_t();

 	new_node->v = val;
 	new_node->next = *head;

 	(*head) = new_node;

 	return (*head);
}



struct node_t* delete_node(struct node_t* curr_node, struct node_t* node_to_delete) {
	// takes a a node to delete, and the node before that (curr_node)
	// returns curr_node pointing to the node after the deleted node

	// if curr_node is nullptr we have an element at position 0 in the linked list
	if (!curr_node){
		struct node_t* new_head = new node_t();
		if (node_to_delete->next){
			new_head = node_to_delete->next;
		} else {
			new_head = nullptr;
		}

		delete node_to_delete;
		return new_head;
	}

	curr_node->next = node_to_delete->next;
	delete node_to_delete;

	return curr_node;
}

void print(struct node_t* head){
	// takes the head of a linked list
	// iterates over linked list printing each value
	printf("====printing linked list====\n");

	if (!(head)){
		printf("linked list empty\n");
		return;
	}

	while (head) {

		printf("%d\n", head->v);
		head = head->next;

	}

}

struct node_t* even_nodes(struct node_t** head) {
	//	passed a pointer to the head pointer of a list
	//	remove all nodes with even values
	//	putting them in a new list, which is returned

	bool firstItem = true;

	struct node_t* curr_node = new node_t();
	struct node_t* peek = new node_t();

	struct node_t* even_nodes_ = new node_t();



	curr_node = (*head);
	peek = (*head);

	while (peek){

		// checks if first item is even
		if (firstItem && (curr_node->v % 2 == 0)){
			even_nodes_ = add_node(&even_nodes_, curr_node->v);
			peek = delete_node(nullptr, curr_node);
			(*head) = peek;


			firstItem = false;
		}

		// removes elements via peeking
		if (peek){
			if (peek->v % 2 == 0) {
				even_nodes_ = add_node(&even_nodes_, peek->v);
				peek = delete_node(curr_node, peek);
			}
		}
		curr_node = peek;
		peek = peek->next;
	}

	delete curr_node;
	delete peek;

	even_nodes_->next = nullptr;

	return even_nodes_;
}






int main(void) {
	printf("Program Begin\n");

	struct node_t* head = new node_t();

	head->v = 10;
	head->next = nullptr;

	head = add_node(&head, 4);
	head = add_node(&head, 1);
	head = add_node(&head, 5);
	head = add_node(&head, 6);
	head = add_node(&head, 7);
	head = add_node(&head, 10);


	print(head);


	struct node_t* tester = new node_t();
//
//
	tester = even_nodes(&head);
//
	printf("even_nodes\n");
	print(tester);

	printf("original list\n");
	print(head);

	printf("done");
//




	return 0;
}
