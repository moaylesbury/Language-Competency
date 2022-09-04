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

int node_is_null(struct node_t* node){
	// returns true if node value and next is NULL, else false
	if (node->v == NULL && node->next == NULL) return 1;
	return 0;
}

struct node_t* add_node(struct node_t** head, int val){
	// adds new node to the front of the linked list

	// if the node is null simply change its value
	if (node_is_null(*head)==1){
		(*head)->v = val;
		return (*head);
	}

	// otherwise create a new node
 	struct node_t* new_node = init_node();

 	new_node->v = val;
 	new_node->next = *head;

 	(*head) = new_node;

 	return (*head);
}



struct node_t* delete_node(struct node_t* curr_node, struct node_t* node_to_delete) {
	// takes a a node to delete, and the node before that (curr_node)
	// returns curr_node pointing to the node after the deleted node

	// if curr_node is null we have an element at position 0 in the linked list
	if (curr_node == NULL){
		struct node_t* new_head = init_node();
		if (node_to_delete->next){
			new_head = node_to_delete->next;
		} else {
			new_head->v = NULL;
			new_head->next = NULL;
		}

		free(node_to_delete);
		return new_head;
	}

	curr_node->next = node_to_delete->next;
	free(node_to_delete);

	return curr_node;
}

void print(struct node_t* head){
	// takes the head of a linked list
	// iterates over linked list printing each value
	printf("====printing linked list====\n");

	if (node_is_null(head) == 1){
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

	int firstItem = 0;

	struct node_t* curr_node = init_node();
	struct node_t* peek = init_node();

	struct node_t* even_nodes_ = init_node();

	even_nodes_->v = NULL;
	even_nodes_->next = NULL;

	curr_node = (*head);
	peek = (*head);

	while (peek){

		// checks if first item is even
		if (firstItem==0 && (curr_node->v % 2 == 0)){

			even_nodes_ = add_node(&even_nodes_, curr_node->v);
			peek = delete_node(NULL, curr_node);
			(*head) = peek;


			firstItem = 1;
		}

		// removes elements via peeking
		if (node_is_null(peek) == 0){
			if (peek->v % 2 == 0) {
				even_nodes_ = add_node(&even_nodes_, peek->v);
				peek = delete_node(curr_node, peek);
			}
		}

		curr_node = peek;
		peek = peek->next;
	}

	free(curr_node);
	free(peek);


	return even_nodes_;
}






int main(void) {
	printf("Program Begin\n");



	struct node_t* head = init_node();
	struct node_t* a = init_node();
	struct node_t* b = init_node();

	head->v = 10;
	head->next = NULL;

	head = add_node(&head, 4);
	head = add_node(&head, 1);
	head = add_node(&head, 5);
	head = add_node(&head, 6);
	head = add_node(&head, 7);
	head = add_node(&head, 3);





	struct node_t* tester = init_node();


	tester = even_nodes(&head);

	printf("even_nodes\n");
	print(tester);

	printf("original list\n");
	print(head);

	printf("done");
//




	return 0;
}
