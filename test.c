#include <stdio.h>
#include <string.h>
#include <stdlib.h>

 struct node_t
 {
     unsigned v;
     struct node_t* next;
 };




struct node_t* add_node(struct node_t** head, int val){

 	struct node_t* new_node = (struct node_t*)malloc(sizeof(struct node_t));

 	new_node->v = val;
 	new_node->next = *head;

 	(*head) = new_node;

 	return (*head);


}



struct node_t* delete_node(struct node_t* curr_node, struct node_t* node_to_delete) {
	// takes a a node to delete, and the node before that (curr_node)
	// returns curr_node pointing to the node after the deleted node

	printf("del call\n");

//	struct node_t null_node = {.v=NULL, .next=NULL};

	curr_node->next = node_to_delete->next;
	free(node_to_delete);
//	node_to_delete = &null_node;

	return curr_node;
}

struct node_t* even_nodes(struct node_t** head, int change) {
	//	passed a pointer to the head pointer of a list
	//	remove all nodes with even values
	//	putting them in a new list, which is returned



	// theres gonna be an issue differentiating between head and next_node


	struct node_t* next_node = (*head);

	// NULL initialisation
//	struct node_t even_nodes = {.v=NULL, .next=NULL};
//	struct node_t even_nodes;
	struct node_t* even_nodes_head;
	struct node_t* peek = (*head);
	struct node_t* even_nodes_tail;
	int firstItem = 0; // 0 false 1 true


	struct node_t* even_nodes_ = NULL;
	even_nodes_ = (struct node_t*)malloc(sizeof(struct node_t));


	printf("fun call\n");

//	printf("test %d\n", (**head).v);




//	while (next_node) {
	while (peek){



		peek = next_node->next;
		printf("n= %d", next_node->v);
		if (peek) printf("  |  p= %d\n", peek->v) ; else printf("\n");

		// checks if first item is even
		if (firstItem==0 && (next_node->v % 2 == 0) && change == 1){
			printf("c1 with %d\n", next_node->v);
			// if first item

			// set current item to even head and remove next pointer
//			even_nodes = (*next_node);
//			struct node_t even_nodes = {.v=next_node->v, .next=NULL};

			even_nodes_->v = next_node->v;
			even_nodes_->next = NULL;

//			even_nodes_head = &even_nodes;
//			even_nodes_tail = &even_nodes;


			// move the head pointer along by one
			(*head) = peek;
			next_node = peek;
			peek=peek->next;

			firstItem = 1;
		}


		// removes elements via peeking
		if (peek){
			if (peek->v % 2 == 0 && change == 1) { // check even nodes tail is init
				printf("c2 with %d\n", peek->v);
//				even_nodes_tail = add_node(even_nodes_tail, peek->v);
//				even_nodes_tail = add_node(&even_nodes_tail, peek->v);
				even_nodes_ = add_node(&even_nodes_, peek->v);
//				next_node = delete_node(next_node, peek);
				peek = delete_node(next_node, peek);


			}
		}





		next_node = peek;
	}

	printf("loop ended\n");


	return even_nodes_;
//	return NULL;

}


void print(struct node_t* head){
	printf("====printing linked list====\n");
	while (head) {

		printf("%d\n", head->v);
		head = head->next;

	}
	printf("============================\n");

}



int main(void) {
	printf("!!!Hello World!!!\n");



	struct node_t* head = NULL;
	struct node_t* a = NULL;
	struct node_t* b = NULL;

	head = (struct node_t*)malloc(sizeof(struct node_t));
	a = (struct node_t*)malloc(sizeof(struct node_t));
	b = (struct node_t*)malloc(sizeof(struct node_t));

	head->v = 10;
	head->next = a;

	a->v = 1;
	a->next = b;

	b->v = 4;
	b->next = NULL;


//	print(head);




	struct node_t* tester = (struct node_t*)malloc(sizeof(struct node_t));


	tester = even_nodes(&head, 1);

	print(tester);

	print(head);

	printf("done");







	return 0;
}












