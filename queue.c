#include<stdio.h>

int main()
{
    int q[100],ch,front=0,rear=0,i,n;
    printf("enter size of queue : \n");
    scanf("%d",&n);
    
    
    while(1){
    printf("\n1.Insertion \n2.Deletion \n3.Display \n4.Exit");
    printf("\nenter your choice : ");
    scanf("%d",&ch);
    switch(ch){
    
    case 1:{
        if(rear==n){
            printf("que is full cant insert more elements\n ");
        }
        else{
            printf("enter your element : ");
            rear++;
            scanf("%d",&q[rear]);
        }
        break;
    } 
    
    
    case 2:{
        if(front==rear){
            printf("que is empty nothing to delete\n ");
            
        }
        else{
            printf("deleted element is  %d",q[front]);
            front++;
            n++;
        }
        break;
    }
        
    
    
    
    case 3:{
        if(front==rear){
            printf("que is empty nothing to display\n ");

        }
        else{
            for(i=front;i<=rear;i++)
            printf("%d",q[i]);
        }
    break;
    }
        
    
    
    
    case 4:{
        return(0);
    
    break;
    }
    default:{
        printf("enter a valid option ");
    }
    
    }
    }
   return(0); 
    }
