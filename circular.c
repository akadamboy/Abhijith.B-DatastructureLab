 #include<stdio.h>
#define max 5
int ar[max],front=-1,rear=-1;
void enqueue(){
    int data;
    if(front==(rear+1)%max){
        printf("overflow");
    }
    else{
    printf("enter data: ");
    scanf("%d",&data);
    if(front==-1 && rear==-1){
        front=0;
        rear=0;
        ar[rear]=data;
    }
    else if(front!=0 && rear==max-1){
        rear=0;
        ar[rear]=data;    
    }
    else{
        rear=(rear+1)%max;
        ar[rear]=data;
    }
    }
}
void dequeue(){
    int val;
    if(front==-1){
        printf("Circular Queue underflow");
    }
    else if(front==rear){
        val=ar[front];
        printf("%d deleted\ncurrent queue : ",val);
        front=-1;
        rear=-1;
        display();
    }
    else if(front==max-1){
        val=ar[front];
        printf("%d deleted\ncurrent queue : ",val);
        front=0;
        display();
    }
    else{
        val=ar[front];
        printf("%d deleted\ncurrent queue : ",val);
        front=(front+1)%max;
        display();
    }
}
void display(){
    int i;
    if(front<=rear){
        for(i=front;i<=rear;i++){
            printf("%d\t",ar[i]);
        }
    }
    else if(front>rear){
        for(i=front;i<max;i++){
            printf("%d\t",ar[i]);
        }
        for(i=0;i<=rear;i++){
            printf("%d\t",ar[i]);
        }
    }
}
int main(){
    int n,a;
    do{
    printf("\n1.enqueue\n2.dequeue\n3.display\n4.exit\n");
    scanf("%d",&n);
    switch (n)
    {
    case 1:
        printf("no. of elements: ");
        scanf("%d",&a);
        for(int i=0;i<a;i++){
        enqueue();
    }
        break;
    case 2:
        dequeue();
        break;
    case 3:
        display();
        break;
    case 4:
        break;
    default:printf("enter a valid option:\n");
        break;
    }
    } while (n != 4);
return 0;
}
