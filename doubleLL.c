#include <stdio.h>
#include <stdlib.h>

struct node{
	int data;
	struct node *next;
	struct node *prev;
};

struct node *head = NULL, *tail = NULL;

void insertBeg(int data);
void insertEnd(int data);
void insertRandom(int data, int pos);
void deleteBeg();
void deleteEnd();
void deleteRandom();
void display();
void printMenu();

void main(){
	int choice = 0, data, pos, n;
	printf("\nHow many nodes do you want to create : ");
	scanf("%d", &n);
	for(int i = 0; i < n; i++){
		printf("\nEnter data for node %d : ", i+1);
		scanf("%d", &data);
		insertEnd(data);
	}
	while(choice != 8){
	
	  	printMenu();
	 	printf("\nEnter your choice : ");
	  	scanf("%d", &choice);
	  	
		switch(choice){
			case 1: printf("\nEnter data to be inserted : ");
				  scanf("%d", &data);
				  insertBeg(data);
				  break;
			case 2: printf("\nEnter data to be inserted : ");
				  scanf("%d", &data);
				  insertEnd(data);
				  break;
			case 3: 
				  printf("\nEnter data to be inserted : ");
				  scanf("%d", &data);
				  printf("\nEnter the position (from 1): ");
				  scanf("%d", &pos);
				  insertRandom(data, pos);
				  break;
			case 4: deleteBeg();
				  break;
			case 5: deleteEnd();
				  break;
			case 6: printf("Enter position to delete : ");
				  scanf("%d", &pos);
				  deleteRandom(pos);
				  break;
			case 7: display();
				  break;
			case 8: printf("Program Terminated.\nSee u again");
				  break;
			default: printf("Invalid choice...!");
				  break;
		}
	}
}

void printMenu(){
	printf("\nDoubly Linked List Operations\n====================================");
	printf("\n1.Insert At Beginning");
	printf("\n2.Insert At End");
	printf("\n3.Insert At Random");
	printf("\n4.Delete At Beginning");
	printf("\n5.Delete At End");
	printf("\n6.Delete At Random");
	printf("\n7.Display");
	printf("\n8.Exit");
	printf("\n====================================\n");
}

void insertBeg(int data){
	struct node *newNode = (struct node*) malloc(sizeof(struct node));
	if(head == NULL){ // list is empty
		newNode->data = data;
		newNode->next = NULL;
		newNode->prev = NULL;
		head = newNode;
		tail = newNode;
	}else { // atleast one node exists
		newNode->data = data;
		newNode->next = head;
		newNode->prev = NULL;
		head = newNode;
	}	
}

void insertEnd(int data){
	struct node *newNode = (struct node*) malloc(sizeof(struct node));
	if(head == NULL){ // list is empty
		newNode->data = data;
		newNode->next = NULL;
		newNode->prev = NULL;
		head = newNode;
		tail = newNode;
	}else { // atleast one node exists
		newNode->data = data;
		newNode->next = NULL;
		newNode->prev = tail;
		tail->next = newNode;
		tail = newNode;
	}	
}

void insertRandom(int data, int pos) {
	struct node *temp;
	temp = head;
	
	for(int i = 1; i < (pos - 1); i++){
		// move temp untill temp reach just before deleting node
		temp = temp->next;
	}
	
	struct node *newNode = (struct node*) malloc(sizeof(struct node));
	if(head == NULL || pos == 1){
		insertBeg(data);
	}else if(temp->next == NULL){
		insertEnd(data);
	}
	else { // atleast one node exists
		newNode->data = data;
		newNode->next = temp->next;
		newNode->prev = temp;
		temp->next = newNode;
	}		
}

void deleteBeg(){
	if(head == NULL){
		printf("\nNo node to delete.!");
	}else if (head->next != NULL){
		struct node *ptr = head;
		head = head->next;
		head->prev = NULL;
		printf("\n%d Deleted from list.", ptr->data);
		free(ptr);
	}else{
		struct node *ptr = head;
		printf("\n%d Deleted from list.", ptr->data);
		head = tail = NULL;
		free(ptr);
	}
}

void deleteEnd(){
	if(head == NULL){
		printf("\nNo node to delete.!");
	}else if(tail->prev != NULL){
		struct node *ptr = tail;
		tail = tail->prev;
		tail->next = NULL;
		printf("\n%d Deleted from list.", ptr->data);
		free(ptr);
	}else{
		struct node *ptr = tail;
		printf("\n%d Deleted from list.", ptr->data);
		head = tail = NULL;
		free(ptr);
	}
}

void deleteRandom(int pos){
	struct node *temp = head;
	for(int i = 1; i < pos; i++){
		//move temp untill temp reaches the exact node we want to delete
		temp = temp->next;
	}
	if(head == NULL){
		printf("\nNo node to delete.!");
	}else if(pos == 1){	
		deleteBeg();
	}else if(temp->next == NULL){ // if temp is last node(tail)
		deleteEnd();
	}else{
		temp->prev->next = temp->next;
		printf("%d deleted fron List.", temp->data);
		free(temp);		
	}
}

void display(){
	struct node *temp = head;
	if(head == NULL){
		printf("\nList is empty...!\n");
	}else{
		printf("Displaying List\n===================================\n");
		while(temp != NULL){
			printf("%d->", temp->data);
			temp = temp->next;
		}
		printf("\n===================================\n");
	}
	
}

