#include <stdio.h>
#include <string.h>
#include <stdlib.h>

 struct node_t
 {
     unsigned v;
     struct node_t* next;
 };


struct node_t* init_node(){
	// adds memory to heap for new struct object
	return (struct node_t*)malloc(sizeof(struct node_t));
}

struct node_t* add_node(struct node_t** head, int val){
	// adds new node to the front of the linked list

 	struct node_t* new_node = init_node();

 	new_node->v = val;
 	new_node->next = *head;

 	(*head) = new_node;

 	return (*head);
}



struct node_t* delete_node(struct node_t* curr_node, struct node_t* node_to_delete) {
	// takes a a node to delete, and the node before that (curr_node)
	// returns curr_node pointing to the node after the deleted node

	curr_node->next = node_to_delete->next;
	free(node_to_delete);

	return curr_node;
}

void print(struct node_t* head){
	// takes the head of a linked list
	// iterates over linked list printing each value
	printf("====printing linked list====\n");
	while (head) {

		printf("%d\n", head->v);
		head = head->next;

	}
	printf("============================\n");

}

struct node_t* even_nodes(struct node_t** head, int change) {
	//	passed a pointer to the head pointer of a list
	//	remove all nodes with even values
	//	putting them in a new list, which is returned



	int firstItem = 0;

	struct node_t* curr_node = init_node();
	struct node_t* peek = init_node();
	struct node_t* even_nodes_ = init_node();


	curr_node = (*head);
	peek = (*head);




//	while (next_node) {
	while (peek){



		peek = curr_node->next;

		// checks if first item is even
		if (firstItem==0 && (curr_node->v % 2 == 0)){

			even_nodes_->v = curr_node->v;
			even_nodes_->next = NULL;

			(*head) = peek;
			curr_node = peek;
			peek=peek->next;

			firstItem = 1;
		}


		// removes elements via peeking
		if (peek){
			if (peek->v % 2 == 0 && change == 1) { // check even nodes tail is init
				even_nodes_ = add_node(&even_nodes_, peek->v);
				peek = delete_node(curr_node, peek);


			}
		}


		curr_node = peek;
	}

	printf("loop ended\n");

	free(curr_node);
	free(peek);


	return even_nodes_;
//	return NULL;

}






int main(void) {
	printf("!!!Hello World!!!\n");



	struct node_t* head = init_node();
	struct node_t* a = init_node();
	struct node_t* b = init_node();

	head->v = 10;
	head->next = a;

	a->v = 1;
	a->next = b;

	b->v = 4;
	b->next = NULL;


//	print(head);




	struct node_t* tester = init_node();


	tester = even_nodes(&head, 1);

	print(tester);

	print(head);

	printf("done");







	return 0;
}


