#include<stdio.h>
struct node{
	int data;
	struct node *link
	}*head=NULL;
void create(int val){
	if(head==NULL){
		struct node *newnode=(struct node *)malloc(sizeof(struct node));
		newnode->data=val;
		newnode->link=NULL;
		head=newnode;
	}
}
void insert_beg(int val){
	struct node *newnode=(struct node *)malloc(sizeof(struct node));
	newnode->data=val;
	newnode->link=head;
	head=newnode;
    printf("current list: ");
    traverse();
}
void insert_end(int val){
	struct node *temp=head;
	struct node *newnode=(struct node *)malloc(sizeof(struct node));
	while(temp->link!=NULL){
		temp=temp->link;
	}
	newnode->data=val;
	newnode->link=NULL;
	temp->link=newnode;
    printf("current list: ");
    traverse();
}
void insert_pos(int pos,int val){
	struct node *temp=head,*p;
	struct node *newnode=(struct node *)malloc(sizeof(struct node));
	for(int i=1;i<pos;i++){
		p=temp;
		temp=temp->link;
	}
	newnode->data=val;
	newnode->link=temp;
	p->link=newnode;
    printf("current list: ");
    traverse();
}
void delete_beg(){
	int val;
	struct node *temp=head;
	val=temp->data;	
	head=temp->link;
	free(temp);
    printf("%d deleted\ncurrent list: ",val);
    traverse();
}
void delete_end(){
	int val;
	struct node *temp=head,*p;
	while(temp->link!=NULL){
		p=temp;
		temp=temp->link;
	}
	val=temp->data;
	p->link=NULL;
	free(temp);
    printf("%d deleted\ncurrent list: ",val);
    traverse();
}
void delete_pos(int pos){
	int val;
	struct node *temp=head,*p;
	for(int i=1;i<pos;i++){
		p=temp;
		temp=temp->link;
	}
	val=temp->data;
	p->link=temp->link;
	free(temp);
    printf("%d deleted\ncurrent list: ",val);
    traverse();
}
void traverse(){
	struct node *p=head;
	while(p->link!=NULL){
		printf("%d -> ",p->data);
		p=p->link;
	}
	printf("%d",p->data);
}
	
void main(){
    int n,pos,val;
    do{
    printf("\n1.create list\n2.insert begining\n3.insert end\n4.insert at position\n5.delete begining\n6.delete end\n7.delete at position\n8.Display\n9.exit\n");
    scanf("%d",&n);
    switch(n){
        case 1:printf("enter value: ");
                scanf("%d",&val);
                create(val);
                break;
        case 2:printf("enter value: ");
                scanf("%d",&val);
                insert_beg(val);
                break;
        case 3:printf("enter value: ");
                scanf("%d",&val);
		insert_end(val);
                break;
        case 4:printf("enter position and value: ");
                scanf("%d%d",&pos,&val);
		insert_pos(pos,val);		
                break;
	case 5:delete_beg(val);
                break;
        case 6:delete_end(val);
                break;
        case 7:printf("enter position: ");
                scanf("%d",&pos);
		delete_pos(pos);		
                break;
	case 8:traverse();
		break;
	case 9:break;
    }
    }while(n!=9);
}
