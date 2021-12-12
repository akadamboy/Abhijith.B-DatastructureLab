#include<stdio.h>
struct node{
	int data;
	struct node *link
	}*head=NULL;
int flag=0;
void create(int val){
	if(head==NULL){
		struct node *newnode=(struct node *)malloc(sizeof(struct node));
		newnode->data=val;
		newnode->link=NULL;
		head=newnode;
		flag=flag+1;
		traverse();
	}
}

void insert(int pos,int val){
	int vval,vpos;
	if (flag==0){
		printf("please create a list");
	}
	else if(pos<=flag+1){
		struct node *p=head;
		struct node *newnode=(struct node *)malloc(sizeof(struct node));
		for(int i=1;i<pos-1;i++){
		p=p->link;
		}
		newnode->data=val;
		newnode->link=p->link;
		p->link=newnode;
		flag=flag+1;
		traverse();
	}
	else{
		printf("please enter a valid position and value");
		scanf("%d%d",&vpos,&vval);
		insert(vpos,vval);
	}			
}

void delete(int pos){
	struct node *p=head,*prev;
	if(pos==1){
		head=p->link;
		flag--;
		traverse();
	}
	else if(pos<=flag & pos>1){
	for(int i=1;i<=pos-1;i++){
		prev=p;
		p=p->link;
	}
	prev->link=p->link;
	flag--;
	traverse();
	free(p);
	}
	else
		printf("enter valid position");
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
    int n,pos,val,exit;
    do{
    printf("1.create list\n2.insert\n3.delete\n4.traverse\n");
    scanf("%d",&n);
    switch(n){
        case 1:printf("enter value\n");
                scanf("%d",&val);
                create(val);
                break;
        case 2:printf("enter position and value\n");
                scanf("%d%d",&pos,&val);
                insert(pos,val);
                break;
        case 3:printf("enter position\n");
               scanf("%d",&pos);
               delete(pos);
               break;
        case 4:traverse();
                 break;
    }
    printf("\ndo u want to continue 1/0");
    scanf("%d",&exit);
    }while(exit==1);
}
